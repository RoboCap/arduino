#include <Arduino.h>

int LED_H_PIN = 4;
int LED_V_PIN = 7;
int BUTTON_PIN = 2;

void setup()
{
    pinMode(LED_H_PIN, OUTPUT);
    pinMode(LED_V_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT);

    Serial.begin(9600);
}

int isH = true;
int wasButtonPressed = LOW;

void loop()
{
    //
    // handle button
    //
    int buttonPressed = digitalRead(BUTTON_PIN);

    Serial.print(" | button: " );
    Serial.print(buttonPressed);

    if (wasButtonPressed == LOW && buttonPressed == HIGH)
    {
        isH = !isH;
    }
    wasButtonPressed = buttonPressed;

    //
    // set led
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

    Serial.println();
    delay(50);
}

