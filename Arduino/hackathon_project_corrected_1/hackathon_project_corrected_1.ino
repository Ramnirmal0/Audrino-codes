float value;
float sensor;
const float vpp = 0.0048875855327468;
float r1 = 30000;
float r2 = 7500;
float voltage;   // for volatge
float current;  // for current
float credit;    // for credit unchanged
float power;    // for power
float unit;    // for unit of current recieved
int myclock;   // check measure time at which circuit was in on stages.
float check;   // check wheather the credit is getting over.
float addcredit;   // add up the credit when check conditon pass as fixed constant over the range.
int light = 13; // pinmode of light systems is 13

void printbill(float cp, float vp , float pp , float up)
// printing the original bill
{
  float originalcurrent = cp;
  Serial.println("The current consumed [realtime] : ");
  Serial.print(originalcurrent);  
  float originalvoltage = vp;
  Serial.println("The voltage consumed [realtime] : ");
  Serial.print(originalvoltage);
  float originalpower = pp;
   Serial.println("The power consumed [realtime] : ");
  Serial.print(originalpower);
  float originalunit = up;
   Serial.println("The unit consumed [realtime] : ");
  Serial.print(originalunit);
}
void storetemp(float c, float v, float p , float u )
{
  //storing my temporary value of bill
  float tempcurrent = c;
  float tempvoltage = v;
  float temppower = p;
  float tempunit = u;
}
void setup() {
  pinMode(light, OUTPUT);
  Serial.begin(9600);
  Serial.println(" Welcome to the Online Payment Platform \n Enter the amount you want to spend for electricity : ");
  credit = Serial.read();
  Serial.println("Your maximum amount to spend on electricity is set as:\n Rs  ");
  Serial.print(credit);

}

void loop() {
  if (Serial.available())
  {
    char s = Serial.read();
    if (s == 'a')
    {
      digitalWrite(light, HIGH);
      myclock = myclock + 1;
      value = analogRead(A0);  // for current
      sensor = analogRead(A1);  // for voltage
      value = value - 515 ;
      voltage = value * vpp;
      current = (voltage / 0.066) + 13.48;  //current readings
      float readvoltage = (5.0 * sensor * (r1 + r2)) / (1024.0 * r2); //voltage readings
      power=readvoltage*current; // read power consumption of a module
      unit=(power*myclock)/(1000*3600); // unit readings
      storetemp(current,readvoltage,power,unit);
      delay(1000);
      printbill(current,readvoltage,power,unit);
      }
      else if(s=='b')
      {
        digitalWrite(light,LOW);
      }
  }
}

