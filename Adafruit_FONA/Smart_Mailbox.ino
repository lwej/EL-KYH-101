#include "Adafruit_FONA.h"

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

const int barrier = A0;
const int reed = 12;
int barrierValue = 0;
int reedValue = 0;

char userNumber[32] = "";

str message = "";
str battery = "";

bool MAIL = false;
bool EMPTY = false;

#define FONA_RX  9
#define FONA_TX  8
#define FONA_RST 4
#define FONA_RI  7


void setup() {
  // Define pins purpose
  pinMode(barrier, INPUT);
  pinMode(reed, INPUT);
  // Serial monitor for testing
  Serial.begin(9600);
}

void loop() {
  // Needs update with deepsleep later on
  barrierValue = analogRead(barrier);
  reedValue = digitalRead(reed);

  // Print barrierValue while we are testing
  Serial.println(barrierValue);

  // If barrier is broken
  if (barrierValue > 100 ) {
    MAIL = true;
    while (MAIL) {
      // Include Battery level
      battery = fona.getBattPercent();
      //fona_time = fona.getTime();
      message = ("You've got mail " + battery);

      //TEST first:
      Serial.println(message);
      //Serial.print(fona_time);
      //fona.sendSMS(userNumber, message);

      // Wait for 10 seconds then set MAIL to false
      delay(10000);
      MAIL = false;
    }
  }

  // If box-lid is opened
  if (reedValue == HIGH) {
    EMPTY = true;
    while (EMPTY) {
      message = "Your mailbox has been emptied";
      Serial.println(message);
      // Send sms that box has been emptied
      //fona.sendSMS(userNumber, message);
      // Wait for 1 minute
      delay(60000);
      EMPTY = false;
    }
  }

  // If SMS is received
  // ????
  if (fona.getSMSSender() == userNumber) {
    battery = fona.getBattPercent();
    message = "The battery level is: " + battery;
    Serial.println("User requests battery %");
    Serial.println(message);
    // Send battery sms
    // fona.sendSMS(userNumber, message);
    // Delete received sms
    //fona.deleteSMS();
  }
}
