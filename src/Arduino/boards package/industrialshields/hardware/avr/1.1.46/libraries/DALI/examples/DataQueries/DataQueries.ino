/*
   Copyright (c) 2023 Boot&Work Corp., S.L. All rights reserved
*/

#include <DALI.h>

#define LAMP_ADDR 0

DALI dali(18, 19);

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600UL);

  dali.begin();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  static uint8_t desired_intensity = 0;
  dali.setValue(LAMP_ADDR, desired_intensity);

  Serial.println("-----------------------------");

  int8_t lampState = dali.isLampOn(LAMP_ADDR);
  switch (lampState) {
  case 1:
    if (desired_intensity > 0) {
      Serial.println("Lamp ON");
    }
    else {
      Serial.println("Lamp reports ON, but it shouldn't be");
    }
    break;
  case 0:
    if (desired_intensity == 0) {
      Serial.println("Lamp OFF");
    }
    else {
      Serial.println("Lamp reports OFF, but it shouldn't be");
    }
    break;
  default:
    Serial.print("There was an error when trying to get the "
    "state of the lamp. The lamp should be ");
    Serial.println(desired_intensity == 0 ? "OFF" : "ON");
    break;
  }

  int16_t received_intensity = dali.getIntensityValue(LAMP_ADDR);
  if (received_intensity != desired_intensity) {
    Serial.print("Error: The received intensity value is ");
    Serial.print(received_intensity, DEC);
    Serial.print(", but it was supposed to be ");
    Serial.println(desired_intensity, DEC);
  }
  else {
    Serial.print("Intensity value: ");
    Serial.println(received_intensity);
  }

  if (desired_intensity == 0) {
    desired_intensity = 175;
  }
  else {
    desired_intensity = 0;
  }
  delay(2000);
}

/* TODO
int8_t powerState = dali.isPowerOn(LAMP_ADDR);
Serial.print("Power: ");
if (powerState) {
  Serial.println("ON");
} else {
  Serial.println("OFF");
}

delay(1000);
*/
