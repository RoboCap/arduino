#include <Arduino.h>

void printValues(int rV, int mV) {
  Serial.print("Read value: ");
  Serial.print(rV);
  Serial.print(", mapped value: ");
  Serial.println(mV);
}

void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rV = analogRead(A0);
  int mV = map(rV, 0, 1023, 0, 255);
  printValues(rV, mV);
  analogWrite(11, mV);
  delay(500);
}


