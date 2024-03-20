#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MergeIterativeSort.h"
 
static void Merge(int* arr, int left, int mid, int right);

int min(int a, int b)
{
    return a < b ? a : b;
}

static void Merge(int* arr, int left, int mid, int right)
{
    int it1     = 0;
    int it2     = 0;
    int* result = (int*)calloc(right - left + 1, sizeof(int));

    while (left + it1 < mid && mid + it2 < right)
    {
        if (arr[left + it1] < arr[mid + it2])
        {
            result[it1 + it2] = arr[left + it1];
            it1++;
        }
        else
        {
            result[it1 + it2] = arr[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid)
    {
        result[it1 + it2] = arr[left + it1];
        it1++;
    }

    while (mid + it2 < right)
    {
        result[it1 + it2] = arr[mid + it2];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++)
    {
        arr[left + i] = result[i];
    }
    free(result);
}
void MergeSortIterative(int* arr, size_t size)
{
    for(int i = 1; i < (int)size; i *= 2)
    {
        for (int j = 0; j < (int)size - i; j += 2 * i)
        {
            Merge(arr, j, j + i, min(j + 2 * i, (int)size));
        }
    }
}