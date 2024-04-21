#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "FlagQsort.h"
#include "../Common.h"

static void Qsort(int* arr, size_t left, size_t right);

static void Partition(int* arr, size_t left, size_t right, size_t* equals_form, size_t* equals_to)
{
    assert(arr != NULL);

    int pivot = arr[left + (right - left) / 2];
    size_t mid = left;

    while(mid <= right)
    {
        if (arr[mid] < pivot)
        {
            swap(&arr[left++], &arr[mid++], sizeof(int));
        }
        else if(arr[mid] == pivot)
        {
            ++mid;
        }
        else
        {
            swap(&arr[mid], &arr[right--], sizeof(int));
        }
    }
    *equals_form = left;
    *equals_to   = right;
}

static void Qsort(int* arr, size_t left, size_t right)
{
    assert(arr != NULL);

    if (left < right)
    {
        size_t equals_from = 0, equals_to = 0;
        Partition(arr, left, right, &equals_from, &equals_to);
        Qsort(arr, left, equals_from - 1);
        Qsort(arr, equals_to + 1, right);
    }
}

void FlagQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, (size_t)0, size - 1);
}