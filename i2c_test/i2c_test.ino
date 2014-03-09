#include "Wire.h"
#define DS1307_IC2_ADRESS 0x68

//Wire.beginTransmission(DS1307_I2C_ADDRESS);   // Open I2C line in write mode
//Wire.write((byte)0x00);                       // Set the register pointer to (0x00)
//Wire.endTransmission();

//from http://combustory.com/wiki/index.php/RTC1307_-_Real_Time_Clock
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val/16*10) + (val%16) );
}

// get time in hhmmss format
long get_time() {
  byte second;
  byte minute;
  byte hour;
  Wire.beginTransmission(0x68);
  Wire.write((byte)0x00);                              // Set the register pointer to (0x00)
  Wire.endTransmission(); 
  // second = bcdToDec(Wire.read() & 0x7f); // Read seven bytes of data
  Serial.println(Wire.read() & 0x7f);
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0x3f);
  long ret = hour * 10000L + minute * 100L + second;
  return ret;
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
};

void loop() {
  Serial.println(get_time());
  delay(500);
}


