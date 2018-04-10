
#include <Wire.h>
#include "rgb_lcd.h" //using an LCD RGB backlight

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 42;
bool bruit_conf = 0;
void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB); //setup RGB light
}

void loop() 
{
    if (bruit_conf == 0);
    {
    lcd.clear();
    lcd.autoscroll();
    lcd.setCursor(0,0);
    lcd.print("Initialisation du bruit");
    delay(2000);
    int pinRead0 = analogRead(A0); // photodiode 
    float pVolt0 = pinRead0 / 1024.0 * 5.0;
    int bruit = pVolt0;
    
    lcd.setCursor(0, 1); 
    lcd.print("En Attente");
    delay(500);
    lcd.setCursor(0, 1); 
    lcd.print("En Attente.");
    delay(500);
    lcd.setCursor(0, 1); 
    lcd.print("En Attente..");
    delay(500);
    lcd.setCursor(0, 1); 
    lcd.print("En Attente...");
    delay(500);
    bruit_conf = 1;
    }
    
    lcd.clear();
    int pinRead0 = analogRead(A0); // photodiode 
    float pVolt0 = pinRead0 / 1024.0 * 5.0;
    int mesure = pVolt0 - bruit;
    
    lcd.noAutoscroll();
    lcd.setCursor(0,0);
    lcd.print("Mesure obtenue :");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bruit :");
    lcd.setCursor(8,0);
    lcd.print(bruit);
    lcd.setCursor(0, 1);
    lcd.print(mesure);
    delay(10000);
}
