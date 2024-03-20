#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "RandMedianQsort.h"

static void Qsort(int* arr, int left, int right);
static void swap(int* a, int* b);

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int FindMedian(int* arr, int left, int right)
{
    int n = right - left + 1;
    int i, medianIndex = 0;
    int numMedians = (n + 4) / 5;
    int* medians = (int*)malloc(numMedians * sizeof(int));

    for(i = 0; i < n / 5; i++)
    {

        for(int j = 0; j < 5; j++)
        {
            for(int k = j + 1; k < 5; k++)
            {
                if(arr[left + 5 * i + j] > arr[left + 5 * i + k])
                {
                    swap(&arr[left + 5 * i + j], &arr[left + 5 * i + k]);
                }
            }
        }
        medians[i] = arr[left + 5 * i + 2];
    }

    if(n % 5 != 0)
    {
        int remaining = n % 5;
        for(int j = 0; j < remaining; j++)
        {
            for(int k = j + 1; k < remaining; k++)
            {
                if(arr[left + n - remaining + j] > arr[left + n - remaining + k])
                {
                    swap(&arr[left + n - remaining + j], &arr[left + n - remaining + k]);
                }
            }
        }
        medians[numMedians - 1] = arr[left + n - remaining/2 - 1];
    }

    medianIndex = numMedians == 1 ? medians[0] : FindMedian(medians, 0, numMedians - 1);

    free(medians);
    return medianIndex;
}

int RandMedianHoarPartition(int* arr, int left, int right)
{
    int pivot   = FindMedian(arr, left, right);
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
    if (left < right)
    {
        int piv_idx = RandMedianHoarPartition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void RandMedianQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, 0, size - 1);
}