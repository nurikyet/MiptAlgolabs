#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef int elem_t;

const int POISON = 0;

struct Stack
{
    int capacity;
    int size;

    elem_t* data;
};

typedef struct Stack stack_t;

stack_t* StackCtor(size_t capacity)
{
    assert(capacity > 0);

    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));

    stk->capacity = capacity;
    stk->size     = 0;

    stk->data  = (elem_t*) calloc(capacity, sizeof(elem_t));

    return stk;
}

int StackPush(stack_t* stk, const int value)
{
    assert(stk);

    if(stk->size >= stk->capacity)
    {
        printf("I can't push element\n");
        return 0;
    }

    (stk->data)[(stk->size)]     = value;
    (stk->size)++;

    return 1;
}

int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        printf("I can't pop element\n");
        return 0;
    }
    (stk->size)--;
    (stk->data)[(stk->size)] = POISON;

    return 1;
}

elem_t StackTop(stack_t* stk)
{
    return (stk->data)[(stk->size)];
}

void StackDtor(stack_t* stk)
{
    free(stk->data);
    stk->size     = POISON;
    stk->capacity = POISON;
    free(stk);
}

void first_test()
{
    double time_test1 = 0.0;

    for (int t = 0; t < 3; t++)
    {
        stack_t* stk1 = StackCtor(1000010);
        clock_t begin = clock();

        for(int i = 0; i < 1000000; i++)
        {
            StackPush(stk1, i);
        }

        while (stk1->size > 100000)
        {
            for (int i = 0; i < stk1->size / 2; i++)
            {
                StackPop(stk1);
            }

            for (int i = 0; i < stk1->size / 4; i++)
            {
                StackPush(stk1, i);
            }
        }

        clock_t end = clock();
        time_test1 += (double)(end - begin) / CLOCKS_PER_SEC;

        StackDtor(stk1);
    }

    time_test1 /= 3.0;

    printf("Test 1 spends %f sec\n", time_test1);

    return;
}

void second_test()
{
    double time_test2 = 0.0;

    for (int i = 0; i < 3; i++)
    {
        stack_t* stk2 = StackCtor(1000010);
        clock_t begin     = clock();

        for(int i = 0; i < 1000000; i++)
        {
            StackPush(stk2, i);
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 10000; j++)
            {
                StackPop(stk2);
            }

            for (int k = 0; k < 10000; k++)
            {
                StackPush(stk2, k);
            }
        }

        while(stk2->size > 100000)
        {
            for (int i = 0; i < stk2->size / 2; i++)
            {
                StackPop(stk2);
            }

            for (int i = 0; i < stk2->size / 4; i++)
            {
                StackPush(stk2, i);
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
                StackPush(stk2, k);
            }
        }
        clock_t end = clock();
        time_test2 += (double)(end - begin) / CLOCKS_PER_SEC;

        StackDtor(stk2);
    }


    time_test2 /= 3.0;

    printf("Test 2 spends %f sec\n", time_test2);
}

void third_test()
{
    double time_test3 = 0.0;

    for (int t = 0; t < 3; t++)
    {
        stack_t* stk3 = StackCtor(1500000);

        for (int i = 0; i < 1000000; i++)
        {
            StackPush(stk3, i);
        }
        srand(time(NULL));

        clock_t begin = clock();

        for (int i = 0; i < 1000000; i++)
        {
            int randomNumber = rand() % 2 + 1;
            if (randomNumber == 1)
            {
                StackPush(stk3, randomNumber);
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

    time_test3 /= 3.0;

    printf("Test 3 spends %f sec\n", time_test3);
    return;
}

void fourth_test()
{
    FILE* out_file = fopen("output2.txt", "w");
    if (out_file == NULL)
    {
        printf("Error of opening file\n");
    }
    double spend_time = 0.0;

    stack_t* stk4 = StackCtor(1000010);
    clock_t begin = clock();

    for (int i = 0; i <= 1000000; i++)
    {
        if (i % 1000 == 0)
        {
            clock_t end   = clock();
            spend_time = ((double)(end - begin)) / CLOCKS_PER_SEC;
            fprintf(out_file, "%d %f\n", i, spend_time);
        }
        StackPush(stk4, i);
    }
    StackDtor(stk4);
    fclose(out_file);
}

int main()
{
    first_test();
    second_test();
    third_test();
    fourth_test();

    return 0;
}
