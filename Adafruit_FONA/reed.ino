#include "Adafruit_FONA.h"

#define FONA_RX  9
#define FONA_TX  8
#define FONA_RST 4
#define FONA_RI  7

int REED = 10;
int STATUS;
int BAUD = 9600;

void setup() {
pinMode(REED, INPUT);
Serial.begin(BAUD);
}

void loop() {
Serial.print("Reed status: ");
Serial.println(STATUS);
STATUS = digitalRead(REED);
delay(1000);
}
