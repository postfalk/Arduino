#include "TimerOne.h"  

int refreshrate=48;
     
void setup() {
  Serial.begin(9600);
  DDRD = B00111100;
  DDRB = B00001111;
  PORTD = B00000000;
  PORTB = B00001000;
  Timer1.initialize(1000000/refreshrate);
  Timer1.attachInterrupt(update_display);
}
     
void update_display() {
   Serial.println('refresh');            
 }


void loop(){
  for (int i=0; i<10; i++) {
    PORTD = i * 4;
    Serial.println("sec");
    delay(1000);
  }
}



