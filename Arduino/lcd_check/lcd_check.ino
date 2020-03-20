#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); /*rs,en,d4,d5,d6,d7*/

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 0);    // (column , row)
  lcd.print("First line");   // for anything to print on lcd firstline
  Serial.println("First line");  // for printing in serial monitor

  lcd.setCursor(0, 1);   //(column , row)
  lcd.print("Second line");  // for anything to print on lcd secondline
  Serial.println("Second line");  // for printing in serial monitor

  delay(1000);   // clear entire lcd display within 1 second delay
  lcd.clear();  // clear lcd display to avoid overlapping

}
