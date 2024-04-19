#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MSD.h"

#define MAX 255
#define SHIFT 8

#define ERROR -1
#define TRUE 1

int RadixSortMSD(int *arr, int *result, int size, int shift) 
{
    assert(arr    != NULL);
    assert(result != NULL);

    int* count    = (int*)calloc(MAX + 1, sizeof(int));
    if(count == NULL)
    {
        return ERROR;
    }

    int* pref_cnt = (int*)calloc(MAX + 1, sizeof(int));
    if(pref_cnt == NULL)
    {
        return ERROR;
    }

    for (int i = 0; i < size; ++i) 
    {
        count[(arr[i] >> shift) & 0xFF]++;
    }

    pref_cnt[0] = 0;
    for (int i = 1; i <= MAX; ++i) 
    {
        pref_cnt[i] = pref_cnt[i-1] + count[i-1];
    }

    for (int i = 0; i < size; ++i) 
    {
        result[pref_cnt[(arr[i] >> shift) & 0xFF]++] = arr[i];
    }

    if (shift > 0) 
    {
        for (int i = 0; i < MAX; ++i) 
        {
            if (count[i] > 1) 
            {
                RadixSortMSD(result + pref_cnt[i], arr + pref_cnt[i], count[i], shift - SHIFT);
            }
        }
    }

    return TRUE;
}

void MSD(int* arr, size_t size) 
{
    assert(arr != NULL);

    int* result = (int*)calloc(size, sizeof(int));
    if (result == NULL)
    {
        return;
    }

    RadixSortMSD(arr, result, size, sizeof(int) * 8);
    
    for (size_t i = 0; i < size; ++i) 
    {
        arr[i] = result[i];
    }
    
    free(result);
}
