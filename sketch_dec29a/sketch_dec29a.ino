#include <dht_nonblocking.h>
#include <Ethernet.h>
#include <SPI.h>

byte macaddress[] = {0x80, 0x80, 0x80, 0xA80, 0x80, 0x80};
EthernetClient client;

//mac di arduino
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//Sensor
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

#define URL "tiadeca.com"
#define PORT 80 // HTTPS port
String path = "/probe/savedataPost.php?temperature=55&humidity=55";
#define METHOD "POST"
#define CONTENTTYPE "application/json"
String body = "{\"temperature\": \"5\", \"humidity\": \"6\"}";
    
EthernetClient httpsClient;

void setup() {
    Serial.begin(9600);
    while (Ethernet.begin(mac) != 1)
    {
      Serial.println("Error getting IP address via DHCP, trying again...");
      delay(15000);
    }  
}

float temperature, humidity;
int checker;

void loop() {
  do{
    if(!dht_sensor.measure(&temperature, &humidity))checker = 1;
    else checker = 0;
  }
  while(checker == 1);
  if(checker == 0){
  path = "/probe/savedataPost.php?temperature="+String(temperature)+"&humidity="+String(humidity);
  body = "{\"temperature\": \""+String(temperature)+"\", \"humidity\": \""+String(humidity)+"\"}";
  Serial.println("****************");
  Serial.println(path);
  Serial.println("****************");

  delay(1000);
  Serial.print("Connecting to ");
  Serial.println(URL);

  while(!httpsClient.connect(URL, PORT)) {
      delay(1000);
      Serial.print(".");
  }

    // Forming the request (the hardest part).
    String request = String(METHOD) + " " + path + " HTTP/1.1\r\n" +
        "Host: " + URL + "\r\n" +
        "Content-Type: " + CONTENTTYPE + "\r\n" +
        "Connection: close\r\n\r\n" +
        body + "\r\n\r\n";

    // Printing the request to be sure it's formed fine.
    Serial.println("Request is: ");
    Serial.println(request);

    // Making the request.
    httpsClient.print(request);

    // Receiving response headers.
    while(httpsClient.connected()) {
        String line = httpsClient.readStringUntil('\n');
        Serial.println("-----HEADERS START-----");
        Serial.println(line);
        if(line == "\r") {
            Serial.println("-----HEADERS END-----");
            break;
        }
    }

    // Receiving response body.
    while(httpsClient.available()) {
        String line = httpsClient.readStringUntil('\n');
        Serial.println(line);
    }
    delay(300000);}
}