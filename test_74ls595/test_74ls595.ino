void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void write(byte in) {
  for (int i = 0; i < 9; i++) {
    digitalWrite(8, in & B10000000);
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
    in = in << 1;
  }
  digitalWrite(9, LOW);
  digitalWrite(9, HIGH);
};

void loop() {
  int sum = 1;
  for(int i = 0; i < 8; i++) {
     sum = sum + sum;
     write(sum-1);   // wait for a second
     delay(100);
  }
}
