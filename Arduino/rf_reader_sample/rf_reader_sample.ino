// only connect rf reader transistor wire to reciver after uploading to board
char x[50];

int count;
void setup() {
  Serial.begin(9600);
 

}

void loop() {
  count=0;
   
  if(Serial.available())
  {
    for(int i=0;i<12;i++)
    {
      char y[]="10004A9624E8";
      x[i]=Serial.read();
      delay(10);
      Serial.print(x[i]);
      Serial.println(y[i]);
      
      if(x[i]==y[i])
      {
        count=count+1;
      }
    }
      
    
    Serial.println();
    if(count==12)
      {
       
        Serial.println("Access Granted ");
      }
      else if(count!=12)
      {
        Serial.println("Access Denied ");
      }
  }
}
  


