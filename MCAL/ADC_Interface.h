#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "ADC_Private.h"

typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
} ADC_Channel;

typedef enum
{
    AREF,
    AVCC,
    INTERNAL
} ADC_REFV;

typedef enum
{
    DIV2,
    DIV4,
    DIV8,
    DIV16,
    DIV32,
    DIV64,
    DIV128
} ADC_Prescaler;

void ADC_Init(void);
u16 analogread(u8 channel);

#endif // ADC_INTERFACE_H