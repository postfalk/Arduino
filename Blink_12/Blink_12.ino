 /*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led[] = {3,4,5,6,7,8,9,10};
int dl = 100

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int i=0; i<8; i++) {
    pinMode(led[i], OUTPUT);     
  }
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i=0; i<8; i++) {
    digitalWrite(led[i], HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(dl);               // wait for a second
    digitalWrite(led[i], LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
