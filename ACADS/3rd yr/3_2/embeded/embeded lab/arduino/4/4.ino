#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include "DHT.h"

// include libraries

#define DHTTYPE DHT22 //dht22 type being specified
DHT dht (1, DHTTYPE); // creating dht object
#define CHANNEL_ID 1685351
#define CHANNEL_API_KEY "PR1R2SQGFKYT4POC"

WiFiClient client; //creating client
void setup()
{
  dht.begin(); // dht initiate
  Serial.begin(115200);
  WiFi.disconnect();
  Serial.print("Searching network");
  WiFi.begin("CAMPUS_SECURED", "Mansinumber1!");
  while(WiFi.status()!=WL_CONNECTED) // waiting to be connected
  {
    Serial.println("...");
    delay(300);   
  }

  Serial.println();
  Serial.println("Connected Successfully");
  Serial.print("Your IP:");
  Serial.println(WiFi.localIP()); // printing IP of connected device
  ThingSpeak.begin(client); // client
}

void loop()
{
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  ThingSpeak.writeField(CHANNEL_ID,1,h,CHANNEL_API_KEY);
  ThingSpeak.writeField(CHANNEL_ID,2,t,CHANNEL_API_KEY);
  delay(500);
}
