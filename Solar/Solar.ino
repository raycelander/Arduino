#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int batteryValue = 0;
float outputValue = 0;
float maxValue = 0;
float minValue = 10;

void setup() {
  // initialize digital pin 13 as an output.
    Serial.println("Initializing");
    Serial.begin(9600);
   lcd.begin(20,4);
   lcd.setCursor(3, 1);
   lcd.print("Solarpanel 0.1");
}


void loop() {
  delay(1000);
  lcd.clear();
  batteryValue = analogRead(A0);
  outputValue = (float(batteryValue)*5)/1023*2;
  float v = outputValue;
  if (v < minValue){
    minValue = v;
  }
  if (maxValue < v){
    maxValue = v;
  }
  lcd.setCursor(0,0);
  lcd.print("V cur: " + String(v)); 
  lcd.setCursor(0,1);
  lcd.print("V max: " + String(maxValue));
  lcd.setCursor(0,2);
  lcd.print("V min: " + String(minValue));
}
