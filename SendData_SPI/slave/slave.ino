#include <SPI.h>

volatile bool dataReceived = false;
String receivedData = "";

void setup() {
  Serial.begin(115200);
  pinMode(SS, INPUT_PULLUP);  // Ensure SS (CS) pin is high initially
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);

  attachInterrupt(digitalPinToInterrupt(SS), onCSLOW, FALLING);
}

void loop() {
  if (dataReceived) {
    Serial.println("Received: " + receivedData);
    dataReceived = false;
    receivedData = "";
  }
}

void onCSLOW() {
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  while (digitalRead(SS) == LOW) {
    char c = SPI.transfer(0);  // Send dummy byte to receive data
    if (c != '\0') {  // Check for null terminator
      receivedData += c;
      Serial.print(c);  // Debugging: Print each received character
    } else {
      break;
    }
  }

  SPI.endTransaction();
  dataReceived = true;
  Serial.println();  // Debugging: Print a newline after the message is received
}
