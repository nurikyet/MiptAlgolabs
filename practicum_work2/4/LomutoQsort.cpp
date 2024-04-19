#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "LomutoQsort.h"
#include "../Common.h"

static void Qsort(int* arr, int left, int right);

static int Partition(int* arr, int left, int right)
{
    assert(arr != NULL);

    int pivot = arr[left + (right - left) / 2];
    swap(&arr[right], &arr[left + (right - left) / 2], sizeof(int));
    int i = left;
    for (int j = left; j <= right; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i++], &arr[j], sizeof(int));
        }
    }
    swap(&arr[i], &arr[right], sizeof(int));
    return i;
}

static void Qsort(int* arr, int left, int right)
{
    assert(arr != NULL);

    if (left < right)
    {
        int piv_idx = Partition(arr, left, right);
        Qsort(arr, left, piv_idx - 1);
        Qsort(arr, piv_idx + 1, right);
    }
}

void LomutoQsort(int* arr, size_t size)
{
    assert(arr != NULL);
    assert(size > 0);

    Qsort(arr, 0, (int)size - 1);
}