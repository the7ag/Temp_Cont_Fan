#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN A0
DHT dht(DHTPIN, DHTTYPE);
void setup() {
dht.begin();
Serial.begin(9600);
}

void loop() {
float cel = dht.readTemperature();
Serial.println("Temprature = ");
Serial.println(cel);
delay(2000);
}
