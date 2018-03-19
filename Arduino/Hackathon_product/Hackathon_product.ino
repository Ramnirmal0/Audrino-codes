int value;
const float vpp = 0.0048875855327468;
float r1 = 30000;
float r2 = 7500;
float voltage;
float current;
float credit;
float power;
float unit;
int ontime;
void storetemp(float c,float v,float p ,float u )
{
  float tempcurrent =c;
  float tempvoltage=v;
  float temppower=p;
  float tempunit=u;
}
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available())
  {
    char s = Serial.read();
    credit = s; // getting my credit from user
    float check;
    float creditup = 0; // setting the initial value for credit to increment
    for (check = 0; check <= credit; check++)
    {
      value = analogRead(A0);
      int sensor = analogRead(A1);
      value = value - 515 ;
      voltage = value * vpp;
      current = (voltage / 0.066) + 13.48;   // read current value
      float readvoltage = (5.0 * sensor * (r1 + r2)) / (1024.0 * r2);   // read voltage value
      power=readvoltage*current; // read power consumption of a module
     
      
      

    }
  }
