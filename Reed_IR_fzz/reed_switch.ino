int LED = 7;
int REED = 4;
int STATUS;
int BAUD = 9600;

void setup() {
pinMode(LED, OUTPUT);
pinMode(REED, INPUT);
Serial.begin(BAUD);
}

void loop() {
Serial.print("Reed status: ");
STATUS = digitalRead(REED);
Serial.println(STATUS);
if (STATUS == 1) {
  digitalWrite(LED, LOW);
  Serial.println(STATUS);
} else { digitalWrite(LED, HIGH);
}
delay(1000);
}
