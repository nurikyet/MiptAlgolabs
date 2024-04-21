#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "../Common.h"

#include "OneBranchHoaraQsort.h"

static void Qsort(int* arr, size_t left, size_t right);

static size_t Partition(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    size_t piv_idx = left + (right - left) / 2;
    int pivot   = arr[piv_idx];
    size_t i       = left;
    size_t j       = right;
    while(i <= j)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i >= j)
        {
            return j;
        }
        swap(&arr[i++], &arr[j--], sizeof(int));
    }
    return j;
}

static void Qsort(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    while (left < right)
    {
        size_t piv_idx = Partition(arr, left, right);

        if (piv_idx - left < right - piv_idx)
        {
            Qsort(arr, left, piv_idx);
            left = piv_idx + 1;
        }
        else
        {
            Qsort(arr, piv_idx + 1, right);
            right = piv_idx;
        }
    }
}

void OneBranchHoaraQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, (size_t)0, size - 1);
}