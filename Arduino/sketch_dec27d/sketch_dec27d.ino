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
  int x=analogRead(A0);
  Serial.println(x);

if(x<180)
{
    Serial.println(x);
    if (digitalRead(8) == HIGH) {
    for (int i= 4; i < 8; i++)
    {
      Serial.println(x);
      Serial.print("low voltage ");
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
else if(x>260)
{
  Serial.println(x);
    if (digitalRead(8) == HIGH) {
     for (int i= 4; i < 8; i++)
    {
      Serial.print("High voltage ");
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

else
{
  Serial.println(x);
    if (digitalRead(8) == HIGH) {
    for (int i= 4; i < 8; i++)
    {
      Serial.println(x);
      Serial.print("Safe Voltage ");
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
}

