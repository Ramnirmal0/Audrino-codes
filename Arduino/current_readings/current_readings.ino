int value;
const float vpp=0.0048875855327468;
float r1=30000;
float r2=7500;
float voltage;
float current;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(A0);
int sensor=analogRead(A1);
value=value-515 ;
voltage=value*vpp;
current=(voltage/0.066)+13.48;
float readvoltage=(5.0*sensor*(r1+r2))/(1024.0*r2);
Serial.println(value);
Serial.println("   A current reading ");
delay(1000);
Serial.println(readvoltage);
Serial.println("   V voltage value");
delay(1000);
}
