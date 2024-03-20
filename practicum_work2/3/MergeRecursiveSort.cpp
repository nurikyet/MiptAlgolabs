#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MergeRecursive.h"

static void Merge(int* array, int left, int mid, int right);
static void MergeSort(int* arr, size_t size, int left, int right);
static int min(int a, int b);

static int min(int a, int b)
{
    return a < b ? a : b;
}

static void Merge(int* array, int left, int mid, int right)
{
    size_t left_index  = left;
    size_t right_index = mid + 1;

    int* sorted_array = (int*) calloc(right - left + 1, sizeof(int));

    size_t index = 0;

    while ((int)left_index <= mid && (int)right_index <= right)
    {
        if (array[left_index] < array[right_index])
        {
            sorted_array[index++] = array[left_index++];
        }
        else 
        {
            sorted_array[index++] = array[right_index++];
        }
    }

    while ((int)left_index <= mid)
    {
        sorted_array[index++] = array[left_index++];
    }

    while ((int)right_index <= right)
    {   
        sorted_array[index++] = array[right_index++];
    }

    for (int i = 0; i <= right - left; i++)
    {
        array[i + left] = sorted_array[i];
    }

    free(sorted_array);
}


void MergeSort(int* arr, size_t size, int left, int right)
{
    if (left == right)
    {
        return;
    }

    int mid = (right - left) / 2 + left;
    MergeSort(arr, size, left, mid);
    MergeSort(arr, size, 1 + mid, right);
    Merge(arr, left, mid, right);
}

void MergeSortRecursive(int* arr, size_t size)
{
    assert(arr != NULL);
    MergeSort(arr, size, 0, (int)size - 1);
}