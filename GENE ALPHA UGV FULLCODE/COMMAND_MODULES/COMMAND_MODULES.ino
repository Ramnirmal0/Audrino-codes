char data;
int const POWER_LED = 2;
int const TRASMITTER_LED = 3;
int const RECIEVER_LED = 4;

void setup() {
  Serial.begin(9600);
  pinMode(POWER_LED, OUTPUT);
  pinMode(TRASMITTER_LED, OUTPUT);
  pinMode(RECIEVER_LED, OUTPUT);
  digitalWrite(POWER_LED, HIGH);

}

void transmitter_led()
{
  digitalWrite(TRASMITTER_LED, HIGH);
  delay(10);
  digitalWrite(TRASMITTER_LED, LOW);
  delay(10);

}

void receiver_led()
{
  digitalWrite(RECIEVER_LED, HIGH);
  delay(10);
  digitalWrite(RECIEVER_LED, LOW);
  delay(10);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == 'w')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 's')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 'a')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 'd')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 'x')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '5')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '0')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '8')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '2')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '4')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '6')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '+')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == '-')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 'n')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    if (data == 'm')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-AMD Cheat activated");
      receiver_led();
    }

    // swarm controls



    if (data == 'b')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }

    if (data == 'i')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'j')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'k')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'l')
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'f')  //suicide
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'g') //recall
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


    if (data == 'h') //attack
    {
      transmitter_led();
      Serial.println("REQ-ACK : CMD-SMD Cheat activated");
      receiver_led();
    }


  }
}
