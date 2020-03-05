#include <Servo.h>
Servo arm_finger;
Servo arm_palm;
Servo arm_wrist;
Servo docker;

int docking_val = 0;
int undocking_val = 100;
int wrist_left_val = 0;
int wrist_right_val = 100;
int palm_up_val = 0;
int palm_down_val = 100;
int finger_open_val = 0;
int finger_close_val = 100;


int IN1 = 53 , IN2 = 51 , IN3 = 49 , IN4 = 47;  //L298N 1
int IN5 = 52 , IN6 = 50 , IN7 = 48 , IN8 = 46;  //L298N 2
int IN9 = 13 , IN10 = 12 , IN11 = 11 , IN12 = 10;  //L298N 3

void docking()
{
  Serial.println("Docking command");
  docker.write(docking_val);
}
void undocking()
{
  Serial.println("Undocking command");
  docker.write(undocking_val);
}
void wrist_left()
{
  Serial.println("wrist left command");
  arm_wrist.write(wrist_left_val);
}
void wrist_right()
{
  Serial.println("wrist down command");
  arm_wrist.write(wrist_right_val);
}
void palm_up()
{
  Serial.println("palm up command");
  arm_palm.write(palm_up_val);
}
void palm_down()
{
  Serial.println("palm down command");
  arm_palm.write(palm_down_val);
}
void finger_open()
{
  Serial.println("finger open command");
  arm_finger.write(finger_open_val);
}
void finger_close()
{
  Serial.println("finger down command");
  arm_finger.write(finger_close_val);
}

void backward() {
  Serial.println("backward command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, HIGH);
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
}
void forward() {
  Serial.println("Forward command" );
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);

  digitalWrite(IN9, HIGH);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
}
void right() {
  Serial.println("right command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, HIGH);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
}
void left()
{
  Serial.println("left command" );
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, HIGH);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
}
void stopme()
{
  Serial.println("stop command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, LOW);
}

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);

  arm_finger.attach(7);
  arm_palm.attach(6);
  arm_wrist.attach(5);
  docker.attach(4);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char s = Serial.read();

    if (s == 'W')
    {
      forward();
    }
    if (s == 'S')
    {
      backward();
    }
    if (s == 'A')
    {
      left();
    }
    if (s == 'D')
    {
      right();
    }
    if (s == 'X')
    {
      stopme();
    }
    if (s == '+')
    {
      docking();
    }
    if (s == '-')
    {
      undocking();
    }
    if (s == '4')
    {
      wrist_left();
    }
    if (s == '6')
    {
      wrist_right();
    }
    if (s == '8')
    {
      palm_up();
    }
    if (s == '2')
    {
      palm_down();
    }
    if (s == '5')
    {
      finger_open();
    }
    if (s == '0')
    {
      finger_close();
    }

  }
}
