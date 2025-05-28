#include "WifiModule.h"

#if defined(HAVE_ESP32)

#if defined(HAVE_ESP32_SOFT)
WifiModuleClass::WifiModuleClass(uint8_t rxPin, uint8_t txPin) : SoftwareSerial(rxPin, txPin) {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void WifiModuleClass::begin(unsigned long baud) {
	pinMode(ESP32_TX_PIN, OUTPUT);
	pinMode(ESP32_RX_PIN, INPUT);

	SoftwareSerial::begin(baud);
}
WifiModuleClass WifiModule(ESP32_RX_PIN, ESP32_TX_PIN);
#endif // HAVE_ESP32_SOFT

#if defined(HAVE_ESP32_HARD)

#include <HardwareSerial_private.h>

#if ESP32_HWSERIAL == 1
ISR(USART1_RX_vect)
{
	WifiModule._rx_complete_irq();
}
ISR(USART1_UDRE_vect)
{
	WifiModule._tx_udr_empty_irq();
}
HardwareSerial WifiModule(&UBRR1H, &UBRR1L, &UCSR1A, &UCSR1B, &UCSR1C, &UDR1);
#elif ESP32_HWSERIAL == 2
ISR(USART2_RX_vect)
{
	WifiModule._rx_complete_irq();
}
ISR(USART2_UDRE_vect)
{
	WifiModule._tx_udr_empty_irq();
}
HardwareSerial WifiModule(&UBRR2H, &UBRR2L, &UCSR2A, &UCSR2B, &UCSR2C, &UDR2);
#elif ESP32_HWSERIAL == 3
ISR(USART3_RX_vect)
{
	WifiModule._rx_complete_irq();
}
ISR(USART3_UDRE_vect)
{
	WifiModule._tx_udr_empty_irq();
}
HardwareSerial WifiModule(&UBRR3H, &UBRR3L, &UCSR3A, &UCSR3B, &UCSR3C, &UDR3);
#endif // ESP32_HWSERIAL

#endif // HAVE_ESP32_HARD
#endif // HAVE_ESP32
