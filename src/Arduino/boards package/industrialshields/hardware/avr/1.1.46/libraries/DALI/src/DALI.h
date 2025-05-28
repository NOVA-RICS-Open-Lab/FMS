#ifndef __DALI_H__
#define __DALI_H__

#include <Arduino.h>

class DALI {
	private:
		enum {
			COMMAND_BROADCAST	= 0b11111111,
			COMMAND_GRUPO		= 0b10000001,
			RESET			= 0b00100000,
			INITIALISE		= 0b10100101,
			RANDOMISE		= 0b10100111,
			SEARCHADDRH		= 0b10110001,
			SEARCHADDRM		= 0b10110011,
			SEARCHADDRL		= 0b10110101,
			COMPARE			= 0b10101001,
			WITHDRAW		= 0b10101011,
			TERMINATE		= 0b10100001,
			SHORT_POWER		= 0b00000000,
			PROGRAM_SHORT_ADDRESS	= 0b10110111,
			VERIFY_SHORT_ADDRESS	= 0b10111001,

			CONTROL_BROADCAST	= 0b11111110,
			
			QUERY_ACTUAL_LEVEL	= 0b10100000,
			QUERY_LAMP_POWER_ON	= 0b10100011,
		};

	public:
#if defined(DALI_TX) && defined(DALI_RX)
		explicit DALI(int txPin = DALI_TX, int rxPin = DALI_RX);
#else
		explicit DALI(int txPin, int rxPin);
#endif

	public:
		void begin();
		int initNodes(const uint8_t* addresses, uint8_t numAddresses);
	        inline int initNodes(uint8_t address) {
			const uint8_t addresses[1] = {address};
			return initNodes(addresses, 1);
		}

		void turnOff(uint8_t nodeAddress);
		void setMax(uint8_t nodeAddress);
		void setValue(uint8_t nodeAddress, uint8_t value);
		
		/**
		* @brief Checks if the power is on for the specified DALI node.
		*
		* @param nodeAddress The address of the DALI node.
		* @return -1 if an error occurred, 0 if power is off, 1 if power is on.
		*/
		// int8_t isPowerOn(uint8_t nodeAddress);

		/**
		* @brief Gets the intensity value of the specified DALI node.
		*
		* @param nodeAddress The address of the DALI node.
		* @return The intensity value (-1 if an error occurred).
		*/
		int16_t getIntensityValue(uint8_t nodeAddress);

		/**
		* @brief Checks if the lamp is on for the specified DALI node.
		*
		*
		* @param nodeNumber The number of the DALI node.
		* @return -1 if an error occurred, 0 if the lamp is off, or 1 if the lamp is on.
		*/
		inline int8_t isLampOn(uint8_t nodeNumber) {
			int16_t response = getIntensityValue(nodeNumber);
			return (response == -1) ? -1 : (response == 0) ? 0 : 1;
		}
		

	private:
		void sendZero(void);
		void sendOne(void);
		uint8_t receiveData(void);
		int16_t waitResponse(void);
		void sendCommand(uint8_t command, uint8_t data);
		bool sendSearchAddr(uint32_t addr);
		bool sendProgramShortAddr(uint8_t nodeNumber);
		void withdrawNode(uint32_t addr);

	private:
		int txPin;
		int rxPin;
};

#endif // __DALI_H__
