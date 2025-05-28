/*
   Copyright (c) 2019 Boot&Work Corp., S.L. All rights reserved

   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "GPRS.h"

#if defined(__AVR__)
#include <avr/pgmspace.h>
#endif

GPRSClass GPRS;

////////////////////////////////////////////////////////////////////////////////////////////////////
bool GPRSClass::begin(uint16_t port) {
	GPRSModule::begin();

	GPRSModule::setTCPServerPort(port);

	// Hardware reset
	GPRSModule::reset();

	// Check communication
	uint32_t resetStartTime = millis();
	bool ready = false;
	while (millis() - resetStartTime < 7000) {
		if (GPRSModule::at()) {
			ready = true;
			break;
		}
		delay(100);
	}

	if (ready) {
		delay(100);
		GPRSModule::flushInput();

		GPRSModule::enableEcho();

		// Wait some time
		delay(500);

		if (!GPRSModule::enableEcho()) {
			return false;
		}
	}

	return ready;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t GPRSClass::getGPRSStatus() const {
	uint8_t ret = 0;
	for (int i = 0; i < 3; ++i) {
		ret = GPRSModule::getGPRSStatus();
		if (ret != 0) {
			break;
		}
	}
	return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
GPRSClient GPRSClass::available() const {
	if (GPRSModule::updateConnections()) {
		for (int i = 0; i < GPRSModule::MaxConnections; ++i) {
			if (GPRSModule::connections[i] == GPRSModule::ServerConnection) {
				GPRSClient client(i);
				if (client.available()) {
					return client;
				}
			}
		}
	}

	return GPRSClient();
}
