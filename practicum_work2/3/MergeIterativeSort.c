#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MergeIterativeSort.h"

#define ERROR 0
#define TRUE 1

static int Merge(int* arr, int* result, int left, int mid, int right);

int min(int a, int b)
{
    return a < b ? a : b;
}

static int Merge(int* arr, int* result, int left, int mid, int right)
{
    int it1          = 0;
    int it2          = 0;
    int result_index = 0;
    
    while (left + it1 < mid || mid + it2 < right)
    {
        if (mid + it2 >= right || (left + it1 < mid && arr[left + it1] < arr[mid + it2]))
        {
            result[result_index] = arr[left + it1];
            it1++;
        }
        else
        {
            result[result_index] = arr[mid + it2];
            it2++;
        }
        result_index++;
    }

    memcpy(arr + left, result, sizeof(int) * (it1 + it2));

    return TRUE;
}

void MergeSortIterative(int* arr, size_t size)
{
    for (size_t i = 1; i < size; i *= 2)
    {
        for (size_t j = 0; j < size - i; j += 2 * i)
        {
            size_t right = min(j + 2 * i, (int)size);
            size_t left  = j;

            int* result = (int*)calloc(right - left + 1, sizeof(int));
            if (result == NULL)
            {
                return;
            }

            Merge(arr, result, left, j + i, right);

            free(result);
        }
    }
}
