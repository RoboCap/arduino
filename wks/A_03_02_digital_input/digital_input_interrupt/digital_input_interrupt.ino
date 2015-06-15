#include <Arduino.h>
volatile int isHigh = HIGH;
void onOff() {
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();
  if (newMillis - lastMillis > 50) {
    isHigh = !isHigh;
    digitalWrite(13,isHigh);
    lastMillis = newMillis;
  }
}
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13,isHigh);
  attachInterrupt(0, onOff, FALLING);
}
void loop() {
}


