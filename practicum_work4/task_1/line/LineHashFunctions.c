#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#include "LineHashFunctions.h"

const int M = 1e9+7;

int LineLen(char* line)
{
    return ((int)strlen(line)) % MOD;
}

int SumLetters(char* line)
{
    int sum = 0;
    int len = (int)strlen(line);
    
    for (int i = 0; i < len; i++) 
    {
        char letter = line[i];
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) 
        {
            sum += letter;
        }
    }
    return sum % MOD;
}

int Polynomial(char *str) 
{
    long long hash = 0;
    int len = (int)strlen(str);
    for (int i = 0; i < len; i++) 
    {
        int x = (int) (str[i] - 'a' + 1);
        hash = (hash * P + x) % M;
    }
    return (int)(hash % MOD);
}

int xcrc32 (char* buf)
{
    int len = (int)strlen(buf);
    unsigned int init = 0;
    unsigned int crc = init;
    while (len--)
    {
        crc = (crc << CHAR_BIT) ^ crc32_table[((crc >> (3*CHAR_BIT)) ^ *buf) & UCHAR_MAX];
        buf++;
    }
    return crc % MOD;
}
