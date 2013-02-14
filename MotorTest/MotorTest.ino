// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
// #include <Servo.h> 

// DC motor on M2
AF_DCMotor motor1(2);
AF_DCMotor motor2(1);
// DC hobby servo
// Servo servo1;
// Stepper motor on M3+M4 48 steps per revolution
// AF_Stepper stepper(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
  // turn on servo
  //  servo1.attach(9);
   
  // turn on motor #2
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
   motor1.run(FORWARD);
   motor2.run(FORWARD);
  for (i=0; i<255; i++) {  
    motor1.setSpeed(i);
    motor2.setSpeed(i); 
    delay(3);
  }
  delay(500);
  for (i=255; i>0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i); 
    delay(3);
  }
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
    for (i=0; i<255; i++) {  
    motor1.setSpeed(i);
    motor2.setSpeed(i); 
    delay(3);
  }
  delay(500);
  for (i=255; i>0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i); 
    delay(3);
  }
  delay(100);
}
