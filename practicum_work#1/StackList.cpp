#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct Node node_t;
typedef struct Stack stack_t;

struct Node
{
    int value;
    node_t* next;
};

struct Stack
{
    node_t* head;
    int num;
};

stack_t* StackCtor()
{

    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));

    stk->head     = NULL;
    stk->num      = 0;

    return stk;
}

int StackPush(stack_t* stk, const int value)
{
    assert(stk);

    node_t* new_node = (node_t*)calloc(1, sizeof(node_t));

    new_node->value    = value;
    new_node->next     = stk->head;

    stk->head          = new_node;
    stk->num++;

    return 1;
}

int StackPop(stack_t* stk)
{
    if (stk->num == 0)
    {
        printf("I can't pop element\n");
        return 0;
    }

    stk->head = stk->head->next;
    stk->num--;

    return 1;
}

int StackTop(stack_t* stk)
{
    return(stk->head->value);
}

void StackDtor(stack_t* stk)
{
    for (int i = 0; i < stk->num; i++)
    {
        StackPop(stk);
    }
    free(stk);
}

void first_test()
{
    double time_test1 = 0.0;

    for (int t = 0; t < 3; t++)
    {
        stack_t* stk1 = StackCtor();
        clock_t begin = clock();

        for(int i = 0; i < 1000000; i++)
        {
            StackPush(stk1, i);
        }

        while (stk1->num > 100000)
        {
            for (int i = 0; i < stk1->num / 2; i++)
            {
                StackPop(stk1);
            }

            for (int i = 0; i < stk1->num / 4; i++)
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
        stack_t* stk2 = StackCtor();
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

        while(stk2->num > 100000)
        {
            for (int i = 0; i < stk2->num / 2; i++)
            {
                StackPop(stk2);
            }

            for (int i = 0; i < stk2->num / 4; i++)
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
        stack_t* stk3 = StackCtor();

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
    FILE* out_file = fopen("output1.txt", "w");
    if (out_file == NULL)
    {
        printf("Error of opening file\n");
    }
    double spend_time = 0.0;

    stack_t* stk4 = StackCtor();
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
