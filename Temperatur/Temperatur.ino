#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperatur: " + String(t) + " Grad");
  Serial.println("Feuchtigkeit: " + String(h) + " Prozent");
  delay(10000);
}
