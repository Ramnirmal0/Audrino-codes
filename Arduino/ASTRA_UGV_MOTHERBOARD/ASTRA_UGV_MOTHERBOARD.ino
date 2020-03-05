#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h>
#include <LiquidCrystal.h>
Servo arm_finger;
Servo arm_palm;
Servo arm_wrist;
Servo arm_elbow;
/*define dict=
      {{'#A1B3':'w'}},
      '#[A-C:0-9:A-C:0-9]' : 'a',
      '#[A-C:0-9:A-C:0-9]' : 'd',
      '#[A-C:0-9:A-C:0-9]' : 's',
      '#[A-C:0-9:A-C:0-9]' : '+',
      '#[A-C:0-9:A-C:0-9]' : '-',
      '#[A-C:0-9:A-C:0-9]' : '(',
      '#[A-C:0-9:A-C:0-9]' : ')',
      '#[A-C:0-9:A-C:0-9]' : '8',
      '#[A-C:0-9:A-C:0-9]' : '2',
      '#[A-C:0-9:A-C:0-9]' : '4',
      '#[A-C:0-9:A-C:0-9]' : '6',
      '#[A-C:0-9:A-C:0-9]' : '5',
      '#[A-C:0-9:A-C:0-9]' : 'l',
      '#[A-C:0-9:A-C:0-9]' : 'r',
      '#[A-C:0-9:A-C:0-9]' : 'f',
      '#[A-C:0-9:A-C:0-9]' : 'r',
      '#[A-C:0-9:A-C:0-9]' : 'b',
      '#[A-C:0-9:A-C:0-9]' : '*',
      '#[A-C:0-9:A-C:0-9]' : '/',
      '#[A-C:0-9:A-C:0-9]' : 'k',}*/
int max_bomb_value;
int min_bomb_value;
int alert_level[1] = {0};
int us1_max;
int us2_max;
int us3_max;
char temp_storage;

const int elbow_up_val = 0;
const int elbow_down_val = 100;
const int wrist_left_val = 0;
const int wrist_right_val = 100;
const int palm_up_val = 0;
const int palm_down_val = 100;
const int finger_open_val = 0;
const int finger_close_val = 100;


// int wiring schemematics

const int eng1_in1 = 13;
const int eng1_in2 = 12;
const int eng1_in3 = 11;
const int eng1_in4 = 10;

const int eng2_in1 = 9;
const int eng2_in2 = 8;
const int eng2_in3 = 7;
const int eng2_in4 = 6;

const int eng3_in1 = 5;
const int eng3_in2 = 4;
const int eng3_in3 = 3;
const int eng3_in4 = 2;

const int eng4_in1 = 23;
const int eng4_in2 = 25;
const int eng4_in3 = 27;
const int eng4_in4 = 29;

const int nrf_csn = 53;
const int nrf_mosi = 51;
const int nrf_ce = 49;
const int nrf_sck = 47;
const int nrf_miso = 45;

const int us1_echo = 52;
const int us1_trigger = 50;

const int us2_echo = 48;
const int us2_trigger = 46;

const int us3_echo = 44;
const int us3_trigger = 42;

const int esp_suart_tx = 14;
const int esp_suart_rx = 15;

const int display_d7 = 40;
const int display_d6 = 38;
const int display_d5 = 36;
const int display_d4 = 34;
const int display_e = 32;
const int display_rs = 30;

LiquidCrystal lcd(display_rs, display_e, display_d4, display_d5, display_d6, display_d7);
RF24 radio(nrf_ce, nrf_csn); // CE, CSN
const byte address[6] = "00001";
void forward()
{

  check_safe();
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
  check_safe();
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
  check_safe();
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
  check_safe();
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

void wheel_left()
{
  check_safe();
  Serial.println("wheel Left turn command");
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

void wheel_right()
{
  check_safe();
  Serial.println("wheel right turn command");
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

void front_actuator_down()
{
  alert_level[0] = 1;
  digitalWrite(eng4_in1, HIGH);
  digitalWrite(eng4_in2, LOW);
  digitalWrite(eng4_in3, LOW);
  digitalWrite(eng4_in4, HIGH);
}

void front_actuator_up()
{
  alert_level[0] = 1;
  digitalWrite(eng4_in1, HIGH);
  digitalWrite(eng4_in2, LOW);
  digitalWrite(eng4_in3, LOW);
  digitalWrite(eng4_in4, HIGH);
}

void side_actuator_down()
{
  alert_level[0] = 1;
  digitalWrite(eng4_in1, HIGH);
  digitalWrite(eng4_in2, LOW);
  digitalWrite(eng4_in3, LOW);
  digitalWrite(eng4_in4, HIGH);
}

void side_actuator_up()
{
  alert_level[0] = 1;
  digitalWrite(eng4_in1, HIGH);
  digitalWrite(eng4_in2, LOW);
  digitalWrite(eng4_in3, LOW);
  digitalWrite(eng4_in4, HIGH);
}

void setup() {
  //nrf settings
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  arm_finger.attach(31);
  arm_palm.attach(33);
  arm_wrist.attach(35);
  arm_elbow.attach(37);

  lcd.begin(16, 2);

}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("Received command :");
    Serial.println(text);
    temp_storage = text;
    switch (temp_storage)
    {
      case 'f' : brake(); break;
      case 'w' : forward(); break ;
      case 'a' : left(); break ;
      case 'd' : right(); break ;
      case 's' : reverse(); break ;
      case 'q' : wheel_left(); break;
      case 'e' : wheel_right(); break;
      case '9' : elbow_up(); break;
      case '3' : elbow_down(); break;
      case '4' : wrist_left(); break;
      case '6' : wrist_right(); break;
      case '8' : palm_up(); break;
      case '2' : palm_down(); break;
      case '0' : finger_open(); break;
      case '1' : finger_close(); break;
      case 'p' : front_actuator_up(); break;
      case 'l' : front_actuator_down(); break;
      case 'o' : side_actuator_up(); break;
      case 'k' : side_actuator_down(); break;
    }
  }
  else
  {
    auto_algorithms();
  }
}

void check_safe()
{
  if (alert_level[0] == 1)
  {
    // coil program
  }
}

void alert_protocol()
{

}

void lcd_display()
{
  lcd.setCursor(0, 1);
  lcd.print("auto comm mode");
}

void auto_algorithms()
{

}
