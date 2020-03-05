int eng1_in1 = 13;
int eng1_in2 = 12;
int eng1_in3 = 11;
int eng1_in4 = 10;

int eng2_in1 = 9;
int eng2_in2 = 8;
int eng2_in3 = 7;
int eng2_in4 = 6;

int eng3_in1 = 5;
int eng3_in2 = 4;
int eng3_in3 = 3;
int eng3_in4 = 2;

int eng4_in1 = 23;
int eng4_in2 = 25;
int eng4_in3 = 27;
int eng4_in4 = 29;

void setup() {

  Serial.begin(9600);

}
void forward()
{

  Serial.println("Forward command");
  digitalWrite(eng1_in1, HIGH);
  digitalWrite(eng1_in2, LOW);
  digitalWrite(eng1_in3, LOW);
  digitalWrite(eng1_in4, HIGH);

  digitalWrite(eng2_in1, HIGH);
  digitalWrite(eng2_in2, LOW);
  digitalWrite(eng2_in3, LOW);
  digitalWrite(eng2_in4, HIGH);

  digitalWrite(eng3_in1, HIGH);
  digitalWrite(eng3_in2, LOW);
  digitalWrite(eng3_in3, LOW);
  digitalWrite(eng3_in4, HIGH);
}

void reverse()
{

  Serial.println("Reverse command");
  digitalWrite(eng1_in1, HIGH);
  digitalWrite(eng1_in2, LOW);
  digitalWrite(eng1_in3, LOW);
  digitalWrite(eng1_in4, HIGH);

  digitalWrite(eng2_in1, HIGH);
  digitalWrite(eng2_in2, LOW);
  digitalWrite(eng2_in3, LOW);
  digitalWrite(eng2_in4, HIGH);

  digitalWrite(eng3_in1, HIGH);
  digitalWrite(eng3_in2, LOW);
  digitalWrite(eng3_in3, LOW);
  digitalWrite(eng3_in4, HIGH);
}

void left()
{

  Serial.println("left command");
  digitalWrite(eng1_in1, HIGH);
  digitalWrite(eng1_in2, LOW);
  digitalWrite(eng1_in3, LOW);
  digitalWrite(eng1_in4, HIGH);

  digitalWrite(eng2_in1, HIGH);
  digitalWrite(eng2_in2, LOW);
  digitalWrite(eng2_in3, LOW);
  digitalWrite(eng2_in4, HIGH);

  digitalWrite(eng3_in1, HIGH);
  digitalWrite(eng3_in2, LOW);
  digitalWrite(eng3_in3, LOW);
  digitalWrite(eng3_in4, HIGH);
}

void right()
{

  Serial.println("Right command");
  digitalWrite(eng1_in1, HIGH);
  digitalWrite(eng1_in2, LOW);
  digitalWrite(eng1_in3, LOW);
  digitalWrite(eng1_in4, HIGH);

  digitalWrite(eng2_in1, HIGH);
  digitalWrite(eng2_in2, LOW);
  digitalWrite(eng2_in3, LOW);
  digitalWrite(eng2_in4, HIGH);

  digitalWrite(eng3_in1, HIGH);
  digitalWrite(eng3_in2, LOW);
  digitalWrite(eng3_in3, LOW);
  digitalWrite(eng3_in4, HIGH);
}

void brake()
{

  Serial.println("Brake command");
  digitalWrite(eng1_in1, LOW);
  digitalWrite(eng1_in2, LOW);
  digitalWrite(eng1_in3, LOW);
  digitalWrite(eng1_in4, LOW);

  digitalWrite(eng2_in1, LOW);
  digitalWrite(eng2_in2, LOW);
  digitalWrite(eng2_in3, LOW);
  digitalWrite(eng2_in4, LOW);

  digitalWrite(eng3_in1, LOW);
  digitalWrite(eng3_in2, LOW);
  digitalWrite(eng3_in3, LOW);
  digitalWrite(eng3_in4, LOW);
}

void loop() {
  if (Serial.available())
  {
    char c = Serial.read();
    switch (c)
    {
      case 'w' : forward(); break;
      case 's' : reverse(); break;
      case 'a' : left(); break;
      case 'd' : right(); break;
      case 'f' : brake(); break;

      default: Serial.println("Wrong command");

    }
  }
}
