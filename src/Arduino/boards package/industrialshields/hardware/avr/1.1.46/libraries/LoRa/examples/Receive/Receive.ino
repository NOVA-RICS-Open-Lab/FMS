/*
   Copyright (c) 2020 Boot&Work Corp., S.L. All rights reserved

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   NOTE: Programs that use this library must adhere to GPLv3-only
   licensing, as it is based on a GPLv3 library.
 */

#include <LoRa.h>

uint32_t counter = 0UL;

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600L);

  // Begin LoRa hardware
  if (!LoRa.begin()) {
    Serial.println("LoRa begin error: is LoRa module connected?");
    while (true);
  }

  // Default LoRa values after begin:
  // Frequency: 434.0MHz
  // Modulation GFSK_Rb250Fd250
  // TX power: +13dBm

  // Set LoRa working frequency
  if (!LoRa.setFrequency(868.0)) {
    Serial.println("LoRa set frequency error");
    while (true);
  }

  Serial.println("Send started");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // Wait packets from Send example
  if (LoRa.available()) {
    uint32_t value;
    uint8_t len = sizeof(value);

    // Save the received packet payload into value
    if (LoRa.recv((uint8_t *) &value, &len)) {
      Serial.print("Received value: ");
      Serial.println(value);
    }
  }
}
