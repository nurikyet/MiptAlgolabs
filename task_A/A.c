#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct
{
    int* data;
    int size;
} Stack;

void readCommands(Stack* stack, FILE* inputFile, FILE* outputFile);
void dtorStack(Stack* stack);
void initStack(Stack* stack);
void push(Stack* stack, int n, FILE* fp);
void pop(Stack* stack, FILE* fp);
void back(Stack* stack, FILE* fp);
void size(Stack* stack, FILE* fp);
void clear(Stack* stack, FILE* fp);

int main()
{
    Stack* stack = calloc(1, sizeof(Stack));
    if (stack == NULL)
    {
        printf("Error of allocation of memory (line - %d)\n", __LINE__);
        assert(false);
    }

    FILE* inputFile  = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error of openning file %s\n", "input.txt");
        assert(false);
    }
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error of openning file %s\n", "output.txt");
        assert(false);
    }

    initStack(stack);

    readCommands(stack, inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    dtorStack(stack);

    return 0;
}


void initStack(Stack* stack)
{
    assert(stack != NULL);

    int* data = calloc(MAX_SIZE, sizeof(int));
    if (data == NULL)
    {
        printf("Error of allocation of memory (line - %d)\n", __LINE__);
        assert(false);
    }
    stack->data = data;
    stack->size = -1;
}

void push(Stack* stack, int n, FILE* fp)
{
    assert(stack != NULL);

    stack->size++;
    stack->data[stack->size] = n;
    fprintf(fp, "ok\n");
}

void pop(Stack* stack, FILE* fp)
{
    assert(stack != NULL);
    assert(stack->size > 0);

    if (stack->size == -1)
    {
        fprintf(fp, "error\n");
    }
    else
    {
        fprintf(fp, "%d\n", stack->data[stack->size]);
        stack->size--;
    }
}

void back(Stack* stack, FILE* fp)
{
    assert(stack != NULL);

    if (stack->size == -1)
    {
        fprintf(fp, "error\n");
    }
    else
    {
        fprintf(fp, "%d\n", stack->data[stack->size]);
    }
}

void size(Stack* stack, FILE* fp)
{
    assert(stack != NULL);

    fprintf(fp, "%d\n", stack->size + 1);
}

void clear(Stack* stack, FILE* fp)
{
    assert(stack != NULL);

    stack->size = -1;
    fprintf(fp, "ok\n");
}

void readCommands(Stack* stack, FILE* inputFile, FILE* outputFile)
{
    assert(stack != NULL);
    int n = 0;
    char operation[10];
    while (fscanf(inputFile, "%s", operation) > 0)
    {
        if (strcmp(operation, "push") == 0)
        {
            fscanf(inputFile, "%d", &n);
            push(stack, n, outputFile);
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
}

void dtorStack(Stack* stack)
{
    assert(stack != NULL);

    free(stack->data);
    stack->size = -1;
    free(stack);
}

