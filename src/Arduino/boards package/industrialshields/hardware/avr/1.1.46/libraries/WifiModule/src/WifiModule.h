/*
   Copyright (c) 2019 Boot&Work Corp., S.L.

   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __INDUSTRIALSHIELDS_WIFI_MODULE_H__
#define __INDUSTRIALSHIELDS_WIFI_MODULE_H__

#include <Arduino.h>

#if defined(HAVE_ESP32)

#if defined(HAVE_ESP32_SOFT)
#include <SoftwareSerial.h>
class WifiModuleClass : public SoftwareSerial {
	public:
		WifiModuleClass(uint8_t rxPin, uint8_t txPin);

	public:
		virtual void begin(unsigned long baud);
};
extern WifiModuleClass WifiModule;
#endif // HAVE_ESP32_SOFT

#if defined(HAVE_ESP32_HARD)
#include <HardwareSerial.h>
extern HardwareSerial WifiModule;
#endif // HAVE_ESP32_HARD

#endif // HAVE_ESP32

#endif // __INDUSTRIALSHIELDS_WIFI_MODULE_H__
