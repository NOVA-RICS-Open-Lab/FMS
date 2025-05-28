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

#ifndef __INDUSTRIALSHIELDS_RS485_H__
#define __INDUSTRIALSHIELDS_RS485_H__

#include <Arduino.h>

#if defined(HAVE_RS485)

#if defined(HAVE_RS485_SOFT)
#include <SoftwareSerial.h>
class RS485Class : public SoftwareSerial {
	public:
		RS485Class(uint8_t rxPin, uint8_t txPin);

	public:
		// Both duplex and config are not used in SoftwareSerial devices
		void begin(unsigned long baud, uint8_t duplex = HALFDUPLEX, uint8_t config = SERIAL_8N1);

	public:
		virtual size_t write(uint8_t value);
		virtual size_t write(const uint8_t *buff, size_t len);
		using SoftwareSerial::write;

	private:
		inline void enableTx();
		inline void disableTx();

	private:
		bool _bufferMode;
};
#endif // HAVE_RS485_SOFT

#if defined(HAVE_RS485_HARD)
#include <HardwareSerial.h>

class RS485Class : public HardwareSerial {
	public:
		RS485Class(
				volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
				volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
				volatile uint8_t *ucsrc, volatile uint8_t *udr);
	public:
		// baud: bits per seconds
		// duplex: FULLDUPLEX or HALFDUPLEX
		// config: Serial configuration parameter (default: SERIAL_8N1)
		void begin(unsigned long baud, uint8_t duplex = HALFDUPLEX, uint8_t config = SERIAL_8N1);
		void end();

	public:
		virtual size_t write(uint8_t value);
		using HardwareSerial::write;

		virtual void flush();

		void _tx_irq();

	private:
		inline void enableTx();
		inline void disableTx();

	private:
		uint8_t _duplex;
		volatile bool _sending;
};
#endif // HAVE_RS485_HARD

extern RS485Class RS485;

#endif // HAVE_RS485

#endif // __INDUSTRIALSHIELDS_RS485_H__
