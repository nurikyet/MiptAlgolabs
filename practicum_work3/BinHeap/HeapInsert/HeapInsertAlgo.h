#ifndef HEAP_INSERT_ALGO_H
#define HEAP_INSERT_ALGO_H

#include "../Heap.h"

Heap* HeapInsertCtor(int capacity, int k, FILE* file_in, FILE* file_res);
void GetInsertTime(Heap* h, FILE* file_in, FILE* file_res);

#endif