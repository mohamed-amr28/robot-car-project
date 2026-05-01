#ifndef TYPES_H
#define TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;
typedef long double f128;

#define clear_bit(reg, bit) ((reg) &= ~(1 << (bit)))
#define set_bit(reg, bit) ((reg) |= (1 << (bit)))
#define toggle_bit(reg, bit) ((reg) ^= (1 << (bit)))
#define read_bit(reg, bit) (((reg) >> (bit)) & 1)

#endif // TYPES_H