#include <Servo.h>
Servo door;

int trigger = 3;
int echo = 4;
void setup() {
  for(int i=8;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }
  door.attach(6);  
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(trigger, OUTPUT);      // triggger is output
  pinMode(echo, INPUT);           // echo is input
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x = pulseIn(echo, HIGH);
  int y=x/(29*2);
  Serial.print("  cm ");
  Serial.println(y);
if(y<20)
 {
  for(int i=8;i<12;i++)
  {
    digitalWrite(i,HIGH);
  } 
  door.write(90);
  

 
 }
 else
 {
   for(int i=8;i<12;i++)
  {
    digitalWrite(i,LOW);
  }
  door.write(0);
   
  
 }
}
