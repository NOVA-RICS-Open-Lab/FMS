// GPRS library example
// by Industrial Shields

#include <GPRS.h>

#define PIN "YOUR-SIM-PIN"
#define APN "YOUR-APN"
#define USERNAME "YOUR-APN-USER"
#define PASSWORD "YOUR-APN-PASSWORD"

uint8_t buffer[1024];
int networkStatus = -1;

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600UL);

  if (!GPRS.begin(80)) {
    Serial.println("Impossible to begin GPRS");
    while(true);
  }

  int pinRequired = GPRS.isPINRequired();
  if (pinRequired == 1) {
    if (!GPRS.unlockSIM(PIN)) {
      Serial.println("Invalid PIN");
      while (true);
    }
  }
  else if (pinRequired != 0) {
    Serial.println("Blocked SIM");
    while (true);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  static uint32_t lastStatusRead = millis();

  if (millis() - lastStatusRead > 3000) {
    networkStatus = GPRS.getNetworkStatus();
    lastStatusRead = millis();

    if (networkStatus == 1 || networkStatus==5) {
      if (!GPRS.enableGPRS(APN, USERNAME, PASSWORD)){
        GPRS.enableGPRS(APN, USERNAME, PASSWORD);
      }
      else{
        GPRSClient client = GPRS.available();
        if (client) {
          size_t len = client.available();
          if (len > 0) {
            client.read(buffer, len);
            Serial.write(buffer, len);
          }
        }
      }
    }

    switch (networkStatus) {
      case 0:
        Serial.println("Not registered");
        break;

      case 1:
        Serial.println("Registered (home)");
        break;

      case 2:
        Serial.println("Not registered (searching)");
        break;

      case 3:
        Serial.println("Denied");
        break;

      case 4:
        Serial.println("Unknown");
        break;

      case 5:
        Serial.println("Registered (roaming)");
        break;
    }
  }
}
