#ifndef BIN_HEAP_TESTING_H
#define BIN_HEAP_TESTING_H

#include "HeapInsert/HeapInsertAlgo.h"
#include "HeapLine/HeapLineAlgo.h"

#define NUMBER_K 1
#define CHILDREN_NUM 2

const int FROM  = 100000;
const int TO    = 1000000;
const int STEP  = 100000;

void HeapTester(const char* out_folder);
void HeapTesting(const char* res_name, FILE* file_in, int size);

#endif