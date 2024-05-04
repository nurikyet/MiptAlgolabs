#ifndef CHAIN_HASH_H
#define CHAIN_HASH_H

#define LEN 1024
#define POISON -1

#define NUMBER_OF_ELEMENTS 1000000
#define MAX_LOAD_FACTOR 0.6

#define ABOBA printf("%s %d\n", __func__, __LINE__);

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
    struct Node* next;
} Node;

typedef struct Table
{
    size_t size;
    size_t capacity;
    Node* hash_table;
}Table;


bool check(Table* table, int value);
void delete(Table* table, int value);
void TableDtor(Table* table);
void LoadFactorTester(FILE* res_file, int capacity, double load_factor);
Table* Rehash(Table* table, double load_factor);
Table* TableCtor(int capacity);
Table* add(Table* table, int value, double load_factor);

const double A = 0.6180339887;

const int FIRST_MOD  = 3;
const int SECOND_MOD = 4;

const char* FIRST_TEST_FILE   = "result/1/first_test";
const char* SECOND_TEST_FILE  = "result/2/second_test";

#endif