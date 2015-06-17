#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int batteryValue = 0;
float v = 0;
float maxV = 0;
float minV = 10;

void setup() {
    Serial.begin(9600);
    lcd.begin(20,4);
    lcd.setCursor(3, 1);
    lcd.print("Solarpanel 0.1");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("V cur:"); 
    lcd.setCursor(0,1);
    lcd.print("V max:");
    lcd.setCursor(0,2);
    lcd.print("V min:");
}

void loop() {
    batteryValue = analogRead(A0);
    v = (float(batteryValue)*5)/1023*2;
    if (v < minV){
      minV = v;
    }
    if (maxV < v){
      maxV = v;
    }
    lcd.setCursor(7,0);
    lcd.print(String(v)); 
    lcd.setCursor(7,1);
    lcd.print(String(maxV));
    lcd.setCursor(7,2);
    lcd.print(String(minV));
    delay(1000);
}
