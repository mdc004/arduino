#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

  
float temperature;
float humidity;

void setup(){
Serial.begin(9600);
pinMode(2, OUTPUT);
digitalWrite(2, LOW);
}

bool checkTemp(){
  if(temperature > 30)return true;
  else return false;
}

void loop( )
{


dht_sensor.measure(&temperature, &humidity);

if(checkTemp())digitalWrite(2, HIGH);
else digitalWrite(2, LOW);
}
/*
digitalWrite(13, HIGH);
delay(2000);
digitalWrite(13, LOW);
delay(2000);
}

void setup(){
  pinMode(13, OUTPUT);
}

void loop(){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}*/
