const int devWassersensor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(devWassersensor, INPUT);
}

void loop() {
  int val = analogRead(devWassersensor);
  Serial.println(val);
  delay(1000);
}
