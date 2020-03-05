/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
        == Node 02 (Child of Master node 00) ==
*/
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define led 5
RF24 radio(8, 0);              // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format
// create servo object to control a servo
void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);   // (servo pin)
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    if (header.from_node == 1) {    // If data comes from Node 02
      digitalWrite(led, HIGH); // tell servo to go to a particular angle
    }
    if (header.from_node == 0) {    // If data comes from Node 02
      digitalWrite(led, LOW); // tell servo to go to a particular angle
    }

  }
}
