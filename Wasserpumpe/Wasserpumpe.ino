const int ledMessen = 9;
const int devSensorPower = 10;
const int devPumpePower = 12;
const int devSensorInput = 13;

void setup() {
  pinMode(devSensorInput, INPUT);
  pinMode(devPumpePower, OUTPUT);
  pinMode(devSensorPower, OUTPUT);
  pinMode(ledMessen, OUTPUT);
}

void loop() {
  digitalWrite(ledMessen, HIGH); 
  digitalWrite(devSensorPower, HIGH); // Sensor starten
  delay(1000);

  while(digitalRead(devSensorInput) == 1){
    digitalWrite(devPumpePower, HIGH);
    delay(4000);  
    digitalWrite(devPumpePower, LOW);
    delay(10000);
  }

  digitalWrite(ledMessen, LOW);
  digitalWrite(devSensorPower, LOW); // Sensor ausschalten
  delay(900000); 
}
