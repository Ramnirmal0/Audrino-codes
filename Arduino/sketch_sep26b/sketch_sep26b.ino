void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);

Serial.begin(9600);
}

void loop() {
  digitalWrite(13,HIGH);
int sensorValue = analogRead(A0);
Serial.println(sensorValue);
delay(500);
}
