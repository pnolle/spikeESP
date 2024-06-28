#include <SPI.h>

const int CS_SLAVE_1 = 5;  // Chip Select pin for Slave 1
const int CS_SLAVE_2 = 18; // Chip Select pin for Slave 2

void setup() {
  Serial.begin(115200);
  SPI.begin();  // Initialize SPI

  pinMode(CS_SLAVE_1, OUTPUT);
  pinMode(CS_SLAVE_2, OUTPUT);

  digitalWrite(CS_SLAVE_1, HIGH); // Deselect Slave 1
  digitalWrite(CS_SLAVE_2, HIGH); // Deselect Slave 2
}

void loop() {
  sendToSlave(CS_SLAVE_1, "Hello Slave 1");
  delay(1000);
  sendToSlave(CS_SLAVE_2, "Hello Slave 2");
  delay(1000);
}

void sendToSlave(int csPin, const char* message) {
  digitalWrite(csPin, LOW); // Select the slave
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  for (size_t i = 0; i < strlen(message); i++) {
    SPI.transfer((uint8_t)message[i]);
  }

  SPI.transfer((uint8_t)'\0'); // Send null terminator to indicate end of message

  SPI.endTransaction();
  digitalWrite(csPin, HIGH); // Deselect the slave
}
