/* Wired Door Window Sensor 330mm [S140] : http://rdiot.tistory.com/121 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD1602
int pushButton = 2;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD1602");
  pinMode(pushButton, INPUT_PULLUP);
  
  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S140:Window Sensor");

  int buttonState = digitalRead(pushButton);

  lcd.setCursor(0,1);
  lcd.print("value=" + (String)buttonState + " ");

  if(buttonState == 1)
  {
    digitalWrite(8, HIGH);
  }
  else
  {
   digitalWrite(8, LOW); 
  }
  delay(1);
}
