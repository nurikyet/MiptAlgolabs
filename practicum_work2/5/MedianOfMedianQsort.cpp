#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "MedianOfMedianQsort.h"
#include "../Common.h"

#define ERROR -1
#define TRUE 1
#define ARR_SIZE 5

static void Qsort(int* arr, int left, int right);

size_t Select(int* arr, size_t left, size_t right, size_t n);
size_t GetPivot(int* arr, size_t left, size_t right);

void InsertionSort(int* arr, size_t left, size_t right);



size_t GetPivot(int* arr, size_t left, size_t right) 
{
    if (right - left < ARR_SIZE) 
    {
        InsertionSort(arr, left, right);
        return (left + right) / 2;
    }
    for (size_t i = left; i <= right; i += ARR_SIZE) 
    {
        size_t sub_right = i + ARR_SIZE - 1;
        if (sub_right > right) 
        {
            sub_right = right;
        }
        size_t median5 = (i + sub_right) / 2;
        swap(&arr[median5], &arr[left + (i - left) / ARR_SIZE], sizeof(int));
    }

    size_t mid = (right - left) / (2 * ARR_SIZE) + left + 1;

    return Select(arr, left, left + (right - left) / ARR_SIZE, mid);
}

void InsertionSort(int* arr, size_t left, size_t right) 
{
    for (size_t i = left + 1; i < right; ++i) 
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = current;
    }
}

size_t Select(int* arr, size_t left, size_t right, size_t n) 
{
    assert(arr != NULL);
    while (true) 
    {
        if (left == right) 
        {
            return left;
        }
        size_t pivot_index = GetPivot(arr, left, right);
        pivot_index        = Partition(arr, left, right);
        if (n == pivot_index) 
        {
            return n;
        } 
        else if (n < pivot_index) 
        {
            right = pivot_index - 1;
        } 
        else 
        {
            left = pivot_index + 1;
        }
    }
}

static int Partition(int* arr, int left, int right)
{
    int pivot_idx = GetPivot(arr, left, right);
    int pivot   = arr[pivot_idx];
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

static void Qsort(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t piv_idx = Partition(arr, left, right);
        Qsort(arr, left, piv_idx);
        Qsort(arr, piv_idx + 1, right);
    }
}

void RandMedianQsort(int* arr, size_t size)
{
    assert(size > 0);
    assert(arr != NULL);

    Qsort(arr, (size_t)0, size - 1);
}