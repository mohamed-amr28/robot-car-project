#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Types.h"
#include "GPIO_Interface.h"
#include "ADC_Interface.h"
#include "MOTOR_Interface.h"

void Joystick_Read(void);
void Joystick_Control(void);

#endif // JOYSTICK_H