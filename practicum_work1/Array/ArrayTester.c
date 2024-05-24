#include "StackArray.h"
#include "ArrayTester.h"

void first_test(int number_of_tests)
{
    double time_test1 = 0.0;

    for (int t = 0; t < number_of_tests; t++)
    {
        stack_t* stk1 = StackCtor(1000010, sizeof(VALUE));
        clock_t begin = clock();

        for(int i = 0; i < 1000000; i++)
        {
            StackPush(stk1, &i);
        }

        while (stk1->size > 100000)
        {
            for (size_t i = 0; i < stk1->size / 2; i++)
            {
                StackPop(stk1);
            }

            for (size_t i = 0; i < stk1->size / 4; i++)
            {
                StackPush(stk1, &i);
            }
        }

        clock_t end = clock();
        time_test1 += (double)(end - begin) / CLOCKS_PER_SEC;

        StackDtor(stk1);
    }

    time_test1 /= number_of_tests;

    printf("Test 1 spends %f sec\n", time_test1);

    return;
}

void second_test(int number_of_tests)
{
    double time_test2 = 0.0;

    for (int t = 0; t < number_of_tests; t++)
    {
        stack_t* stk2 = StackCtor(1000010, sizeof(VALUE));
        clock_t begin     = clock();

        for(int i = 0; i < 1000000; i++)
        {
            StackPush(stk2, &i);
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 10000; j++)
            {
                StackPop(stk2);
            }

            for (int k = 0; k < 10000; k++)
            {
                StackPush(stk2, &k);
            }
        }

        while(stk2->size > 100000)
        {
            for (size_t i = 0; i < stk2->size / 2; i++)
            {
                StackPop(stk2);
            }

            for (size_t i = 0; i < stk2->size / 4; i++)
            {
                StackPush(stk2, &i);
            }
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 10000; j++)
            {
                StackPop(stk2);
            }

            for (int k = 0; k < 10000; k++)
            {
                StackPush(stk2, &k);
            }
        }
        clock_t end = clock();
        time_test2 += (double)(end - begin) / CLOCKS_PER_SEC;

        StackDtor(stk2);
    }

    time_test2 /= number_of_tests;

    printf("Test 2 spends %f sec\n", time_test2);
}

void third_test(int number_of_tests)
{
    double time_test3 = 0.0;

    for (int t = 0; t < number_of_tests; t++)
    {
        stack_t* stk3 = StackCtor(1500000, sizeof(VALUE));

        for (int i = 0; i < 1000000; i++)
        {
            StackPush(stk3, &i);
        }
        srand((unsigned int)time(NULL));

        clock_t begin = clock();

        for (int i = 0; i < 1000000; i++)
        {
            int randomNumber = rand() % 2 + 1;
            if (randomNumber == 1)
            {
                StackPush(stk3, &randomNumber);
            }
            else
            {
                StackPop(stk3);
            }
        }

        clock_t end = clock();
        StackDtor(stk3);
        time_test3 += (double) (end - begin) / CLOCKS_PER_SEC;
    }

    time_test3 /= number_of_tests;

    printf("Test 3 spends %f sec\n", time_test3);
    return;
}

void fourth_test()
{
    FILE* out_file = fopen("res_massiv_stack.txt", "w");
    if (out_file == NULL)
    {
        printf("Error of opening file\n");
    }
    double spend_time = 0.0;

    stack_t* stk4 = StackCtor(1000010, sizeof(VALUE));
    clock_t begin = clock();

    for (int i = 0; i <= 1000000; i++)
    {
        if (i % 1000 == 0)
        {
            clock_t end   = clock();
            spend_time = ((double)(end - begin)) / CLOCKS_PER_SEC;
            fprintf(out_file, "%d %f\n", i, spend_time);
        }
        StackPush(stk4, &i);
    }
    StackDtor(stk4);
    fclose(out_file);
}