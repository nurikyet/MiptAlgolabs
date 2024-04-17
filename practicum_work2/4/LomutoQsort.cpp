#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "LomutoQsort.h"

static void Qsort(int* arr, int left, int right);
static void swap(int* first, int* second);

static void swap(int* first, int* second)
{
    int temp = *first;
    *first   = *second;
    *second  = temp;
}

int LomutoPartition(int* arr, int left, int right)
{
    assert(arr != NULL);

    int pivot = arr[left + (right - left) / 2];
    swap(&arr[right], &arr[left + (right - left) / 2]);
    int i = left;
    for (int j = left; j <= right; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i++], &arr[j]);
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

static void Qsort(int* arr, int left, int right)
{
    assert(arr != NULL);

    if (left < right)
    {
        int piv_idx = LomutoPartition(arr, left, right);
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