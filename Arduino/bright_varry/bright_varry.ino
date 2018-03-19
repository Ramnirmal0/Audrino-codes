int led=9;
void setup() {
 pinMode(9,OUTPUT);
}
void loop() {
  int x= analogRead(A0);
  analogWrite(led, x/4);
}
