#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial wifi(2, 3); // RX, TX
String GET = "GET /?pom=Buro&temp=24&hum=70  HTTP/1.0\r\nHost: fireproxy.azurewebsites.net\r\n\r\n";
String IP = "191.233.85.165";
String SSID = "SSID";
String PW = "xton-hhw3-931b-o6c2";

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(5000);

  lcd.begin(20, 4);

  lcdPrint("Resetting module...");
  Serial.println("AT+RST"); // reset and test if module is ready
  Serial.flush();
  delay(1000);

  if (Serial.find("OK")) {
    lcdPrint("Module ready");
  } else {
    lcdPrint("Module not ready");
    return;
  }

  lcdPrint("connecting wifi");
  delay(1000);
  boolean connected = false;
  for (int i = 0; i < 5; i++) {
    if (connectWiFi()) {
      connected = true;
      lcdPrint("Connected to WiFi…");
      break;
    }
  }
  if (!connected) {
    lcdPrint("could not connect to WiFi…");
    return;
  }
  delay(1000);
  sendDatas();
}

void loop() { }

boolean connectWiFi() {
  Serial.println("AT+CWMODE=1");
  Serial.flush();
  delay(1000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PW;
  cmd += "\"";
  Serial.println(cmd);
  Serial.flush();
  delay(1000);
  if (Serial.find("OK")) {
    return true;
  } else {
    return false;
  }
}

boolean sendDatas() {
  Serial.println("AT+CIPMUX=1"); // set to multi connection mode
  Serial.flush();
  if ( Serial.find( "Error")) {
    lcdPrint( "Err connection" );
    return false;
  }

  String cmd = "AT+CIPSTART=4,\"TCP\",\"" + IP + "\",80";
  Serial.println(cmd);
  Serial.flush();
  if (Serial.find("OK")) {
    lcdPrint("connection open");
    delay(1000);
  }
  cmd = GET;
  Serial.println("AT+CIPSEND=4,78");
  Serial.flush();
  if (Serial.find(">")) {
    lcdPrint("ready");
    Serial.print(cmd);
    Serial.flush();
    delay(10);

    int i = 0;
    while (Serial.available()) {
      String line = Serial.readStringUntil('\r');
      lcdPrintLine(line,i,0);
      delay(1000);
      i++;
      if (i == 4){
        i = 0;
      }
    }

      
    if (Serial.find("GET")) {
      lcdPrint("datas received");
      /*
      String content = "";
      char character;

      while (Serial.available()) {
        character = Serial.read();
        content.concat(character);
      }

      if (content != "") {
        lcdPrint(content);
      }
      delay(5000);
*/
    } else {
      lcdPrint("datas not received");
    }
  } else {
    lcdPrint("Connection timeout!");
    return false;
  }
  return true;
}

void lcdPrint(String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
}
void lcdPrintLine(String msg, int line, int row) {
  lcd.setCursor(row, line);
  lcd.print(msg);
}


