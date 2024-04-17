#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "BubbleSort.h"

static void swap(int* first, int* second)
{
    int* temp = first;
    first     = second;
    second    = temp;
}

void BubbleSort(int* arr, size_t size)
{
    assert(arr != NULL);

    size_t i = 0, j = 0;
    int temp = 0;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}