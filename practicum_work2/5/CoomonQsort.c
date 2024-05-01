#include "CommonQsort.h"
#include "../Common.h"

size_t PartitionHelper(int* arr, size_t left, size_t right, int pivot)
{
    size_t i = left;
    size_t j = right;
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        swap(&arr[i++], &arr[j--], sizeof(int));
    }
    return j;
}
