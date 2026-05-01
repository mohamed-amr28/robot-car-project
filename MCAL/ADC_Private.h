#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "Types.h"

#define ADMUX (*(volatile u8 *)(0x7C))  // ADC Multiplexer Selection Register
#define ADCSRA (*(volatile u8 *)(0x7A)) // ADC Control and Status Register A
#define ADCSRB (*(volatile u8 *)(0x7B)) // ADC Control and Status Register B
#define ADCL (*(volatile u8 *)(0x78))   // ADC Data Register Low Byte
#define ADCH (*(volatile u8 *)(0x79))   // ADC Data Register High Byte

#endif // ADC_PRIVATE_H