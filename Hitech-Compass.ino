#include <Wire.h>
int compassAddress = 0x01;  //use the I2C scanner sketch to get this but for Hitech it is usually 0x01
int heading;                //the compass heading variable

void setup() {
  Serial.begin(9600); //sets up the serial monitor
  Wire.begin();  //initialize i2c
}

void loop() {
  Wire.beginTransmission(compassAddress); // here we start transmiting to the compass sensor
  Wire.write(0x44); // "0x44" is asking for the heading data
  Wire.endTransmission(); // this ends the transmission
  // here we receive the data:
  while (Wire.available() < 2) // we keep receiving until the sensor stop transmitting data
    ;
  byte lowbyte = Wire.read();
  byte highbyte = Wire.read();
  heading = word(highbyte, lowbyte); // this combines the 2 bytes
  Serial.println(heading); //prints the compass heading
}