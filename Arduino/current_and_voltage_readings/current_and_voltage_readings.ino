float voltage;
float current;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
current=analogRead(A0);
current=current-511;
voltage=analogRead(A1);
Serial.print(current);
Serial.println("          A current reading ");
delay(1000);
Serial.print(voltage);
Serial.println("          V voltage value");
delay(1000);
}
