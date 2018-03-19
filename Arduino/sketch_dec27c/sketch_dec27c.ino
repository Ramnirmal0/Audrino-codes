#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  for(int i=4;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop() {
 
 int x=analogRead(A0);
 Serial.println(x);
 lcd.setCursor(7,0);
 lcd.print(x);
 if(x<100)
 {
 digitalWrite(4,HIGH);
 delay(300);
 }
 if(x<300)
 {
 digitalWrite(5,HIGH);
 delay(300);
 }
 if(x<600)
 {
 digitalWrite(6,HIGH);
 delay(300);
 }
 if(x<1000)
 {
 digitalWrite(7,HIGH);
 delay(300);
 }
  
}
