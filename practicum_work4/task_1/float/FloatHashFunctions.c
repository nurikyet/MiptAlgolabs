#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "FloatHashFunctions.h"

int FloatToIntBit(float number)
{
    unsigned int hash  = 0;
    memcpy(&hash, &number, sizeof(number));
    return hash % MOD;
}

int FloatBits(float number) 
{
    unsigned int result = 0;
    union 
    {
        float f;
        unsigned int i;
    } u;
    
    u.f = number;
    result = u.i;
    
    return result % MOD; 
}

int Exponent(float number)
{ 
    typedef union 
    {
        float f;
        struct 
        {
            unsigned int mantissa : 23;
            unsigned int exponent : 8;
            unsigned int sign : 1;
        } parts;
    } float_cast;

    float_cast data;
    data.f  = number;
    int ans = data.parts.exponent % MOD;
    return ans;
}

int Mantissa(float number)
{
    typedef union 
    {
        float f;
        struct 
        {
            unsigned int mantissa : 23;
            unsigned int exponent : 8;
            unsigned int sign : 1;
        } parts;
    } float_cast;
    float_cast data;
    data.f  = number;
    return data.parts.mantissa % MOD;
}

int FloatMultiplyHash(float number)
{
    return Mantissa(number)*Exponent(number) % MOD;
}

