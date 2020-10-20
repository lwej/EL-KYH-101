int b = 3;
int g = 5;
int y = 7;
int w = 9;
int r = 11;

void setup() {
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(w, OUTPUT);
  pinMode(r, OUTPUT);  
}

void loop() {
  // PÅ
  digitalWrite(b, HIGH);
  delay(1000);
  digitalWrite(g, HIGH);
  delay(1500);
  digitalWrite(y, HIGH);
  delay(2000);
  digitalWrite(w, HIGH);
  delay(2500);
  digitalWrite(r, HIGH);
  delay(3000);
  // AV
  digitalWrite(r, LOW);
  delay(1000);
  digitalWrite(w, LOW);
  delay(1500);
  digitalWrite(y, LOW);
  delay(2000);
  digitalWrite(g, LOW);
  delay(2500);
  digitalWrite(b, LOW);
  delay(3000);
}
