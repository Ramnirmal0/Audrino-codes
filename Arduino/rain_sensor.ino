int rainSensePin= 0; // analog pin 0 – sensor i/p
int alertPin= 8; // digital pin 8 – alert o/p
int curCounter= 0; // current counter – goes up by 1 every second while sensing
void setup()
{
Serial.begin(9600);
pinMode(alertPin, OUTPUT);
pinMode(rainSensePin, INPUT);
}
void loop()
{
int rainSenseReading = analogRead(rainSensePin);
Serial.println(rainSenseReading); // use this for serial monitoring if available
delay(250); // relax
if (curCounter >= 30){ // end of the time delay
digitalWrite(alertPin, HIGH); //raise an alert after x time
}
if (rainSenseReading <300)
{ // while raining at threshold level – see text curCounter++; // increment sensing counter } else if (rainSenseReading >300) { // if not raining at threshold level
digitalWrite(alertPin, LOW); // don’t raise an alert
curCounter = 0; // reset the counter to 0
}
delay(1000);
}
