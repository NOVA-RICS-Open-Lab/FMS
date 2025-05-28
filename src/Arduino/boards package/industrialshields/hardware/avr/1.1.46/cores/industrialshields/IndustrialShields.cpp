#include "IndustrialShields.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
void IS_initDefaultIOPins() {
#if defined(ARDBOX_ANALOG) || defined(ARDBOX_ANALOG_HF) || defined(ARDBOX_ANALOG_HF_PLUS) || defined(ARDBOX_BASIC)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);
	pinMode(PIN_I0_8, INPUT);
	pinMode(PIN_I0_9, INPUT);

	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
	pinMode(PIN_Q0_3, OUTPUT);
	pinMode(PIN_Q0_4, OUTPUT);
	pinMode(PIN_Q0_5, OUTPUT);
	pinMode(PIN_Q0_6, OUTPUT);
	pinMode(PIN_Q0_7, OUTPUT);
	pinMode(PIN_Q0_8, OUTPUT);
	pinMode(PIN_Q0_9, OUTPUT);
#endif

#if defined(SPARTAN_16DA)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);

	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
	pinMode(PIN_Q0_3, OUTPUT);
	pinMode(PIN_Q0_4, OUTPUT);
	pinMode(PIN_Q0_5, OUTPUT);
	pinMode(PIN_Q0_6, OUTPUT);
	pinMode(PIN_Q0_7, OUTPUT);
#endif
#if defined(SPARTAN_16RDA)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);

	pinMode(PIN_R1, OUTPUT);
	pinMode(PIN_R2, OUTPUT);
	pinMode(PIN_R3, OUTPUT);
	pinMode(PIN_R4, OUTPUT);
	pinMode(PIN_R5, OUTPUT);
	pinMode(PIN_R6, OUTPUT);
#endif

#if defined(ARDBOX_RELAY) || defined(ARDBOX_RELAY_HF) || defined(ARDBOX_RELAY_HF_PLUS)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);
	pinMode(PIN_I0_8, INPUT);
	pinMode(PIN_I0_9, INPUT);

#if defined(ARDBOX_RELAY)
	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
#elif defined(ARDBOX_RELAY_HF_RS485) || defined(ARDBOX_RELAY_HF_RS232) || defined(ARDBOX_RELAY_HF_PLUS_RS485) || defined(ARDBOX_RELAY_HF_PLUS_RS232)
	pinMode(PIN_A0_0, OUTPUT);
	pinMode(PIN_A0_1, OUTPUT);
#endif

	pinMode(PIN_R1, OUTPUT);
	pinMode(PIN_R2, OUTPUT);
	pinMode(PIN_R3, OUTPUT);
	pinMode(PIN_R4, OUTPUT);
	pinMode(PIN_R5, OUTPUT);
	pinMode(PIN_R6, OUTPUT);
	pinMode(PIN_R7, OUTPUT);
	pinMode(PIN_R8, OUTPUT);
#endif

#if defined(MDUINO_21) || defined(MDUINO_42) || defined(MDUINO_58)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);
	pinMode(PIN_I0_8, INPUT);
	pinMode(PIN_I0_9, INPUT);
	pinMode(PIN_I0_10, INPUT);
	pinMode(PIN_I0_11, INPUT);
	pinMode(PIN_I0_12, INPUT);
	pinMode(PIN_I1_0, INPUT);
	pinMode(PIN_I1_1, INPUT);
	pinMode(PIN_I1_2, INPUT);
	pinMode(PIN_I1_3, INPUT);
	pinMode(PIN_I1_4, INPUT);
	pinMode(PIN_I1_5, INPUT);
	pinMode(PIN_I1_6, INPUT);
	pinMode(PIN_I1_7, INPUT);
	pinMode(PIN_I1_8, INPUT);
	pinMode(PIN_I1_9, INPUT);
	pinMode(PIN_I1_10, INPUT);
	pinMode(PIN_I1_11, INPUT);
	pinMode(PIN_I1_12, INPUT);
	pinMode(PIN_I2_0, INPUT);
	pinMode(PIN_I2_1, INPUT);
	pinMode(PIN_I2_2, INPUT);
	pinMode(PIN_I2_3, INPUT);
	pinMode(PIN_I2_5, INPUT);
	pinMode(PIN_I2_6, INPUT);
	pinMode(PIN_I2_7, INPUT);
	pinMode(PIN_I2_8, INPUT);
	pinMode(PIN_I2_9, INPUT);
	pinMode(PIN_I2_10, INPUT);

	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
	pinMode(PIN_Q0_3, OUTPUT);
	pinMode(PIN_Q0_4, OUTPUT);
	pinMode(PIN_Q0_5, OUTPUT);
	pinMode(PIN_Q0_6, OUTPUT);
	pinMode(PIN_Q0_7, OUTPUT);
	pinMode(PIN_Q1_0, OUTPUT);
	pinMode(PIN_Q1_1, OUTPUT);
	pinMode(PIN_Q1_2, OUTPUT);
	pinMode(PIN_Q1_3, OUTPUT);
	pinMode(PIN_Q1_4, OUTPUT);
	pinMode(PIN_Q1_5, OUTPUT);
	pinMode(PIN_Q1_6, OUTPUT);
	pinMode(PIN_Q1_7, OUTPUT);
	pinMode(PIN_Q2_0, OUTPUT);
	pinMode(PIN_Q2_1, OUTPUT);
	pinMode(PIN_Q2_2, OUTPUT);
	pinMode(PIN_Q2_3, OUTPUT);
	pinMode(PIN_Q2_5, OUTPUT);
	pinMode(PIN_Q2_6, OUTPUT);
#endif

#if defined(MDUINO_19R) || defined(MDUINO_38R) || defined(MDUINO_57R)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);
	pinMode(PIN_I1_0, INPUT);
	pinMode(PIN_I1_1, INPUT);
	pinMode(PIN_I1_2, INPUT);
	pinMode(PIN_I1_3, INPUT);
	pinMode(PIN_I1_4, INPUT);
	pinMode(PIN_I1_5, INPUT);
	pinMode(PIN_I2_0, INPUT);
	pinMode(PIN_I2_1, INPUT);
	pinMode(PIN_I2_2, INPUT);
	pinMode(PIN_I2_3, INPUT);
	pinMode(PIN_I2_4, INPUT);
	pinMode(PIN_I2_5, INPUT);

	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
	pinMode(PIN_Q1_0, OUTPUT);
	pinMode(PIN_Q1_1, OUTPUT);
	pinMode(PIN_Q1_2, OUTPUT);
	pinMode(PIN_Q2_0, OUTPUT);
	pinMode(PIN_Q2_1, OUTPUT);

	pinMode(PIN_R0_1, OUTPUT);
	pinMode(PIN_R0_2, OUTPUT);
	pinMode(PIN_R0_3, OUTPUT);
	pinMode(PIN_R0_4, OUTPUT);
	pinMode(PIN_R0_5, OUTPUT);
	pinMode(PIN_R0_6, OUTPUT);
	pinMode(PIN_R0_7, OUTPUT);
	pinMode(PIN_R0_8, OUTPUT);
	pinMode(PIN_R1_1, OUTPUT);
	pinMode(PIN_R1_2, OUTPUT);
	pinMode(PIN_R1_3, OUTPUT);
	pinMode(PIN_R1_4, OUTPUT);
	pinMode(PIN_R1_5, OUTPUT);
	pinMode(PIN_R1_6, OUTPUT);
	pinMode(PIN_R1_7, OUTPUT);
	pinMode(PIN_R1_8, OUTPUT);
	pinMode(PIN_R2_1, OUTPUT);
	pinMode(PIN_R2_2, OUTPUT);
	pinMode(PIN_R2_3, OUTPUT);
	pinMode(PIN_R2_4, OUTPUT);
	pinMode(PIN_R2_6, OUTPUT);
	pinMode(PIN_R2_7, OUTPUT);
	pinMode(PIN_R2_8, OUTPUT);
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_21_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_38AR_PLUS) || defined(SPARTAN_21)
	pinMode(PIN_I0_0, INPUT);
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_6, INPUT);
	pinMode(PIN_I0_7, INPUT);
	pinMode(PIN_I0_8, INPUT);
	pinMode(PIN_I0_9, INPUT);
	pinMode(PIN_I0_10, INPUT);
	pinMode(PIN_I0_11, INPUT);
	pinMode(PIN_I0_12, INPUT);

#if !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_LORA_PLUS)
	pinMode(PIN_I0_5, INPUT);
#endif
	
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS) || defined(SPARTAN_19R)
	pinMode(PIN_I0_1, INPUT);
	pinMode(PIN_I0_2, INPUT);
	pinMode(PIN_I0_3, INPUT);
	pinMode(PIN_I0_4, INPUT);
	pinMode(PIN_I0_5, INPUT);

#if !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_LORA_PLUS)
	pinMode(PIN_I0_0, INPUT);
#endif
	
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_57AAR_PLUS)
	pinMode(PIN_I1_0, INPUT);
	pinMode(PIN_I1_1, INPUT);
	pinMode(PIN_I1_2, INPUT);
	pinMode(PIN_I1_3, INPUT);
	pinMode(PIN_I1_4, INPUT);
	pinMode(PIN_I1_7, INPUT);
	pinMode(PIN_I1_8, INPUT);
	pinMode(PIN_I1_9, INPUT);
	pinMode(PIN_I1_10, INPUT);
	pinMode(PIN_I1_11, INPUT);
	pinMode(PIN_I1_12, INPUT);

#if !defined(MDUINO_DALI_PLUS) && !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_WIFI_PLUS) \
  && !defined(MDUINO_WIFI_GPRS_PLUS)
	pinMode(PIN_I1_5, INPUT);
	pinMode(PIN_I1_6, INPUT);
#endif
	
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
	pinMode(PIN_I1_2, INPUT);
	pinMode(PIN_I1_3, INPUT);
	pinMode(PIN_I1_4, INPUT);
	pinMode(PIN_I1_5, INPUT);

#if !defined(MDUINO_WIFI_PLUS) && !defined(MDUINO_GPRS_PLUS) && !defined(MDUINO_WIFI_GPRS_PLUS) \
  && !defined(MDUINO_DALI_PLUS)
	pinMode(PIN_I1_0, INPUT);
	pinMode(PIN_I1_1, INPUT);
#endif

	
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_54ARA_PLUS) || defined(MDUINO_50RRA_PLUS)
	pinMode(PIN_I2_0, INPUT);
	pinMode(PIN_I2_1, INPUT);
	pinMode(PIN_I2_2, INPUT);
	pinMode(PIN_I2_3, INPUT);
	pinMode(PIN_I2_5, INPUT);
	pinMode(PIN_I2_6, INPUT);
	pinMode(PIN_I2_7, INPUT);
	pinMode(PIN_I2_8, INPUT);
	pinMode(PIN_I2_9, INPUT);
	pinMode(PIN_I2_10, INPUT);
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)
	pinMode(PIN_I2_0, INPUT);
	pinMode(PIN_I2_1, INPUT);
	pinMode(PIN_I2_2, INPUT);
	pinMode(PIN_I2_3, INPUT);
	pinMode(PIN_I2_4, INPUT);
	pinMode(PIN_I2_5, INPUT);
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_21_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_38AR_PLUS) || defined(SPARTAN_21)
	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
	pinMode(PIN_Q0_3, OUTPUT);
	pinMode(PIN_Q0_4, OUTPUT);
	pinMode(PIN_Q0_5, OUTPUT);
	pinMode(PIN_Q0_6, OUTPUT);
	pinMode(PIN_Q0_7, OUTPUT);
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS) || defined(SPARTAN_19R)
	pinMode(PIN_Q0_0, OUTPUT);
	pinMode(PIN_Q0_1, OUTPUT);
	pinMode(PIN_Q0_2, OUTPUT);
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_42_PLUS) || defined(MDUINO_57AAR_PLUS)
	pinMode(PIN_Q1_0, OUTPUT);
	pinMode(PIN_Q1_1, OUTPUT);
	pinMode(PIN_Q1_2, OUTPUT);
	pinMode(PIN_Q1_3, OUTPUT);
	pinMode(PIN_Q1_4, OUTPUT);
	pinMode(PIN_Q1_7, OUTPUT);
	
#elif defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
	pinMode(PIN_Q1_0, OUTPUT);
	pinMode(PIN_Q1_1, OUTPUT);
	pinMode(PIN_Q1_2, OUTPUT);
#endif

#if defined(MDUINO_58_PLUS) || defined(MDUINO_54ARA_PLUS) || defined(MDUINO_50RRA_PLUS)
	pinMode(PIN_Q2_0, OUTPUT);
	pinMode(PIN_Q2_1, OUTPUT);
	pinMode(PIN_Q2_2, OUTPUT);
	pinMode(PIN_Q2_3, OUTPUT);

#if !defined(MDUINO_LORA_PLUS) 
	pinMode(PIN_Q2_5, OUTPUT);
#endif

#if !defined(MDUINO_LORA_PLUS) &&  !defined(MDUINO_WIFI_GPRS_PLUS) 
	pinMode(PIN_Q2_6, OUTPUT);
#endif
	
#elif (defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)) && !defined(MDUINO_LORA_PLUS)
	pinMode(PIN_Q2_0, OUTPUT);

#if !defined(MDUINO_WIFI_GPRS_PLUS)
	pinMode(PIN_Q2_1, OUTPUT);
#endif
	
#endif

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_19R_PLUS) || \
	defined(MDUINO_50RRA_PLUS) || defined(SPARTAN_19R)
	pinMode(PIN_R0_1, OUTPUT);
	pinMode(PIN_R0_2, OUTPUT);
	pinMode(PIN_R0_3, OUTPUT);
	pinMode(PIN_R0_4, OUTPUT);
	pinMode(PIN_R0_5, OUTPUT);
	pinMode(PIN_R0_6, OUTPUT);
	pinMode(PIN_R0_7, OUTPUT);
	pinMode(PIN_R0_8, OUTPUT);
#endif

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_38R_PLUS) || defined(MDUINO_54ARA_PLUS) || \
	defined(MDUINO_53ARR_PLUS) || defined(MDUINO_50RRA_PLUS) || defined(MDUINO_38AR_PLUS)
	pinMode(PIN_R1_1, OUTPUT);
	pinMode(PIN_R1_2, OUTPUT);
	pinMode(PIN_R1_3, OUTPUT);
	pinMode(PIN_R1_4, OUTPUT);
	pinMode(PIN_R1_5, OUTPUT);
	pinMode(PIN_R1_6, OUTPUT);
	pinMode(PIN_R1_7, OUTPUT);
	pinMode(PIN_R1_8, OUTPUT);
#endif

#if defined(MDUINO_57R_PLUS) || defined(MDUINO_57AAR_PLUS) || defined(MDUINO_53ARR_PLUS)
	pinMode(PIN_R2_1, OUTPUT);
	pinMode(PIN_R2_2, OUTPUT);
	pinMode(PIN_R2_3, OUTPUT);
	pinMode(PIN_R2_4, OUTPUT);
	pinMode(PIN_R2_6, OUTPUT);
	pinMode(PIN_R2_7, OUTPUT);
	pinMode(PIN_R2_8, OUTPUT);
#endif

#if defined(MDUINO_PLUS) || defined(SPARTAN_21) || defined(SPARTAN_19R)
	// The Ethernet chip select pin (D10) to HIGH
	pinMode(10, OUTPUT);
	digitalWrite(10, HIGH);
#endif
}
