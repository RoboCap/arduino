#include <Arduino.h>
#include <Servo.h>

int SENSOR_H_PIN = A4;
int SENSOR_V_PIN = A5;

int SERVO_H_PIN = 9;
int SERVO_V_PIN = 10;

int SENSOR_LEVEL = 3;

Servo serverH;
Servo serverV;

void setup()
{
    serverH.attach(SERVO_H_PIN);
    serverV.attach(SERVO_V_PIN);

    Serial.begin(9600);
}

void loop()
{
    //
    // read sensors
    //
    int sensorH = analogRead(SENSOR_H_PIN);
    int mappedSensorH = map(sensorH, 0, 1024, 1, SENSOR_LEVEL*2);

    int sensorV = analogRead(SENSOR_V_PIN);
    int mappedSensorV = map(sensorV, 0, 1024, 1, SENSOR_LEVEL*2);

    Serial.print(" | sensorH: " );
    Serial.print(sensorH);
    Serial.print(" | ");
    Serial.print(mappedSensorH);

    Serial.print(" | sensorV: " );
    Serial.print(sensorV);
    Serial.print(" | ");
    Serial.print(mappedSensorV);

    //
    // set servo
    //
    if (mappedSensorH != SENSOR_LEVEL)
    {
        int delta = mappedSensorH - SENSOR_LEVEL;

        serverH.write(serverH.read() + delta);
    }

    if (mappedSensorV != SENSOR_LEVEL)
    {
        int delta = mappedSensorV - SENSOR_LEVEL;

        serverV.write(serverV.read() + delta);
    }

    Serial.print("| servo H: " );
    Serial.print(serverH.read());
    Serial.print("| server V: ");
    Serial.print(serverV.read());

    Serial.println();
    delay(50);
}

