#include "StackArray.h"

stack_t* StackCtor(size_t capacity, size_t element_size)
{
    assert(capacity > 0);

    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));
    if (stk == NULL)
    {
        printf("Function %s: not enough memory to allocate - %d", __func__, __LINE__);
    }

    stk->capacity = capacity;
    stk->size     = 0;

    void* data = calloc(capacity, element_size);
    if (data == NULL)
    {
        printf("Insufficient amount of memory - %d\n", __LINE__);
    }

    stk->element_size = element_size;
    stk->data         = data;
    if (stk->data == NULL)
    {
        stk->capacity = 0;
        printf("Function %s: not enough memory to allocate - %d", __func__, __LINE__);
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
    data = memcpy(data, value, stk->element_size);
    if (data == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    
    (stk->size)++;

    return TRUE;
}

int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        return ERROR_SIZE;
    }
    if (stk->size == (size_t)(BOUNDARY_REALLOC*stk->capacity))
    {
        StackRealloc(stk, COEFFICIENT_DOWN);
    }
    stk->size--;

    return TRUE;
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

    memcpy(element, value, sizeof(value));
    return TRUE;
}

void StackDtor(stack_t* stk)
{
    assert(stk);

    free(stk->data);
    stk->size     = 0;
    stk->capacity = 0;
    free(stk);
}

void StackRealloc(stack_t* stk, double coef)
{
    assert(stk);

    size_t new_size = (size_t)(coef*(stk->capacity)*sizeof(int));
    void* new_data = (void*) realloc(stk->data, new_size);
    if(new_data == NULL)
    {
        printf("Error of allocating memmory - %d\n", __LINE__);
        return;
    }
    stk->data     = new_data;
    stk->capacity = coef * stk->capacity;
}
