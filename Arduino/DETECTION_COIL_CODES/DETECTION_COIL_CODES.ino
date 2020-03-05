#define vinPin A0
#define buz 9
#define pulsePin A4
#define led 10
long sumExpect = 0;
long ignor = 0;
long diff = 0;
long pTime = 0;
long buzPeriod = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(pulsePin, OUTPUT);
  digitalWrite(pulsePin, LOW);
  pinMode(vinPin, INPUT);
  pinMode(buz, OUTPUT);
  digitalWrite(buz, LOW);
  pinMode(led, OUTPUT);
}
void loop()
{
  int minval = 1023;
  int maxval = 0;
  long unsigned int sum = 0;
  for (int i = 0; i < 256; i++)
  {
    pinMode(vinPin, OUTPUT);
    digitalWrite(vinPin, LOW);
    delayMicroseconds(20);
    pinMode(vinPin, INPUT);
    applyPulses();
    int val = analogRead(vinPin);
    Serial.println(val);
    minval = min(val, minval);
    maxval = max(val, maxval);
    sum += val;
    long unsigned int cTime = millis();
    char buzState = 0;
    if (cTime < pTime + 10)
    {
      if (diff > 0)
        buzState = 1;
      else if (diff < 0)
        buzState = 2;
    }
    if (cTime > pTime + buzPeriod)
    {
      if (diff > 0)
        buzState = 1;
      else if (diff < 0)
        buzState = 2;
      pTime = cTime;
    }
    if (buzPeriod > 300)
      buzState = 0;
    if (buzState == 0)
    {
      digitalWrite(led, LOW);
      noTone(buz);
    }
    else if (buzState == 1)
    {
      tone(buz, 2000);
      digitalWrite(led, HIGH);
    }
    else if (buzState == 2)
    {
      tone(buz, 500);
      digitalWrite(led, HIGH);
    }
  }
  sum -= minval;
  sum -= maxval;
  if (sumExpect == 0)
    sumExpect = sum << 6;
  long int avgsum = (sumExpect + 32) >> 6;
  diff = sum - avgsum;
  if (abs(diff)<avgsum >> 10)
  {
    sumExpect = sumExpect + sum - avgsum;
    ignor = 0;
  }
  else
    ignor++;
  if (ignor > 64)
  {
    sumExpect = sum << 6;
    ignor = 0;
  }
  if (diff == 0)
    buzPeriod = 1000000;
  else
    buzPeriod = avgsum / (2 * abs(diff));
}
void applyPulses()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(pulsePin, HIGH); //take 3.5 uS
    delayMicroseconds(3);
    digitalWrite(pulsePin, LOW); //take 3.5 uS
    delayMicroseconds(3);
  }
}
