#include <Servo.h>
Servo arm_finger;
Servo arm_palm;
Servo arm_wrist;
Servo arm_elbow;

int elbow_up_val = 0;
int elbow_down_val = 100;
int wrist_left_val = 0;
int wrist_right_val = 100;
int palm_up_val = 0;
int palm_down_val = 100;
int finger_open_val = 0;
int finger_close_val = 100;


void elbow_up()
{
  Serial.println("Elbow up command");
  arm_elbow.write(elbow_up_val);
}
void elbow_down()
{
  Serial.println("elbow down command");
  arm_elbow.write(elbow_down_val);
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

void setup() {
  Serial.begin(9600);
  arm_finger.attach(7);
  arm_palm.attach(6);
  arm_wrist.attach(5);
  arm_elbow.attach(4);
}

void loop() {
  if (Serial.available())
  {
    char c = Serial.read();
    if (c == '+')
    {
      elbow_up();
    }
    if (c == '-')
    {
      elbow_down();
    }
    if (c == '4')
    {
      wrist_left();
    }
    if (c == '6')
    {
      wrist_right();
    }
    if (c == '8')
    {
      palm_up();
    }
    if (c == '2')
    {
      palm_down();
    }
    if (c == '5')
    {
      finger_open();
    }
    if (c == '0')
    {
      finger_close();
    }
  }
}
