#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "IntroQsort.h"
#include "../Common.h"

static void Qsort(int* arr, int left, int right);

int IntroHoarPartition(int* arr, int left, int right)
{
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
        swap(&arr[i++], &arr[j--], sizeof(int));
    }
    return j;
}

static void Qsort(int* arr, int left, int right)
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

    Qsort(arr, 0, size - 1);
}