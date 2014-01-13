# include <avr/interrupt.h>
# include <avr/io.h>

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  DDRD = B00111100;
  DDRB = B00001111;
  PORTD = B0000000;
  PORTB = B0001000;
  // setup timer2 to fire every 1ms
  TCCR2B = 0x00;        //Disbale Timer2 while we set it up
  TCNT2  = 0;           //Reset Timer Count to 130 out of 255
  TIFR2  = 0x00;        //Timer2 INT Flag Reg: Clear Timer Overflow Flag
  TIMSK2 = 0x01;        //Timer2 INT Reg: Timer2 Overflow Interrupt Enable
  TCCR2A = 0x00;        //Timer2 Control Reg A: Normal port operation, Wave Gen Mode normal
  TCCR2B = 0x05;        //Timer2 Control Reg B: Timer Prescaler set to 128
}

ISR(TIMER2_OVF_vect) {
  TCNT2 = 0;
  TIFR2 = 0X00;
  PORTB = PORTB >> 1;
  if (PORTB == 0) {
    PORTB == B0001000;
  }
}

void loop(){
  for (int i=0; i<10; i++) {
    PORTD = i * 4;
    delay(300);
  }
}



