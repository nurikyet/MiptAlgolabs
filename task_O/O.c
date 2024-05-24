#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000001
#define LINE_LEN 40

enum Status
{
    NO_ERROR                = 0,
    ERROR_SCANF             = 1,
    ERROR_ALLOCATING_MEMORY = 2
};

typedef struct
{
    long long data;
    int index;
    int number;
} Element;

typedef struct
{
    Element* array;
    Element** request;

    int size;
    int capacity;
} Heap;

int ExecuteCommands(Heap* heap);
void HeapDtor(Heap* heap);
Heap* HeapCtor();

int main()
{
    Heap* heap = HeapCtor();

    ExecuteCommands(heap);
    HeapDtor(heap);

    return 0;
}

void SwapData(Heap* heap, int first, int second)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(first >= 0);
    assert(second >= 0);

    Element temp         = heap->array[first];
    heap->array[first]   = heap->array[second];
    heap->array[second]  = temp;

}

void SwapRequests(Heap* heap, int first, int second)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(first >= 0);
    assert(second >= 0);

    int first_number  = heap->array[first].number;
    int second_number = heap->array[second].number;

    Element* temp                = heap->request[first_number];
    heap->request[first_number]  = heap->request[second_number];
    heap->request[second_number] = temp;
}

void swap(Heap* heap, int first, int second)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(first >= 0);
    assert(second >= 0);

    heap->array[first].index  = second;
    heap->array[second].index = first;

    SwapData(heap, first, second);
    SwapRequests(heap, first, second);
}

int GetParent(int index)
{
    if (index < 1) return index;

    return (index - 1) / 2;
}

int GetLeftChild(int index, int size)
{
    assert(index >= 0);
    assert(size  >= 0);

    int left = 2 * index + 1;
    if (left >= size)
    {
        return index;
    }
    return left;
}

int GetRightChild(int index, int size)
{
    assert(index >= 0);
    assert(size >= 0);

    int right = 2 * index + 2;
    if (right >= size)
    {
        return index;
    }
    return right;
}

long long GetMin(Heap* heap)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);

    return heap->array[0].data;
}

void SiftUp(Heap* heap, int index)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(index >= 0);

    while (index > 0)
    {
        int parent = GetParent(index);

        if (heap->array[index].data < heap->array[parent].data)
        {
            swap(heap, index, parent);
            index = parent;
        }

        else
        {
            return;
        }
    }
}

void SiftDown(Heap* heap, int index)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(index >= 0);

    while (index * 2 + 1 < heap->size)
    {
        int min_index = index;
        int left      = GetLeftChild(index, heap->size);
        int right     = GetRightChild(index, heap->size);

        if (heap->array[left].data < heap->array[min_index].data)
        {
            min_index = left;
        }

        if (heap->array[right].data < heap->array[min_index].data)
        {
            min_index = right;
        }

        if (min_index != index)
        {
            swap(heap, index, min_index);
            index = min_index;
        }
        else
        {
            return;
        }
    }
}

Heap* HeapCtor()
{
    Heap* heap     = (Heap*)calloc(1, sizeof(Heap));
    if (heap == NULL)
    {
        return NULL;
    }

    Element* array = (Element*)calloc(MAX_LEN, sizeof(Element));
    if (array == NULL)
    {
        return NULL;
    }
    heap->array    = array;
    
    heap->size     = 0;
    heap->capacity = MAX_LEN;
    Element** request = (Element**)calloc(MAX_LEN, sizeof(Element*));
    if (request == NULL)
    {
        return NULL;
    }
    heap->request  = request;
    return heap;
}

void HeapInsert(Heap* heap, long long new_element, int number)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);

    heap->array[heap->size].data   = new_element;
    heap->array[heap->size].number = number;
    heap->array[heap->size].index  = heap->size;

    heap->request[number]        = &heap->array[heap->size];
    heap->size++;
    SiftUp(heap, heap->size - 1);
}

long long ExtractMin(Heap* heap)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);
    assert(heap->size > 0);

    long long root = heap->array[0].data;
    swap(heap, 0, heap->size - 1);
    heap->size--;

    SiftDown(heap, 0);

    return root;
}

void HeapDtor(Heap* heap)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);

    free(heap->array);
    free(heap->request);

    heap->size = 0;
    heap->capacity = 0;

    free(heap);
}

void DecreaseKey(Heap* heap, int number, long long difference)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);

    int index_in_array = (*(heap->request[number])).index;
    heap->array[index_in_array].data -= difference;

    SiftUp(heap, index_in_array);
}

int ExecuteCommands(Heap* heap)
{
    assert(heap          != NULL);
    assert(heap->array   != NULL);
    assert(heap->request != NULL);

    size_t commands_num = 0;
    if (scanf("%ld", &commands_num) <= 0)
    {
        return ERROR_SCANF;
    }

    char line[LINE_LEN] = "";

    for (size_t i = 0; i < commands_num; i++)
    {
        if (scanf("%s", line) <= 0)
        {
            return ERROR_SCANF;
        }

        if (strcmp(line, "insert") == 0)
        {
            long long new_element = 0;
            if (scanf("%lld", &new_element) <= 0)
            {
                return ERROR_SCANF;
            }
            HeapInsert(heap, new_element, i + 1);
        }

        else if (strcmp(line, "getMin") == 0)
        {
            long long root = GetMin(heap);
            printf("%lld\n", root);
        }

        else if (strcmp(line, "extractMin") == 0)
        {
            long long min = ExtractMin(heap);
        }

        else if (strcmp(line, "decreaseKey") == 0)
        {
            int           number = 0;
            long long difference = 0;
            if (scanf("%d %lld", &number, &difference) <= 0)
            {
                return ERROR_SCANF;
            }

            DecreaseKey(heap, number, difference);
        }

        else
        {
            break;
        }
    }
}



