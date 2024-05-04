#include <stdio.h>
#include <stdlib.h>

#include "LineSolver.h"
#include "LineHashFunctions.h"

int main()
{
    FILE* test_file = fopen(TEST_FILE, "r");
    if(test_file == NULL)
    {
        return ERROR_FILE;    
    }
    GetResults(test_file, LINE_LEN_FILE, LineLen);
    GetResults(test_file, SUM_LETTERS_FILE, SumLetters);
    GetResults(test_file, POLINOMIAL_FILE, Polynomial);
    GetResults(test_file, CRC_32_FILE, xcrc32);

    fclose(test_file);
    return 0;
}