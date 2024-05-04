#include <stdio.h>
#include <stdlib.h>

#include "IntSolver.h"
#include "IntHashFunctions.h"

int main()
{
    FILE* test_file = fopen(TEST_FILE, "r");
    if(test_file == NULL)
    {
        ABOBA;
        return ERROR_FILE;    
    }

    GetResults(test_file, DIVISION_FILE, DivisionMethod);
    GetResults(test_file, BIT_FILE, BitRepresentationMethod);
    GetResults(test_file, MULTIPLICATION_FILE, MultiplicationMethod);

    fclose(test_file);
    return 0;
}