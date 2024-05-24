#include "HeapInsertAlgo.h"

void GetInsertTime(Heap* h, FILE* file_in, FILE* file_res)
{
    double time_spent = 0.0;

    for(int i = 0; i < h->capacity; i++)
    {
        int data = 0;
        fscanf(file_in, "%d", &data);

        clock_t begin = clock();
        
        HeapInsert(h, data);

        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    fprintf(file_res, "%d %lf\n", h->capacity, time_spent);
}

Heap* HeapInsertCtor(int capacity, int k, FILE* file_in, FILE* file_res)
{
    Heap* h     = (Heap*)calloc(1, sizeof(Heap));
    if (h == NULL)
    {
        return (Heap*)ERROR_OF_ALLOCATING_MEMORY;
    }
    h->size     = 0;
    h->capacity = capacity;
    h->children = k;

    int* arr = (int*)calloc(capacity, sizeof(int));
    if (arr == NULL)
    {
        return (Heap*)ERROR_OF_ALLOCATING_MEMORY;
    }

    h->arr      = arr;

    GetInsertTime(h, file_in, file_res);

    return h;
}