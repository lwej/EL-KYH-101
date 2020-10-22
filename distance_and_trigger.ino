// Define pins and baud rate

const unsigned int tPin = 13;
const unsigned int ePin = 12;
const unsigned int baudRate  = 9600;

const int PIR = 2;

long cm = 0.0;
long base = 0.0;

void printState(long cm) {
  if (cm >= base) {
    Serial.println("Mailbox is empty!");
  } else if (cm < base){
    Serial.println("YOU'VE GOT MAIL!");
  }
}

long readDistance() {
  // Trigger pin set as output to clear it from any leftovers
  pinMode(tPin, OUTPUT);
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  pinMode(ePin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(ePin, HIGH);
}

long setBaseDistance() {
  const unsigned long baseDistance =  0.01723 * readDistance();
  return baseDistance;
}

void setup()
{
  // This enables Serial.print()
  Serial.begin(9600);
  base = setBaseDistance();
  // Print base distance
  Serial.println("Base distance is: ");
  Serial.print(base);
  delay(2000);
}

void loop()
{
  int pirStatus = digitalRead(PIR);
  Serial.println(statusSensor);

  while (pirStatus == 1) {
    cm = 0.01723 * readDistance();
    Serial.println(cm);
    printState(cm);
    delay(100);
    pirStatus = digitalRead(PIR);
  }

}
