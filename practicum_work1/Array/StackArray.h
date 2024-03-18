#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

const int POISON = 0;

#define TRUE  1;
#define FALSE 0;

typedef void elem_t;
typedef struct Stack stack_t;

struct Stack
{
    size_t capacity;
    size_t size;
    size_t element_size;

    void* data;
};

stack_t* StackCtor(size_t capacity, size_t element_size);

int StackPush(stack_t* stk, void* value);
int StackPop(stack_t* stk);
int StackTop(stack_t* stk, void* element);

void StackDtor(stack_t* stk);
