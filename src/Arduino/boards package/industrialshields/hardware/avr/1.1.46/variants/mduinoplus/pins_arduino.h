/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            70
#define NUM_ANALOG_INPUTS           16
#define analogInputToDigitalPin(p)  ((p < 16) ? (p) + 54 : -1)
#define digitalPinHasPWM(p)         (((p) >= 2 && (p) <= 13) || ((p) >= 44 && (p)<= 46))

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to M-DUINO+ inputs

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_21_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_38AR_PLUS)
#define PIN_I0_0		(22)
#define PIN_I0_1		(23)
#define PIN_I0_2		(24)
#define PIN_I0_3		(25)
#define PIN_I0_4		(26)
#define PIN_I0_6		(3)
#define PIN_I0_7		(54)
#define PIN_I0_8		(55)
#define PIN_I0_9		(56)
#define PIN_I0_10		(57)
#define PIN_I0_11		(58)
#define PIN_I0_12		(59)
static const uint8_t I0_0 = PIN_I0_0;
static const uint8_t I0_1 = PIN_I0_1;
static const uint8_t I0_2 = PIN_I0_2;
static const uint8_t I0_3 = PIN_I0_3;
static const uint8_t I0_4 = PIN_I0_4;
static const uint8_t I0_6 = PIN_I0_6;
static const uint8_t I0_7 = PIN_I0_7;
static const uint8_t I0_8 = PIN_I0_8;
static const uint8_t I0_9 = PIN_I0_9;
static const uint8_t I0_10 = PIN_I0_10;
static const uint8_t I0_11 = PIN_I0_11;
static const uint8_t I0_12 = PIN_I0_12;

#if !defined(MDUINO_GPRS_PLUS) &&  !defined(MDUINO_LORA_PLUS)
#define PIN_I0_5		(2)
static const uint8_t I0_5 = PIN_I0_5;
#endif

#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS)
#define PIN_I0_1		(3)
#define PIN_I0_2		(54)
#define PIN_I0_3		(55)
#define PIN_I0_4		(56)
#define PIN_I0_5		(57)
static const uint8_t I0_1 = PIN_I0_1;
static const uint8_t I0_2 = PIN_I0_2;
static const uint8_t I0_3 = PIN_I0_3;
static const uint8_t I0_4 = PIN_I0_4;
static const uint8_t I0_5 = PIN_I0_5;

#if !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_LORA_PLUS) 
#define PIN_I0_0		(2)
static const uint8_t I0_0 = PIN_I0_0;
#endif

#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_57AAR_PLUS)
#define PIN_I1_0		(27)
#define PIN_I1_1		(28)
#define PIN_I1_2		(29)
#define PIN_I1_3		(30)
#define PIN_I1_4		(31)
#define PIN_I1_7		(60)
#define PIN_I1_8		(61)
#define PIN_I1_9		(62)
#define PIN_I1_10		(63)
#define PIN_I1_11		(64)
#define PIN_I1_12		(65)
static const uint8_t I1_0 = PIN_I1_0;
static const uint8_t I1_1 = PIN_I1_1;
static const uint8_t I1_2 = PIN_I1_2;
static const uint8_t I1_3 = PIN_I1_3;
static const uint8_t I1_4 = PIN_I1_4;
static const uint8_t I1_7 = PIN_I1_7;
static const uint8_t I1_8 = PIN_I1_8;
static const uint8_t I1_9 = PIN_I1_9;
static const uint8_t I1_10 = PIN_I1_10;
static const uint8_t I1_11 = PIN_I1_11;
static const uint8_t I1_12 = PIN_I1_12;

#if !defined(MDUINO_DALI_PLUS) && !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_WIFI_PLUS) \
  && !defined(MDUINO_WIFI_GPRS_PLUS)
#define PIN_I1_5		(18)
#define PIN_I1_6		(19)
static const uint8_t I1_5 = PIN_I1_5;
static const uint8_t I1_6 = PIN_I1_6;
#endif

#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
#define PIN_I1_2		(60)
#define PIN_I1_3		(61)
#define PIN_I1_4		(62)
#define PIN_I1_5		(63)
static const uint8_t I1_2 = PIN_I1_2;
static const uint8_t I1_3 = PIN_I1_3;
static const uint8_t I1_4 = PIN_I1_4;
static const uint8_t I1_5 = PIN_I1_5;

#if !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_WIFI_PLUS) && !defined(MDUINO_WIFI_GPRS_PLUS) \
  && !defined(MDUINO_DALI_PLUS)
#define PIN_I1_0		(18)
#define PIN_I1_1		(19)
static const uint8_t I1_0 = PIN_I1_0;
static const uint8_t I1_1 = PIN_I1_1;
#endif

#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_54ARA_PLUS) || defined(MDUINO_50RRA_PLUS)
#define PIN_I2_0		(32)
#define PIN_I2_1		(33)
#define PIN_I2_2		(34)
#define PIN_I2_3		(35)
#define PIN_I2_5		(20)
#define PIN_I2_6		(21)
#define PIN_I2_7		(66)
#define PIN_I2_8		(67)
#define PIN_I2_9		(68)
#define PIN_I2_10		(69)
static const uint8_t I2_0 = PIN_I2_0;
static const uint8_t I2_1 = PIN_I2_1;
static const uint8_t I2_2 = PIN_I2_2;
static const uint8_t I2_3 = PIN_I2_3;
static const uint8_t I2_5 = PIN_I2_5;
static const uint8_t I2_6 = PIN_I2_6;
static const uint8_t I2_7 = PIN_I2_7;
static const uint8_t I2_8 = PIN_I2_8;
static const uint8_t I2_9 = PIN_I2_9;
static const uint8_t I2_10 = PIN_I2_10;
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)
#define PIN_I2_0		(20)
#define PIN_I2_1		(21)
#define PIN_I2_2		(66)
#define PIN_I2_3		(67)
#define PIN_I2_4		(68)
#define PIN_I2_5		(69)
static const uint8_t I2_0 = PIN_I2_0;
static const uint8_t I2_1 = PIN_I2_1;
static const uint8_t I2_2 = PIN_I2_2;
static const uint8_t I2_3 = PIN_I2_3;
static const uint8_t I2_4 = PIN_I2_4;
static const uint8_t I2_5 = PIN_I2_5;
#endif


// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to M-DUINO+ digital outputs

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_21_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_38AR_PLUS)
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
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS)
#define PIN_Q0_0		(4)
#define PIN_Q0_1		(5)
#define PIN_Q0_2		(6)
static const uint8_t Q0_0 = PIN_Q0_0;
static const uint8_t Q0_1 = PIN_Q0_1;
static const uint8_t Q0_2 = PIN_Q0_2;
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_57AAR_PLUS)
#define PIN_Q1_0		(41)
#define PIN_Q1_1		(42)
#define PIN_Q1_2		(43)
#define PIN_Q1_3		(44)
#define PIN_Q1_4		(45)
#define PIN_Q1_5		(8)
#define PIN_Q1_6		(9)
#define PIN_Q1_7		(7)
static const uint8_t Q1_0 = PIN_Q1_0;
static const uint8_t Q1_1 = PIN_Q1_1;
static const uint8_t Q1_2 = PIN_Q1_2;
static const uint8_t Q1_3 = PIN_Q1_3;
static const uint8_t Q1_4 = PIN_Q1_4;
static const uint8_t Q1_5 = PIN_Q1_5;
static const uint8_t Q1_6 = PIN_Q1_6;
static const uint8_t Q1_7 = PIN_Q1_7;

#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
#define PIN_Q1_0		(8)
#define PIN_Q1_1		(9)
#define PIN_Q1_2		(7)
static const uint8_t Q1_0 = PIN_Q1_0;
static const uint8_t Q1_1 = PIN_Q1_1;
static const uint8_t Q1_2 = PIN_Q1_2;
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_54ARA_PLUS) || defined(MDUINO_50RRA_PLUS)
#define PIN_Q2_0		(53)
#define PIN_Q2_1		(47)
#define PIN_Q2_2		(48)
#define PIN_Q2_3		(49)
static const uint8_t Q2_0 = PIN_Q2_0;
static const uint8_t Q2_1 = PIN_Q2_1;
static const uint8_t Q2_2 = PIN_Q2_2;
static const uint8_t Q2_3 = PIN_Q2_3;

#if !defined(MDUINO_LORA_PLUS) 
#define PIN_Q2_5		(12)
static const uint8_t Q2_5 = PIN_Q2_5;
#endif

#if !defined(MDUINO_LORA_PLUS) && !defined(MDUINO_WIFI_GPRS_PLUS)
#define PIN_Q2_6		(13)
static const uint8_t Q2_6 = PIN_Q2_6;
#endif

#elif (defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)) && !defined(MDUINO_LORA_PLUS)
#define PIN_Q2_0		(12)
static const uint8_t Q2_0 = PIN_Q2_0;

#if !defined(MDUINO_WIFI_GPRS_PLUS)
#define PIN_Q2_1		(13)
static const uint8_t Q2_1 = PIN_Q2_1;
#endif

#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to M-DUINO+ analog outputs

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_21_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_38AR_PLUS)
#define PIN_A0_5		PIN_Q0_5
#define PIN_A0_6		PIN_Q0_6
#define PIN_A0_7		PIN_Q0_7
static const uint8_t A0_5 = PIN_A0_5;
static const uint8_t A0_6 = PIN_A0_6;
static const uint8_t A0_7 = PIN_A0_7;
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS)
#define PIN_A0_0		(4)
#define PIN_A0_1		(5)
#define PIN_A0_2		(6)
static const uint8_t A0_0 = PIN_A0_0;
static const uint8_t A0_1 = PIN_A0_1;
static const uint8_t A0_2 = PIN_A0_2;
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_57AAR_PLUS)
#define PIN_A1_5		PIN_Q1_5
#define PIN_A1_6		PIN_Q1_6
#define PIN_A1_7		PIN_Q1_7
static const uint8_t A1_5 = PIN_A1_5;
static const uint8_t A1_6 = PIN_A1_6;
static const uint8_t A1_7 = PIN_A1_7;

#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
#define PIN_A1_0		(8)
#define PIN_A1_1		(9)
#define PIN_A1_2		(7)
static const uint8_t A1_0 = PIN_A1_0;
static const uint8_t A1_1 = PIN_A1_1;
static const uint8_t A1_2 = PIN_A1_2;
#endif

#if (defined(MDUINO_58_PLUS) || defined(MDUINO_54ARA_PLUS) || defined(MDUINO_50RRA_PLUS)) && !defined(MDUINO_LORA_PLUS)
#define PIN_A2_5		PIN_Q2_5
static const uint8_t A2_5 = PIN_A2_5;

#if !defined (MDUINO_WIFI_GPRS_PLUS)
#define PIN_A2_6		PIN_Q2_6
static const uint8_t A2_6 = PIN_A2_6;
#endif

#elif (defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)) && !defined(MDUINO_LORA_PLUS)
#define PIN_A2_0		(12)
static const uint8_t A2_0 = PIN_A2_0;

#if !defined(MDUINO_WIFI_GPRS_PLUS)
#define PIN_A2_1		(13)
static const uint8_t A2_1 = PIN_A2_1;
#endif

#endif

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS)
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

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
#define PIN_R1_1		(28)
#define PIN_R1_2		(27)
#define PIN_R1_3		(30)
#define PIN_R1_4		(29)
#define PIN_R1_5		(45)
#define PIN_R1_6		(44)
#define PIN_R1_7		(43)
#define PIN_R1_8		(42)
static const uint8_t R1_1 = PIN_R1_1;
static const uint8_t R1_2 = PIN_R1_2;
static const uint8_t R1_3 = PIN_R1_3;
static const uint8_t R1_4 = PIN_R1_4;
static const uint8_t R1_5 = PIN_R1_5;
static const uint8_t R1_6 = PIN_R1_6;
static const uint8_t R1_7 = PIN_R1_7;
static const uint8_t R1_8 = PIN_R1_8;
#endif

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)
#define PIN_R2_1		(33)
#define PIN_R2_2		(32)
#define PIN_R2_3		(35)
#define PIN_R2_4		(34)
#define PIN_R2_6		(49)
#define PIN_R2_7		(48)
#define PIN_R2_8		(47)
static const uint8_t R2_1 = PIN_R2_1;
static const uint8_t R2_2 = PIN_R2_2;
static const uint8_t R2_3 = PIN_R2_3;
static const uint8_t R2_4 = PIN_R2_4;
static const uint8_t R2_6 = PIN_R2_6;
static const uint8_t R2_7 = PIN_R2_7;
static const uint8_t R2_8 = PIN_R2_8;
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to M-DUINO+ RS-485
#define HAVE_RS485
#define HAVE_RS485_HARD
#define RS485_HWSERIAL 3
#define RS485_DE				(46)
#define RS485_RE				(11)

// Industrial Shields by Boot&Work Corp., S.L.
// Mapping: Arduino pins to M-DUINO RS-232
#define HAVE_RS232
#define HAVE_RS232_HARD
#define RS232_HWSERIAL 2

// GPRS module
#if defined(MDUINO_GPRS_PLUS) 
#define HAVE_SIM800L
#define HAVE_SIM800L_HARD
#define SIM800L_HWSERIAL (1)
#define SIM800L_RATE 57600UL
#define SIM800L_RESET_PIN (2)
#elif defined(MDUINO_WIFI_GPRS_PLUS)
#define HAVE_SIM800L
#define HAVE_SIM800L_HARD
#define SIM800L_HWSERIAL (2)
#define SIM800L_RATE 57600UL
#define SIM800L_RESET_PIN (13)
#endif

// WiFi module
#if defined(MDUINO_WIFI_PLUS) || defined(MDUINO_WIFI_GPRS_PLUS)
#define HAVE_ESP32
#define HAVE_ESP32_HARD
#define ESP32_HWSERIAL 1
#endif

// LoRa module
#if defined(MDUINO_LORA_PLUS)
#define HAVE_RFM9X
#define RFM9X_RESET_PIN (13)
#define RFM9X_SS_PIN (12)
#define RFM9X_INT_PIN (2)
#endif

// DALI module
#if defined(MDUINO_DALI_PLUS)
#define DALI_TX (18)
#define DALI_RX (19)
#endif

// Industrial Shields by Boot&Work Corp., S.L.
// It has got RTC DS1307
#define HAVE_RTC
#define HAVE_RTC_DS1307

#define HAVE_SD

#define HAVE_ETHERNET

#define PIN_SPI_SS    (53)
#define PIN_SPI_MOSI  (51)
#define PIN_SPI_MISO  (50)
#define PIN_SPI_SCK   (52)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (20)
#define PIN_WIRE_SCL        (21)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 13

#define PIN_A0   (54)
#define PIN_A1   (55)
#define PIN_A2   (56)
#define PIN_A3   (57)
#define PIN_A4   (58)
#define PIN_A5   (59)
#define PIN_A6   (60)
#define PIN_A7   (61)
#define PIN_A8   (62)
#define PIN_A9   (63)
#define PIN_A10  (64)
#define PIN_A11  (65)
#define PIN_A12  (66)
#define PIN_A13  (67)
#define PIN_A14  (68)
#define PIN_A15  (69)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
static const uint8_t A8 = PIN_A8;
static const uint8_t A9 = PIN_A9;
static const uint8_t A10 = PIN_A10;
static const uint8_t A11 = PIN_A11;
static const uint8_t A12 = PIN_A12;
static const uint8_t A13 = PIN_A13;
static const uint8_t A14 = PIN_A14;
static const uint8_t A15 = PIN_A15;

// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// (I've deliberately left out pin mapping to the Hardware USARTs - seems senseless to me)
// Pins: 10, 11, 12, 13,  50, 51, 52, 53,  62, 63, 64, 65, 66, 67, 68, 69

#define digitalPinToPCICR(p)    ( (((p) >= 10) && ((p) <= 13)) || \
                                  (((p) >= 50) && ((p) <= 53)) || \
                                  (((p) >= 62) && ((p) <= 69)) ? (&PCICR) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) ( (((p) >= 10) && ((p) <= 13)) || (((p) >= 50) && ((p) <= 53)) ? 0 : \
                                ( (((p) >= 62) && ((p) <= 69)) ? 2 : \
                                0 ) )

#define digitalPinToPCMSK(p)    ( (((p) >= 10) && ((p) <= 13)) || (((p) >= 50) && ((p) <= 53)) ? (&PCMSK0) : \
                                ( (((p) >= 62) && ((p) <= 69)) ? (&PCMSK2) : \
                                ((uint8_t *)0) ) )

#define digitalPinToPCMSKbit(p) ( (((p) >= 10) && ((p) <= 13)) ? ((p) - 6) : \
                                ( ((p) == 50) ? 3 : \
                                ( ((p) == 51) ? 2 : \
                                ( ((p) == 52) ? 1 : \
                                ( ((p) == 53) ? 0 : \
                                ( (((p) >= 62) && ((p) <= 69)) ? ((p) - 62) : \
                                0 ) ) ) ) ) )

#define digitalPinToInterrupt(p) ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) >= 18 && (p) <= 21 ? 23 - (p) : NOT_AN_INTERRUPT)))

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
	(uint16_t) &DDRH,
	NOT_A_PORT,
	(uint16_t) &DDRJ,
	(uint16_t) &DDRK,
	(uint16_t) &DDRL,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
	(uint16_t) &PORTH,
	NOT_A_PORT,
	(uint16_t) &PORTJ,
	(uint16_t) &PORTK,
	(uint16_t) &PORTL,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
	(uint16_t) &PINH,
	NOT_A_PIN,
	(uint16_t) &PINJ,
	(uint16_t) &PINK,
	(uint16_t) &PINL,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		
	PE	, // PE 0 ** 0 ** USART0_RX	
	PE	, // PE 1 ** 1 ** USART0_TX	
	PE	, // PE 4 ** 2 ** PWM2	
	PE	, // PE 5 ** 3 ** PWM3	
	PG	, // PG 5 ** 4 ** PWM4	
	PE	, // PE 3 ** 5 ** PWM5	
	PH	, // PH 3 ** 6 ** PWM6	
	PH	, // PH 4 ** 7 ** PWM7	
	PH	, // PH 5 ** 8 ** PWM8	
	PH	, // PH 6 ** 9 ** PWM9	
	PB	, // PB 4 ** 10 ** PWM10	
	PB	, // PB 5 ** 11 ** PWM11	
	PB	, // PB 6 ** 12 ** PWM12	
	PB	, // PB 7 ** 13 ** PWM13	
	PJ	, // PJ 1 ** 14 ** USART3_TX	
	PJ	, // PJ 0 ** 15 ** USART3_RX	
	PH	, // PH 1 ** 16 ** USART2_TX	
	PH	, // PH 0 ** 17 ** USART2_RX	
	PD	, // PD 3 ** 18 ** USART1_TX	
	PD	, // PD 2 ** 19 ** USART1_RX	
	PD	, // PD 1 ** 20 ** I2C_SDA	
	PD	, // PD 0 ** 21 ** I2C_SCL	
	PA	, // PA 0 ** 22 ** D22	
	PA	, // PA 1 ** 23 ** D23	
	PA	, // PA 2 ** 24 ** D24	
	PA	, // PA 3 ** 25 ** D25	
	PA	, // PA 4 ** 26 ** D26	
	PA	, // PA 5 ** 27 ** D27	
	PA	, // PA 6 ** 28 ** D28	
	PA	, // PA 7 ** 29 ** D29	
	PC	, // PC 7 ** 30 ** D30	
	PC	, // PC 6 ** 31 ** D31	
	PC	, // PC 5 ** 32 ** D32	
	PC	, // PC 4 ** 33 ** D33	
	PC	, // PC 3 ** 34 ** D34	
	PC	, // PC 2 ** 35 ** D35	
	PC	, // PC 1 ** 36 ** D36	
	PC	, // PC 0 ** 37 ** D37	
	PD	, // PD 7 ** 38 ** D38	
	PG	, // PG 2 ** 39 ** D39	
	PG	, // PG 1 ** 40 ** D40	
	PG	, // PG 0 ** 41 ** D41	
	PL	, // PL 7 ** 42 ** D42	
	PL	, // PL 6 ** 43 ** D43	
	PL	, // PL 5 ** 44 ** D44	
	PL	, // PL 4 ** 45 ** D45	
	PL	, // PL 3 ** 46 ** D46	
	PL	, // PL 2 ** 47 ** D47	
	PL	, // PL 1 ** 48 ** D48	
	PL	, // PL 0 ** 49 ** D49	
	PB	, // PB 3 ** 50 ** SPI_MISO	
	PB	, // PB 2 ** 51 ** SPI_MOSI	
	PB	, // PB 1 ** 52 ** SPI_SCK	
	PB	, // PB 0 ** 53 ** SPI_SS	
	PF	, // PF 0 ** 54 ** A0	
	PF	, // PF 1 ** 55 ** A1	
	PF	, // PF 2 ** 56 ** A2	
	PF	, // PF 3 ** 57 ** A3	
	PF	, // PF 4 ** 58 ** A4	
	PF	, // PF 5 ** 59 ** A5	
	PF	, // PF 6 ** 60 ** A6	
	PF	, // PF 7 ** 61 ** A7	
	PK	, // PK 0 ** 62 ** A8	
	PK	, // PK 1 ** 63 ** A9	
	PK	, // PK 2 ** 64 ** A10	
	PK	, // PK 3 ** 65 ** A11	
	PK	, // PK 4 ** 66 ** A12	
	PK	, // PK 5 ** 67 ** A13	
	PK	, // PK 6 ** 68 ** A14	
	PK	, // PK 7 ** 69 ** A15	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX	
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX	
	_BV( 4 )	, // PE 4 ** 2 ** PWM2	
	_BV( 5 )	, // PE 5 ** 3 ** PWM3	
	_BV( 5 )	, // PG 5 ** 4 ** PWM4	
	_BV( 3 )	, // PE 3 ** 5 ** PWM5	
	_BV( 3 )	, // PH 3 ** 6 ** PWM6	
	_BV( 4 )	, // PH 4 ** 7 ** PWM7	
	_BV( 5 )	, // PH 5 ** 8 ** PWM8	
	_BV( 6 )	, // PH 6 ** 9 ** PWM9	
	_BV( 4 )	, // PB 4 ** 10 ** PWM10	
	_BV( 5 )	, // PB 5 ** 11 ** PWM11	
	_BV( 6 )	, // PB 6 ** 12 ** PWM12	
	_BV( 7 )	, // PB 7 ** 13 ** PWM13	
	_BV( 1 )	, // PJ 1 ** 14 ** USART3_TX	
	_BV( 0 )	, // PJ 0 ** 15 ** USART3_RX	
	_BV( 1 )	, // PH 1 ** 16 ** USART2_TX	
	_BV( 0 )	, // PH 0 ** 17 ** USART2_RX	
	_BV( 3 )	, // PD 3 ** 18 ** USART1_TX	
	_BV( 2 )	, // PD 2 ** 19 ** USART1_RX	
	_BV( 1 )	, // PD 1 ** 20 ** I2C_SDA	
	_BV( 0 )	, // PD 0 ** 21 ** I2C_SCL	
	_BV( 0 )	, // PA 0 ** 22 ** D22	
	_BV( 1 )	, // PA 1 ** 23 ** D23	
	_BV( 2 )	, // PA 2 ** 24 ** D24	
	_BV( 3 )	, // PA 3 ** 25 ** D25	
	_BV( 4 )	, // PA 4 ** 26 ** D26	
	_BV( 5 )	, // PA 5 ** 27 ** D27	
	_BV( 6 )	, // PA 6 ** 28 ** D28	
	_BV( 7 )	, // PA 7 ** 29 ** D29	
	_BV( 7 )	, // PC 7 ** 30 ** D30	
	_BV( 6 )	, // PC 6 ** 31 ** D31	
	_BV( 5 )	, // PC 5 ** 32 ** D32	
	_BV( 4 )	, // PC 4 ** 33 ** D33	
	_BV( 3 )	, // PC 3 ** 34 ** D34	
	_BV( 2 )	, // PC 2 ** 35 ** D35	
	_BV( 1 )	, // PC 1 ** 36 ** D36	
	_BV( 0 )	, // PC 0 ** 37 ** D37	
	_BV( 7 )	, // PD 7 ** 38 ** D38	
	_BV( 2 )	, // PG 2 ** 39 ** D39	
	_BV( 1 )	, // PG 1 ** 40 ** D40	
	_BV( 0 )	, // PG 0 ** 41 ** D41	
	_BV( 7 )	, // PL 7 ** 42 ** D42	
	_BV( 6 )	, // PL 6 ** 43 ** D43	
	_BV( 5 )	, // PL 5 ** 44 ** D44	
	_BV( 4 )	, // PL 4 ** 45 ** D45	
	_BV( 3 )	, // PL 3 ** 46 ** D46	
	_BV( 2 )	, // PL 2 ** 47 ** D47	
	_BV( 1 )	, // PL 1 ** 48 ** D48	
	_BV( 0 )	, // PL 0 ** 49 ** D49	
	_BV( 3 )	, // PB 3 ** 50 ** SPI_MISO	
	_BV( 2 )	, // PB 2 ** 51 ** SPI_MOSI	
	_BV( 1 )	, // PB 1 ** 52 ** SPI_SCK	
	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS	
	_BV( 0 )	, // PF 0 ** 54 ** A0	
	_BV( 1 )	, // PF 1 ** 55 ** A1	
	_BV( 2 )	, // PF 2 ** 56 ** A2	
	_BV( 3 )	, // PF 3 ** 57 ** A3	
	_BV( 4 )	, // PF 4 ** 58 ** A4	
	_BV( 5 )	, // PF 5 ** 59 ** A5	
	_BV( 6 )	, // PF 6 ** 60 ** A6	
	_BV( 7 )	, // PF 7 ** 61 ** A7	
	_BV( 0 )	, // PK 0 ** 62 ** A8	
	_BV( 1 )	, // PK 1 ** 63 ** A9	
	_BV( 2 )	, // PK 2 ** 64 ** A10	
	_BV( 3 )	, // PK 3 ** 65 ** A11	
	_BV( 4 )	, // PK 4 ** 66 ** A12	
	_BV( 5 )	, // PK 5 ** 67 ** A13	
	_BV( 6 )	, // PK 6 ** 68 ** A14	
	_BV( 7 )	, // PK 7 ** 69 ** A15	
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX	
	TIMER3B	, // PE 4 ** 2 ** PWM2	
	TIMER3C	, // PE 5 ** 3 ** PWM3	
	TIMER0B	, // PG 5 ** 4 ** PWM4	
	TIMER3A	, // PE 3 ** 5 ** PWM5	
	TIMER4A	, // PH 3 ** 6 ** PWM6	
	TIMER4B	, // PH 4 ** 7 ** PWM7	
	TIMER4C	, // PH 5 ** 8 ** PWM8	
	TIMER2B	, // PH 6 ** 9 ** PWM9	
	TIMER2A	, // PB 4 ** 10 ** PWM10	
	TIMER1A	, // PB 5 ** 11 ** PWM11	
	TIMER1B	, // PB 6 ** 12 ** PWM12	
	TIMER0A	, // PB 7 ** 13 ** PWM13	
	NOT_ON_TIMER	, // PJ 1 ** 14 ** USART3_TX	
	NOT_ON_TIMER	, // PJ 0 ** 15 ** USART3_RX	
	NOT_ON_TIMER	, // PH 1 ** 16 ** USART2_TX	
	NOT_ON_TIMER	, // PH 0 ** 17 ** USART2_RX	
	NOT_ON_TIMER	, // PD 3 ** 18 ** USART1_TX	
	NOT_ON_TIMER	, // PD 2 ** 19 ** USART1_RX	
	NOT_ON_TIMER	, // PD 1 ** 20 ** I2C_SDA	
	NOT_ON_TIMER	, // PD 0 ** 21 ** I2C_SCL	
	NOT_ON_TIMER	, // PA 0 ** 22 ** D22	
	NOT_ON_TIMER	, // PA 1 ** 23 ** D23	
	NOT_ON_TIMER	, // PA 2 ** 24 ** D24	
	NOT_ON_TIMER	, // PA 3 ** 25 ** D25	
	NOT_ON_TIMER	, // PA 4 ** 26 ** D26	
	NOT_ON_TIMER	, // PA 5 ** 27 ** D27	
	NOT_ON_TIMER	, // PA 6 ** 28 ** D28	
	NOT_ON_TIMER	, // PA 7 ** 29 ** D29	
	NOT_ON_TIMER	, // PC 7 ** 30 ** D30	
	NOT_ON_TIMER	, // PC 6 ** 31 ** D31	
	NOT_ON_TIMER	, // PC 5 ** 32 ** D32	
	NOT_ON_TIMER	, // PC 4 ** 33 ** D33	
	NOT_ON_TIMER	, // PC 3 ** 34 ** D34	
	NOT_ON_TIMER	, // PC 2 ** 35 ** D35	
	NOT_ON_TIMER	, // PC 1 ** 36 ** D36	
	NOT_ON_TIMER	, // PC 0 ** 37 ** D37	
	NOT_ON_TIMER	, // PD 7 ** 38 ** D38	
	NOT_ON_TIMER	, // PG 2 ** 39 ** D39	
	NOT_ON_TIMER	, // PG 1 ** 40 ** D40	
	NOT_ON_TIMER	, // PG 0 ** 41 ** D41	
	NOT_ON_TIMER	, // PL 7 ** 42 ** D42	
	NOT_ON_TIMER	, // PL 6 ** 43 ** D43	
	TIMER5C	, // PL 5 ** 44 ** D44	
	TIMER5B	, // PL 4 ** 45 ** D45	
	TIMER5A	, // PL 3 ** 46 ** D46	
	NOT_ON_TIMER	, // PL 2 ** 47 ** D47	
	NOT_ON_TIMER	, // PL 1 ** 48 ** D48	
	NOT_ON_TIMER	, // PL 0 ** 49 ** D49	
	NOT_ON_TIMER	, // PB 3 ** 50 ** SPI_MISO	
	NOT_ON_TIMER	, // PB 2 ** 51 ** SPI_MOSI	
	NOT_ON_TIMER	, // PB 1 ** 52 ** SPI_SCK	
	NOT_ON_TIMER	, // PB 0 ** 53 ** SPI_SS	
	NOT_ON_TIMER	, // PF 0 ** 54 ** A0	
	NOT_ON_TIMER	, // PF 1 ** 55 ** A1	
	NOT_ON_TIMER	, // PF 2 ** 56 ** A2	
	NOT_ON_TIMER	, // PF 3 ** 57 ** A3	
	NOT_ON_TIMER	, // PF 4 ** 58 ** A4	
	NOT_ON_TIMER	, // PF 5 ** 59 ** A5	
	NOT_ON_TIMER	, // PF 6 ** 60 ** A6	
	NOT_ON_TIMER	, // PF 7 ** 61 ** A7	
	NOT_ON_TIMER	, // PK 0 ** 62 ** A8	
	NOT_ON_TIMER	, // PK 1 ** 63 ** A9	
	NOT_ON_TIMER	, // PK 2 ** 64 ** A10	
	NOT_ON_TIMER	, // PK 3 ** 65 ** A11	
	NOT_ON_TIMER	, // PK 4 ** 66 ** A12	
	NOT_ON_TIMER	, // PK 5 ** 67 ** A13	
	NOT_ON_TIMER	, // PK 6 ** 68 ** A14	
	NOT_ON_TIMER	, // PK 7 ** 69 ** A15	
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE3       Serial3
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial2
#define SERIAL_PORT_HARDWARE_OPEN2  Serial3

#endif
