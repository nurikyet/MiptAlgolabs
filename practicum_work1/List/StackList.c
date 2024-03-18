#include "StackList.h"

stack_t* StackCtor(size_t element_size)
{
    stack_t* stk = (stack_t*)calloc(1, sizeof(stack_t));
    if (stk == NULL)
    {
        stk->num = 0;
        printf("Function %s: not enough memory to allocate", __func__);
        return NULL;
    }

    stk->head         = NULL;
    stk->num          = 0;
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
        printf("You can't push new element. Function %s: not enough memory to allocate", __func__);
        return FALSE;
    }

    new_node->value = calloc(1, stk->element_size);
    if (new_node->value == NULL)
    {
        printf("You can't push new element. Function %s: not enough memory to allocate", __func__);
        free(new_node);
        return FALSE;
    }

    memcpy(new_node->value, value, stk->element_size);
    new_node->next = stk->head;

    stk->head = new_node;
    stk->num++;

    return TRUE;
}


int StackPop(stack_t* stk)
{
    assert(stk);

    if (stk->num == 0)
    {
        printf("I can't pop element\n");
        return FALSE;
    }

    stk->head = stk->head->next;
    stk->num--;

    return TRUE;
}

int StackTop(stack_t* stk, void* element)
{
    assert(stk);

    if (stk->num == 0)
    {
        printf("Stack is empty, no top element\n");
        return FALSE;
    }
    element = (stk->head->value);
    return TRUE;
}

void StackDtor(stack_t* stk)
{
    assert(stk);

    if (stk->num == 0)
    {
        free(stk);
        return;
    }

    for (int i = 0; i < stk->num; i++)
    {
        StackPop(stk);
    }
    free(stk);
}