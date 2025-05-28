/*
   Copyright (c) 2016 Boot&Work Corp., S.L.

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

#ifndef __INDUSTRIALSHIELDS_RS232_H__
#define __INDUSTRIALSHIELDS_RS232_H__

#include <Arduino.h>

#if defined(HAVE_RS232)

#if defined(HAVE_RS232_SOFT)
#include <SoftwareSerial.h>
class RS232Class : public SoftwareSerial {
	public:
		RS232Class(uint8_t rxPin, uint8_t txPin);

	public:
	virtual void begin(unsigned long baud, uint8_t config = SERIAL_8N1);
};
extern RS232Class RS232;
#endif // HAVE_RS232_SOFT

#if defined(HAVE_RS232_HARD)
#include <HardwareSerial.h>
extern HardwareSerial RS232;
#endif // HAVE_RS232_HARD

#endif // HAVE_RS232

#endif // __INDUSTRIALSHIELDS_RS232_H__
