#include <dht_nonblocking.h>
#include <Ethernet.h>
#include <SPI.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11

//Sensor
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

//Internet connection
char serverIP = "217.160.0.19";
char server = "www.tiadeca.com";
char request = "GET /probe/savedata.php?";
byte macaddress[] = {0x80, 0x80, 0x80, 0xA80, 0x80, 0x80};
EthernetClient client;

int counter = 0;

void setup(){
  pinMode(13,OUTPUT);
  Serial.begin(115200);
}

void loop(){
  delay(10000);
  counter++;
  float temperature, humidity;
  if(dht_sensor.measure(&temperature, &humidity)){
    //char temp = "Attempt: ".counter." T = ".temperature." deg. C, H = ".humidity."%: data stored";
    Serial.println("Attempt: ");
    Serial.println(counter);
    Serial.println(" T = ");
    Serial.println(temperature);
    Serial.println(" deg. C, H = ");
    Serial.println(humidity);
    Serial.println("%: data stored");
    Serial.println();
  }
  
  if (client.connect(serverIP, 80)){
    // concatening the request
    strcat(request,"Temperature=");
    strcat(request,char(temperature));
    strcat(request,"&Humidity=");
    strcat(request,char(humidity));
    strcat(request," HTTP/1.1");
    //client.print(request,"Temperature=",temperature,"&Humidity=",humidity," HTTP/1.1"); 
    
    // sending the request
    client.println(request);
    client.println("Connection: close"); 
    client.println(); 
    client.stop();
    Serial.println(request);

    // output a confirm
    char temp = "\nConnessione OK. Attempt: ";
    strcat(temp,counter);
    strcat(temp," sent to the server");
    Serial.println(temp);
    //Serial.println("\nConnessione OK. Attempt: ", counter, " sent to the server");  
  } else{
    Serial.println("\nConnection failed\n");
  }
}
