#include "GPIO_interface.h"

// GPIO Program
void pinmode(Port_t port, Pin_t pin, Direction_t direction)
{
    switch (port)
    {
    case GPIO_PORTB:
        switch (direction)
        {
        case INPUT:
            clear_bit(DDRB, pin);
            break;

        case INPUT_PULLUP:
            clear_bit(DDRB, pin);
            set_bit(PORTB, pin);
            break;

        case OUTPUT:
            set_bit(DDRB, pin);
            break;
        }
        break;

    case GPIO_PORTC:
        switch (direction)
        {
        case INPUT:
            clear_bit(DDRC, pin);
            break;

        case INPUT_PULLUP:
            clear_bit(DDRC, pin);
            set_bit(PORTC, pin);
            break;

        case OUTPUT:
            set_bit(DDRC, pin);
            break;
        }
        break;
    case GPIO_PORTD:
        switch (direction)
        {
        case INPUT:
            clear_bit(DDRD, pin);
            break;

        case INPUT_PULLUP:
            clear_bit(DDRD, pin);
            set_bit(PORTD, pin);
            break;

        case OUTPUT:
            set_bit(DDRD, pin);
            break;
        }
        break;
    }
}
void digitalwrite(Port_t port, Pin_t pin, Value_t value)
{
    switch (port)
    {
    case GPIO_PORTB:
        if (value == HIGH)
        {
            set_bit(PORTB, pin);
        }
        else
        {
            clear_bit(PORTB, pin);
        }
        break;

    case GPIO_PORTC:
        if (value == HIGH)
        {
            set_bit(PORTC, pin);
        }
        else
        {
            clear_bit(PORTC, pin);
        }
        break;

    case GPIO_PORTD:
        if (value == HIGH)
        {
            set_bit(PORTD, pin);
        }
        else
        {
            clear_bit(PORTD, pin);
        }
    }
}
Value_t digitalread(Port_t port, Pin_t pin)
{
    u8 pinValue = 0;
    switch (port)
    {
    case GPIO_PORTB:
        if (read_bit(PINB, pin))
        {
            pinValue = HIGH;
        }
        else
        {
            pinValue = LOW;
        }
        break;

    case GPIO_PORTC:
        if (read_bit(PINC, pin))
        {
            pinValue = HIGH;
        }
        else
        {
            pinValue = LOW;
        }
        break;

    case GPIO_PORTD:
        if (read_bit(PIND, pin))
        {
            pinValue = HIGH;
        }
        else
        {
            pinValue = LOW;
        }
        break;
    }
    return pinValue;
}