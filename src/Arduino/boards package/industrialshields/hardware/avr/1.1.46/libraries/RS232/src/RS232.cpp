#include "RS232.h"

#if defined(HAVE_RS232)

#if defined(HAVE_RS232_SOFT)
RS232Class::RS232Class(uint8_t rxPin, uint8_t txPin) : SoftwareSerial(rxPin, txPin) {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RS232Class::begin(unsigned long baud, uint8_t config) {
	pinMode(RS232_TX, OUTPUT);
	pinMode(RS232_RX, INPUT);

	SoftwareSerial::begin(baud);
}
RS232Class RS232(RS232_RX, RS232_TX);
#endif // HAVE_RS232_SOFT

#if defined(HAVE_RS232_HARD)

#include <HardwareSerial_private.h>

#if RS232_HWSERIAL == 1
ISR(USART1_RX_vect)
{
	RS232._rx_complete_irq();
}
ISR(USART1_UDRE_vect)
{
	RS232._tx_udr_empty_irq();
}
HardwareSerial RS232(&UBRR1H, &UBRR1L, &UCSR1A, &UCSR1B, &UCSR1C, &UDR1);
#elif RS232_HWSERIAL == 2
ISR(USART2_RX_vect)
{
	RS232._rx_complete_irq();
}
ISR(USART2_UDRE_vect)
{
	RS232._tx_udr_empty_irq();
}
HardwareSerial RS232(&UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2);
#elif RS232_HWSERIAL == 3
ISR(USART3_RX_vect)
{
	RS232._rx_complete_irq();
}
ISR(USART3_UDRE_vect)
{
	RS232._tx_udr_empty_irq();
}
HardwareSerial RS232(&UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3);
#endif // RS232_HWSERIAL

#endif // HAVE_RS232_HARD

void RS232Event() __attribute__((weak));

void RS232EventRun() {
	if (RS232Event && RS232.available()) {
		RS232Event();
	}
}

#endif // HAVE_RS232
