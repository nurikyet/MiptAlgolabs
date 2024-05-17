#ifndef FLOAT_SOLVER_H
#define FLOAT_SOLVER_H

#define NUMBER_OF_ELEMENTS 1000000

static const char*  FLOAT_TO_INT_FILE        = "result/res_float_to_int.txt";
static const char*  FLOAT_BITS_FILE          = "result/res_bits.txt";
static const char*  EXPONENT_FILE            = "result/res_exponent.txt";
static const char*  MANTISSA_FILE            = "result/res_mantissa.txt";
static const char*  FLOAT_MULTIPLY_HASH_FILE = "result/res_float_multi.txt";
static const char*  TEST_FILE                = "../tests/tests_float.txt";

int PrintResults(int* collisions, const char* res_file_name);
int FillCollisions(int* collisions, FILE* test_file, int (*hash_function)(float));
int GetResults(FILE* test_file, const char* res_file_name, int (*hash_function)(float));

#endif