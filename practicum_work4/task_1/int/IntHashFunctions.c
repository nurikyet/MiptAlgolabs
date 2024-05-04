#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "IntHashFunctions.h"

int DivisionMethod(int number)
{
    return (number % DEVISION % MOD);
}

int BitRepresentationMethod(int number)
{
    unsigned int result = 0;
    for (int i = INT_NUMBER_LEN - 1; i >= 0; i--)
    {
        result |= ((number >> i) & 1) << i;
    }
    return result % MOD;
}

int MultiplicationMethod(int number)
{
    return MOD * (number * A - (int)(number*A));
}