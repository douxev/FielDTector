#include <Wire.h>
#include "rgb_lcd.h" //using an LCD RGB backlight

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 42;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB); //setup RGB light
}

void loop() 
{
    int pinRead0 = analogRead(A0); // photodiode 1 (first of a 9*9 matrix, experimentating)
    float pVolt0 = pinRead0 / 1024.0 * 5.0;

  if (pVolt0>=4.65) //stupid condition to get used to pVolt0 values
  {
    lcd.setCursor(0,0);
    lcd.print("Not much photons");
    
  }
  else if (pVolt0<4.65) //same stupid condition
  {
    lcd.setCursor(0,0);
    lcd.print("Light is ON     ");
  }

    lcd.setCursor(0, 1); //print Voltage value reads
    lcd.print(pVolt0);

    delay(500);
}
