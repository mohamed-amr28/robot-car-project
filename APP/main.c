#include "Joystick.h"
#include "battery.h"
#include "MOTOR_Interface.h"
#include "GPIO_Interface.h"
#include "ADC_Interface.h"
#include "Types.h"

int main(void)
{
    ADC_Init();

    // Motor control pins
    pinmode(GPIO_PORTB, PIN0, OUTPUT);
    pinmode(GPIO_PORTB, PIN1, OUTPUT);
    pinmode(GPIO_PORTB, PIN2, OUTPUT);
    pinmode(GPIO_PORTB, PIN3, OUTPUT);

    // Battery indicator LEDs
    pinmode(GPIO_PORTD, PIN2, OUTPUT);
    pinmode(GPIO_PORTD, PIN3, OUTPUT);

    // Analog joystick / battery pins (ADC channels)
    pinmode(GPIO_PORTC, PIN0, INPUT);
    pinmode(GPIO_PORTC, PIN1, INPUT);
    pinmode(GPIO_PORTC, PIN2, INPUT);

    MOTOR_stop();

    while (1)
    {
        Joystick_Read();
        Joystick_Control();
        battery_read();
        battery(batt);

        if (batt <= BATTERY_LOW_THRESHOLD)
        {
            MOTOR_stop();
        }
    }

    return 0;
}
