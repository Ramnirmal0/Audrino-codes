int k;
int i;
int RMP = 10, RMN = 11, LMP = 7, LMN = 6;
void setup()

{
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       pinMode(1, OUTPUT);
   pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(14, INPUT);
  Serial.begin(9600);

}

void loop() {

remote();
  if (k ==2) // forward
  {
  Serial.println("moving forward " );
      //forward motion

      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);

  }
 
  else if (k ==4 ) // left
  {
     Serial.println("moving left" );
      //LEFT MOTION
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);

  }
 
  else if (k ==6 ) // right
  {
    Serial.println("moving Right " );
      //RIGHT MOTION
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);

  }
 
  else if (k ==8 ) // backward
  {
  Serial.println("moving backword" );
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);

  }

  else if (k ==5 ) // stop
  {
    Serial.println("moving Right " );
      //RIGHT MOTION
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, LOW);

  }
  
}
void remote()
{
 k = 1;
  if (pulseIn(14, LOW) > 2200)
  {
    for (int i = 0; i < 7; i++)
    {
      if (pulseIn(14, LOW) > 1000)
      {
        k = k + (1 << i);
      }
    }
    Serial.println(k);

  }
}



