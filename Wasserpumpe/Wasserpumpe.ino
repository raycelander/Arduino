const int devPumpeOutput = 12;
const int devSensorLedOutput = 13;
const int devSensorInput = 0;

void setup() {
  pinMode(devSensorInput, INPUT);
  pinMode(devPumpeOutput, OUTPUT);
  pinMode(devSensorLedOutput, OUTPUT);
}

void loop() {
  digitalWrite(devSensorLedOutput, HIGH); // Sensor starten
  delay(1000);

  while(analogRead(devSensorInput) < 310){
    digitalWrite(devPumpeOutput, HIGH);
    delay(4000);  
    digitalWrite(devPumpeOutput, LOW);
    delay(10000);
  }

  digitalWrite(devSensorLedOutput, LOW); // Sensor ausschalten
  delay(900000); 
}
