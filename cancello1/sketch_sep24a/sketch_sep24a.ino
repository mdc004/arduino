#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>


#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
    Serial.begin(115200);
  Serial.println();
  // put your setup code here, to run once:
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nWiFi connected. IP address: ");
  delay(500);
}
