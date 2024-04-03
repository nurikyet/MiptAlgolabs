#include "StackArray.h"

stack_t* StackCtor(size_t capacity, size_t element_size)
{
    assert(capacity > 0);

    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));
    if (stk == NULL)
    {
        assert(false);
    }

    stk->capacity = capacity;
    stk->size     = 0;

    void* data = calloc(capacity, element_size);
    if (data == NULL)
    {
        assert(false);
    }

    stk->element_size = element_size;
    stk->data         = data;
    if (stk->data == NULL)
    {
        stk->capacity = 0;
        return NULL;
    }

    return stk;
}

int StackPush(stack_t* stk, void* value)
{
    assert(stk);
    assert(value);

    if(stk->size > stk->capacity)
    {
        return ERROR_SIZE;
    }

    if (stk->capacity == stk->size)
    {
        StackRealloc(stk, COEFFICIENT_UP);
    }

    void* data  = stk->data + (stk->size)*(stk->element_size);
    if (data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    memcpy(data, value, stk->element_size);
    if (data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    
    (stk->size)++;

    return NO_ERROR;
}

int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        return ERROR_SIZE;
    }
    if (stk->size == (size_t)(BOUNDARY_REALLOC*(double)stk->capacity))
    {
        StackRealloc(stk, COEFFICIENT_DOWN);
    }
    stk->size--;

    return NO_ERROR;
}

int StackTop(stack_t* stk, void* element)
{
    assert(element);
    assert(stk);

    if (stk->size == 0)
    {
        return ERROR_SIZE;
    }
    void* value = stk->data + (stk->size - 2)*(stk->element_size);

    memcpy(element, value, stk->element_size);
    return NO_ERROR;
}

void StackDtor(stack_t* stk)
{
    assert(stk);

    free(stk->data);
    stk->size     = 0;
    stk->capacity = 0;
    free(stk);
}

int StackRealloc(stack_t* stk, double coef)
{
    assert(stk);

    size_t new_size = (size_t)(coef*(double)((stk->capacity)*sizeof(int)));
    void* new_data = (void*) realloc(stk->data, new_size);
    if(new_data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    stk->data     = new_data;
    stk->capacity = (size_t)(coef * (double)stk->capacity);

    return NO_ERROR;
}