#include <Wire.h> // Wire kütüphanemizi projemize dahil ediyoruz
 
byte dataStorage[2]; // Alınan veriyi hafızada tutmak için 2 indisli dizemiz 
 
void setup() {
  Wire.begin(); // Begin communication as master
  Serial.begin(9600);
}
 
void loop() {
  Wire.requestFrom(1,2); // Send 2 byte read request to first slave device-1
  
  if(Wire.available()){
    int receivedData = Wire.available();// 
    for(int i = 0; i<receivedData; i++){
      dataStorage[i] = Wire.read(); 
    }
    word result = word(dataStorage[0], dataStorage[1]);
    Serial.print("Reading : ");
    Serial.println(result);
    delay(1000);
  } 
}
