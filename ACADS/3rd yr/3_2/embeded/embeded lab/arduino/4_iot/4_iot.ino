#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <SimpleDHT.h>

#define CHANNEL_ID 1685351
#define CHANNEL_API_KEY "PR1R2SQGFKYT4POC"

const int pinDHT22 = D1; // Connected to the out pin OF DHT22 Sensor
WiFiClient client;
SimpleDHT22 dht(pinDHT22);

void setup() {
  Serial.begin(115200);
  pinMode(pinDHT22, INPUT);
  WiFi.disconnect();

  Serial.print("Searching for the network...");
  WiFi.begin("CAMPUS_SECURED", "Mansinumber1!");
  while (!(WiFi.status() == WL_CONNECTED)) {
    Serial.print("...");
    delay(300);
  }

  Serial.println();
  Serial.println("Connected Successfully");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {

  float temp = 0, humidity = 0;

  // checks whether the values obtained are not NAN
  while ((dht.read2(&temp, &humidity, NULL)) != 0) {
    Serial.println("DHT22 failed...");
    delay(3000);
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" degree C");
  Serial.print("Humidity: ");
  Serial.print(humidity);

  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY);
  delay(15000);

}
