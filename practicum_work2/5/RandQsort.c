#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "RandQsort.h"
#include "CommonQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

static size_t Partition(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    int pivot   = arr[left + (rand() % (right - left + 1))];

    return PartitionHelper(arr, left, right, pivot);
}

void Qsort(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    if (left < right)
    {
        size_t piv_idx = Partition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void RandQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, 0, size - 1);
}