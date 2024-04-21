#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "LomutoQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

static size_t Partition(int* arr, int left, int right)
{
    assert(arr != NULL);

    int pivot = arr[left + (right - left) / 2];
    swap(&arr[right], &arr[left + (right - left) / 2], sizeof(int));
    size_t i = left;
    for (size_t j = left; j <= right; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i++], &arr[j], sizeof(int));
        }
    }
    swap(&arr[i], &arr[right], sizeof(int));
    return i;
}

static void Qsort(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    if (left < right)
    {
        size_t piv_idx = Partition(arr, left, right);
        Qsort(arr, left, piv_idx - 1);
        Qsort(arr, piv_idx + 1, right);
    }
}

void LomutoQsort(int* arr, size_t size)
{
    assert(arr != NULL);
    assert(size > 0);

    Qsort(arr, (size_t)0, size - 1);
}