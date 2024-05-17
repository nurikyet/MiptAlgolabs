#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define OPEN_HASH_2

#ifdef  OPEN_HASH_1
#include "open_hash_1/OpenHash1.h"
const char* FIRST_TEST_FILE   = "open_hash_1/result/1/first_test";
const char* SECOND_TEST_FILE  = "open_hash_1/result/2/second_test";

#elif defined(OPEN_HASH_2)
#include "open_hash_2/OpenHash2.h"
const char* FIRST_TEST_FILE   = "open_hash_2/result/1/first_test";
const char* SECOND_TEST_FILE  = "open_hash_2/result/2/second_test";

#elif defined(DOUBLE_HASH)
#include "2_hash/DoubleHash.h"
const char* FIRST_TEST_FILE   = "2_hash/result/1/first_test";
const char* SECOND_TEST_FILE  = "2_hash/result/2/second_test";

#endif


#define LEN 1024
#define POISON -1

#define NUMBER_OF_ELEMENTS 1000000

enum Status
{
    NO_ERROR                   =  0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_SCANF                = -2,
    ERROR_FILE                 = -3
};

typedef struct Node
{
    int value;
} Node;

typedef struct Table
{
    size_t size;
    size_t capacity;
    Node** hash_table;
}Table;

double  GiveLoadFactor(Table* table);

Table* Rehash(Table* table, double load_factor);
Table* TableCtor(size_t capacity);
Table* add(Table* table, int key, double load_factor);
bool check(Table* table, int key);

void TableDtor(Table* table);

const int FIRST_MOD  = 3;
const int SECOND_MOD = 4;

#define ABOBA printf("%s %d\n", __func__, __LINE__);

int hash1(int key, size_t table_size);

#endif