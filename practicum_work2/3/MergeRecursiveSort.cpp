#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "MergeRecursive.h"

#define ERROR 0;
#define TRUE 1;

static void MergeSort(int* arr, size_t size, size_t left, size_t right);

static int Merge(int* array, size_t left, size_t mid, size_t right);
static int min(int a, int b);

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int Merge(int* array, size_t left, size_t mid, size_t right)
{
    size_t left_index  = left;
    size_t right_index = mid + 1;

    int* sorted_array = (int*) calloc(right - left + 1, sizeof(int));
    if (sorted_array == NULL)
    {
        return ERROR;
    }

    size_t index = 0;

    while (left_index <= mid && right_index <= right)
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

    while (left_index <= mid)
    {
        sorted_array[index++] = array[left_index++];
    }

    while (right_index <= right)
    {   
        sorted_array[index++] = array[right_index++];
    }

    for (int i = 0; i <= right - left; i++)
    {
        array[i + left] = sorted_array[i];
    }

    free(sorted_array);
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
    Merge(arr, left, mid, right);
}

void MergeSortRecursive(int* arr, size_t size)
{
    assert(arr != NULL);

    MergeSort(arr, size, (size_t)0, size - 1);
}