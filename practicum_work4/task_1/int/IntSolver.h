#ifndef INT_SOLVER_H
#define INT_SOLVER_H

#define MAX_LEN 10000
#define NUMBER_OF_ELEMENTS 1000000

static const char*  DIVISION_FILE       = "result/res_division.txt";
static const char*  BIT_FILE            = "result/res_bit.txt";
static const char*  MULTIPLICATION_FILE = "result/res_multi.txt";
static const char*  TEST_FILE           = "../tests/tests_int.txt";

int PrintResults(int* collisions, const char* res_file_name);
int FillCollisions(int* collisions, FILE* test_file, int (*hash_function)(int));
int GetResults(FILE* test_file, const char* res_file_name, int (*hash_function)(int));
#endif