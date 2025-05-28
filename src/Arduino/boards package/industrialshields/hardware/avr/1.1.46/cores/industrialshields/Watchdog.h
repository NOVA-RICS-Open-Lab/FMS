#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

#include <avr/wdt.h>

class WatchdogClass {
	public:
		WatchdogClass();

	public:
		void enable(int timeout = WDTO_8S);
		void disable();
		inline bool isEnabled() { return enabled; }
		inline void reset() { wdt_reset(); }

	private:
		bool enabled;
};

extern WatchdogClass Watchdog;

#endif
