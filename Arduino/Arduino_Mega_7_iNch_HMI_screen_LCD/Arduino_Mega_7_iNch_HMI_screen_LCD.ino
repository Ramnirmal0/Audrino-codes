#include <URTouch.h>
//#include <UTouchCD.h>
#define TOUCH_ORIENTATION  LANDSCAPE

#include <UTFT_Buttons.h>

#include <UTFT.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

int button1on = 0; // USED AS A FLAG

int x, y;
int led=13;
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";

  // variables for displaying seconds
  // Interval is how long we wait
// add const if this should never change
int interval= 1 ; // in secs
// Tracks the time since last event fired
unsigned long previousMillis=0;
int previoussecs = 0;
int currentsecs = 0;

int bg[] = {
  0, 0, 255};

int fg[] = {
  255, 255, 255};
UTFT myGLCD(ITDB50, 38,39,40,41);   // Remember to change the model parameter to suit your display module!
URTouch        myTouch(2,3,4,5,6);


// Finally we set up UTFT_Buttons :)
/*void drawButtons()
{
// Draw the upper row of buttons
   myGLCD.setColor(bg[0], bg[1], bg[2]);
  myGLCD.fillRoundRect (90, 180, 220, 230);
  myGLCD.setColor(fg[0], fg[1], fg[2]);
  myGLCD.drawRoundRect (90, 180, 220, 230);
  myGLCD.print(" ON", 115, 195);
  myGLCD.setBackColor (0, 0, 0);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

}*/

void setup()
{
  int led=13;
  Serial.begin(9600);
  pinMode(led,OUTPUT);
// Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(SevenSegNumFont);
   //myGLCD.setColor(0, 0, 0);
   //myGLCD.fillScr(255, 255, 255);
  myGLCD.setBackColor(0, 0, 0);
//  drawButtons();
}

void loop()
{

  
   while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
    
    
        if ((x>=90 && x<=220 && y >=180 && y<=230)&&(button1on == 0)  )  // Button: Enter
    {
      waitForIt(90, 180, 220, 230);
        myGLCD.setColor(bg[1], bg[1], bg[2]);
  myGLCD.fillRoundRect (90, 180, 220, 230);
  myGLCD.setColor(fg[1], fg[1], fg[2]);
  myGLCD.drawRoundRect (90, 180, 220, 230);
  myGLCD.print(" OFF", 115, 195);
  myGLCD.setBackColor (0, 0, 0);
   Serial.println("ON");
   digitalWrite(led,HIGH);
   button1on = 1;
   x=0;
   y=0;
  
   delay(1000);
    }
            if ((x>=90 && x<=220 && y >=180 && y<=230)&&(button1on == 1)  )  // Button: Enter
    {
      waitForIt(90, 180, 220, 230);
        myGLCD.setColor(bg[0], bg[1], bg[2]);
  myGLCD.fillRoundRect (500, 500, 500, 500);
  myGLCD.setColor(fg[0], fg[1], fg[2]);
  myGLCD.drawRoundRect (90, 180, 220, 230);
  myGLCD.print(" ON", 115, 195);
  myGLCD.setBackColor (0, 0, 0);
   Serial.println("off");
   digitalWrite(led,LOW);
   button1on = 0;
   x=0;
   y=0;
  
   delay(1000);
    }


  

    }
  
          // Get snapshot of time
   unsigned long currentMillis = millis();
   currentsecs = currentMillis / 1000;
     // How much time has passed, accounting for rollover with subtraction!
   if ((unsigned long)(currentsecs - previoussecs) >= interval) {
      // It's time to do something!
      myGLCD.setColor(fg[0], fg[0], fg[0]); // set font color
      myGLCD.setFont(SevenSegNumFont);
   //myGLCD.printNumI(currentsecs, CENTER, 300);
  // write code here for anything you want to control on
  //timely basis
      // Use the snapshot to set track time until next event
      previoussecs = currentsecs;
   }
       myGLCD.setColor(fg[0], fg[0], fg[0]); // set font color
      myGLCD.setFont(BigFont);
    myGLCD.print("Devaditek ", CENTER, 190);
    myGLCD.print("by Sumit C Mohan ", CENTER, 300);
}


      

}

void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(0, 0, 0);
  myGLCD.drawRoundRect (x2, y1, x1, y2);
  while (myTouch.dataAvailable()){
  }
  delay(20);


  // list all files in the card with date and size

  myGLCD.setColor(fg[0], fg[0], fg[0]);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}
