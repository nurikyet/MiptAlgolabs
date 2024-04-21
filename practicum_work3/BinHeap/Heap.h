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
    int  size;
    int  capacity;
} Heap;

enum Status
{
    NO_ERROR                   = 0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_SCANF                = -2
};

void swap(void* a, void* b, size_t elem_size);
void SiftDown(Heap* hp, int index);
void SiftUp(Heap* hp, int index);
void HeapInsert(Heap* hp, int data);
void HeapDtor(Heap* h);


int GetChild(int index, int k, int i);
int GetParent(int index, int k);
int GetMax(Heap* hp, int index);
int ExtractMax(Heap* h);

#endif 