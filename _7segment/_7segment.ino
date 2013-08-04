// see http://playground.arduino.cc//Code/SimpleTimer#GetTheCode
#include <SimpleTimer.h>

int display_value = 5;

// the timer object
SimpleTimer timer;

// a function to be executed periodically
void repeatMe() {
  write_number(display_value);
}

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  
  timer.setInterval(1, repeatMe);
}

void write(byte in) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(8, in & B10000000);
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
    in = in << 1;
  }
  digitalWrite(9, LOW);
  digitalWrite(9, HIGH);
};

void write_number(int in) {
  int dataArray[10];
  dataArray[0] = B00000001; // 0 dec 0001 0001 bin
  dataArray[1] = B01100111; // 1 dec 1101 0111 bin
  dataArray[2] = B00010010; // 2 dec 0011 0010 bin
  dataArray[3] = B01000010; // 3 dec 1001 0010 bin
  dataArray[4] = B01100100; // 4 dec 1101 0100 bin
  dataArray[5] = B01001000; // 5 dec 1001 1000 bin
  dataArray[6] = B00001000; // 6 dec 0000 1000 bin
  dataArray[7] = B01100011; // 7 dec 1101 0011 bin
  dataArray[8] = B00000000; // 8 dec 0001 0000 bin
  dataArray[9] = B01000000; // 9 dec 1000 0000 bin
  write(dataArray[in]);
}


void loop() {
  timer.run();
  int sum = 1;
  for(int i = 0; i < 10; i++) {
  //   sum = sum + sum;
    display_value = i;   // wait for a second
    delay(100)
  }
}
