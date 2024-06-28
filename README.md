# spikeESP
Small projects to spike specific functionalities on ESP32


# Detect shorted pins

Detect which pins are connected and set the firmware to a different mode, depending on which GPIO pins are shorted. 

## Pin Configuration:
Configure some of the GPIO pins as outputs and others as inputs with internal pull-ups or pull-downs.

## Detection Logic:
* Set an output pin to a known state (HIGH or LOW).
* Read the state of the input pins.
* If an input pin reads the same state as the output pin, it indicates a connection between those pins.
  
1. Pin Definitions:
OUTPUT_PIN1 and OUTPUT_PIN2 are configured as output pins.<br>
INPUT_PIN1 and INPUT_PIN2 are configured as input pins with pull-up resistors.<br>

2. Check Connections:
The function checkConnections() sets an output pin to a known state (LOW or HIGH).<br>
It then reads the corresponding input pin to determine if a connection (short-cut) exists.<br>
If the input pin reads the same state as the output pin, it indicates a connection.<br>
Based on the detected connections, the setFirmwareMode() function is called to change the firmware mode.<br>

3. Set Firmware Mode:
The setFirmwareMode() function sets the firmware mode based on the detected connections.<br>

