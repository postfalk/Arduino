/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
}

void left() {
  matrix.drawRect(0, 0, 4, 4, LED_ON); 
}

void middle() {
  matrix.drawRect(0, 2, 4, 4, LED_ON);
}

void right() {
  matrix.drawRect(0, 4, 4, 4, LED_ON);
}

void noSignal() {
   matrix.drawRect(2, 2, 4, 4, LED_ON);
}

const int pinLeftSensor = A0;
const int pinRightSensor = A1;
const int delta = 50;
const int noiseLevel = 10;

const int LEFT = 0;
const int RIGHT = 1;
const int MIDDLE = 2;
const int NONE = 3;


void drawDirection(int i) {
    switch(i) {
       case LEFT: 
           left();
           break;
       case MIDDLE:
          middle();
         break;
       case RIGHT:
          right();
          break;
       case NONE:
           noSignal();
           break;
       default:
           break;
          
    } 
}


void render(int direction) {
    matrix.clear();
    drawDirection(direction);
    matrix.writeDisplay();
    delay(250);
}

int detectDirection(int leftSensorValue, int rightSensorValue) {
  int detectedDirection = NONE;
  if (leftSensorValue - rightSensorValue > delta ) {
     detectedDirection = LEFT;
  } else if (rightSensorValue - leftSensorValue > delta) {
     detectedDirection = RIGHT; 
  } else if (rightSensorValue > noiseLevel && leftSensorValue > noiseLevel) {
     detectedDirection = MIDDLE; 
  }
  return detectedDirection;
}

void simulate() { 
  render(detectDirection(delta*2, 0));
  render(detectDirection(delta*2, delta*2));
  render(detectDirection(0, delta*2));
  render(detectDirection(noiseLevel/2, noiseLevel/2));
}

const boolean useSensor = true;

void loop() {  
  int leftSensorValue = analogRead(pinLeftSensor);
  int rightSensorValue = analogRead(pinRightSensor);
  Serial.print("left ");
  Serial.println(leftSensorValue);
  Serial.print("right ");
  Serial.println(rightSensorValue);
  useSensor ? render(detectDirection(leftSensorValue, rightSensorValue)) : simulate();
}
