// GPRS library example
// by Industrial Shields

#include <GPRS.h>

#define PIN "YOUR-SIM-PIN"
#define APN "YOUR-APN"
#define USERNAME "YOUR-APN-USER"
#define PASSWORD "YOUR-APN-PASSWORD"

GPRSClient client;
uint8_t buffer[1024];

////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600UL);

  if (!GPRS.begin()) {
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

  if (!GPRS.enableGPRS(APN, USERNAME, PASSWORD)) {
    Serial.println("GPRS not enabled");
    while(true);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  static uint32_t lastStatusTime = millis();
  if (millis() - lastStatusTime > 2000) {
    uint8_t networkStatus = GPRS.getNetworkStatus();
    Serial.print("Status: ");
    Serial.println(networkStatus);
    lastStatusTime = millis();

    if ((networkStatus == 1) || (networkStatus == 5)) {
      int GPRSStatus = GPRS.getGPRSStatus();
      if (GPRSStatus == 0) {
        if (!GPRS.enableGPRS(APN, USERNAME, PASSWORD)) {
          Serial.println("GPRS not enabled");
        }
      }
      else if (GPRSStatus == 1) {
        if (GPRS.connected()) {
          if (!client.connected()) {
            static bool requestDone = false;
            if (!requestDone) {
              if (!client.connect("www.industrialshields.com", 80)) {
                Serial.println("Error connecting to web");
              }
              else {
                client.println("GET /index.html HTTP/1.1");
                client.println("Host: www.industrialshields.com");
                client.println("User-Agent: GPRS-PLC");
                client.println();
                Serial.println("Connected");
                Serial.println("Data sent");
                requestDone = true;
              }
            }
          }
          else if (client.available()) {
            Serial.println("HTTP response:");
            size_t len = client.read(buffer, sizeof(buffer));
            Serial.write(buffer, len);
            client.stop();
          }
        }
      }
    }
  }
}
