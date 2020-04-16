#include <LiquidCrystal.h>

const int rs = 21, en = 19, d4 = 18, d5 = 5, d6 = 17, d7 = 16;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String jatin;
void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{
    lcd.setCursor(0, 0);
    jatin = "welcom";
    lcd.print(jatin);
    
    delay(1000);
}
