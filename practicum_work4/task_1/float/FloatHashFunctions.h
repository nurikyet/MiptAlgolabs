#ifndef FLOAT_FUNCTIONS_H
#define FLOAT_FUNCTIONS_H

#define MOD 1000

// Максимальное количество битов в мантиссе
#define MANTISSA_BITS 23

// Смещение для порядка
#define EXPONENT_BIAS 127
#define TOTAL_BITS 32

// Количество битов в порядке
#define EXPONENT_BITS 8

// Маска для знака
#define SIGN_MASK 0x80000000

// Маска для порядка
#define EXPONENT_MASK 0x7F800000

// Маска для мантиссы
#define MANTISSA_MASK 0x007FFFFF

#define ABOBA printf("%s %d\n", __func__, __LINE__);

enum Status
{
    NO_ERROR                   =  0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_SCANF                = -2,
    ERROR_FILE                 = -3
};

int FloatToIntBit(float number);
int FloatBits(float number);
int Exponent(float number);
int Mantissa(float number);
int FloatMultiplyHash(float number);

#endif 