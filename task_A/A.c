#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define LINE_LEN 40
#define COEFFICIENT_UP 2
#define COEFFICIENT_DOWN 0.5
#define BOUNDARY_REALLOC 0.25

enum Status 
{
    NO_ERROR                   = 0,
    ERROR_OF_ALLOCATING_MEMORY = 1,
    ERROR_SIZE                 = 2
};

typedef struct Stack Stack;

struct Stack
{
    int* data;
    int size;
    int capacity;
};

int reallocStack(Stack* stk, double coef);
int pop(Stack* stack, FILE* fp);
int back(Stack* stack, FILE* fp);
int initStack(Stack* stack, int capacity);
int push(Stack* stack, int n, FILE* fp);
int executeCommands(Stack* stack, FILE* inputFile, FILE* outputFile);

void dtorStack(Stack* stack);
void size(Stack* stack, FILE* fp);
void clear(Stack* stack, FILE* fp);

int main()
{
    Stack* stack = (Stack*)calloc(1, sizeof(Stack)); 
    if (stack == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    FILE* inputFile  = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    initStack(stack, MAX_SIZE); 

    executeCommands(stack, inputFile, outputFile); 

    fclose(inputFile);
    fclose(outputFile);
    dtorStack(stack); 

    return 0;
}


int initStack(Stack* stack, int capacity)
{
    assert(stack != NULL);

    int* data = (int*)calloc(capacity, sizeof(int));
    if (data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    stack->data     = data;
    stack->capacity = capacity;
    stack->size     = -1;
    return NO_ERROR;
}

int push(Stack* stack, int n, FILE* fp)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    if (stack->capacity == stack->size)
    {
        reallocStack(stack, COEFFICIENT_UP);
    }

    stack->size++;
    stack->data[stack->size] = n;

    fprintf(fp, "ok\n");
    return NO_ERROR;
}

int pop(Stack* stack, FILE* fp)
{
    assert(stack       != NULL);
    assert(stack->size  >= 0);
    assert(stack->data != NULL);

    if (stack->size == -1)
    {
        return ERROR_SIZE;
    }
    else
    {
        if (stack->size == (int)(BOUNDARY_REALLOC*(double)(stack->capacity)))
        {
            if (reallocStack(stack, COEFFICIENT_DOWN) != NO_ERROR)
            {
                return ERROR_OF_ALLOCATING_MEMORY;
            }
        }

        fprintf(fp, "%d\n", stack->data[stack->size]);
        stack->size--;
        return NO_ERROR;
    }
}

int back(Stack* stack, FILE* fp)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    if (stack->size == -1)
    {
        fprintf(fp, "error\n");
        return ERROR_SIZE;
    }
    else
    {
        fprintf(fp, "%d\n", stack->data[stack->size]);
        return NO_ERROR;
    }
}

void size(Stack* stack, FILE* fp)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    fprintf(fp, "%d\n", stack->size + 1);
}

void clear(Stack* stack, FILE* fp)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    stack->size = -1;
    fprintf(fp, "ok\n");
}

int executeCommands(Stack* stack, FILE* inputFile, FILE* outputFile)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    int value = 0;
    char* operation = (char*)calloc(LINE_LEN, sizeof(char));
    if(operation == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    while (fscanf(inputFile, "%s", operation) > 0)
    {
        if (strcmp(operation, "push") == 0)
        {
            fscanf(inputFile, "%d", &value);
            push(stack, value, outputFile);
        }
        else if (strcmp(operation, "pop") == 0)
        {
            pop(stack, outputFile);
        }
        else if (strcmp(operation, "back") == 0)
        {
            back(stack, outputFile);
        }
        else if (strcmp(operation, "size") == 0)
        {
            size(stack, outputFile);
        }
        else if (strcmp(operation, "clear") == 0)
        {
            clear(stack, outputFile);
        }
        else if (strcmp(operation, "exit") == 0)
        {
            fprintf(outputFile, "bye\n");
            break;
        }
    }
    free(operation);
    return NO_ERROR;
}

void dtorStack(Stack* stack)
{
    assert(stack       != NULL);
    assert(stack->data != NULL);

    free(stack->data);
    stack->size = -1;
    free(stack);
}

int reallocStack(Stack* stk, double coef)
{
    assert(stk       != NULL);
    assert(stk->data != NULL);

    size_t new_size = (int)(coef*(double)((stk->capacity)*sizeof(int)));
    int* new_data = (int*) realloc(stk->data, new_size);
    if(new_data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    stk->data     = new_data;
    stk->capacity = (int)(coef * (double)stk->capacity);

    return NO_ERROR;
}