#include <stdio.h>
#include <stdlib.h>

#include "FloatSolver.h"
#include "FloatHashFunctions.h"

int main()
{
    FILE* test_file = fopen(TEST_FILE, "r");
    if(test_file == NULL)
    {
        return ERROR_FILE;    
    }

    GetResults(test_file, FLOAT_TO_INT_FILE, FloatToIntBit);
    GetResults(test_file, FLOAT_BITS_FILE, FloatBits);
    GetResults(test_file, EXPONENT_FILE, Exponent);
    GetResults(test_file, MANTISSA_FILE, Mantissa);
    GetResults(test_file, FLOAT_MULTIPLY_HASH_FILE, FloatMultiplyHash);

    fclose(test_file);
    return 0;
}