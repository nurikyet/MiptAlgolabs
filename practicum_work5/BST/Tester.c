#include "Testing.h"
#include "BST.h"

const char* BST_FILE1 = "result/bst_push.txt";
const char* BST_FILE2 = "result/bst_pop.txt";
const char* BST_FILE3 = "result/bst_push_bamb.txt";
const char* BST_FILE4 = "result/bst_pop_bamb.txt";

void FirstTester()
{
    FILE* push_file = fopen(BST_FILE1, "a");
    if (push_file == NULL)
    {
        return;
    }

    FILE* pop_file = fopen(BST_FILE2, "a");
    if (pop_file == NULL)
    {
        return;
    }

    Tree* tree     = TreeCtor();

    double time_test1 = 0.0;
    for (int i = 0; i < MAX_LEN; i++)
    {
        int data = rand();
        clock_t begin = clock();
        Insert(tree->root, data);
        clock_t end = clock();
        time_test1 += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    fprintf(push_file, "%d %lg\n", MAX_LEN, time_test1);

    double time_test2 = 0.0;
    for (int i = 0; i < MAX_LEN / 2; i++)
    {
        int data_2 = rand();
        clock_t begin = clock();
        tree->root = Delete(tree->root, data_2);
        clock_t end = clock();

        time_test2 += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    fprintf(pop_file, "%d %lg\n", MAX_LEN / 2, time_test2);

    TreeDtor(tree->root);
    free(tree);
    fclose(push_file);
    fclose(pop_file);
}

void SecondTester()
{
    FILE* push_file = fopen(BST_FILE3, "a");
    if (push_file == NULL)
    {
        return;
    }

    FILE* pop_file = fopen(BST_FILE4, "a");
    if (pop_file == NULL)
    {
        return;
    }
    Tree* tree     = TreeCtor();

    double time_test3 = 0.0;
    for (int i = 0; i < BAMBUK_LEN; i++)
    {
        clock_t begin = clock();
        tree->root = Insert(tree->root, i);
        clock_t end = clock();

        time_test3 += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    fprintf(push_file, "%d %lg\n", MAX_LEN, time_test3);

    double time_test4 = 0.0;
    for (int i = 0; i < BAMBUK_LEN / 2; i++)
    {
        clock_t begin = clock();
        tree->root = Delete(tree->root, i);
        clock_t end = clock();

        time_test4 += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    fprintf(pop_file, "%d %lg\n", MAX_LEN / 2, time_test4);
    TreeDtor(tree->root);

    free(tree);
    fclose(push_file);   
    fclose(pop_file);    
}

