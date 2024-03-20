#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "FlagQsort.h"

static void Qsort(int* arr, int left, int right);

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void FlagPartition(int* arr, int left, int right, int* equals_form, int* equals_to)
{
    int pivot = arr[left + (right - left) / 2];
    int mid = left;

    while(mid <= right)
    {
        if (arr[mid] < pivot)
        {
            swap(&arr[left++], &arr[mid++]);
        }
        else if(arr[mid] == pivot)
        {
            ++mid;
        }
        else
        {
            swap(&arr[mid], &arr[right--]);
        }
    }
    *equals_form = left;
    *equals_to   = right;
}

static void Qsort(int* arr, int left, int right)
{
    if (left < right)
    {
        int equals_from = 0, equals_to = 0;
        FlagPartition(arr, left, right, &equals_from, &equals_to);
        Qsort(arr, left, equals_from - 1);
        Qsort(arr, equals_to + 1, right);
    }
}

void FlagQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, 0, (int)size - 1);
}