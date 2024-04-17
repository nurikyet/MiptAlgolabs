#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "OneBranchHoaraQsort.h"

static void Qsort(int* arr, int left, int right);
static void swap(int* first, int* second);

static void swap(int* first, int* second)
{
    int temp = *first;
    *first   = *second;
    *second  = temp;
}

int OneBranchHoarPartition(int* arr, int left, int right)
{
    assert(arr != NULL);

    int piv_idx = left + (right - left) / 2;
    int pivot   = arr[piv_idx];
    int i       = left;
    int j       = right;
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
        swap(&arr[i++], &arr[j--]);
    }
    return j;
}

static void Qsort(int* arr, int left, int right)
{
    assert(arr != NULL);

    while (left < right)
    {
        int piv_idx = OneBranchHoarPartition(arr, left, right);

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

    Qsort(arr, 0, (int)size - 1);
}