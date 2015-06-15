#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup(){
   lcd.begin(16,2);
   lcd.setCursor(3, 1);
   lcd.print("Hallo Yannick");
}
  
void loop() { }
