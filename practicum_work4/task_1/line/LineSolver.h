#ifndef LINE_SOLVER_H
#define LINE_SOLVER_H

#define MAX_LINE_LEN 20
#define NUMBER_OF_ELEMENTS 1000000

static const char*  LINE_LEN_FILE       = "result/res_line_len.txt";
static const char*  SUM_LETTERS_FILE    = "result/res_sum_letters.txt";
static const char*  POLINOMIAL_FILE     = "result/res_polinomial.txt";
static const char*  CRC_32_FILE         = "result/res_crc32.txt";
static const char*  TEST_FILE           = "../tests/tests_line.txt";

int PrintResults(int* collisions, const char* res_file_name);
int FillCollisions(int* collisions, FILE* test_file, int (*hash_function)(char*));
int GetResults(FILE* test_file, const char* res_file_name, int (*hash_function)(char*));


#endif