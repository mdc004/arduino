#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>

// Initialize Wifi connection to the router
const char* ssid     = "FASTWEB-XE9L7H";  
const char* password = "NQSFLGG5QN";
// Initialize Telegram BOT
const char BotToken[] = "5885025211:AAG_Wd4S0NEowfdEYoD-p0mXGZXekzYA19Q";
WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);
 // the number of the LED pin  
void setup() 
{  
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  Serial.begin(115200);   

  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    digitalWrite(D1, HIGH);
    delay(500);
    digitalWrite(D1, LOW);
    delay(500);
  }
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
  digitalWrite(D1, HIGH);

  bot.begin(); 

  for(int i = 0; i < 5; i++){
    digitalWrite(D2, HIGH);
    delay(500);
    digitalWrite(D2, LOW);
    delay(500);
  }
}  
void loop() 
{  
 message m = bot.getUpdates(); // Read new messages  
 bot.sendMessage(m.chat_id, "System On");

 if (m.text.equals("on")){  
   digitalWrite(D2, HIGH);   
   bot.sendMessage(m.chat_id, "The Led is now ON");  
 }  
 else if (m.text.equals("off")){  
   digitalWrite(D2, LOW);   
   bot.sendMessage(m.chat_id, "The Led is now OFF");  
 }  
}  