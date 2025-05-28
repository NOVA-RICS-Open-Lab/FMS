#ifndef __pins_is_H__
#define __pins_is_H__

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to ARDBOX Relay HF inputs
#if defined(ARDBOX_RELAY_HF_LEGACY)
#define PIN_I0_0					(2)
#define PIN_I0_1					(3)
#define PIN_I0_2					(0)
#define PIN_I0_3					(1)
#define PIN_I0_4					(18)
#define PIN_I0_5					(19)
#define PIN_I0_6					(20)
#define PIN_I0_7					(21)
#define PIN_I0_8					(22)
#define PIN_I0_9					(23)

#elif defined(ARDBOX_RELAY_HF_RS485) || defined(ARDBOX_RELAY_HF_RS232) || defined(ARDBOX_RELAY_HF_PLUS_RS485) || defined(ARDBOX_RELAY_HF_PLUS_RS232)
#define PIN_I0_0					(2)
#define PIN_I0_1					(12)
#define PIN_I0_2					(4)
#define PIN_I0_3					(8)
#define PIN_I0_4					(18)
#define PIN_I0_5					(19)
#define PIN_I0_6					(20)
#define PIN_I0_7					(21)
#define PIN_I0_8					(22)
#define PIN_I0_9					(23)
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

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to ARDBOX Relay HF digital outputs
#if defined(ARDBOX_RELAY_HF_RS485) || defined(ARDBOX_RELAY_HF_RS232) || defined(ARDBOX_RELAY_HF_PLUS_RS485) || defined(ARDBOX_RELAY_HF_PLUS_RS232)
#define PIN_A0_0					(13)
#define PIN_A0_1					(11)

static const uint8_t A0_0 = PIN_A0_0;
static const uint8_t A0_1 = PIN_A0_1;
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to ARDBOX Relay HF relay outputs
#if defined(ARDBOX_RELAY_HF_LEGACY)
#define PIN_R1						(4)
#define PIN_R2						(7)
#define PIN_R3						(8)
#define PIN_R4						(9)
#define PIN_R5						(10)
#define PIN_R6						(11)
#define PIN_R7						(12)
#define PIN_R8						(13)

#elif defined(ARDBOX_RELAY_HF_RS485) || defined(ARDBOX_RELAY_HF_RS232) || defined(ARDBOX_RELAY_HF_PLUS_RS485) || defined(ARDBOX_RELAY_HF_PLUS_RS232)
#define PIN_R1						(10)
#define PIN_R2						(9)
#define PIN_R3						(6)
#define PIN_R4						(5)
#define PIN_R5						(3)
#define PIN_R6						(7)
#define PIN_R7						(0)
#define PIN_R8						(1)
#endif

static const uint8_t R1 = PIN_R1;
static const uint8_t R2 = PIN_R2;
static const uint8_t R3 = PIN_R3;
static const uint8_t R4 = PIN_R4;
static const uint8_t R5 = PIN_R5;
static const uint8_t R6 = PIN_R6;
static const uint8_t R7 = PIN_R7;
static const uint8_t R8 = PIN_R8;

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to ARDBOX Relay HF RS-485
#if defined(ARDBOX_RELAY_HF_RS232) || defined(ARDBOX_RELAY_HF_PLUS_RS232)
#define HAVE_RS232
#define HAVE_RS232_HARD
#define RS232_HWSERIAL 1

#elif defined(ARDBOX_RELAY_HF_RS485) || defined(ARDBOX_RELAY_HF_PLUS_RS485)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 1
#define RS485_RE				(18)
#define RS485_DE				(19)

#define HAVE_RS232
#define HAVE_RS232_SOFT
#define RS232_RX				(8)
#define RS232_TX				(4)

#elif defined(ARDBOX_RELAY_HF_LEGACY)
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
