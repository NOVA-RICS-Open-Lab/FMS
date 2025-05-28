#include "RS485.h"

#if defined(HAVE_RS485)

#if defined(HAVE_RS485_SOFT)
////////////////////////////////////////////////////////////////////////////////////////////////////
RS485Class::RS485Class(uint8_t rxPin, uint8_t txPin) : SoftwareSerial(rxPin, txPin) {
	_bufferMode = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::begin(unsigned long baud, uint8_t duplex, uint8_t config) {
	// Both duplex and config are not used
	UNUSED(duplex);
	UNUSED(config);

	pinMode(RS485_RE, OUTPUT);
	pinMode(RS485_DE, OUTPUT);
	pinMode(RS485_RX, INPUT);

	disableTx();

	SoftwareSerial::begin(baud);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::enableTx() {
	digitalWrite(RS485_DE, HIGH);
	digitalWrite(RS485_RE, HIGH);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::disableTx() {
	digitalWrite(RS485_DE, LOW);
	digitalWrite(RS485_RE, LOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t RS485Class::write(uint8_t value) {
	enableTx();
	size_t ret = SoftwareSerial::write(value);
	if (!_bufferMode) {
		disableTx();
	}
	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t RS485Class::write(const uint8_t *buff, size_t len) {
	_bufferMode = true;
	enableTx();
	size_t ret = SoftwareSerial::write(buff, len);
	disableTx();
	_bufferMode = false;
	return ret;
}

RS485Class RS485(RS485_RX, RS485_TX);

#endif // HAVE_RS485_SOFT

#if defined(HAVE_RS485_HARD)

#include <HardwareSerial_private.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
RS485Class::RS485Class(
		volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
		volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
		volatile uint8_t *ucsrc, volatile uint8_t *udr) :
	HardwareSerial(ubrrh, ubrrl, ucsra, ucsrb, ucsrc, udr)
{
	_sending = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::begin(unsigned long baud, uint8_t duplex, uint8_t config) {
	_duplex = duplex;

	pinMode(RS485_RE, OUTPUT);
	pinMode(RS485_DE, OUTPUT);

	disableTx();

	HardwareSerial::begin(baud, config);

	// Enable TX complete interrupt
	sbi(*_ucsrb, TXCIE0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::end() {
	HardwareSerial::end();

	// Disable TX complete interrupt
	cbi(*_ucsrb, TXCIE0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::flush() {
	while (_sending);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
size_t RS485Class::write(uint8_t value) {
	enableTx();
	return HardwareSerial::write(value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::_tx_irq() {
	disableTx();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::enableTx() {
	_sending = true;
	if (_duplex == HALFDUPLEX) {
		// Disable reception
		digitalWrite(RS485_RE, HIGH);
	}
	digitalWrite(RS485_DE, HIGH);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS485Class::disableTx() {
	digitalWrite(RS485_DE, LOW);
	if (_duplex == HALFDUPLEX) {
		// Enable reception
		digitalWrite(RS485_RE, LOW);
	}
	_sending = false;
}

#if RS485_HWSERIAL == 1
ISR(USART1_RX_vect)
{
	RS485._rx_complete_irq();
}
ISR(USART1_UDRE_vect)
{
	RS485._tx_udr_empty_irq();
}
ISR(USART1_TX_vect)
{
	RS485._tx_irq();
}
RS485Class RS485(&UBRR1H, &UBRR1L, &UCSR1A, &UCSR1B, &UCSR1C, &UDR1);
#elif RS485_HWSERIAL == 2
ISR(USART2_RX_vect)
{
	RS485._rx_complete_irq();
}
ISR(USART2_UDRE_vect)
{
	RS485._tx_udr_empty_irq();
}
ISR(USART2_TX_vect)
{
	RS485._tx_irq();
}
RS485Class RS485(&UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2);
#elif RS485_HWSERIAL == 3
ISR(USART3_RX_vect)
{
	RS485._rx_complete_irq();
}
ISR(USART3_UDRE_vect)
{
	RS485._tx_udr_empty_irq();
}
ISR(USART3_TX_vect)
{
	RS485._tx_irq();
}
RS485Class RS485(&UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3);
#endif // RS485_HWSERIAL

#endif // HAVE_RS485_HARD

void RS485Event() __attribute__((weak));

void RS485EventRun() {
	if (RS485Event && RS485.available()) {
		RS485Event();
	}
}

#endif // HAVE_RS485
