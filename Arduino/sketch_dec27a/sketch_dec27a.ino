void setup() {
  for (int i = 4; i < 8; i++)
    pinMode(i, OUTPUT);
}
void loop() {
  for (int i = 4; i < 8; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}
