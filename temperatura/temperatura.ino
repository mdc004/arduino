#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN1 7     // Digital pin connected to the DHT sensor 
#define DHTPIN2 6     // Digital pin connected to the DHT sensor 
#define DHTPIN3 5     // Digital pin connected to the DHT sensor 


// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

  DHT_Unified dht1(DHTPIN1, DHTTYPE); // Garage dht sensor
  DHT_Unified dht2(DHTPIN2, DHTTYPE); // sala pranzo dht sensor
  DHT_Unified dht3(DHTPIN3, DHTTYPE); // camera dht sensor

void setup() {
  Serial.begin(9600);
  dht1.begin();
  sensor_t sensor1;

  dht2.begin();
  sensor_t sensor2;
  
  dht3.begin();
  sensor_t sensor3;
  
  // Initialize device.
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  // Set delay between sensor readings based on sensor details.
}

void loop() {
  // Delay between measurements.
  delay(1000);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht1.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature 1: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht1.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity 1: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
  // Get temperature event and print its value.
  dht2.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature 2: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht2.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity 2: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
  // Get temperature event and print its value.
  dht3.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature 3: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht3.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity 3: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
