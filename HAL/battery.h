#ifndef BATTERY_H
#define BATTERY_H

#include "Types.h"
#include "GPIO_Interface.h"
#include "ADC_Interface.h"

#define BATTERY_LOW_THRESHOLD 6.5f

extern f32 batt;

void battery_read(void);
void battery(f32 batt);

#endif // BATTERY_H