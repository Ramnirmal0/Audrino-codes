void setup() {
  for (int i = 4; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  Serial.begin(9600);
}



void loop() {
  if (digitalRead(8) == HIGH) {
    for (int i= 4; i < 8; i++)
    {
      Serial.print("LED IS IN ON STAGE . PLEASE PLUGIN THE SWITCH TO OFF \n");
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
  }
  else if (digitalRead(8) == LOW)
  {
    for (int i= 4; i < 8; i++)
    {
   digitalWrite(i, LOW);
  }
}
}
