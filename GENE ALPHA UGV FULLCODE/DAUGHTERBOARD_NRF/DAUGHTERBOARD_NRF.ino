/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
            == Node 012 (child of Node 02)==
*/
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define led 13
RF24 radio(7, 12);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 012;  // Address of our node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;    // Address of the other node in Octal format
void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long buttonState;
    network.read(header, &buttonState, sizeof(buttonState)); // Read the incoming data
    if (header.from_node == 2) {
      digitalWrite(led, HIGH);
    }// Turn on or off the LED
  }
  //===== Sending =====//
  unsigned long irV = 0;
  RF24NetworkHeader header8(node01);
  bool ok = network.write(header8, &irV, sizeof(irV)); // Send the data
}
