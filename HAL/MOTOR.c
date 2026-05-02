#include "MOTOR_Interface.h"

void MOTOR_setDirection(MotorID motor, MotorDirection direction)
{
    switch (motor)
    {

    case MOTOR_A:
        switch (direction)
        {
        case MOTOR_FORWARD:
            digitalwrite(GPIO_PORTB, PIN0, HIGH);
            digitalwrite(GPIO_PORTB, PIN1, LOW);
            break;

        case MOTOR_BACKWARD:
            digitalwrite(GPIO_PORTB, PIN0, LOW);
            digitalwrite(GPIO_PORTB, PIN1, HIGH);
            break;

        case MOTOR_STOP:
            digitalwrite(GPIO_PORTB, PIN0, LOW);
            digitalwrite(GPIO_PORTB, PIN1, LOW);
            break;
        }
        break;

    case MOTOR_B:
        switch (direction)
        {
        case MOTOR_FORWARD:
            digitalwrite(GPIO_PORTB, PIN2, HIGH);
            digitalwrite(GPIO_PORTB, PIN3, LOW);
            break;

        case MOTOR_BACKWARD:
            digitalwrite(GPIO_PORTB, PIN2, LOW);
            digitalwrite(GPIO_PORTB, PIN3, HIGH);
            break;

        case MOTOR_STOP:
            digitalwrite(GPIO_PORTB, PIN2, LOW);
            digitalwrite(GPIO_PORTB, PIN3, LOW);
            break;
        }
        break;
    }
}

void MOTOR_moveForward(void)
{
    MOTOR_setDirection(MOTOR_A, MOTOR_FORWARD);
    MOTOR_setDirection(MOTOR_B, MOTOR_FORWARD);
}

void MOTOR_moveBackward(void)
{
    MOTOR_setDirection(MOTOR_A, MOTOR_BACKWARD);
    MOTOR_setDirection(MOTOR_B, MOTOR_BACKWARD);
}

void MOTOR_turnLeft(void)
{
    MOTOR_setDirection(MOTOR_A, MOTOR_BACKWARD);
    MOTOR_setDirection(MOTOR_B, MOTOR_FORWARD);
}

void MOTOR_turnRight(void)
{
    MOTOR_setDirection(MOTOR_A, MOTOR_FORWARD);
    MOTOR_setDirection(MOTOR_B, MOTOR_BACKWARD);
}

void MOTOR_stop(void)
{
    MOTOR_setDirection(MOTOR_A, MOTOR_STOP);
    MOTOR_setDirection(MOTOR_B, MOTOR_STOP);
}