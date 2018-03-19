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
int x=analogRead(A0), y=analogRead(A1) ;
  
    
    if (x>400)
    {
      Serial.print(x);
      Serial.println("moving forward for 5 second" );
      //forward motion

      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);
      
    }
    else if (x<300)
    {
      //BACKWORD MOTION
      Serial.print(x);
      Serial.println("moving backword for 5 second" );
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);
      
    }
   else if (y<300)
    {
      Serial.print(y);
      Serial.println("moving left for 5 second" );
      //LEFT MOTION
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
      digitalWrite(LMP, HIGH);
      digitalWrite(LMN, LOW);
      


    }
    else if (y>400)
    {
      Serial.print(y);
      Serial.println("moving Right for 5 second" );
      //RIGHT MOTION
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
      digitalWrite(LMP, LOW);
      digitalWrite(LMN, HIGH);
      
    }
  
}
