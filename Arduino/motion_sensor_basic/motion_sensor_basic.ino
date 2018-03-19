void setup() {
 Serial.begin(9600);
}

void loop() {
  int x=analogRead(A0), y=analogRead(A1) ;
  Serial.print("x= ");
  Serial.print(x);
  Serial.print("   y= ");
  Serial.print(y);
   
  Serial.println(" ");
delay(500);
  
 
}
