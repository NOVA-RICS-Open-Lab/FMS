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

#include "LoRa.h"

#ifdef HAVE_RFM9X
////////////////////////////////////////////////////////////////////////////////////////////////////
LoRaClass::LoRaClass() : RH_RF95(RFM9X_SS_PIN, RFM9X_INT_PIN) {
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool LoRaClass::begin() {
	pinMode(RFM9X_RESET_PIN, OUTPUT);
	digitalWrite(RFM9X_RESET_PIN, HIGH);

	digitalWrite(RFM9X_RESET_PIN, LOW);
	delay(10);
	digitalWrite(RFM9X_RESET_PIN, HIGH);
	delay(10);

	return init();
}

LoRaClass LoRa;
#endif
