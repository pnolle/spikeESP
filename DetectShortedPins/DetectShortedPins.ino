#include <Arduino.h>

// Define the pins
#define OUTPUT_PIN1 2
#define OUTPUT_PIN2 4
#define INPUT_PIN1 5
#define INPUT_PIN2 18

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);

  // Configure output pins
  pinMode(OUTPUT_PIN1, OUTPUT);
  pinMode(OUTPUT_PIN2, OUTPUT);

  // Configure input pins with internal pull-up resistors
  pinMode(INPUT_PIN1, INPUT_PULLUP);
  pinMode(INPUT_PIN2, INPUT_PULLUP);

  // Check connections
  checkConnections();
}

void loop() {
  // Main loop can be empty if detection is done in setup
}

void checkConnections() {
  // Set OUTPUT_PIN1 to LOW and check INPUT_PIN1
  digitalWrite(OUTPUT_PIN1, LOW);
  delay(100); // Small delay to stabilize the signal
  bool isConnected = digitalRead(INPUT_PIN1) == LOW;
  if (isConnected) {
    Serial.println("Pin 5 is connected to Pin 2");
    // Set firmware mode accordingly
    setFirmwareMode(1);
  } else {
    Serial.println("Pin 5 is disconnected from Pin 2");
  }

  // Set OUTPUT_PIN2 to LOW and check INPUT_PIN2
  digitalWrite(OUTPUT_PIN2, LOW);
  delay(100);
  isConnected = digitalRead(INPUT_PIN2) == LOW;
  if (isConnected) {
    Serial.println("Pin 18 is connected to Pin 4");
    // Set firmware mode accordingly
    setFirmwareMode(2);
  } else {
    Serial.println("Pin 18 is disconnected from Pin 4");
  }
}

void setFirmwareMode(int mode) {
  switch (mode) {
    case 1:
      // Set mode 1
      Serial.println("Setting firmware to mode 1");
      break;
    case 2:
      // Set mode 2
      Serial.println("Setting firmware to mode 2");
      break;
    default:
      Serial.println("Unknown mode");
      break;
  }
}
