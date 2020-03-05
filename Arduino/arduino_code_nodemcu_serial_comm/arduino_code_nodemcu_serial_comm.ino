#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s(3,1);

int data; //Initialized variable to store recieved data

void setup() {
  //Serial Begin at 9600 Baud 
  Serial.begin(9600);
  s.begin(9600);
}

void loop() {
  data = s.read(); //Read the serial data and store it
  delay(1000);
  Serial.println(data);
}
