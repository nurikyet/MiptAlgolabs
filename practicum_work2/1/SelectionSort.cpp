#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "SelectionSort.h"

static void swap(int* first, int* second)
{
    int* temp = first;
    first     = second;
    second    = temp;
}

void SelectionSort(int* arr, size_t size)
{
    assert(arr != NULL);

    int min = INT_MAX, temp = 0;
    for(size_t i = 0; i < size - 1; i++)
    {
        min = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min == i)
        {
            continue;
        }
        swap(&arr[i], &arr[min]);
    }
}
