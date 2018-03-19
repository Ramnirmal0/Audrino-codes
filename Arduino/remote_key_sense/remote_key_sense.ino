void setup()

{
  for (int i = 8; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
  int k = 1;



  if (pulseIn(7, LOW) > 2200)
  {
    for (int i = 0; i < 7; i++)
    {
      if (pulseIn(7, LOW) > 1000)
      {
        k = k + (1 << i);
      }
    }
    Serial.println(k);
    if (k == 2)
    {
      digitalWrite(8, HIGH);

    }
    else if (k == 3)
    {
      digitalWrite(8, LOW);

    }
    else if (k == 4 )
    {
      digitalWrite(9, HIGH);

    }
    else if (k == 5 )
    {
      digitalWrite(9, LOW);


    }
    else if (k == 6 )
    {
      digitalWrite(10, HIGH);

    }
    else if (k == 7 )
    {
      digitalWrite(10, LOW);


    }
    else if (k == 8 )
    {
      digitalWrite(11, HIGH);

    }
    else if (k == 9 )
    {
      digitalWrite(11, LOW);


    }
  }
}


