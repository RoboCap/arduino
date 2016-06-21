#include <Arduino.h>

//Pin connected to DS    of 74HC595
int dataPin = 10;
//Pin connected to ST_CP of 74HC595
int latchPin = 11;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;

// bit number from right (the first is 0)
//   2
// 3   1
//   4
// 5   7
//   6

byte dec_digits[] = {0b00010000,0b01111101,0b10001001,0b00101001,0b01100101,0b00100011,0b00000011,0b01111001,0b00000001,0b00100000 };

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 10; numberToDisplay++)
  {
    Serial.println(numberToDisplay);
    
    // take the latchPin low so
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);

    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[numberToDisplay]);

    // take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);

    delay(500);
  }
}
