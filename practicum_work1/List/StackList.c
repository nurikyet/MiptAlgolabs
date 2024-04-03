#include "StackList.h"

stack_t* StackCtor(size_t element_size)
{
    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));
    if (stk == NULL)
    {
        stk->size = 0;
        printf("Function %s: not enough memory to allocate", __func__);
        return NULL;
    }

    stk->head         = NULL;
    stk->size          = 0;
    stk->element_size = element_size;

    return stk;
}

int StackPush(stack_t* stk, void* value)
{
    assert(stk);
    assert(value);

    node_t* new_node = (node_t*)calloc(1, sizeof(node_t));
    if (new_node == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    new_node->value = calloc(1, stk->element_size);
    if (new_node->value == NULL)
    {
        free(new_node);
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    memcpy(new_node->value, value, stk->element_size);
    new_node->next = stk->head;

    stk->head = new_node;
    stk->size++;

    return NO_ERROR;
}


int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }

    stk->head = stk->head->next;
    stk->size--;

    return NO_ERROR;
}

int StackTop(stack_t* stk, void* element)
{
    assert(stk);

    if (stk->size == 0)
    {
        return ERROR_SIZE;
    }

    memcpy(element, stk->head->value, stk->element_size);
    return NO_ERROR;
}

void StackDtor(stack_t* stk)
{
    assert(stk);

    if (stk->size == 0)
    {
        free(stk);
        return;
    }

    for (int i = 0; i < stk->size; i++)
    {
        StackPop(stk);
    }
    free(stk);
}