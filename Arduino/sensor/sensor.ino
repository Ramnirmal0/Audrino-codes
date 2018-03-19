void setup() {
  for (int i = 4; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}



void loop() {
  int x=analogRead(A0);
  Serial.println(x);
  if(x<100)
  {
    for(int i=4;i<8;i++)
    {
      digitalWrite(i,HIGH);
      digitalWrite(11,HIGH);  // buzzer if required
    }
  }
else
{
  for(int i=4;i<8;i++)
  {
  digitalWrite(i,LOW);
  digitalWrite(11,LOW);
}
}
}

