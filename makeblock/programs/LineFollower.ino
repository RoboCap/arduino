# Author: Piotr Fleger

#include <Makeblock.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define MAX_SPEED 255
#define INIT_MAX_SPEED 255

MeLineFollower lineFollower(PORT_3);

MeDCMotor motorLeft(M1);
MeDCMotor motorRight(M2);
boolean wasOut = false;

int leftMotor = 0;
int rightMotor = 0;
boolean leftOutLast = false;
boolean rightOutLast = false;

int turnSpeed = 255; //180
int turnSpeed2 =180; //120

int minOutSpeed = 200;

void setup()
{
}

void loop()
{
    int sensorState = lineFollower.readSensors();
    switch(sensorState) {
        case S1_IN_S2_OUT:
            leftMotor = turnSpeed2;
            rightMotor = turnSpeed;
            rightOutLast = true;
            leftOutLast = false;
            wasOut = true;
            break;
        case S1_OUT_S2_IN:
            leftMotor = turnSpeed;
            rightMotor = turnSpeed2;
            leftOutLast = true;
            rightOutLast = false;
            wasOut=true;
            break;
        case S1_IN_S2_IN:
            if (wasOut) {
                leftMotor = MAX_SPEED;
                rightMotor = MAX_SPEED;
            } else {
                leftMotor = INIT_MAX_SPEED;
                rightMotor = INIT_MAX_SPEED;
            }
            leftOutLast = false;
            rightOutLast = false;
            break;
        case S1_OUT_S2_OUT:
            wasOut = true;
            if (rightOutLast) {
                leftMotor = 0;
                rightMotor = turnSpeed;
            } else if (leftOutLast) {
                leftMotor = turnSpeed;
                rightMotor = -0;
            } else {
                leftMotor = 0;
                rightMotor = 0;
            }
            break;
    }

    motorLeft.run(leftMotor);
    motorRight.run(-rightMotor);
}
