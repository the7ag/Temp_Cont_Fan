#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN A0    // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.begin(16,2);
  lcd.print("Team EL2optan");
  dht.begin();
  delay(500);
}
void loop() {
  float t = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temparture = ");
  lcd.print(cel);
  delay(2000);
}
