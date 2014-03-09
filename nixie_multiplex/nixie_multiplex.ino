#include "TimerOne.h"  
int digits[4];
int lit = 0;
     
void setup() {
  Serial.begin(9600);
  DDRD = B01111100;
  DDRB = B00001111;
  PORTD = B00000000;
  PORTB = B00001000;
  int refreshrate = 200;
  Timer1.initialize(1000000/refreshrate);
  Timer1.attachInterrupt(update_display);
}
     
void update_display() {
  if (lit == 4) {
    lit = 0;
  }
  PORTB = B00001000 >> lit;
  //Serial.println(PORTB);
  PORTD = (digits[lit] * 4) + B01000000;
  lit++;   
}

void create_digits(int number) {
  for (int p=0; p<4; p++) {
    digits[p] = int(number/pow(10, p)) % 10;
  } 
}

void loop(){
  for (int i=0; i<10000; i++) {
    create_digits(i);
    delay(200);
  }
}


