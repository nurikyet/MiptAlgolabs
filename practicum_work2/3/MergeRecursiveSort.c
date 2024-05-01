#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MergeRecursive.h"

#define ERROR 0;
#define TRUE  1;

static void MergeSort(int* arr, size_t size, size_t left, size_t right);

static int Merge(int* array, int* sorted_array, size_t left, size_t mid, size_t right);
static int min(int a, int b);

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int Merge(int* array, int* sorted_array, size_t left, size_t mid, size_t right)
{
    size_t left_index  = left;
    size_t right_index = mid + 1;

    size_t index = 0;

    while (left_index <= mid || right_index <= right)
    {
        if (left_index <= mid && (right_index > right || array[left_index] < array[right_index]))
        {
            sorted_array[index++] = array[left_index++];
        }
        else
        {
            sorted_array[index++] = array[right_index++];
        }
    }

    memcpy(array + left, sorted_array, sizeof(int) * (right - left + 1));

    return TRUE;
}


void MergeSort(int* arr, size_t size, size_t left, size_t right)
{
    if (left == right)
    {
        return;
    }

    size_t mid = (right - left) / 2 + left;
    MergeSort(arr, size, left, mid);
    MergeSort(arr, size, 1 + mid, right);
    
    int* sorted_array = (int*) calloc(right - left + 1, sizeof(int));
    if (sorted_array == NULL)
    {
        return;
    }
    Merge(arr, sorted_array, left, mid, right);
    free(sorted_array);
}

void MergeSortRecursive(int* arr, size_t size)
{
    assert(arr != NULL);

    MergeSort(arr, size, (size_t)0, size - 1);
}