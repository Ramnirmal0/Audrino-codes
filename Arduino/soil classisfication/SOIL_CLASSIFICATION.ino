/*
MQ A4 D7
MQ3 A0 D8
SOIL A5



*/



/* MQ-3 Alcohol Sensor Circuit with Arduino */
int analog_IN = A4;  // This is our input pin    

const int AOUTpin = 0; //the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin = 8; //the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino

int sensor_pin = A5;

int output_value ;

int limit;
int value;

void setup() {
  Serial.begin(9600);//sets the baud rate
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
  pinMode(analog_IN, INPUT);
}

void loop()
{
  value = analogRead(AOUTpin); //reads the analaog value from the alcohol sensor's AOUT pin
  limit = digitalRead(DOUTpin); //reads the digital value from the alcohol sensor's DOUT pin
  Serial.print("methane contents : ");
  Serial.println(value);//prints the alcohol value
  delay(1000);
  Serial.println("======================================");
  output_value = analogRead(sensor_pin);
  output_value = map(output_value, 550, 0, 0, 100);
  Serial.print("soil Moisture : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);

  int Value1 = analogRead(analog_IN);
  Serial.print("Nitrogen Gas reading : ");
  Serial.println(Value1);


}
