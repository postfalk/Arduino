
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  DDRD = B00111100;
  DDRB = B00001111;
  PORTD = B0000000;
  PORTB = B0001000;
}

void loop(){
  PORTB = B0001000;
  for (int j=0; j<4; j++) {
    for (int i=0; i<10; i++) {
      PORTD = i * 4;
      delay(300);
    }
    PORTB = PORTB >> 1;
  }
}



