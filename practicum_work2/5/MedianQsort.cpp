#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MedianQsort.h"

static void Qsort(int* arr, int left, int right);
static void swap(int* a, int* b);

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int GiveMiddle(int first, int second, int third)
{
    if (first < second)
    {
        if (second < third)
        {
            return second;
        }
        else if(first < third)
        {
            return third;
        }
        else
        {
            return first;
        }
    }
    else
    {
        if (third < second)
        {
            return third;
        }
        else if (first < third)
        {
            return first;
        }
        else
        {
            return second;
        }
    }
}

int MedianHoarPartition(int* arr, int left, int right)
{
    int piv_idx = left + (right - left) / 2;
    int pivot   = GiveMiddle(arr[left], arr[piv_idx], arr[right]);
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
        int piv_idx = MedianHoarPartition(arr, left, right);
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