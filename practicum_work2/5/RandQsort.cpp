#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "RandQsort.h"

static void Qsort(int* arr, int left, int right);
static void swap(int* a, int* b);

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int RandQsortHoarPartition(int* arr, int left, int right)
{
    int pivot   = arr[left + (rand() % (right - left + 1))];
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

void Qsort(int* arr, int left, int right)
{
    if (left < right)
    {
        int piv_idx = RandQsortHoarPartition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void RandQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, 0, size - 1);
}