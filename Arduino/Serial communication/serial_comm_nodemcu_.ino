#include<SoftwareSerial.h>
SoftwareSerial SUART(4, 5);
void setup() {
  Serial.begin(115200); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
}
void loop()
{
  byte n = SUART.available(); //n != 0 means a character has arrived
  if (n != 0)
  {
    char x = SUART.read();  //read character
    Serial.print("Recieving data = \t");        //show character on Serial Monitor
    Serial.print(x);        //show character on Serial Monitor
    Serial.print("\n===============\n");
  }
}
