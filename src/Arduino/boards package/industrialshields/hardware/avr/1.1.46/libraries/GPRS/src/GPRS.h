#ifndef __GPRS_H__
#define __GPRS_H__

#include <Arduino.h>
#include "GPRSClient.h"

#if defined(HAVE_SIM800L)
#include "utilities/sim800l.h"
#else
#error "Undefined GPRS module"
#endif

class GPRSClass {
	public:
		bool begin(uint16_t port = 0);

		inline int isPINRequired() const {
			return GPRSModule::isPINRequired();
		}
		inline bool unlockSIM(const char *pin) const {
			return GPRSModule::unlockSIM(pin);
		}
		inline uint8_t getRSSI() const {
			return GPRSModule::getRSSI();
		}
		inline uint8_t getNetworkStatus() const {
			return GPRSModule::getNetworkStatus();
		}
		inline bool enableNetworkTimeSync() const {
			return GPRSModule::enableNetworkTimeSync();
		}
		uint8_t getGPRSStatus() const;
		inline bool enableGPRS(const char *apn, const char *username = nullptr, const char *password = nullptr) const {
			return GPRSModule::enableGPRS(apn, username, password);
		}
		inline bool connected() const {
			return GPRSModule::connected();
		}
		inline IPAddress localIP() const {
			return GPRSModule::getIPAddress();
		}
		inline int getTime(char *buff, size_t len) const {
			return GPRSModule::getTime(buff, len);
		}
		inline bool sendSMS(const char* number, const char* text) const {
			return GPRSModule::sendSMS(number, text);
		}
		GPRSClient available() const;
};

extern GPRSClass GPRS;

#endif
