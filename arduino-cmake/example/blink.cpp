#include "Arduino.h"
#include <SPI.h>
#include <blinkLib.h>


void setup() {                
    blink_setup(); // Setup for blinking
    Serial.begin(9600);
}

void loop() {
    blink(1000); // Blink for a second
}
