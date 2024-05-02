#ifndef HEAP_LINE_ALGO_H
#define HEAP_LINE_ALGO_H

#include "../Heap.h"

void Heapify(Heap* heap);
Heap* HeapLineCtor(int capacity, int k, FILE* file_in, FILE* file_res);

#endif