/*
   Copyright (c) 2020 Boot&Work Corp., S.L. All rights reserved

   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License v3 as published
   by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LoRa_H__
#define __LoRa_H__

#include <Arduino.h>

#ifdef HAVE_RFM9X
#include <RH_RF95.h>

class LoRaClass : public RH_RF95 {
	public:
		explicit LoRaClass();

	public:
		bool begin();

	protected:
		virtual bool init() {
			return RH_RF95::init();
		}
};

extern LoRaClass LoRa;
#endif

#endif // __LoRa_H__
