/**********************************************
 Derived from Adafruit LED I2C backpack and 
 Yun example libraries.
 **********************************************/

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
YunServer server;
uint8_t my_bmp[8] {};
String string;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70);  // pass in the address
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
}

// use this function to create the matrix send to the display
void update_array(String string, uint8_t *array) {
  for (int i=0; i<8; i++) {
    char buf[8];
    string.substring(2*i, 2*i+2).toCharArray(buf, 16);
    array[i] = strtoul(buf, 0, 16);
  }
}

// my own bitmap drawer since the adafruit library works with static 
// bitmaps from PROGMEM
// TODOD: I hope there is a more elegant way to achieve this
void draw_bitmap(uint8_t *array) {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            matrix.drawPixel(i, j, array[i] >> j & 1);
        }
    }
}

void loop() {
  string = Serial.readString();
  if (string != "") {
    update_array(string, my_bmp);
  }
  draw_bitmap(my_bmp);
  matrix.writeDisplay();
}
