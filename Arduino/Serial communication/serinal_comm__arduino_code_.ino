#include<SoftwareSerial.h>
SoftwareSerial SUART(2, 3); //SRX=Dpin-2; STX-DPin-3
void setup()
{
  Serial.begin(115200); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
}
void loop()
{
  SUART.print(9);  // transmitting data 9 to esp8266
  delay(1000);
}
