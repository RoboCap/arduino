#include <Arduino.h>

int LED_H_PIN = 4;
int LED_V_PIN = 7;

void setup()
{
    pinMode(LED_H_PIN, OUTPUT);
    pinMode(LED_V_PIN, OUTPUT);
}

int isH = true;

void loop()
{
    //
    // blink led
    //
    if(isH)
    {
        digitalWrite(LED_H_PIN, HIGH);
        digitalWrite(LED_V_PIN, LOW);
    }
    else
    {
        digitalWrite(LED_V_PIN, HIGH);
        digitalWrite(LED_H_PIN, LOW);
    }

    isH = !isH;

    delay(50);
}

