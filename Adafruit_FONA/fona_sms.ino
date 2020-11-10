#include "Adafruit_FONA.h"
#include <SoftwareSerial.h>

#define FONA_RX 9
#define FONA_TX 8
#define FONA_RST 4
#define FONA_RI 7
 
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

char callerIDbuffer[32] = "0722600532";
 
void setup() { 
 
  // make it slow so its easy to read!
  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    while(1);
  }
}

void loop() {
  fona.sendSMS(callerIDbuffer, "heyhey 2");
      
 delay(60000); 
}
