const int ledFeuchtigkeit = 10;
const int ledMessen = 9;
const int devSensor = 13;
const int devPumpe = 12;
int val = 0;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(devSensor, INPUT);
  pinMode(devPumpe, OUTPUT);
  pinMode(ledFeuchtigkeit, OUTPUT);
  pinMode(ledMessen, OUTPUT);
  //Serial.begin(9600);
  //Serial.println("Starting");
}

void loop() {
  val = digitalRead(devSensor);
  digitalWrite(ledFeuchtigkeit, val == 1 ? LOW : HIGH);
  //Serial.println("val: " + val);
  while(val == 1){
    digitalWrite(devPumpe, HIGH);
    delay(4000);  
    digitalWrite(devPumpe, LOW);
    digitalWrite(ledMessen, HIGH);
    delay(10000);
    val = digitalRead(devSensor);
    digitalWrite(ledMessen, LOW);
  }
  digitalWrite(ledFeuchtigkeit, val == 1 ? LOW : HIGH);
  delay(900000); 
}
