#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "IntroQsort.h"
#include "../5/CommonQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

size_t IntroHoarPartition(int* arr, size_t left, size_t right)
{
    size_t piv_idx = left + (right - left) / 2;
    int    pivot   = arr[piv_idx];

    return PartitionHelper(arr, left, right, pivot);
}

static void Qsort(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        int piv_idx = IntroHoarPartition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void IntroQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, (size_t)0, size - 1);
}