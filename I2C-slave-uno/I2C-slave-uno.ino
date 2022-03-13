#include <Wire.h>
 
void setup(){
  Wire.begin(1); // Begin communication as slave-device-1
  Wire.onRequest(result); // When request is come run result function
}
 
void loop(){
  delay(100);
}
 
void result(){
  word readingData = analogRead(0);
  delay(10);
  byte data[] = {highByte(readingData), lowByte(readingData)};
  Wire.write(data, 2);
}
