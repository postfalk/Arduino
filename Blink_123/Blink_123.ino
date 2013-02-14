/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 12;
int led2 = 10;
int led3 = 8;
int led4 = 6;
int katode[] = {A0, A1, A2, A3};

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
  pinMode(led3, OUTPUT);     
  pinMode(led4, OUTPUT);
  pinMode(katode[0], OUTPUT);
  pinMode(katode[1], OUTPUT);
  pinMode(katode[2], OUTPUT);
  pinMode(katode[3], OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(katode[j], HIGH);
    }
    digitalWrite(katode[i], LOW);
    //digitalWrite(katode[i], LOW);
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);               // wait for a second
    digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);               // wait for a second
    digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);
    digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);  // wait for a second
    digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
    delay(500);              // wait for a second
    digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
    delay(500);               // wait for a second
    digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
    delay(500);  // wait for a second
    digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
    delay(500);  // wait for a second
  }
}
