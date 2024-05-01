#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LEN 1000

typedef struct
{
    int* arr;
    int  children;
    size_t  size;
    size_t  capacity;
} Heap;

enum Status
{
    NO_ERROR                   = 0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_SCANF                = -2
};

void HeapInsert(Heap* hp, int data);
void HeapDtor(Heap* h);

int GetMax(Heap* hp, size_t index);
int ExtractMax(Heap* h);

#endif 