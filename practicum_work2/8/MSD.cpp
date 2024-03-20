#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "../Common.h"
#include "MSD.h"

#define MAX 256

void CountSort(int* arr, int n, int digit_pos)
{
    int count[10] = {0};
    int* output = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        int digit = (arr[i] / digit_pos) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / digit_pos) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }

    free(output);
}

void RadixSort(int* arr, size_t n) 
{
    int max_num = 0;
    for (int i = 0; i < (int)n; i++) 
    {
        if (arr[i] > max_num) 
        {
            max_num = arr[i];
        }
    }

    int digit_pos = 1;
    while (max_num / digit_pos > 0) 
    {
        CountSort(arr, (int)n, digit_pos);
        digit_pos *= 10;
    }
}