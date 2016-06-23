#include <Arduino.h> 
void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  char c = 0;
  String s;
  do {
    if (Serial.available()) {
      c = Serial.read();
      s += c;      
    }
  } while(c != '\n');  
  int v = s.toInt();
  analogWrite(10, v);
  Serial.println(v);
}

