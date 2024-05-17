#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <time.h>

#include "LineSolver.h"
#include "LineHashFunctions.h"

int PrintResults(int* collisions, const char* res_file_name)
{
    FILE* res_file = fopen(res_file_name, "w");
    if (res_file == NULL)
    {
        return ERROR_FILE;
    }
    
    for (int i = 0; i < MOD; i++)
    {
        fprintf(res_file, "%d %d\n", i, collisions[i]);    
    }
    
    fclose(res_file);
    return NO_ERROR;
}

int FillCollisions(int* collisions, FILE* test_file, int (*hash_function)(char*))
{
    double time_spent = 0.0;
    
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        char* data = (char*)calloc(MAX_LINE_LEN + 1, sizeof(char));
        if (data == NULL)
        {
            return ERROR_OF_ALLOCATING_MEMORY;
        }
        
        if (fscanf(test_file, "%20s", data) != 1)
        {
            return ERROR_SCANF;
        }

        clock_t begin      = clock();
        
        int index_in_hash  = hash_function(data);

        clock_t end        = clock();
        time_spent        += (double)(end - begin) / CLOCKS_PER_SEC;
        collisions[index_in_hash]++;
        free(data);
    }
    printf("%lg sec\n", time_spent);
    fseek(test_file, 0, SEEK_SET);
    return NO_ERROR;
}

int GetResults(FILE* test_file, const char* res_file_name, int (*hash_function)(char*))
{
    int* collisions = (int*)calloc(MOD, sizeof(int));
    if (collisions == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    FillCollisions(collisions, test_file, hash_function);
    PrintResults(collisions, res_file_name);

    free(collisions);
    return NO_ERROR;
}
