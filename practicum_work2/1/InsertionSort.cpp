#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "InsertionSort.h"

#define GET_CMP(a, b) ((a) > (b))

static void swap(int* first, int* second)
{
    int* temp = first;
    first     = second;
    second    = temp;
}

void InsertionSort(int* arr, size_t size)
{
    assert(arr != NULL);

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
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}
