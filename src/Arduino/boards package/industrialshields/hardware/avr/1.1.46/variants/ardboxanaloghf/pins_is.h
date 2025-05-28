// Industrial Shields by Boot&Work Corp., S.L.

#ifndef __pins_is_H__
#define __pins_is_H__

#if defined(ARDBOX_ANALOG_HF_LEGACY)
#define PIN_I0_0					(2)
#define PIN_I0_1					(12)
#define PIN_I0_2					(8)
#define PIN_I0_3					(4)
#define PIN_I0_4					(23)
#define PIN_I0_5					(22)
#define PIN_I0_6					(21)
#define PIN_I0_7					(20)
#define PIN_I0_8					(19)
#define PIN_I0_9					(18)

#elif defined(ARDBOX_ANALOG_HF_RS485) || defined(ARDBOX_ANALOG_HF_RS232)
#define PIN_I0_0					(2)
#define PIN_I0_1					(7)
#define PIN_I0_2					(1)
#define PIN_I0_3					(0)
#define PIN_I0_4					(23)
#define PIN_I0_5					(22)
#define PIN_I0_6					(21)
#define PIN_I0_7					(20)
#define PIN_I0_8					(19)
#define PIN_I0_9					(18)

#elif defined(ARDBOX_ANALOG_HF_PLUS_RS485) || defined(ARDBOX_ANALOG_HF_PLUS_RS232)
#define PIN_I0_0					(2)
#define PIN_I0_1					(29) // D12
#define PIN_I0_2					(24) // D4
#define PIN_I0_3					(26) // D8
#define PIN_I0_4					(23)
#define PIN_I0_5					(22)
#define PIN_I0_6					(21)
#define PIN_I0_7					(20)
#define PIN_I0_8					(19)
#define PIN_I0_9					(18)
#endif

static const uint8_t I0_0 = PIN_I0_0;
static const uint8_t I0_1 = PIN_I0_1;
static const uint8_t I0_2 = PIN_I0_2;
static const uint8_t I0_3 = PIN_I0_3;
static const uint8_t I0_4 = PIN_I0_4;
static const uint8_t I0_5 = PIN_I0_5;
static const uint8_t I0_6 = PIN_I0_6;
static const uint8_t I0_7 = PIN_I0_7;
static const uint8_t I0_8 = PIN_I0_8;
static const uint8_t I0_9 = PIN_I0_9;

#if defined(ARDBOX_ANALOG_HF_LEGACY)
#define PIN_Q0_0					(13)
#define PIN_Q0_1					(11)
#define PIN_Q0_2					(10)
#define PIN_Q0_3					(9)
#define PIN_Q0_4					(6)
#define PIN_Q0_5					(5)
#define PIN_Q0_6					(3)
#define PIN_Q0_7					(7)
#define PIN_Q0_8					(1)
#define PIN_Q0_9					(0)

#elif defined(ARDBOX_ANALOG_HF_RS485) || defined(ARDBOX_ANALOG_HF_RS232)
#define PIN_Q0_0					(13)
#define PIN_Q0_1					(11)
#define PIN_Q0_2					(10)
#define PIN_Q0_3					(9)
#define PIN_Q0_4					(6)
#define PIN_Q0_5					(5)
#define PIN_Q0_6					(3)
#define PIN_Q0_7					(12)
#define PIN_Q0_8					(8)
#define PIN_Q0_9					(4)

#elif defined(ARDBOX_ANALOG_HF_PLUS_RS485) || defined(ARDBOX_ANALOG_HF_PLUS_RS232)
#define PIN_Q0_0					(13)
#define PIN_Q0_1					(11)
#define PIN_Q0_2					(10)
#define PIN_Q0_3					(9)
#define PIN_Q0_4					(6)
#define PIN_Q0_5					(5)
#define PIN_Q0_6					(3)
#define PIN_Q0_7					(7)
#define PIN_Q0_8					(0)
#define PIN_Q0_9					(1)

#endif

static const uint8_t Q0_0 = PIN_Q0_0;
static const uint8_t Q0_1 = PIN_Q0_1;
static const uint8_t Q0_2 = PIN_Q0_2;
static const uint8_t Q0_3 = PIN_Q0_3;
static const uint8_t Q0_4 = PIN_Q0_4;
static const uint8_t Q0_5 = PIN_Q0_5;
static const uint8_t Q0_6 = PIN_Q0_6;
static const uint8_t Q0_7 = PIN_Q0_7;
static const uint8_t Q0_8 = PIN_Q0_8;
static const uint8_t Q0_9 = PIN_Q0_9;

static const uint8_t A0_0 = PIN_Q0_0;
static const uint8_t A0_1 = PIN_Q0_1;
static const uint8_t A0_2 = PIN_Q0_2;
static const uint8_t A0_3 = PIN_Q0_3;
static const uint8_t A0_4 = PIN_Q0_4;
static const uint8_t A0_5 = PIN_Q0_5;
static const uint8_t A0_6 = PIN_Q0_6;

#if defined(ARDBOX_ANALOG_HF_RS232) || defined(ARDBOX_ANALOG_HF_PLUS_RS232)
#define HAVE_RS232
#define HAVE_RS232_HARD
#define RS232_HWSERIAL 1

#elif defined(ARDBOX_ANALOG_HF_RS485)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 1
#define RS485_RE				(11)
#define RS485_DE				(10)

#define HAVE_RS232
#define HAVE_RS232_SOFT
#define RS232_RX				(8)
#define RS232_TX				(4)

#elif defined(ARDBOX_ANALOG_HF_PLUS_RS485)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 1
#define RS485_RE				(18)
#define RS485_DE				(19)

#define HAVE_RS232
#define HAVE_RS232_SOFT
#define RS232_RX				(8)
#define RS232_TX				(4)

#elif defined(ARDBOX_ANALOG_HF_LEGACY)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 1
#define RS485_RE				(11)
#define RS485_DE				(10)
#endif

// DALI module
#if defined(ARDBOX_DALI_HF_PLUS)
#define DALI_RX (14)
#define DALI_TX (16)
#endif

// GPRS module
#if defined(ARDBOX_GPRS_HF_PLUS)
#define HAVE_SIM800L
#define HAVE_SIM800L_SOFT
#define SIM800L_RATE 19200UL
#define SIM800L_RX_PIN (14)
#define SIM800L_TX_PIN (16)
#define SIM800L_RESET_PIN (2)
#endif

// LoRa module
#if defined(ARDBOX_LORA_HF_PLUS)
#define HAVE_RFM9X
#define RFM9X_RESET_PIN (3)
#define RFM9X_SS_PIN (23)
#define RFM9X_INT_PIN (2)
#endif

// WiFi module
#if defined(ARDBOX_WIFI_HF_PLUS)
#define HAVE_ESP32
#define HAVE_ESP32_SOFT
#define ESP32_RX_PIN (14)
#define ESP32_TX_PIN (16)
#endif


#define HAVE_I2C
#define HAVE_SPI


#endif // __pins_is_H__
