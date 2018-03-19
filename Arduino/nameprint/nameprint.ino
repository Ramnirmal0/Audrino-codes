#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
void setup() {
  lcd.begin(16, 2);
  lcd.print("I LOVE APPLE ITS TASTY");
  delay(100);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("I LOVE APPLE ITS TASTY");
  delay(1000);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 16; j++)
    {
      lcd.setCursor(j, i);
      lcd.print(" ");

    }

  }
  delay(1000);
}


