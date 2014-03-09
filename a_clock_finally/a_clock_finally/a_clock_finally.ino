#include "TimerOne.h"
#include "Wire.h"
int digits[4];
int lit = 0;

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
long read_time() {
  byte second;
  byte minute;
  byte hour;
  Wire.beginTransmission(0x68);
  Wire.write((byte)0x00);                              // Set the register pointer to (0x00)
  Wire.endTransmission(); 
  Wire.requestFrom(0x68, 7);
  second = bcdToDec(Wire.read() & 0x7f);
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read() & 0x3f);
  long ret = hour * 10000L + minute * 100L + second;
  // Serial.println(ret);  
  return ret;
}

void write_time(long inp) {
  byte hour;
  byte minute;
  byte second;
  hour = floor(inp/10000);
  minute = int(inp/100) % 100;
  second = inp % 100;
  Wire.beginTransmission(0x68);
  Wire.write((byte)0x00);
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.endTransmission();
};

void setup() {
  Wire.begin();
  Serial.begin(9600);
  DDRD = B01111100;
  DDRB = B00001111;
  DDRC = B00000000;
  PORTD = B00000000;
  PORTB = B00001000;
  int refreshrate = 200;
  Timer1.initialize(1000000/refreshrate);
  Timer1.attachInterrupt(update_display);
  // write_time(0);
}
     
void update_display() {
  if (lit == 4) {
    lit = 0;
  }
  PORTB = B00001000 >> lit;
  PORTD = (digits[lit] * 4);
  lit++;   
}

void create_digits(int number) {
  for (int p=0; p<4; p++) {
    digits[p] = int(number/pow(10, p)) % 10;
  } 
}

void loop(){
  long time = floor(read_time()/100l);
  // set hour
  if (PINC == 54){
    time = time + 100;
    if (time > 2399) {
      time = time - 2400;
    };
    write_time(time*100);
  };
  if (PINC == 58) {
    time = time + 10;
    if (time % 100 > 59) {
      time = time - 60;
    }
    write_time(time*100);
  };
  if (PINC == 60) {
    time = time + 1;
    if (time % 100 > 59) {
      time = time - 60;
    }
    write_time(time*100);
  };
  create_digits(time);
  delay(200);
}


