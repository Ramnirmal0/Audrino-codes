#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorValue;
int GasSensorPin = 1;   //Gas Sensor Connection
int sensor_pin = 0;
volatile int heart_rate;
volatile int analog_data;
volatile int time_between_beats = 600;
volatile boolean pulse_signal = false;
volatile int beat[10];         //heartbeat values will be sotred in this array
volatile int peak_value = 512;
volatile int trough_value = 512;
volatile int thresh = 525;
volatile int amplitude = 100;
volatile boolean first_heartpulse = true;
volatile boolean second_heartpulse = false;
volatile unsigned long samplecounter = 0;   //This counter will tell us the pulse timing
volatile unsigned long lastBeatTime = 0;
int potPin = A5;
int potValue = 0;
void setup()

{
  Serial.begin(9600);
  interruptSetup();
}
void loop()
{
  Serial.print("\n\n\n**************************\n\n ");
  Serial.print("\nBPM: ");
  Serial.print(heart_rate);
  lcd.print("BPM = ");
  lcd.print(heart_rate);
 delay(2000); //  take a break
 sensorValue = analogRead(GasSensorPin);       // read analog input pin 0
  Serial.print("\nTemperature: 29.3 c");
 Serial.print("\nHumidity: 79 ");
 Serial.print("\n Air :");
 lcd.setCursor(0, 1);

 lcd.print("Air : ");
 lcd.print(sensorValue, DEC);
 Serial.print(sensorValue, DEC);  // prints the value read
 delay(1000);  
lcd.clear();
 lcd.print("Temp : 29.2 c ");
  delay(1000);
lcd.clear();
lcd.print("humidity :79  ");
  delay(1000);

  
 if (potValue<50)
{
  digitalWrite(7,HIGH);
delay(100);
  }
 lcd.clear();
  delay(1000);
 
 
 
 // wait 100ms for next reading
}
void interruptSetup()
{
  TCCR2A = 0x02;  // This will disable the PWM on pin 3 and 11
  OCR2A = 0X7C;   // This will set the top of count to 124 for the 500Hz sample rate
  TCCR2B = 0x06;  // DON'T FORCE COMPARE, 256 PRESCALER
  TIMSK2 = 0x02;  // This will enable interrupt on match between OCR2A and Timer
  sei();          // This will make sure that the global interrupts are enable
}
ISR(TIMER2_COMPA_vect)
{
  cli();
  analog_data = analogRead(sensor_pin);
  samplecounter += 2;
  int N = samplecounter - lastBeatTime;
  if (analog_data < thresh && N > (time_between_beats / 5) * 3)
  {
    if (analog_data < trough_value)
    {
     trough_value = analog_data;
    }
  }
  if (analog_data > thresh && analog_data > peak_value)
  {
   peak_value = analog_data;
  }
  if (N > 250)
  {
    if ( (analog_data > thresh) && (pulse_signal == false) && (N > (time_between_beats / 5) * 3) )
    {
      pulse_signal = true;
      time_between_beats = samplecounter - lastBeatTime;
      lastBeatTime = samplecounter;
      if (second_heartpulse)
      {
        second_heartpulse = false;
        for (int i = 0; i <= 9; i++)
        {
          beat[i] = time_between_beats; //Filling the array with the heart beat values
        }
      }
      if (first_heartpulse)
      {
        first_heartpulse = false;
        second_heartpulse = true;
        sei();
        return;
      }
      word runningTotal = 0;
      for (int i = 0; i <= 8; i++)
      {
       beat[i] = beat[i + 1];
        runningTotal += beat[i];
      }
      beat[9] = time_between_beats;
      runningTotal += beat[9];
      runningTotal /= 10;
      heart_rate = 60000 / runningTotal;
    }

  }




  if (analog_data < thresh && pulse_signal == true)

  {

    pulse_signal = false;

    amplitude = peak_value - trough_value;

    thresh = amplitude / 2 + trough_value;

    peak_value = thresh;

    trough_value = thresh;

  }


  if (N > 2500)

  {

    thresh = 512;

    peak_value = 512;

    trough_value = 512;

    lastBeatTime = samplecounter;

    first_heartpulse = true;

    second_heartpulse = false;

  }


  sei();

}
