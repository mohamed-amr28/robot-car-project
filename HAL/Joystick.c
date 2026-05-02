#include "Joystick.h"

#define JOYSTICK_DEADZONE_LOW 300
#define JOYSTICK_DEADZONE_HIGH 720

f32 x;
f32 y;

void Joystick_Read(void)
{
    x = analogread(ADC0);
    y = analogread(ADC1);
}

void Joystick_Control(void)
{
    if (y > JOYSTICK_DEADZONE_HIGH)
    {
        MOTOR_moveForward();
    }
    else if (y < JOYSTICK_DEADZONE_LOW)
    {
        MOTOR_moveBackward();
    }
    else if (x > JOYSTICK_DEADZONE_HIGH)
    {
        MOTOR_turnRight();
    }
    else if (x < JOYSTICK_DEADZONE_LOW)
    {
        MOTOR_turnLeft();
    }
    else
    {
        MOTOR_stop();
    }
}
