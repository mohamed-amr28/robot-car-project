#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "Types.h"
#include "GPIO_Interface.h"

typedef enum
{
    MOTOR_A,
    MOTOR_B
} MotorID;

typedef enum
{
    MOTOR_STOP,
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} MotorDirection;

void MOTOR_setDirection(MotorID motor, MotorDirection direction);
void MOTOR_moveForward(void);
void MOTOR_moveBackward(void);
void MOTOR_turnRight(void);
void MOTOR_turnLeft(void);
void MOTOR_stop(void);

#endif // INTERFACE_H