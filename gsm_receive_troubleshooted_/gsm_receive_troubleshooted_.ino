
#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(3, 4); // RX, TX

void setup() {
  Serial.begin(115200);
  gsmSerial.begin(115200);
  Serial.println("GSM Module Ready");
  delay(2000);
  gsmSerial.print("AT+CMGF=1\r"); // Set SMS to text mode
  delay(2000);
  gsmSerial.print("AT+CNMI=2,2,0,0,0\r"); // Configure the module to send SMS data to serial out upon receipt
  delay(2000);
}

void loop() {
  if (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
  if (Serial.available()) {
    //gsmSerial.write(Serial.read());
  }
}
