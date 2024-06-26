#include "Heap.h"

void swap(void* a, void* b, size_t elem_size);
void SiftDown(Heap* hp, size_t index);
void SiftUp(Heap* hp, size_t index);
size_t GetChild(size_t index, size_t k, size_t i);
size_t GetParent(size_t index, size_t k);

void swap(void* first, void* second, size_t elem_size)
{
    void* temp = calloc(1, elem_size);
    if(temp == NULL)
    {
        return;
    }

    memcpy(temp, first, elem_size);
    memcpy(first, second, elem_size);
    memcpy(second, temp, elem_size);

    free(temp);
}

size_t GetParent(size_t index, size_t k)
{
    if (index < 1) return 0;
    return (index - 1) / k;
}

size_t GetChild(size_t index, size_t k, size_t i)
{
    return index * k + i;
}

int GetMax(Heap* hp, size_t index)
{
    assert(hp != NULL);
 
    size_t max_index = index;
    int max_value = INT_MIN;
    size_t k         = hp->children;

    for (int i = 1; i < k + 1; i++)
    {
        size_t child = GetChild(index, k, i);
        if (child < hp->size && hp->arr[child] > max_value)
        {
            max_index = child;
            max_value = hp->arr[child];
        }
    }

    return max_index;
}

void SiftDown(Heap* hp, size_t index)
{
    assert(hp != NULL);

    if (index >= hp->size) return;
    size_t k = hp->children;
    while(index * k + 1 < hp->size)
    {
        int i_max = GetMax(hp, index);
        if (hp->arr[index] < hp->arr[i_max])
        {
            swap(&(hp->arr[index]), &(hp->arr[i_max]), sizeof(int));
        }
        else
        {
            break;
        }
        index = i_max;
    }
}

void SiftUp(Heap* hp, size_t index)
{
    assert(hp != NULL);

    size_t parent    = 0;

    while(index != 0)
    {
        parent    = GetParent(index, hp->children);

        if (hp->arr[index] > hp->arr[parent])
        {
            swap(&(hp->arr[index]), &(hp->arr[parent]), sizeof(int));  

            index = parent;
        }
        else return;
    }
}

int ExtractMax(Heap* hp)
{
    assert(hp != NULL);

    int root   = hp->arr[0];

    hp->arr[0] = hp->arr[hp->size - 1];
    hp->size--;

    SiftDown(hp, 0);

    return root;
}

void HeapInsert(Heap* hp, int data)
{
    assert(hp != NULL);

    if (hp->size >= hp->capacity)
    {
        return;
    }
    hp->arr[hp->size] = data;
    hp->size++;

    size_t i = hp->size;
    SiftUp(hp, i - 1);

}

void HeapDtor(Heap* hp)
{
    assert(hp != NULL);

    free(hp->arr);
    hp->size     = 0;
    hp->capacity = 0;
}


