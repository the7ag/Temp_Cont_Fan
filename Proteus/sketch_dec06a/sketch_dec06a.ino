#include <LiquidCrystal.h>
#define sensor A0
#define out 13
int sensorVal=0;
bool flag=false;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
lcd.begin(16,2);
lcd.print("Team Mohamed Ali");
pinMode(sensor,INPUT);
pinMode(out,OUTPUT);
}
void loop() {
sensorVal=(analogRead(A0)/1024.0)*5000;
float cel=(sensorVal)/10;
if(cel<=40){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Normal Temp");
  lcd.setCursor(0,1);
  lcd.print("TEMPRATURE = ");
  lcd.print(cel);
  lcd.print("*C");
  delay(500);
}else{
  flag=true;
  while(flag){
    sensorVal=(analogRead(A0)/1024.0)*5000;
    cel=(sensorVal)/10;
    if(cel>=30){
    digitalWrite(out,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("7AREKAAAAAAAAA!");
    lcd.setCursor(0,1);
    lcd.print("TEMPRATURE = ");
    lcd.print(cel);
    lcd.print("*C");
    delay(500);   
    }else{
      digitalWrite(out,LOW);
      flag=false;
    } 
  }
}
}
