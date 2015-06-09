
int batteryValue = 0;
float outputValue = 0;
float oldValue = 0;
int timer = 0;
void setup() {
  // initialize digital pin 13 as an output.
  Serial.println("Initializing");
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}


void loop() {
  timer = timer + 1;
  batteryValue = analogRead(A0);
  outputValue = (float(batteryValue)*5)/1023*2;
  Serial.println(timer);  
  int v = outputValue;
  if (timer == 40){
      if (oldValue > 0){
        for (int i=0;i<3;i++){
          digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(100);
          digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
          delay(100);
        }
        
        if (oldValue < outputValue){
          digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        }else if(oldValue > outputValue){
          digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        }else{
          digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
        Serial.println("outputValue: " + String(outputValue) + " / oldValue: " + String(oldValue)); 
   }
  oldValue = outputValue;
  timer = 0;
 }
  for (int i=0;i<v;i++){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
  }
 
  delay(3000);
}
