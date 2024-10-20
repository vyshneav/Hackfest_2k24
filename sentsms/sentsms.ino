void setup() {
  // Start serial communication with the Serial Monitor
  Serial.begin(115200);  // Baud rate for Serial Monitor

  // Initialize serial communication with the GSM module
  Serial1.begin(115200);  // Baud rate for GSM module (make sure it matches the module's settings)
  
  // Allow some time for the GSM module to initialize
  delay(1000);

  // Configure GSM module to send SMS notifications
  Serial1.println("AT");  // Check if GSM module is responsive
  delay(1000);

  // Set GSM module to text mode for SMS
  Serial1.println("AT+CMGF=1");
  delay(1000);

  // Configure GSM module to show SMS notifications
  Serial1.println("AT+CNMI=2,1,0,0,0");
  delay(1000);
}

void loop() {
  // Check if there is data available from the GSM module
  if (Serial1.available()) {
    // Read and forward the data from GSM module to Serial Monitor
    while (Serial1.available()) {
      char c = Serial1.read();
      Serial.write(c);
    }
  }

  // Optional: Check if there is data available from Serial Monitor to send to GSM
  // if (Serial.available()) {
  //   Serial1.write(Serial.read());
  // }
}
