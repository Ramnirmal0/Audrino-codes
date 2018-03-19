int r[7];
void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (pulseIn(7, LOW) > 2200)
  {
    for (int i= 0; i < 7; i++)
    {
      r[i] = pulseIn(7, LOW);
      Serial.print(r[i]);
      Serial.print("  ");
      

    }
Serial.println("         ");
delay(1000);
  }


}
