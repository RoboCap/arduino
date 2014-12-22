#include <Arduino.h>
#include <Servo.h>

int LED_H_PIN = 4;
int LED_V_PIN = 7;
int BUTTON_PIN = 2;

int POTENTIOMETR_PIN = A0;

int POTENTIOMETR_LEVEL  = 3;

int SERVO_H_PIN = 9;
int SERVO_V_PIN = 10;

Servo serverH;
Servo serverV;

void setup()
{
    pinMode(LED_H_PIN, OUTPUT);
    pinMode(LED_V_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT);

    serverH.attach(SERVO_H_PIN);
    serverV.attach(SERVO_V_PIN);

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

    //
    // read potentiometr
    //
    int potentiometrValue = analogRead(POTENTIOMETR_PIN);
    int mappedPotentiometrValue = map(potentiometrValue, 0, 1024, 1, POTENTIOMETR_LEVEL*2);

    Serial.print(" | potentiometr: " );
    Serial.print(potentiometrValue);
    Serial.print(" | mapped: ");
    Serial.print(mappedPotentiometrValue);

    //
    // set servo
    //
    if (mappedPotentiometrValue != POTENTIOMETR_LEVEL)
    {
        int delta = mappedPotentiometrValue - POTENTIOMETR_LEVEL;

        if (isH)
        {
            serverH.write(serverH.read() + delta);
        }
        else
        {
            serverV.write(serverV.read() + delta);
        }

        digitalWrite(LED_V_PIN, LOW);
        digitalWrite(LED_H_PIN, LOW);
    }
    Serial.print("| servo H: " );
    Serial.print(serverH.read());
    Serial.print("| server V: ");
    Serial.print(serverV.read());

    Serial.println();
    delay(50);
}

