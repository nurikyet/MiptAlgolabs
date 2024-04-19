#include "Testing.h"

const int K = 5;

void GetFirstPointData()
{
    Tester(SMALL_TESTS_FROM, SMALL_TESTS_TO, SMALL_TESTS_STEP, SMALL_TESTS_PATH,
            "results/1_results/bubble_sort.out", BubbleSort);

    Tester(SMALL_TESTS_FROM, SMALL_TESTS_TO, SMALL_TESTS_STEP, SMALL_TESTS_PATH,
            "results/1_results/insertion_sort.out", InsertionSort);

    Tester(SMALL_TESTS_FROM, SMALL_TESTS_TO, SMALL_TESTS_STEP, SMALL_TESTS_PATH,
            "results/1_results/selection_sort.out", SelectionSort);

    Tester(SMALL_TESTS_FROM, SMALL_TESTS_TO, SMALL_TESTS_STEP, SMALL_TESTS_PATH,
            "results/1_results/shell_sort.out", ShellSort);
}

void GetSecondPointData()
{
    int optimal_number_of_children = 8;

    char dest_path[MAX_PATH_LEN] = "";
    snprintf(dest_path, MAX_PATH_LEN, "results/2_results/%d__heap_sort.out",  optimal_number_of_children);

    HeapTester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP,
                BIG_TESTS_PATH, dest_path,  optimal_number_of_children);
}

void GetThirdPointData()
{
    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/3_results/iterative_merge_sort.out",
            MergeSortIterative);

    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/3_point_results/recursive_merge_sort.out",
            MergeSortRecursive);
}

void GetFourthPointData()
{
    TestQuickPartitions(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/4_results/big_tests/");

    TestQuickPartitions(TESTS_MOST_DUBLICATES_FROM, TESTS_MOST_DUBLICATES_TO,
            TESTS_MOST_DUBLICATES_STEP, TESTS_MOST_DUBLICATES_PATH,
            "results/4_results/tests_most_dublicates/");
}

void GetFifthPointData()
{
    TestQuickPivot(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/5_results/big_tests/");

    TestQuickPivot(TESTS_MOST_DUBLICATES_FROM, TESTS_MOST_DUBLICATES_TO,
            TESTS_MOST_DUBLICATES_STEP, TESTS_MOST_DUBLICATES_PATH,
            "results/5_results/tests_most_dublicates/");
}

void GetSixthPointData()
{
    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/6_results/intro_qsort.out",
            IntroQsort);

    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/6_results/intro_shell_sort.out",
            IntroShellSort);
}

void GetEightsPointData()
{
    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/8_results/msd_sort.out",
            MSD);

    Tester(BIG_TESTS_FROM, BIG_TESTS_TO, BIG_TESTS_STEP, BIG_TESTS_PATH,
            "results/8_results/lsd_sort.out",
            LSD);
}

static void TestQuickPartitions(const int from, const int to, const int step,
                                const char* src_path, const char* out_folder)
{
    assert(src_path);
    assert(out_folder);

    char dest_path[MAX_PATH_LEN] = "";

    snprintf(dest_path, MAX_PATH_LEN, "%sone_branch_hoara_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, OneBranchHoaraQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%shoara_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, HoaraQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%slomuto_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, LomutoQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%sflag_sort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, FlagQsort);
}

static void TestQuickPivot(const int from, const int to, const int step,
                                const char* src_path, const char* out_folder)
{
    assert(src_path);
    assert(out_folder);

    char dest_path[MAX_PATH_LEN] = "";

    snprintf(dest_path, MAX_PATH_LEN, "%smedian_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, HoaraQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%smedian3_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, MedianQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%smedian3_rand_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, Median3RandQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%srand_median_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, RandMedianQsort);

    snprintf(dest_path, MAX_PATH_LEN, "%srand_qsort.out", out_folder);
    Tester(from, to, step, src_path, dest_path, RandQsort);
}

void PrintArr(int* arr, int size)
{
    printf("Massiv size %d\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);        
    }    
    printf("\n");
}

void ArrCtor(FILE* file, int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%d", &arr[i]);        
    }
}

void GiveTime(void (*sorting_algorithm)(int*, size_t), FILE* file, int* arr, int size)
{
    if (size == 0) return;

    double time_spent = 0.0;
    clock_t begin = clock();

    sorting_algorithm(arr, size); 
    
    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(file, "%d %lf\n", size, time_spent);

}

void Tester(int from, int to, int step, const char* file_path, const char* file_res, void (*sorting_algorithm)(int*, size_t))
{
    for (int i = from; i < to; i += step)
    {
        for (int j = 0; j < K; j++)
        {
            char file1[256];
            char file2[256];

            sprintf(file1, "%s%d_%d.in", file_path, i, j);
            sprintf(file2, "%s%d_%d.out", file_path, i, j);

            FILE* file_in = fopen(file1, "rb");
            if (file_in == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            }

            FILE* file_out = fopen(file2, "rb");
            if (file_out == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            }

            Testing(sorting_algorithm, file_res, file_in, file_out, i);

            fclose(file_in);
            fclose(file_out);  
        }
    }
}

void Testing(void (*sorting_algorithm)(int*, size_t), const char* res_name, FILE* file_in, FILE* file_out, int size)
{
    if (size == 0) return;

    int* arr = (int*)calloc(size + 1, sizeof(int));
    if (arr == NULL)
    {
        printf("I can't allocate memmory! - %d\n", __LINE__);
    }
    ArrCtor(file_in, arr, size);   

    FILE* file_res = fopen(res_name, "a");
    if (file_res == NULL)
    {
        printf("I can't open file - %s in line %d\n", res_name, __LINE__);
        return;        
    }
    GiveTime(sorting_algorithm, file_res, arr, size);

    int* res = (int*)calloc(size + 1, sizeof(int));
    if (res == NULL)
    {
        printf("I can't allocate memmory! - %d\n", __LINE__);
    }
    ArrCtor(file_out, res, size);

    for (int i = 0; i < size; i++)
    {
        if(arr[i] != res[i])
        {
            printf("arr = %d, res = %d\n", arr[i], res[i]); 

            printf("your algorithm is incorrect, it fails on the test %d\n", i);
            assert(false);        
        }
    }
    fclose(file_res);
    free(arr);
    free(res);
}

int main()
{
    GetSecondPointData();

    return 0;
}