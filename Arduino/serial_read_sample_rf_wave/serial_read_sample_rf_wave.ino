char x[50];
char y[]="09009711C24D";
void setup() {
  Serial.begin(9600);
 

}

void loop() {
   
  if(Serial.available())
  {
    for(int i=0;i<12;i++)
    {
      x[i]=Serial.read();
      delay(10);
      Serial.print(x[i]);
      if(x[i]==y[i])
      {
        Serial.println("Access Granted ");
      }
      else
      {
        Serial.println("Access Denied ");
      }
    }
    Serial.println();
  }
  

}
