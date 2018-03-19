#include <Servo.h>
Servo myservo;  // any name can be choosen in case of " myservo"

void setup() {
myservo.attach(9);  

}

void loop() {
 myservo.write(179);
 delay(1000);
 myservo.write(0);
 delay(1000);

}
