
// Programed by pineapplem3.com . licenced under Open Source code licence. compiled & developed by : Nirmal Ram#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CommonSenseMetricSystem
//#define ImperialNonsenseSystem

#define trigPin 13
#define echoPin 12

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int trigger = 2;
int echo = 5;
void setup() {

  pinMode(trigger, OUTPUT);      // triggger is output
  pinMode(echo, INPUT);           // echo is input
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();  // clear the display before start
  Serial.begin(9600);
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
  delay(100);

  display.setCursor(22, 10);       //x,y coordinates
  display.setTextSize(3);         //size of the text
  display.setTextColor(WHITE);    //if you write BLACK it erases things
  display.println(y);      //print our variable
  display.setCursor(85, 10);      //set size,print the units (cm/in)
  display.setTextSize(3);
#ifdef CommonSenseMetricSystem//if theres#define CommonSenseMetricSystem
  display.println("cm");        //print "cm" in oled
#endif
#ifdef ImperialNonsenseSystem//if there´s#define ImperialNonsenseSystem
  display.println("in");       //print "in" in oled
#endif
  display.display();          //you need to actually display all that data
  delay(500);                 //wait!, human speed
  display.clearDisplay();
}
