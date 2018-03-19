int i;
int RMP = 10, RMN = 11, LMP = 7, LMN = 6;
void setup() {
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(LMP, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  if (Serial.available())
  {
    char c = Serial.read();
    if (c == 'f' || c == 'F')
    {
      Serial.println("moving forward for 5 second" );
      //forward motion

      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);
      delay(5000);
    }
    else if (c == 'b' || c == 'B')
    {
      //BACKWORD MOTION
      Serial.println("moving backword for 5 second" );
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);
      delay(5000);
    }
    else if (c == 'l' || c == 'L')
    {
      Serial.println("moving left for 5 second" );
      //LEFT MOTION
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);
      delay(5000);


    }
    else if (c == 'r' || c == 'R')
    {
      Serial.println("moving Right for 5 second" );
      //RIGHT MOTION
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);
      delay(5000);
    }
  }
}
