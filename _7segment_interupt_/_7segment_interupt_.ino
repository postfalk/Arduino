// In this script I am using a 8bit shift registor to drive 2 
// 7-segment-displays at the same time. The last bit is used
// to multiplex. It is just connected to a simple NOT gate
// using an additional 74SN00 (old school).

// Analog temperature sensor is connected to A1

// see http://arduinomega.blogspot.com/p/arduino-code.html

// apt-get install avr-libc and avr-gcc to 
// make them available

# include <avr/interrupt.h>
# include <avr/io.h>

byte dataArray[10];

int display_value = 0;
int digit_toggle = B10000000;
int sensorPin = A1;    // select the input pin for the thermo sensor
float sensorValue = 0; 

ISR(TIMER2_OVF_vect) {
  int display_digit;
  TCNT2 = 0;
  TIFR2 = 0X00;
  // deal with incorrect formated input
  display_value = display_value % 100;
  if (digit_toggle == B00000000) {
    display_digit = display_value/10;
  }
  else {
    display_digit = display_value % 10;
  }
  write(dataArray[display_digit] + digit_toggle);
  digit_toggle = digit_toggle ^ B10000000;
}

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
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

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  
  //Setup Timer2 to fire every 1ms
  TCCR2B = 0x00;        //Disbale Timer2 while we set it up
  TCNT2  = 0;         //Reset Timer Count to 130 out of 255
  TIFR2  = 0x00;        //Timer2 INT Flag Reg: Clear Timer Overflow Flag
  TIMSK2 = 0x01;        //Timer2 INT Reg: Timer2 Overflow Interrupt Enable
  TCCR2A = 0x00;        //Timer2 Control Reg A: Normal port operation, Wave Gen Mode normal
  TCCR2B = 0x05;        //Timer2 Control Reg B: Timer Prescaler set to 128
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

void loop() {
  int sum = 1;
  for(int i = 0; i < 100; i++) {
    // display_value = i;
    sensorValue = analogRead(sensorPin);
    
    display_value = (sensorValue*5/1024-.5)*100;
    delay(500);
  }
}
