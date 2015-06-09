#include <SoftwareSerial.h>

SoftwareSerial dbgSerial(2, 3);

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(5000);
  dbgSerial.begin(9600); // for debuging
  dbgSerial.println("Init");
  Serial.println("AT+RST"); // restet and test if module is redy
  delay(1000);
  if (Serial.find("ready")) {
    dbgSerial.println("WiFi – Module is ready");
  } else {
    dbgSerial.println("Module dosn’t respond.");
    while (1);
  }
  delay(1000);
  // try to connect to wifi
  boolean connected = false;
  for (int i = 0; i < 5; i++) {
    if (connectWiFi()) {
      connected = true;
      dbgSerial.println("Connected to WiFi…");
      break;
    }
  }
  if (!connected) {
    dbgSerial.println("Coudn’t connect to WiFi.");
    while (1);
  }
  delay(5000);
  Serial.println("AT+CIPMUX=0"); // set to single connection mode

}

void loop() {
  // put your main code here, to run repeatedly:

  /* --------- TODO: Error handling ---------
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += DST_IP;
  cmd += "\",80";
  Serial.println(cmd);
  dbgSerial.println(cmd);
  if (Serial.find("Error")) return;
  */
  
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "50.23.219.162"; //airstate.firebaseio.com
  cmd += "\",80";
  dbgSerial.println(cmd);
  Serial.println(cmd);
  
  cmd = "GET /pom2.json";
  cmd += " HTTP/1.0\r\nHost: airstate.firebaseio.com\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if (Serial.find(">")) {
    dbgSerial.print(">");
  } else {
    Serial.println("AT+CIPCLOSE");
    dbgSerial.println("connection timeout");
    delay(1000);
    return;
  }
  dbgSerial.println(cmd);
  Serial.print(cmd);

  if (Serial.available()) {
    dbgSerial.println("connection ok");
    String json = Serial.readString();
    dbgSerial.println("received: " + json);
  }else{
    dbgSerial.println("connection error!");
  }
  delay(10000);
}

boolean connectWiFi()
{
  Serial.println("AT+CWMODE=1");
  String cmd = "AT+CWJAP=\"";
  cmd += "rayNet";
  cmd += "\",\"";
  cmd += "rton-hhw3-931b-o6c2";
  cmd += "\"";
  dbgSerial.println(cmd);
  Serial.println(cmd);
  delay(2000);
  if (Serial.find("OK")) {
    dbgSerial.println("OK, Connected to WiFi.");
    return true;
  } else {
    dbgSerial.println("Can not connect to the WiFi.");
    return false;
  }
}
