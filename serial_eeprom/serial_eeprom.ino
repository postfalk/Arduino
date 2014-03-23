#include <Wire.h>

// see http://playground.arduino.cc/Code/I2CEEPROM#.Uy9TjPldU_g
void i2c_eeprom_write_byte(int deviceaddress, unsigned int eeaddress, unsigned int data ) {
  Wire.beginTransmission(deviceaddress);
  Wire.write((byte)(eeaddress & 0xFF));
  Wire.write((byte)(data & 0xFF));
  int ret = Wire.endTransmission();
  // Serial.print("Transmission status after write: ");
  // Serial.println(ret);
}

byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress ) {
    byte rdata = 0xFF;
    Wire.beginTransmission(deviceaddress);
    Wire.write(eeaddress);
    int ret = Wire.endTransmission();
    // Serial.print("Transmission Status after sending address: ");
    // Serial.println(ret)
    // Serial.print(eeaddress);
    // Serial.print(' ');
    Wire.requestFrom(deviceaddress, 1);
    if (Wire.available()) rdata = Wire.read();
    return rdata;
  }

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop() {
  Serial.println("hi");
  for (unsigned int i=0; i<255; i++) {
    i2c_eeprom_write_byte(0x50, i, i);
  }
  for (unsigned int i=0; i<256; i++) {
    Serial.println(i2c_eeprom_read_byte(0x50, i));
    delay(100);
  }
  
};

