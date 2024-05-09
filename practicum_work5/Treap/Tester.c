#include "Testing.h"
#include "Treap.h"
#include "../Common.h"

const char* TREAP_FILE1 = "result/treap_push.txt";
const char* TREAP_FILE2 = "result/treap_pop.txt";


void Tester()
{
    FILE* push_file = fopen(TREAP_FILE1, "a");
    if (push_file == NULL)
    {
        return;
    }

    FILE* pop_file = fopen(TREAP_FILE2, "a");
    if (pop_file == NULL)
    {
        return;
    }

    for (int size = 100000; size < 1000000; size += 100000)
    {
        Node* root = NULL;
        double time_test1 = 0.0;

        for (int i = 0; i < size; i++)
        {
            int data_1 = rand();
            int priority = rand();

            clock_t begin = clock();
            root = NodeInsert(root, data_1, priority);
            clock_t end   = clock();

            time_test1 += (double)(end - begin) / CLOCKS_PER_SEC;
        }

        fprintf(push_file, "%d %lg\n", size, time_test1);
        double time_test2 = 0.0;

        for (int i = 0; i < size / 2; i++)
        {
            int data_2 = rand();
            clock_t begin = clock();
            if (FindNode(root, data_2) != NULL)
            {
                root = NodeDelete(root, data_2);
            }
            clock_t end   = clock();

            time_test2 += (double)(end - begin) / CLOCKS_PER_SEC;
        }

        fprintf(pop_file, "%d %lg\n", size / 2, time_test2);

        RootDelete(root); 
    }
    fclose(push_file);
    fclose(pop_file);
}

