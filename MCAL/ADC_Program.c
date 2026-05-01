#include "ADC_interface.h"

void ADC_Init(void)
{
    set_bit(ADMUX, 6);   // AVcc reference
    clear_bit(ADMUX, 7); // AVcc reference
    clear_bit(ADMUX, 5);
    set_bit(ADCSRA, 2);
    set_bit(ADCSRA, 1);
    set_bit(ADCSRA, 0); // Prescaler of 128
    set_bit(ADCSRA, 7); // Enable ADC
}
u16 analogread(u8 channel)
{
    u16 result = 0;
    // Select the ADC channel (0-7)
    // Ensure channel is between 0 and 7
    ADMUX = (1 << 6) | (channel & 0x07); // Clear previous channel and set new channel

    // Start the conversion
    set_bit(ADCSRA, 7); // Enable ADC
    set_bit(ADCSRA, 6); // Start conversion

    // Wait for conversion to complete
    while (read_bit(ADCSRA, 6))
        ; // Wait until ADSC bit is cleared

    // Read the ADC value (10 bits)
    result = ADCL;         // Read low byte first
    result |= (ADCH << 8); // Read high byte and combine

    return result;
}