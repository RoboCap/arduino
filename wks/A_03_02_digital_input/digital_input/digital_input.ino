#include <Arduino.h>

int isHigh = HIGH;
int wasPressed = LOW;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  int pressed = digitalRead(12);
  if (!wasPressed && pressed)
    isHigh = !isHigh;
  wasPressed = pressed;
  digitalWrite(13,isHigh);
  delay(50);
}


