#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "InsertionSort.h"
#include "../Common.h"

/*
const int FROM = 0;
const int TO   = 1000;
const int STEP = 50;
const int K    = 5;

const char FOLDER[100] = "small_tests";
*/
#define GET_CMP(a, b) ((a) > (b))

void InsertionSort(int* arr, size_t size)
{
    int temp = 0;
    size_t i = 0, j = 0;
    for(i = 1; i < size; i++)
    {
        if (GET_CMP(arr[i - 1], arr[i]))
        {
            j = i;
        }
        while(GET_CMP(arr[j - 1], arr[j]) && j > 0)
        {
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
/*
void PrintArr(int* arr, int size)
{
    printf("Massiv size %d\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);        
    }    
    printf("\n");
}

void ArrCtor(FILE* file, int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%d", &arr[i]);        
    }
}

void GiveTime(FILE* file, int* arr, int size)
{
    if (size == 0) return;

    double time_spent = 0.0;
    clock_t begin = clock();

    InsertionSort(arr, size);  
    
    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(file, "%d %lf\n", size, time_spent);

}

void Testing(const char* res_name, FILE* file_in, FILE* file_out, int size)
{
    if (size == 0) return;

    int* arr = (int*)calloc(size + 1, sizeof(int));
    ArrCtor(file_in, arr, size);   

    FILE* file_res = fopen(res_name, "a");
    if (file_res == NULL)
    {
        printf("I can't open file - %d\n", __LINE__);
        return;        
    }
    GiveTime(file_res, arr, size);

    int* res = (int*)calloc(size + 1, sizeof(int));
    ArrCtor(file_out, res, size);

    for (int i = 0; i < size; i++)
    {
        if(arr[i] != res[i])
        {
            printf("arr = %d, res = %d\n", arr[i], res[i]); 

            printf("your algorithm is incorrect, it fails on the test %d\n", i);
            assert(false);        
        }
    }
    fclose(file_res);
    free(arr);
    free(res);
}

void Tester(const char* file_res)
{
    for(int i = FROM; i < TO; i += STEP)
    {
        char number[100];
        sprintf(number, "%d", i);
        strcat(number, "_");
        
        for (int j = 0; j < K; j++)
        {
            char file_name[140];
            sprintf(file_name, "%s%d", number, j);

            char file1[256];
            char file2[256];
            sprintf(file1, "%s/%s.in",  FOLDER, file_name);
            sprintf(file2, "%s/%s.out",  FOLDER, file_name);

            FILE* file_in  = fopen(file1, "rb");
            if (file_in == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            }

            FILE* file_out = fopen(file2, "rb");
            if (file_out == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            } 
            Testing(file_res, file_in, file_out, i);

            fclose(file_in);
            fclose(file_out);
        }
    }
    
}

int main()
{
    const char* res = "results/insertion_sort.out";
    Tester(res);

    return 0;
}
*/
