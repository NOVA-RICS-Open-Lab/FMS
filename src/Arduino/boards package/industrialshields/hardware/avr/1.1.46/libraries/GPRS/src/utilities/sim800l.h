#ifndef __GPRSMODULE_H__
#define __GPRSMODULE_H__

#include <Arduino.h>
#include <IPAddress.h>

#if defined(HAVE_SIM800L)

class GPRSModule {
	public:
		enum {
			MaxConnections = 6,
			Invalid = MaxConnections,
		};

		enum {
			NoConnection,
			ServerConnection,
			UserConnection,
		};

	public:
		static void begin();
		static void reset();
		static bool at();

		static int isPINRequired();
		static bool unlockSIM(const char *pin);

		static bool enableEcho();
		static bool disableEcho();
		static uint8_t getRSSI();
		static bool enableMultipleConnections();
		static uint8_t getNetworkStatus();
		static bool enableNetworkTimeSync();
		static int getTime(char *buff, size_t len);
		static uint8_t getGPRSStatus();
		static bool disableGPRS();
		static bool enableGPRS();
		static bool enableGPRS(const char *apn, const char *username = nullptr, const char *password = nullptr);
		static bool connected();
		static IPAddress getIPAddress();
		static void setTCPServerPort(uint16_t port);
		static uint8_t startTCPConnection(const char *host, uint16_t port);
		static bool isConnectedConnection(uint8_t sock);
		static int getConnectionAvailable(uint8_t sock);
		static size_t writeToConnection(uint8_t sock, const uint8_t *buff, size_t size);
		static int readFromConnection(uint8_t sock, uint8_t *buff, size_t size);
		static bool stopConnection(uint8_t sock);
		static bool updateConnections();

		static bool sendSMS(const char* number, const char* text);

		static uint8_t getNextSock();
		static void flush();
		static void flushInput();

	private:
		static void setGPRSSettings(const char *apn, const char *username, const char *password);
		static bool startGPRS();
		static bool startWireless();
		static bool startTCPServer();

		static void checkUnsolicited();
		static bool sendOKCommand(const char *req, uint32_t timeout = 500);
		static bool sendOKCommand(const __FlashStringHelper *req, uint32_t timeout = 500);
		static uint16_t sendCommand(const char *req, uint8_t resLines, uint32_t timeout = 500);
		static uint16_t sendCommand(const __FlashStringHelper *req, uint8_t resLines, uint32_t timeout = 500);
		static void beginPartialCommand(const char *partial);
		static void beginPartialCommand(const __FlashStringHelper *partial);
		static void sendPartialCommand(const char *partial);
		static void sendPartialCommand(const __FlashStringHelper *partial);
		static void sendPartialCommand(int32_t partial);
		static uint16_t endPartialCommand(uint8_t resLines, uint32_t timeout = 500);
		static void sendRaw(const uint8_t *buff, size_t len);
		static uint16_t readResponse(uint8_t numLines, uint32_t timeout, bool echoDone = false);
		static int readRawResponse(uint8_t *buff, size_t len);
		static const char *getNextResponseValue(const char *buff, char delim = ',');
		static const char *getNextResponseLine(const char *buff);

	public:
		static uint8_t connections[MaxConnections];

	private:
		static const char *apn;
		static const char *username;
		static const char *password;
		static uint16_t serverPort;
};

#endif

#endif
