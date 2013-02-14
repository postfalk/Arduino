const int PIN13 = 13;
const int PIN02 = 2;
boolean sensor01_state;
boolean sensor02_state;

void setup() {
  pinMode(PIN13, INPUT);
  pinMode(PIN02, INPUT);
  Serial.begin(9600);
};

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  sensor01_state = digitalRead(PIN02);
  sensor02_state = digitalRead(PIN13);
  Serial.println(sensor01_state);
  Serial.println(sensor02_state);
}
  
