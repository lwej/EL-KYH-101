#include "Adafruit_FONA.h"

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED ON
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED  OFF
  delay(1000);              // wait for a second
}
