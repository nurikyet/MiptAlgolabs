#include "Testing.h"
#include "Splay.h"
#include "../Common.h"

const char* SPLAY_FILE1 = "result/splay_push.txt";
const char* SPLAY_FILE2 = "result/splay_pop.txt";

void Tester()
{
    FILE* push_file       = fopen(SPLAY_FILE1, "a");
    if (push_file == NULL)
    {
        return;
    }

    FILE* pop_file = fopen(SPLAY_FILE2, "a");
    if (pop_file == NULL)
    {
        return;
    }

    for (int size = MIN_SIZE; size < MAX_SIZE; size += PERIOD)
    {
        Node* root = NULL;
        double time_test1 = 0.0;

        for (int i = 0; i < size; i++)
        {
            int data_1    = rand();

            clock_t begin = clock();
            Insert(root, data_1);
            clock_t end   = clock();

            time_test1   += (double)(end - begin) / CLOCKS_PER_SEC;
        }

        fprintf(push_file, "%d %lg\n", size, time_test1);

        double time_test2 = 0.0;

        for (int i = 0; i < size / 2; i++)
        {
            int data_2    = rand();
            clock_t begin = clock();
            Delete(root, data_2);
            clock_t end   = clock();

            time_test2   += (double)(end - begin) / CLOCKS_PER_SEC;
        }

        fprintf(pop_file, "%d %lg\n", size / 2, time_test2);
    }
    fclose(push_file);
    fclose(pop_file);
}


