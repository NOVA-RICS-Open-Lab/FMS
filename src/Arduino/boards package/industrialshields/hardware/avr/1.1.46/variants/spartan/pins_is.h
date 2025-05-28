// Industrial Shields by Boot&Work Corp., S.L.

#ifndef __pins_is_H__
#define __pins_is_H__

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to SPARTAN pins
#if defined(SPARTAN_16DA)
#define PIN_I0_0					(2)
#define PIN_I0_1					(29)
#define PIN_I0_2					(24)
#define PIN_I0_3					(26)
#define PIN_I0_4					(23)
#define PIN_I0_5					(22)
#define PIN_I0_6					(21)
#define PIN_I0_7					(20)

#elif defined(SPARTAN_16RDA)
#define PIN_I0_0					(2)
#define PIN_I0_1					(12)
#define PIN_I0_2					(4)
#define PIN_I0_3					(8)
#define PIN_I0_4					(20)
#define PIN_I0_5					(21)
#define PIN_I0_6					(22)
#define PIN_I0_7					(23)

#elif defined(SPARTAN_19R)
#define PIN_I0_0		(2)
#define PIN_I0_1		(3)
#define PIN_I0_2		(54)
#define PIN_I0_3		(55)
#define PIN_I0_4		(56)
#define PIN_I0_5		(57)

#elif defined(SPARTAN_21)
#define PIN_I0_0		(22)
#define PIN_I0_1		(23)
#define PIN_I0_2		(24)
#define PIN_I0_3		(25)
#define PIN_I0_4		(26)
#define PIN_I0_5		(2)
#define PIN_I0_6		(3)
#define PIN_I0_7		(54)
#define PIN_I0_8		(55)
#define PIN_I0_9		(56)
#define PIN_I0_10		(57)
#define PIN_I0_11		(58)
#define PIN_I0_12		(59)
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to SPARTAN inputs
#if defined(SPARTAN_16DA) || defined(SPARTAN_16RDA)
static const uint8_t I0_0 = PIN_I0_0;
static const uint8_t I0_1 = PIN_I0_1;
static const uint8_t I0_2 = PIN_I0_2;
static const uint8_t I0_3 = PIN_I0_3;
static const uint8_t I0_4 = PIN_I0_4;
static const uint8_t I0_5 = PIN_I0_5;
static const uint8_t I0_6 = PIN_I0_6;
static const uint8_t I0_7 = PIN_I0_7;

#elif defined(SPARTAN_19R)
static const uint8_t I0_0 = PIN_I0_0;
static const uint8_t I0_1 = PIN_I0_1;
static const uint8_t I0_2 = PIN_I0_2;
static const uint8_t I0_3 = PIN_I0_3;
static const uint8_t I0_4 = PIN_I0_4;
static const uint8_t I0_5 = PIN_I0_5;

#elif defined(SPARTAN_21)
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
static const uint8_t I0_10 = PIN_I0_10;
static const uint8_t I0_11 = PIN_I0_11;
static const uint8_t I0_12 = PIN_I0_12;
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to SPARTAN outputs
#if defined(SPARTAN_16DA)
#define PIN_Q0_0					(13)
#define PIN_Q0_1					(11)
#define PIN_Q0_2					(10)
#define PIN_Q0_3					(9)
#define PIN_Q0_4					(6)
#define PIN_Q0_5					(5)
#define PIN_Q0_6					(3)
#define PIN_Q0_7					(7)
static const uint8_t Q0_0 = PIN_Q0_0;
static const uint8_t Q0_1 = PIN_Q0_1;
static const uint8_t Q0_2 = PIN_Q0_2;
static const uint8_t Q0_3 = PIN_Q0_3;
static const uint8_t Q0_4 = PIN_Q0_4;
static const uint8_t Q0_5 = PIN_Q0_5;
static const uint8_t Q0_6 = PIN_Q0_6;
static const uint8_t Q0_7 = PIN_Q0_7;
static const uint8_t A0_0 = PIN_Q0_0;
static const uint8_t A0_1 = PIN_Q0_1;
static const uint8_t A0_2 = PIN_Q0_2;
static const uint8_t A0_3 = PIN_Q0_3;
static const uint8_t A0_4 = PIN_Q0_4;
static const uint8_t A0_5 = PIN_Q0_5;
static const uint8_t A0_6 = PIN_Q0_6;

#elif defined(SPARTAN_16RDA)
#define PIN_R1						(10)
#define PIN_R2						(9)
#define PIN_R3						(6)
#define PIN_R4						(5)
#define PIN_R5						(3)
#define PIN_R6						(7)
static const uint8_t R1 = PIN_R1;
static const uint8_t R2 = PIN_R2;
static const uint8_t R3 = PIN_R3;
static const uint8_t R4 = PIN_R4;
static const uint8_t R5 = PIN_R5;
static const uint8_t R6 = PIN_R6;

#elif defined(SPARTAN_19R)
#define PIN_Q0_0		(4)
#define PIN_Q0_1		(5)
#define PIN_Q0_2		(6)
static const uint8_t Q0_0 = PIN_Q0_0;
static const uint8_t Q0_1 = PIN_Q0_1;
static const uint8_t Q0_2 = PIN_Q0_2;

#elif defined(SPARTAN_21)
#define PIN_Q0_0		(36)
#define PIN_Q0_1		(37)
#define PIN_Q0_2		(38)
#define PIN_Q0_3		(39)
#define PIN_Q0_4		(40)
#define PIN_Q0_5		(4)
#define PIN_Q0_6		(5)
#define PIN_Q0_7		(6)
static const uint8_t Q0_0 = PIN_Q0_0;
static const uint8_t Q0_1 = PIN_Q0_1;
static const uint8_t Q0_2 = PIN_Q0_2;
static const uint8_t Q0_3 = PIN_Q0_3;
static const uint8_t Q0_4 = PIN_Q0_4;
static const uint8_t Q0_5 = PIN_Q0_5;
static const uint8_t Q0_6 = PIN_Q0_6;
static const uint8_t Q0_7 = PIN_Q0_7;
#endif

// // Industrial Shields by Boot&Work Corp., S.L.
// // Mapping: Arduino pins to SPARTAN 19 R analog outputs
#if defined(SPARTAN_19R)
#define PIN_A0_0		(4)
#define PIN_A0_1		(5)
#define PIN_A0_2		(6)
static const uint8_t A0_0 = PIN_A0_0;
static const uint8_t A0_1 = PIN_A0_1;
static const uint8_t A0_2 = PIN_A0_2;
#endif

// // Industrial Shields by Boot&Work Corp., S.L.
// // Mapping: Arduino pins to SPARTAN 21 analog outputs
#if defined(SPARTAN_21)
#define PIN_A0_5		PIN_Q0_5
#define PIN_A0_6		PIN_Q0_6
#define PIN_A0_7		PIN_Q0_7
static const uint8_t A0_5 = PIN_A0_5;
static const uint8_t A0_6 = PIN_A0_6;
static const uint8_t A0_7 = PIN_A0_7;
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to SPARTAN 19 R relay outputs
#if defined(SPARTAN_19R)
#define PIN_R0_1		(23)
#define PIN_R0_2		(22)
#define PIN_R0_3		(25)
#define PIN_R0_4		(24)
#define PIN_R0_5		(40)
#define PIN_R0_6		(39)
#define PIN_R0_7		(38)
#define PIN_R0_8		(37)
static const uint8_t R0_1 = PIN_R0_1;
static const uint8_t R0_2 = PIN_R0_2;
static const uint8_t R0_3 = PIN_R0_3;
static const uint8_t R0_4 = PIN_R0_4;
static const uint8_t R0_5 = PIN_R0_5;
static const uint8_t R0_6 = PIN_R0_6;
static const uint8_t R0_7 = PIN_R0_7;
static const uint8_t R0_8 = PIN_R0_8;
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins & definitions to SPARTAN RS485 && SPARTAN RS232
#if defined(SPARTAN_16DA) || defined(SPARTAN_16RDA)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 1
#define RS485_RE				(18)
#define RS485_DE				(19)

#elif defined(SPARTAN_19R) || defined(SPARTAN_21)
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 3
#define RS485_RE				(11)
#define RS485_DE				(46)

#define HAVE_RS232
#define HAVE_RS232_HARD
#define RS232_HWSERIAL 2

#endif

#endif // __pins_is_H__
