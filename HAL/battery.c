#include "battery.h"

f32 batt = 0.0f;

void battery_read(void)
{
    batt = analogread(ADC2) * 1.5f * 5.0f / 1023.0f;
}

void battery(f32 batt)
{
    if (batt > BATTERY_LOW_THRESHOLD)
    {
        digitalwrite(GPIO_PORTD, PIN2, HIGH);
        digitalwrite(GPIO_PORTD, PIN3, LOW);
    }
    else
    {
        digitalwrite(GPIO_PORTD, PIN3, HIGH);
        digitalwrite(GPIO_PORTD, PIN2, LOW);
    }
}
