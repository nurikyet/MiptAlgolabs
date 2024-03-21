#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MSD.h"

#define MAX 255
#define SHIFT 8

void RadixSortMSD(int *arr, int *result, int n, int shift) 
{
    int count[MAX+1]    = {0};
    int pref_cnt[MAX+1] = {0};

    for (int i = 0; i < n; ++i) 
    {
        count[(arr[i] >> shift) & 0xFF]++;
    }

    pref_cnt[0] = 0;
    for (int i = 1; i <= MAX; ++i) 
    {
        pref_cnt[i] = pref_cnt[i-1] + count[i-1];
    }

    for (int i = 0; i < n; ++i) 
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
}

void MSD(int* arr, size_t size) 
{
    int* result = (int*)malloc(size * sizeof(int));
    RadixSortMSD(arr, result, size, sizeof(int) * 8);
    
    for (size_t i = 0; i < size; ++i) 
    {
        arr[i] = result[i];
    }
    
    free(result);
}
