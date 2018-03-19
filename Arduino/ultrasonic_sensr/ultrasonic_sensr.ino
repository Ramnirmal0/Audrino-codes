int trigger = 3;
int echo = 4;
void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(trigger, OUTPUT);      // triggger is output
  pinMode(echo, INPUT);           // echo is input
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x = pulseIn(echo, HIGH);
  int y=x/(29*2);
  Serial.print("  cm ");
  Serial.println(y);
  digitalWrite(11,HIGH);
delay(y);
digitalWrite(11,LOW);
delay(100);
  
}
