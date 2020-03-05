#include "nRF24L01.h"
#include "RF24.h"
const int nrf_csn = 9;
const int nrf_mosi = 10;
const int nrf_ce = 11;
const int nrf_sck = 12;
const int nrf_miso = 13;
RF24 radio(nrf_ce, nrf_csn); // CE, CSN
const byte address[6] = "00001";
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop()
{
  if (Serial.available())
  {
    char s = Serial.read();
    Serial.print("Transmit command :\t");
    Serial.print(s);
    switch (s)
    {
      case 'f' : {
          const char text[] = "f";
          radio.write(&text, sizeof(text)); Serial.println("Cheat code confirmed : brake ");
        } break;
      case 'w' : {
          const char text[] = "w";
          radio.write(&text, sizeof(text)); Serial.println("Cheat code confirmed : forward ");
        } break ;
      case 'a' : {
          const char text[] = "a";
          radio.write(&text, sizeof(text)); Serial.println("Cheat code confirmed : left ");
        } break ;
      case 'd' : {
          const char text[] = "d";
          radio.write(&text, sizeof(text)); Serial.println("Cheat code confirmed : right ");
        } break ;
      case 's' : {
          const char text[] = "s";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : reverse ");
        } break ;
      case 'q' : {
          const char text[] = "q";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : wheel left  ");
        } break;
      case 'e' : {
          const char text[] = "e";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : wheel right ");
        } break;
      case '9' : {
          const char text[] = "9";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : elbow up ");
        } break;
      case '3' : {
          const char text[] = "3";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : elbow down  ");
        } break;
      case '4' : {
          const char text[] = "4";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : wrist left ");
        } break;
      case '6' : {
          const char text[] = "6";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : wrist right ");
        } break;
      case '8' : {
          const char text[] = "8";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : palm up ");
        } break;
      case '2' : {
          const char text[] = "2";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : palm down ");
        } break;
      case '0' : {
          const char text[] = "0";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : finger open ");
        } break;
      case '1' : {
          const char text[] = "1";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : finger close ");
        } break;
      case 'p' : {
          const char text[] = "p";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : front actuator up  ");
        } break;
      case 'l' : {
          const char text[] = "l";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : front actuator down ");
        } break;
      case 'o' : {
          const char text[] = "o";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : side actuator up ");
        } break;
      case 'k' : {
          const char text[] = "k";
          radio.write(&text, sizeof(text));Serial.println("Cheat code confirmed : side actuator down ");
        } break;
    }
  }
}
