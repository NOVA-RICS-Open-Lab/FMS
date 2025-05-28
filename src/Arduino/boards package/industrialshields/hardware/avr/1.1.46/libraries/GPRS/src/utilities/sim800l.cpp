/*
   Copyright (c) 2019 Boot&Work Corp., S.L. All rights reserved

   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sim800l.h"

#if defined(HAVE_SIM800L)

#if defined(__AVR__)
#include <avr/pgmspace.h>
#endif

#if defined(HAVE_SIM800L_HARD)
#include <HardwareSerial_private.h>

#if SIM800L_HWSERIAL == 1
HardwareSerial SIM800L(&UBRR1H, &UBRR1L, &UCSR1A, &UCSR1B, &UCSR1C, &UDR1);
ISR(USART1_RX_vect)
{
	SIM800L._rx_complete_irq();
}
ISR(USART1_UDRE_vect)
{
	SIM800L._tx_udr_empty_irq();
}
#elif SIM800L_HWSERIAL == 2
HardwareSerial SIM800L(&UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2);
ISR(USART2_RX_vect)
{
	SIM800L._rx_complete_irq();
}
ISR(USART2_UDRE_vect)
{
	SIM800L._tx_udr_empty_irq();
}
#elif SIM800L_HWSERIAL == 3
HardwareSerial SIM800L(&UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3);
ISR(USART3_RX_vect)
{
	SIM800L._rx_complete_irq();
}
ISR(USART3_UDRE_vect)
{
	SIM800L._tx_udr_empty_irq();
}
#endif // SIM800L_HWSERIAL

#elif defined(HAVE_SIM800L_SOFT)
#include <SoftwareSerial.h>

SoftwareSerial SIM800L(SIM800L_RX_PIN, SIM800L_TX_PIN);
#endif

#define RESP_F(x) ((const char PROGMEM *) F(x))
#define RESP_OK (RESP_F("OK"))
#define RESP_OK_LEN (2)

const size_t responseSize = 1024;
char response[responseSize];

const char *GPRSModule::apn = nullptr;
const char *GPRSModule::username = nullptr;
const char *GPRSModule::password = nullptr;
uint16_t GPRSModule::serverPort = 0;
uint8_t GPRSModule::connections[GPRSModule::MaxConnections];

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::begin() {
	SIM800L.begin(SIM800L_RATE);

	GPRSModule::enableEcho();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::reset() {
	pinMode(SIM800L_RESET_PIN, OUTPUT);
	digitalWrite(SIM800L_RESET_PIN, HIGH);
	delay(10);
	digitalWrite(SIM800L_RESET_PIN, LOW);
	delay(100);
	digitalWrite(SIM800L_RESET_PIN, HIGH);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::at() {
	if (sendCommand(F("AT"), 2, 100) == 0) {
		return false;
	}
	if (strncmp_P(response, RESP_F("AT"), 2) == 0) {
		return true;
	}
	if (strncmp_P(response, RESP_OK, 2) == 0) {
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int GPRSModule::isPINRequired() {
	if (sendCommand(F("AT+CPIN?"), 2) == 0) {
		return -1;
	}
	if (strncmp_P(response, RESP_F("+CPIN: "), 7) != 0) {
		return -1;
	}
	if (strncmp_P(response + 7, RESP_F("READY"), 5) == 0) {
		return 0;
	}
	if (strncmp_P(response + 7, RESP_F("SIM PIN"), 7) == 0) {
		return 1;
	}

	delay(100);

	return 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSModule::getRSSI() {
	if (sendCommand(F("AT+CSQ"), 2) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CSQ: "), 6) != 0) {
		return 0;
	}
	return atoi(response + 6);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::unlockSIM(const char *pin) {
	beginPartialCommand(F("AT+CPIN="));
	sendPartialCommand(pin);
	if (endPartialCommand(1, 10000) == 0) {
		return false;
	}
	return strcmp_P(response, RESP_OK) == 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::enableEcho() {
	return sendOKCommand(F("ATE1"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::disableEcho() {
	return sendOKCommand(F("ATE0"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::enableMultipleConnections() {
	return sendOKCommand(F("AT+CIPMUX=1"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSModule::getNetworkStatus() {
	if (sendCommand(F("AT+CREG?"), 2) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CREG: "), 7) != 0) {
		return 0;
	}
	return atoi(response + 9);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::enableNetworkTimeSync() {
	return sendOKCommand(F("AT+CLTS=1"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int GPRSModule::getTime(char *buff, size_t len) {
	if (sendCommand(F("AT+CCLK?"), 2) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CCLK: "), 7) != 0) {
		return 0;
	}
	memcpy(buff, response + 7, len);
	buff[len - 1] = '\0';
	return len;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSModule::getGPRSStatus() {
	if (sendCommand(F("AT+CGATT?"), 2) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CGATT: "), 8) != 0) {
		return 0;
	}
	return atoi(response + 8);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::disableGPRS() {
	// Deactivate GPRS PDP context
	if (sendCommand(F("AT+CIPSHUT"), 1, 20000) == 0) {
		return false;
	}
	for (int i = 0; i < MaxConnections; ++i) {
		connections[i] = NoConnection;
	}
	delay(100);

	sendOKCommand(F("AT+SAPBR=0,1"), 10000);
	delay(100);

	sendOKCommand(F("AT+CGATT=0"), 10000);
	delay(100);

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::setGPRSSettings(const char *a, const char *u, const char *p) {
	apn = a;
	username = u;
	password = p;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::enableGPRS() {
	// Deactivate GPRS PDP context
	if (sendCommand(F("AT+CIPSHUT"), 1, 20000) == 0) {
		return false;
	}
	for (int i = 0; i < MaxConnections; ++i) {
		connections[i] = NoConnection;
	}
	delay(100);

	if (getGPRSStatus() == 0) {
		// Attach to GPRS service
		if (!sendCommand(F("AT+CGATT=1"), 10, 10000)) {
			return false;
		}
	}

	return startGPRS();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::enableGPRS(const char *a, const char *u, const char *p) {
	setGPRSSettings(a, u, p);

	return enableGPRS();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::startGPRS() {
	// Multiple connections
	if (!sendOKCommand(F("AT+CIPMUX=1"), 10000)) {
		return false;
	}

	// Enable receive data manually
	if (!sendOKCommand(F("AT+CIPRXGET=1"))) {
		return false;
	}

	// Set APN
	if (apn) {
		beginPartialCommand(F("AT+CSTT=\""));
		sendPartialCommand(apn);
		sendPartialCommand(F("\",\""));
		if (username) {
			sendPartialCommand(username);
		}
		sendPartialCommand(F("\",\""));
		if (password) {
			sendPartialCommand(password);
		}
		sendPartialCommand(F("\""));
		if (endPartialCommand(1, 10000) == 0) {
			return false;
		}
		if (strcmp_P(response, RESP_OK) != 0) {
			return false;
		}

		// Enable wireless connectivity
		if (!startWireless()) {
			return false;
		}

		getIPAddress();

		if (serverPort > 0) {
			startTCPServer();
		}


	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::startWireless() {
	return sendOKCommand(F("AT+CIICR"), 10000);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::connected() {
	if (sendCommand(F("AT+CIPSTATUS"), 8) == 0) {
		return false;
	}
	if (strncmp_P(response, RESP_OK, RESP_OK_LEN) != 0) {
		return false;
	}

	// STATE: <state>
	const char *ptr = getNextResponseLine(response);
	if (strncmp_P(ptr, RESP_F("STATE: "), 7) != 0) {
		flushInput(); // Discard connections states
		return false;
	}

	bool connectedStatus = false;
	const char *status = ptr + 7;
	bool newIPAddress = false;
	bool enableGPRSRequired = false;
	bool startGPRSRequired = false;
	bool startWirelessRequired = false;
	if ((strncmp_P(status, RESP_F("IP STATUS"), 9) == 0) ||
			(strncmp_P(status, RESP_F("IP PROCESSING"), 13) == 0)) {
		connectedStatus = true;
	} else if (strncmp_P(status, RESP_F("IP GPRSACT"), 10) == 0) {
		connectedStatus = true;
		newIPAddress = true;
	} else if (strncmp_P(status, RESP_F("IP START"), 8) == 0) {
		connectedStatus = true;
		startWirelessRequired = true;
	} else if (strncmp_P(status, RESP_F("IP INITIAL"), 10) == 0) {
		startGPRSRequired = true;
	} else if (strncmp_P(status, RESP_F("PDP DEACT"), 9) == 0) {
		enableGPRSRequired = true;
	}

	flushInput(); // Discard connections states
	if (enableGPRSRequired) {
		enableGPRS();
	} else if (startGPRSRequired) {
		startGPRS();
	} else if (startWirelessRequired) {
		startWireless();
	} else if (newIPAddress) {
		getIPAddress();

		if (serverPort > 0) {
			startTCPServer();
		}
	}

	return connectedStatus;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
IPAddress GPRSModule::getIPAddress() {
	IPAddress ipAddress;
	if (sendCommand(F("AT+CIFSR"), 1)) {
		ipAddress.fromString(response);
	}
	return ipAddress;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::startTCPServer() {
	beginPartialCommand(F("AT+CIPSERVER=1,"));
	sendPartialCommand(serverPort);
	if (endPartialCommand(2) == 0) {
		return false;
	}
	return strncmp_P(response, RESP_OK, RESP_OK_LEN) == 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::setTCPServerPort(uint16_t port) {
	serverPort = port;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSModule::startTCPConnection(const char *host, uint16_t port) {
	uint8_t sock = getNextSock();
	if (sock >= MaxConnections) {
		return Invalid;
	}

	// Connect
	beginPartialCommand(F("AT+CIPSTART="));
	sendPartialCommand(sock);
	sendPartialCommand(F(",\"TCP\",\""));
	sendPartialCommand(host);
	sendPartialCommand(F("\",\""));
	sendPartialCommand(port);
	sendPartialCommand(F("\""));
	if (endPartialCommand(1, 30000) == 0) {
		return Invalid;
	}
	if (strncmp_P(response, RESP_OK, RESP_OK_LEN) != 0) {
		return Invalid;
	}

	char *ptr = response;
	uint32_t startTime = millis();
	while (true) {
		while (SIM800L.available()) {
			char c = SIM800L.read();
			if (c == '\r') {
				continue;
			}
			if (c == '\n') {
				if (ptr == response) {
					// Ignore the first '\n'
					continue;
				} else if (sock == (uint8_t) (response[0] - '0')) {
					*ptr = '\0';
					// Parse response: n,"CONNECT OK"
					if (strncmp_P(response + 3, RESP_F("CONNECT OK"), 10) != 0) {
						return Invalid;
					}

					// CONNECT OK

					connections[sock] = UserConnection;
					return sock;
				} else {
					// Invalid line: start again
					ptr = response;
					break;
				}
			}
			*ptr++ = c;

			if (ptr - response >= responseSize - 1) {
				// Overflow
				return Invalid;
			}
		}

		if (millis() - startTime > 30000UL) {
			return Invalid;
		}
	}

	return Invalid;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::isConnectedConnection(uint8_t sock) {
	if (sock >= MaxConnections) {
		return false;
	}

	beginPartialCommand(F("AT+CIPSTATUS="));
	sendPartialCommand(sock);
	if (endPartialCommand(2) == 0) {
		return false;
	}
	if (strncmp_P(response, RESP_F("+CIPSTATUS: "), 11) != 0) {
		return false;
	}
	const char *ptr = response + 11;

	// get 5 values: s, bearer, TCP/UDP, IP address, TCP/UDP port, client state
	uint8_t s = atoi(ptr);
	if (s != sock) {
		return false;
	}

	for (int i = 0; i < 5; ++i) {
		ptr = getNextResponseValue(ptr);
		if (ptr == nullptr) {
			break;
		}
	}
	if (ptr == nullptr) {
		return false;
	}

	return (strncmp_P(ptr, RESP_F("\"CONNECTED\""), 11) == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int GPRSModule::getConnectionAvailable(uint8_t sock) {
	if (sock >= MaxConnections) {
		return 0;
	}

	beginPartialCommand(F("AT+CIPRXGET=4,"));
	sendPartialCommand(sock);
	if (endPartialCommand(2) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CIPRXGET: 4,"), 13) != 0) {
		return 0;
	}
	return atoi(response + 15);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t GPRSModule::writeToConnection(uint8_t sock, const uint8_t *buff, size_t size) {
	if (sock >= MaxConnections) {
		return 0;
	}

	beginPartialCommand(F("AT+CIPSEND="));
	sendPartialCommand(sock);
	sendPartialCommand(F(","));
	sendPartialCommand(size);
	if (endPartialCommand(1) == 0) {
		return 0;
	}
	if (response[0] != '>') {
		return 0;
	}
	sendRaw(buff, size);

	// Discard data echo
	size_t r = 0;
	uint32_t startTime = millis();
	while ((r < size) && (millis() - startTime < 1000)) {
		if (SIM800L.available()) {
			SIM800L.read();
			++r;
			startTime = millis();
		}
	}

	if (readResponse(1, 3000, true) == 0) {
		return 0;
	}
	const char *ptr = getNextResponseValue(response);
	if (ptr == nullptr) {
		return 0;
	}
	if (strcmp_P(ptr, RESP_F(" SEND OK")) != 0) {
		return 0;
	}

	return size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int GPRSModule::readFromConnection(uint8_t sock, uint8_t *buff, size_t size) {
	if (sock >= MaxConnections) {
		return 0;
	}

	beginPartialCommand(F("AT+CIPRXGET=2,"));
	sendPartialCommand(sock);
	sendPartialCommand(F(","));
	sendPartialCommand(size);
	if (endPartialCommand(1) == 0) {
		return 0;
	}
	if (strncmp_P(response, RESP_F("+CIPRXGET: 2,"), 13) != 0) {
		return 0;
	}
	size_t len = atoi(response + 15);
	if (len == 0) {
		return 0;
	}
	return readRawResponse(buff, len);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::stopConnection(uint8_t sock) {
	if (sock >= MaxConnections) {
		return false;
	}

	beginPartialCommand(F("AT+CIPCLOSE="));
	sendPartialCommand(sock);
	endPartialCommand(1);

	connections[sock] = NoConnection;

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::sendOKCommand(const char *req, uint32_t timeout) {
	if (sendCommand(req, 1, timeout) == 0) {
		return false;
	}
	return strcmp_P(response, RESP_OK) == 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::sendOKCommand(const __FlashStringHelper* req, uint32_t timeout) {
	if (sendCommand(req, 1, timeout) == 0) {
		return false;
	}
	return strcmp_P(response, RESP_OK) == 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t GPRSModule::sendCommand(const char *req, uint8_t resLines, uint32_t timeout) {
	beginPartialCommand(req);
	return endPartialCommand(resLines, timeout);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t GPRSModule::sendCommand(const __FlashStringHelper *req, uint8_t resLines, uint32_t timeout) {
	beginPartialCommand(req);
	return endPartialCommand(resLines, timeout);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::checkUnsolicited() {
	delay(100);
	if (SIM800L.available()) {
#if DEBUG
		Serial.print("unsolicited: ");
#endif
		char c;
		do {
			c = SIM800L.read();
#if DEBUG
			Serial.write(c);
#endif
		} while (SIM800L.available());
#if DEBUG
		Serial.println();
		Serial.flush();
#endif
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::beginPartialCommand(const char *partial) {
	checkUnsolicited();

#if DEBUG
	Serial.print("Command: ");
	Serial.print(partial);
#endif
	SIM800L.print(partial);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::beginPartialCommand(const __FlashStringHelper *partial) {
	checkUnsolicited();

#if DEBUG
	Serial.print("Command: ");
	Serial.print(partial);
#endif
	SIM800L.print(partial);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::sendPartialCommand(const char *partial) {
#if DEBUG
	Serial.print(partial);
#endif
	SIM800L.print(partial);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::sendPartialCommand(const __FlashStringHelper *partial) {
#if DEBUG
	Serial.print(partial);
#endif
	SIM800L.print(partial);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::sendPartialCommand(int32_t partial) {
#if DEBUG
	Serial.print(partial);
#endif
	SIM800L.print(partial);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t GPRSModule::endPartialCommand(uint8_t resLines, uint32_t timeout) {
#if DEBUG
	Serial.println();
	Serial.flush();
#endif
	SIM800L.println();
	SIM800L.flush();
	return readResponse(resLines, timeout);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::sendRaw(const uint8_t *buff, size_t len) {
#if DEBUG
	Serial.print("<send raw data>");
#endif
	SIM800L.write(buff, len);
	SIM800L.flush();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::flush() {
	SIM800L.flush();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GPRSModule::flushInput() {
	uint32_t lastByte = millis();
	while (millis() - lastByte < 40) {
		while (SIM800L.available()) {
			SIM800L.read();
			lastByte = millis();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t GPRSModule::readResponse(uint8_t numLines, uint32_t timeout, bool echoDone) {
	char *ptr = response;

	uint32_t startTime = millis();
	while ((numLines > 0) && (millis() - startTime < timeout) && (ptr - response < responseSize - 1)) {
		while (SIM800L.available()) {
			char c = SIM800L.read();
			if (c == '\r') {
				continue;
			}
			if (c == '\n') {
				if (ptr == response) {
					// Ignore the first '\n'
					continue;
				} else if (*(ptr - 1) == '\n') {
					// Ignore empty line
					continue;
				} else if (!echoDone) {
					// echo done or unsolicited line
					echoDone = strncmp_P(response, RESP_F("AT"), 2) == 0;
					ptr = response;
					continue;
				}

				--numLines;
				if (numLines == 0) {
					break;
				}
			}
			*ptr++ = c;

			if (ptr - response >= responseSize - 1) {
#if DEBUG
				Serial.println("response overflow");
#endif
				break;
			}
		}
	}
	*ptr = '\0';
#if DEBUG
	Serial.print("Response: ");
	Serial.println(response);
#endif
	return ptr - response;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int GPRSModule::readRawResponse(uint8_t *buff, size_t len) {
	uint8_t *ptr = buff;
	uint32_t startTime = millis();
	while ((len > 0) && (millis() - startTime < 40)) {
		if (SIM800L.available()) {
			*ptr++ = SIM800L.read();
			startTime = millis();
			--len;
		}
	}
#if DEBUG
	Serial.println("<read raw data>");
#endif
	return ptr - buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char *GPRSModule::getNextResponseValue(const char *ptr, char delim) {
	while ((*ptr != '\0') && (*ptr != delim)) {
		++ptr;
	}
	if (*ptr == '\0') {
		return nullptr;
	}
	return ptr + 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char *GPRSModule::getNextResponseLine(const char *ptr) {
	return getNextResponseValue(ptr, '\n');
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::updateConnections() {
	if (sendCommand(F("AT+CIPSTATUS"), 8, 5000) == 0) {
		// No response
		return false;
	}
	if (strncmp_P(response, RESP_OK, RESP_OK_LEN) != 0) {
		// Not OK response
		return false;
	}

	const char *ptr = getNextResponseLine(response);
	if (ptr == nullptr) {
		// Incomplete response
		return false;
	}

	// STATE: <state>
	if (strncmp_P(ptr, RESP_F("STATE: "), 7) != 0) {
		// Invalid response
		return false;
	}

	for (int i = 0; i < MaxConnections; ++i) {
		ptr = getNextResponseLine(ptr);
		if (ptr == nullptr) {
			// Incomplete response
			break;
		}
		if (*ptr != 'C') {
			// Server or unkown connection line
			continue;
		}

		// FORMAT: C: n,bearer,"TCP/UDP","IP address","TCP/UDP port","client state"
		ptr += 3;
		uint8_t s = *ptr - '0';
		if (s >= MaxConnections) {
			break;
		}

		if (connections[s] == UserConnection) {
			// User controlled connection
			continue;
		}

		for (int i = 0; i < 5; ++i) {
			ptr = getNextResponseValue(ptr);
			if (ptr == nullptr) {
				// Invalid line format
				break;
			}
		}
		if (ptr == nullptr) {
			// Invalid line format
			continue;
		}

		connections[s] = (strncmp_P(ptr, RESP_F("\"INITIAL\""), 9) == 0) ||
			(strncmp_P(ptr, RESP_F("\"CLOSED\""), 8) == 0) ? NoConnection : ServerConnection;
	}

	flushInput(); // Discard other lines

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSModule::getNextSock() {
	if (!updateConnections()) {
		return Invalid;
	}

	for (int i = 0; i < MaxConnections; ++i) {
		if (connections[i] == NoConnection) {
			return i;
		}
	}

	return Invalid;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSModule::sendSMS(const char* number, const char* text) {
	if (!sendOKCommand(F("AT+CMGF=1"))) {
		return false;
	}

	beginPartialCommand(F("AT+CMGS=\""));
	sendPartialCommand(number);
	sendPartialCommand(F("\""));
	if (endPartialCommand(1, 1000) == 0) {
		return false;
	}
	if (response[0] != '>') {
		return false;
	}
	size_t textLen = strlen(text);
	sendRaw((const uint8_t*) text, textLen);
	uint8_t ctrlZ = 26;
	sendRaw(&ctrlZ, 1);

	if (readResponse(2, 60000, true) == 0) {
		return false;
	}
	return true;
}

#endif
