#include "Testing.h"

void LoadFactorTester(int capacity, double load_factor)
{
    assert(capacity > 0);

    FILE* res_file = fopen("result/open_load_factor", "a");
    if (res_file == NULL)
    {
        return;
    }
    Table* table = TableCtor(capacity);

    double time_spent = 0.0;
    clock_t begin     = clock();
    
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        int data = i;
        table = add(table, data, load_factor);        
    }

    clock_t end       = clock();
    time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(res_file, "%lg %lg\n", load_factor, time_spent);

    TableDtor(table);
}

void FirstTest(double max_load_factor)
{
    FILE* test_file = fopen(FIRST_TEST_FILE, "w");
    if (test_file == NULL) 
    {
        return;
    }
    for (int size = 10000; size < 1000000; size += 10000)
    {
        Table* table = TableCtor(size);

        double time_spent = 0.0;
        clock_t begin     = clock();

        for (int i = 0; i < size; i++)
        {
            int data = rand();

            if (data % SECOND_MOD == 0)
            {
                table = add(table, data, max_load_factor);
            }
            else if (data % SECOND_MOD == 2)
            {
                check(table, data);
            }
            else if (data % SECOND_MOD == 1)
            {
                delete(table, data);
            }
        }

        clock_t end       = clock();
        time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(test_file, "%d %lg\n", size, time_spent);
        TableDtor(table);
    }
    fclose(test_file);
}

void SecondTest(max_load_factor)
{
    FILE* test_file = fopen(SECOND_TEST_FILE, "w");
    if (test_file == NULL) 
    {
        return;
    }
    for (int size = 10000; size < 1000000; size += 10000)
    {
        Table* table = TableCtor(size);

        double time_spent = 0.0;
        clock_t begin     = clock();

        for (int i = 0; i < size; i++)
        {
            int data = rand();

            if (data % (SECOND_MOD / 2) == 0)
            {
                table = add(table, data, max_load_factor);
            }
            else if (data % SECOND_MOD == 2)
            {
                check(table, data);
            }
            else
            {
                delete(table, data);
            }
        }

        clock_t end       = clock();
        time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(test_file, "%d %lg\n", size, time_spent);
        TableDtor(table);
    }
    fclose(test_file);
}