
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  DDRD = B00111100;
  PORTD = B0000000;
}

void loop(){
  for (int i=0; i<10; i++) {
    PORTD = i * 4;
    delay(300);
  }
}



