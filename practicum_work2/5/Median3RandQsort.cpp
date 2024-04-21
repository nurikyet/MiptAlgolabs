#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "Median3RandQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

int GetMedian(int first, int second, int third) 
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
    assert(arr != NULL);

    int pivot   = GetMedian(arr[left + (rand() % (right - left + 1))], 
                            arr[left + (rand() % (right - left + 1))], 
                            arr[left + (rand() % (right - left + 1))]);
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

void Median3RandQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, (size_t)0, size - 1);
}