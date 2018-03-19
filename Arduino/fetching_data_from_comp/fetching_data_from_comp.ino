void setup() {
  Serial.begin(9600);
  for (int i = 4; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if (Serial.available())
  {
    char c = Serial.read();
    Serial.println(c);
    if (c == 'a' || c =='A')
    {
      Serial.println("Light is on ");
      for (int i = 4; i < 8; i++)
      {
        digitalWrite(i, HIGH);
      }
    }
    else if (c == 'b' || c == 'B')
    {
      Serial.println("Light is off ");
      for (int i = 4; i < 8; i++)
      {
        digitalWrite(i, LOW);
      }
    }
  }



}
