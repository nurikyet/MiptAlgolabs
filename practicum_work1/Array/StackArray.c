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

    if(stk->size >= stk->capacity)
    {
        printf("I can't push element - %d\n",__LINE__);
        return FALSE;
    }
    
    void* data  = stk->data + (stk->size)*(stk->element_size);
    if (data == NULL)
    {
        printf("Insufficient amount of memory\n");
        printf("I can't push element - %d\n", __LINE__);
        return FALSE;
    }
    data = memcpy(data, value, stk->element_size);
    if (data == NULL)
    {
        printf("I can't push element - %d\n", __LINE__);
        return FALSE;
    }
    
    (stk->size)++;

    return TRUE;
}

int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        printf("I can't pop element\n");
        return FALSE;
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
        printf("I can't give you top element, because stack is empty\n");
        return FALSE;
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
