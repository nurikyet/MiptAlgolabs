#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "BubbleSort.h"
#include "../Common.h"

void BubbleSort(int* arr, size_t size)
{
    assert(arr != NULL);

    for(size_t i = 0; i < size - 1; i++)
    {
        for(size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], sizeof(int));
            }
        }
    }
}