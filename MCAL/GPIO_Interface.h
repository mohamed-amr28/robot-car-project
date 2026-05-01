#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_Private.h"

typedef enum
{
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD
} Port_t;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} Pin_t;

typedef enum
{
    INPUT,
    INPUT_PULLUP,
    OUTPUT
} Direction_t;

typedef enum
{
    LOW,
    HIGH
} Value_t;

void pinmode(Port_t port, Pin_t pin, Direction_t direction);
void digitalwrite(Port_t port, Pin_t pin, Value_t value);
Value_t digitalread(Port_t port, Pin_t pin);

#endif // GPIO_INTERFACE_H