#include "BinHeapTesting.h"

const char*  TESTS = "../tests/";

void HeapTesting(const char* res_name, FILE* file_in, int size)
{
    if (size == 0) return;

    FILE* file_res = fopen(res_name, "a");
    if (file_res == NULL)
    {
        printf("I can't open file - %d\n", __LINE__);
        return;        
    }

    Heap* hp = HeapInsertCtor(size, 2, file_in, file_res);  

    fclose(file_res);
    HeapDtor(hp);
}

void HeapTester(const char* res_name)
{
    for(int i = FROM; i < TO; i += STEP)
    {        
        for (int j = 0; j < NUMBER_K; j++)
        {
            char file1[UCHAR_MAX];

            sprintf(file1, "%s%d_%d.in", TESTS, i, j);
            
            FILE* file_in  = fopen(file1, "rb");
            if (file_in == NULL)
            {
                printf("I can't open file - %s %d\n", file1, __LINE__); 
                return;       
            }

            HeapTesting(res_name, file_in, i);

            fclose(file_in);
        }
    }
    
}
