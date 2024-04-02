#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

const int POISON               = 0;
const double COEFFICIENT_UP    = 2;
const double COEFFICIENT_DOWN  = 0.5;
const double BOUNDARY_REALLOC  = 0.25;



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

void StackRealloc(stack_t* stk, double coef); 
void StackDtor(stack_t* stk);

enum Errors 
{
    TRUE                       = 0,
    ERROR_OF_ALLOCATING_MEMORY = 1,
    ERROR_SIZE                 = 2
};
