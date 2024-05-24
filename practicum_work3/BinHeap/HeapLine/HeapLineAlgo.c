#include "HeapLineAlgo.h"

void Heapify(Heap* heap)
{
    for (int i = heap->capacity / 2 - 1; i >= 0; i--) 
    {
        SiftDown(heap, i);
    }
}

Heap* HeapLineCtor(int capacity, int k, FILE* file_in, FILE* file_res)
{
    Heap* heap     = (Heap*)calloc(1, sizeof(Heap));
    if (heap == NULL)
    {
        return (Heap*)ERROR_OF_ALLOCATING_MEMORY;
    }
    heap->size     = capacity;
    heap->capacity = capacity;
    heap->children = k;

    int* arr = (int*)calloc(capacity, sizeof(int));
    if (arr == NULL)
    {
        return (Heap*)ERROR_OF_ALLOCATING_MEMORY;
    }
    for (int i = 0; i < capacity; i++)
    {
        if (fscanf(file_in, "%d", &arr[i]) != 1)
        {
            return (Heap*)ERROR_SCANF;
        }
    }
    heap->arr = arr;

    double time_spent = 0.0;
    clock_t begin = clock();

    Heapify(heap);

    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(file_res, "%d %lf\n", capacity, time_spent);

    return heap;
}
