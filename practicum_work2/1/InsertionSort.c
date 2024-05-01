#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "InsertionSort.h"
#include "../Common.h"

#define GET_CMP(a, b) ((a) > (b))

void InsertionSort(int* arr, size_t size)
{
    assert(arr != NULL);

    for(size_t i = 1, j = 0; i < size; i++)
    {
        if (GET_CMP(arr[i - 1], arr[i]))
        {
            j = i;
        }
        while(GET_CMP(arr[j - 1], arr[j]) && j > 0)
        {
            swap(&arr[j - 1], &arr[j], sizeof(int));
            j--;
        }
    }
}
