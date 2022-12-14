#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN A0
#define out 13
LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
dht.begin();
pinMode(out,OUTPUT);
lcd.begin(16,2);
lcd.print("Team EL2optan");
delay(500);
}

void loop() {
float cel = dht.readTemperature();
lcd.setCursor(0, 1);
lcd.print("Temprature= ");
lcd.print(cel);
if(cel>=25){
digitalWrite(out,HIGH);
lcd.setCursor(0, 0);
lcd.print("OVERHEATING!!!");
}else if(cel<=22){
digitalWrite(out,LOW);
lcd.setCursor(0, 0);
lcd.print("Normal Temp");
}
delay(2000);
lcd.clear();
}
