//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
 
/*******************************************************
 
This program will test the LCD panel and the buttons
Mark Bramwell, July 2010
 
********************************************************/
 
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
 
void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("temperature"); 
 lcd.setCursor(6,1);
 lcd.print("celsius   ");
 //analogReference(EXTERNAL);
}
 
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT; 
 if (adc_key_in < 195)  return btnUP;
 if (adc_key_in < 380)  return btnDOWN;
 if (adc_key_in < 555)  return btnLEFT;
 if (adc_key_in < 790)  return btnSELECT;  
 return btnNONE;  // when all others fail, return this...
}
 

int sensorPin = A1;    // select the input pin for the potentiometer
float sensorValue = 0;  // variable to store the value coming from the sensor
float realValue;
boolean fahrenheit = false;
int run = 1;

void loop() {
  run = run + 1;
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin)
  if (run % 10 == 0)
  {  
    realValue = (sensorValue*5/1024-.5)*100;
    if (fahrenheit) {
      realValue = realValue * 9/5 + 32;
    }
    lcd.setCursor(0,1);
    lcd.print(realValue);
  }
  
  lcd_key = read_LCD_buttons();  // read the buttons
 
  switch (lcd_key)
  {
    case btnUP:
    {
      fahrenheit = true;
      lcd.setCursor(6,1);
      lcd.print("fahrenheit");
      break;
    }
    case btnDOWN:
    {
      fahrenheit = false;
      lcd.setCursor(6,1);
      lcd.print("celsius   ");
      break;
    }
  }
  delay(50);                  
}
