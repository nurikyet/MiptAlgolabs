#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

const int POISON = 0;
const int VALUE  = 5;

typedef struct Node node_t;
typedef struct Stack stack_t;

struct Node
{
    void*   value;
    node_t* next;
};

struct Stack
{
    node_t* head;
    int     size;
    size_t  element_size;
};

stack_t* StackCtor(size_t element_size);

int StackPush(stack_t* stk, void* value);
int StackPop(stack_t* stk);
int StackTop(stack_t* stk, void* element);

void StackDtor(stack_t* stk);

enum Status 
{
    NO_ERROR                   = 0,
    ERROR_OF_ALLOCATING_MEMORY = 1,
    ERROR_SIZE                 = 2
};
