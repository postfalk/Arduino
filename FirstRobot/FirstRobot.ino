// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
// #include <Servo.h> 

// DC motors on M1, M2
AF_DCMotor motor1(2);
AF_DCMotor motor2(1);
const int PIN13 = 13;
const int PIN02 = 2;
boolean sensor01_state;
boolean sensor02_state;
int i;
boolean forward;

void setup() {
  // forward = true;
  Serial.begin(9600);
  pinMode(PIN13, INPUT);
  pinMode(PIN02, INPUT);  
  // turn on motor #2
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  if (i<255) {i++;}
  sensor01_state = digitalRead(PIN02);
  sensor02_state = digitalRead(PIN13);
  if (sensor01_state == LOW || sensor02_state == LOW) {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    if (forward == true) {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      forward = false;
      Serial.println(forward);
    } else {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      forward = true;
      Serial.println(forward);
    }
      delay(1000); // debouncing
  }
  delay(10);
  motor1.setSpeed(i);
  motor2.setSpeed(i);  
      // Serial.println(sensor01_state);
    // Serial.println(sensor02_state);
  }  
//   motor1.run(FORWARD);
//   motor2.run(FORWARD);
//  for (i=0; i<255; i++) {  
//    motor1.setSpeed(i);
//    motor2.setSpeed(i); 
//    delay(3);
//  }
//  delay(500);
//  for (i=255; i>0; i--) {
//    motor1.setSpeed(i);
//    motor2.setSpeed(i); 
//    delay(3);
//  }
//  motor1.run(BACKWARD);
//  motor2.run(BACKWARD);
//    for (i=0; i<255; i++) {  
//    motor1.setSpeed(i);
//    motor2.setSpeed(i); 
//    delay(3);
//  }
//  delay(500);
//  for (i=255; i>0; i--) {
//    motor1.setSpeed(i);
//    motor2.setSpeed(i); 
//    delay(3);
//  }
//  delay(100);
