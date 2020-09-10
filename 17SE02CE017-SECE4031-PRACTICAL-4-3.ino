#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
int value=0;
void setup()
{
  pinMode(3, OUTPUT);
  lcd.begin(16, 2);
  pinMode(2,INPUT);
}

void loop()
{
  value=digitalRead(2);
  if(value==HIGH)
  {
  digitalWrite(3, HIGH);
  delay(2000);  
  lcd.setCursor(0,0);
  lcd.print("Yes,MotionDetect");
  lcd.setCursor(3,1);
  lcd.print("DC Motor on");
  }
  else
  {
  digitalWrite(3, LOW);
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("No,MotionDetect");
  lcd.setCursor(3,1);
  lcd.print("DC Motor off");
  }
}