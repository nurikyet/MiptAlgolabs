#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MedianQsort.h"
#include "CommonQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

int GiveMiddle(int first, int second, int third) 
{
    if (first < second && second < third) 
    {
        return second;
    }
    else if (second < first && first < third) 
    {
        return first;
    }
    else 
    {
        return third;
    }
}

static size_t Partition(int* arr, size_t left, size_t right)
{
    size_t piv_idx = left + (right - left) / 2;
    int pivot      = GiveMiddle(arr[left], arr[piv_idx], arr[right]);
    
    return PartitionHelper(arr, left, right, pivot);
}

static void Qsort(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t piv_idx = Partition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void MedianQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, 0, size - 1);
}