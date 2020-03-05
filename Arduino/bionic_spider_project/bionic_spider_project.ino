#include<Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
int trigger = 7;
int echo = 8;
int angle1 = 179;
int angle2 = 0;
int angle;
int limit = 100;
void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  s1.attach(6);
  s2.attach(5);
  s3.attach(4);
  s4.attach(3);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x = pulseIn(echo, HIGH);
  int y = x / (29 * 2);
  Serial.print("  cm ");
  Serial.println(y);
  delay(1000);
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
    Serial.println(k);  // Infrared emitter signal value
  }
  switch (k)
  {
    case 1 :
      {
        if (y < limit) {
          forward();
          break;
        }
      }
    case 2:
      {
        if (y < limit) {
          backward();
          break;
        }
      }
    case 3:
      {
        if (y < limit) {
          right();
          break;
        }
      }
    case 4:
      {
        if (y < limit) {
          left();
          break;
        }
      }
    case 5:
      {
        break;
      }
    default : Serial.println("The Signal is bad. Please check your connection ");

  }
}

void forward()
{
  s1.write(angle);
  s2.write(angle);
  s3.write(angle);
  s4.write(angle);
}

void backward()
{
  s1.write(angle);
  s2.write(angle);
  s3.write(angle);
  s4.write(angle);
}

void right()
{
  s1.write(angle);
  s2.write(angle);
  s3.write(angle);
  s4.write(angle);
}


void left()
{
  s1.write(angle);
  s2.write(angle);
  s3.write(angle);
  s4.write(angle);
}
