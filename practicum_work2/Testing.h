#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#include "Common.h"

#include "8/MSD.h"
#include "8/LSD.h"

#include "6/IntroShellSort.h"
#include "6/IntroQsort.h"

#include "5/MedianQsort.h"
#include "5/Median3RandQsort.h"
#include "5/RandQsort.h"
#include "5/MedianOfMedianQsort.h"
#include "5/Median3Qsort.h"

#include "4/FlagQsort.h"
#include "4/HoaraQsort.h"
#include "4/LomutoQsort.h"
#include "4/OneBranchHoaraQsort.h"

#include "3/MergeIterativeSort.h"
#include "3/MergeRecursive.h"

#include "2/HeapSort.h"

#include "1/ShellSort.h"
#include "1/BubbleSort.h"
#include "1/InsertionSort.h"
#include "1/SelectionSort.h"


static const size_t MAX_PATH_LEN = 200;

static const size_t VERY_SMALL_TESTS_FROM = 1;
static const char*  SMALL_TESTS_PATH = "small_tests/";

static const size_t BIG_TESTS_FROM = 0;
static const size_t BIG_TESTS_TO   = 1000000;
static const size_t BIG_TESTS_STEP = 10000;
static const char*  BIG_TESTS_PATH = "big_tests/";

static const size_t TESTS_MOST_DUBLICATES_FROM = 0;
static const size_t TESTS_MOST_DUBLICATES_TO   = 1000000;
static const size_t TESTS_MOST_DUBLICATES_STEP = 10000;
static const char*  TESTS_MOST_DUBLICATES_PATH = "tests_most_dublicates/";
static const size_t VERY_SMALL_TESTS_TO   = 150;
static const size_t VERY_SMALL_TESTS_STEP = 1;
static const char*  VERY_SMALL_TESTS_PATH = "very_small_tests/";

static const size_t SMALL_TESTS_FROM = 0;
static const size_t SMALL_TESTS_TO   = 1000;
static const size_t SMALL_TESTS_STEP = 50;



static void TestQuickPivot(const int from, const int to, const int step,
                                const char* src_path, const char* out_folder);
static void TestQuickPartitions(const int from, const int to, const int step,
                                const char* src_path, const char* out_folder);                                

void Testing(void (*sorting_algorithm)(int*, size_t), const char* res_name, FILE* file_in, FILE* file_out, int size);
void Tester(int from, int to, int step, const char* file_path, const char* file_res, void (*sorting_algorithm)(int*, size_t));
void GiveTime(void (*sorting_algorithm)(int*, size_t), FILE* file, int* arr, int size);
void ArrCtor(FILE* file, int* arr, int size);
void PrintArr(int* arr, int size);
void GetEightsPointData();
void GetSixthPointData();
void GetFifthPointData();
void GetFourthPointData();
void GetThirdPointData();
void GetSecondPointData();
void GetFirstPointData();