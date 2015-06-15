// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

/* 
   THIS SKETCH IS WRITTEN BY NICK GAMMON. 
   IT'S JUST IN MY REPO TO KEEP MY ARDUINO TOOLS IN ORDER 
   
   THANKS GOES TO NICK FOR SAVING ME PRECIOUS TIME   
   AND KEEPING ME FROM BANGING MY HEAD ON THE TABLE!
*/

#include <Wire.h>

void setup() {
 Serial.begin (9600);
 Serial.println ();
 Serial.println ("I2C scanner. Scanning ...");
 byte count = 0;

 Wire.begin();
 for (byte i = 1; i < 120; i++)
 {
   Wire.beginTransmission (i);
   if (Wire.endTransmission () == 0)
     {
     Serial.print ("Found address: ");
     Serial.print (i, DEC);
     Serial.print (" (0x");
     Serial.print (i, HEX);
     Serial.println (")");
     count++;
     delay (1);  // maybe unneeded?
     } // end of good response
 } // end of for loop
 Serial.println ("Done.");
 Serial.print ("Found ");
 Serial.print (count, DEC);
 Serial.println (" device(s).");

}  // end of setup

void loop() {}


