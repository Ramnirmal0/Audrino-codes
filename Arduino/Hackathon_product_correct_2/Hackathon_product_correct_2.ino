/*All right reserved © copyrighted code by bytecoders. Complied by Nirmalram @ Pineapplem3 Inc.
 * the code is open source you can make any changes according to your wish. This code only for
 * educational purpose. copying of this code in any means is strictly prohibited without prior
 * permission of developers.
 * 
 *powered by team bytecoders 



*/
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
float price;

void printbill(float cp, float vp , float pp , float up, float rs)
// printing the original bill
{
  Serial.println("======CONSUMPTION TABLE===========");
  float originalcurrent = cp;
  Serial.print(originalcurrent);
  Serial.println("   A   The current [realtime]  ");

  float originalvoltage = vp;
  Serial.print(originalvoltage);
  Serial.println("   V   The voltage  [realtime]  ");

  float originalpower = pp;
  Serial.print(originalpower);
  Serial.println("  W   The power consumed [realtime]  ");

  float originalunit = up;
  Serial.print(originalunit);
  Serial.println("  KWH   The unit consumed [realtime]  ");

  float originalrs = rs;
  Serial.print(originalrs);
  Serial.println("  Rs   The amount deducted [realtime]  ");
Serial.println("====================================");

Serial.println("");
}
void storetemp(float c, float v, float p , float u, float r )
{
  //storing my temporary value of bill
  float tempcurrent = c;
  float tempvoltage = v;
  float temppower = p;
  float tempunit = u;
  float temprs = r;
}
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter the amount you need to set as limit : ");


}

void loop() {
  if (Serial.available())
  {

    float s = Serial.read();
    credit = s;
    int  flag = 1;
    price = 3.10;
    if (credit != 0)
    {
      check = 0;
      while (check <= credit)
      {
        digitalWrite(13, HIGH);
        myclock = myclock + 1;
        current = analogRead(A0);  // for current
        current=current-510.50;
        voltage = analogRead(A1);  // for voltage
        power = current * voltage;
        unit = (power * myclock) / (1000 * 3600);
        printbill(current, voltage, power, unit, price);

        delay(10000);
        myclock = myclock + 4;
        if ((unit > 0) && (unit < 51))
        {

          price = 3.10;
          Serial.println("price is " );
          Serial.println(price);
          printbill(current, voltage, power, unit, price);
          if (flag == 1)
          {
            credit = credit - 3.10;
            flag = 0;
          }
          else if ((unit > 51) && (unit < 101))
          {
            price = 4.10;
            Serial.println("price is " );
            Serial.println(price);
            printbill(current, voltage, power, unit, price);
            if (flag == 1)
            {
              credit = credit - 1;
              flag = 0;
            }
          }
          else if ((unit > 101) && (unit < 201))
          {
            price = 4.80;
            Serial.println("price is ");
            Serial.println(price);
            printbill(current, voltage, power, unit, price);
            if (flag == 1)
            {
              credit = credit - 0.7;
              flag = 0;
            }

          }

          else if ((unit > 200) && (unit < 301))
          {
            price = 6.80 + .01;
            Serial.println("price is ");
            Serial.println(price);
            credit = credit - 1.7;
            printbill(current, voltage, power, unit, price);

          }

        }

      }
    }

    else
    {
      digitalWrite(light, LOW);
    }
  }
}





