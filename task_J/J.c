#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAX_LEN 200005
#define MAX_LEN_OF_LINE 40

typedef struct
{
    int* arr;
    int size;
    int capacity;
} Heap;

void ReadCommands(Heap* heap);
Heap* HeapCtor(int capacity);
void HeapDtor(Heap* hp);

int main()
{
    Heap* heap = HeapCtor(MAX_LEN);

    ReadCommands(heap);

    HeapDtor(heap);
    free(heap);
    return 0;
}

int GiveLeftChild(int index)
{
    assert(index >= 0);
    return 2 * index + 1;
}

int GiveRightChild(int index)
{
    assert(index >= 0);
    return 2 * index + 2;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int GetParent(int index)
{
    assert(index >= 0);

    if (index < 1) return 0;
    return (index - 1) / 2;
}

int GetGrandParent(int index)
{
    assert(index >= 0);

    if (index < 3) return 0;
    return GetParent(GetParent(index));
}

int FindLevel(int element)
{
    int layer = ceil(log2(element + 2));
    if(layer % 2 == 1)                    //minimum level
    {
        return 1;
    }
    return 0;                             //maximum level
}

int MaxOfThree(Heap* hp, int first, int second, int third)
{
    assert(hp != NULL);
    assert(first  >= 0);
    assert(second >=0);
    assert(third  >= 0);

    int i_max = first;

    if (first >= hp->size)
    {
        return -1;
    }

    if (second >= hp->size)
    {
        return first;
    }

    if (third >= hp->size)
    {
        third = second;
    }

    if(hp->arr[i_max] < hp->arr[second])
    {
        i_max = second;
    }

    if(hp->arr[i_max] < hp->arr[third])
    {
        i_max = third;
    }
    return i_max;
}

int MinOfThree(Heap* hp, int first, int second, int third)
{
    assert(hp != NULL);
    assert(first  >= 0);
    assert(second >=0);
    assert(third  >= 0);

    int i_min = first;

    if (first >= hp->size)
    {
        return -1;
    }

    if (second >= hp->size)
    {
        return first;
    }

    if (third >= hp->size)
    {
        third = second;
    }

    if(hp->arr[i_min] > hp->arr[second])
    {
        i_min = second;
    }

    if(hp->arr[i_min] > hp->arr[third])
    {
        i_min = third;
    }

    return i_min;
}

int MinOfSix(Heap* hp, int first, int second, int third, int fourth, int fifth, int sixth)
{
    assert(hp != NULL);
    assert(first  >= 0);
    assert(second >=0);
    assert(third  >= 0);
    assert(fourth >= 0);
    assert(fifth  >= 0);
    assert(sixth  >= 0);
    
    int i_min = first;

    if(hp->arr[i_min] > hp->arr[second])
    {
        i_min = second;
    }

    if(hp->arr[i_min] > hp->arr[third])
    {
        i_min = third;
    }

    if(hp->arr[i_min] > hp->arr[fourth])
    {
        i_min = fourth;
    }

    if(hp->arr[i_min] > hp->arr[fifth])
    {
        i_min = fifth;
    }

    if(hp->arr[i_min] > hp->arr[sixth])
    {
        i_min = sixth;
    }

    return i_min;
}

int MaxOfSix(Heap* hp, int first, int second, int third, int fourth, int fifth, int sixth)
{
    assert(hp != NULL);
    assert(first  >= 0);
    assert(second >=0);
    assert(third  >= 0);
    assert(fourth >= 0);
    assert(fifth  >= 0);
    assert(sixth  >= 0);

    int i_max = first;

    if(hp->arr[i_max] < hp->arr[second])
    {
        i_max = second;
    }

    if(hp->arr[i_max] < hp->arr[third])
    {
        i_max = third;
    }

    if(hp->arr[i_max] < hp->arr[fourth])
    {
        i_max = fourth;
    }

    if(hp->arr[i_max] < hp->arr[fifth])
    {
        i_max = fifth;
    }

    if(hp->arr[i_max] < hp->arr[sixth])
    {
        i_max = sixth;
    }

    return i_max;
}

int GetMin(Heap* hp, int index)
{
    assert(hp != NULL);
    assert(index >= 0);    
    
    int left    = GiveLeftChild(index)  < hp->size ? GiveLeftChild(index)  : index;      //children
    int right   = GiveRightChild(index) < hp->size ? GiveRightChild(index) : left;

    int l_left  = GiveLeftChild(left)   <  hp->size ? GiveLeftChild(left)   : left;       //grandchildren
    int l_right = GiveRightChild(left)  <  hp->size ? GiveRightChild(left)  : l_left;
    int r_left  = GiveLeftChild(right)  <  hp->size ? GiveLeftChild(right)  : l_right;
    int r_right = GiveRightChild(right) <  hp->size ? GiveRightChild(right) : r_left;

    return MinOfSix(hp, left, right, l_left, l_right,  r_left, r_right);
}

int GetMax(Heap* hp, int index)
{
    assert(hp != NULL);
    assert(index >= 0);   

    int left    = GiveLeftChild(index)  < hp->size ? GiveLeftChild(index)   : index;      //дети
    int right   = GiveRightChild(index) < hp->size ? GiveRightChild(index)  : left;

    int l_left  = GiveLeftChild(left)   <  hp->size ? GiveLeftChild(left)   : left;       //внуки
    int l_right = GiveRightChild(left)  <  hp->size ? GiveRightChild(left)  : l_left;
    int r_left  = GiveLeftChild(right)  <  hp->size ? GiveLeftChild(right)  : l_right;
    int r_right = GiveRightChild(right) <  hp->size ? GiveRightChild(right) : r_left;

    return MaxOfSix(hp, left, right, l_left, l_right,  r_left, r_right);
}

void SiftDown(Heap* hp, int index)
{
    assert(hp != NULL);
    assert(index >= 0);   

    if (index >= hp->size) return;

    while(index * 2 + 1 < hp->size)
    {
        if (FindLevel(index) == 1)                                   //уровень минимумов
        {
            int i_min = GetMin(hp, index);
            if (hp->arr[index] > hp->arr[i_min])
            {
                swap(&(hp->arr[index]), &(hp->arr[i_min]));
                if (i_min >= 2*(2*index + 1) + 1)
                {
                    if (hp->arr[i_min] > hp->arr[(i_min - 1) / 2])
                    {
                        swap(&(hp->arr[i_min]), &(hp->arr[(i_min - 1)/ 2]));

                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            index = i_min;

        }
        else                                                        //уровень максимумов
        {
            int i_max = GetMax(hp, index);
            if (hp->arr[index] < hp->arr[i_max])
            {
                swap(&(hp->arr[index]), &(hp->arr[i_max]));
                if (i_max >= 2*(2*index + 1) + 1)
                {
                    if (hp->arr[i_max] < hp->arr[(i_max - 1) / 2])
                    {
                        swap(&(hp->arr[i_max]), &(hp->arr[(i_max - 1)/ 2]));

                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            index = i_max;
        }
    }
}

Heap* HeapCtor(int capacity)
{
    assert(capacity > 0);

    Heap* heap = (Heap*)calloc(1, sizeof(Heap));
    if (heap == NULL)
    {
        printf("Error of memory\n");
        return NULL;
    }
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int*)calloc(1, MAX_LEN * sizeof(int));

    return heap;
}

void SiftUp(Heap* hp, int index)
{
    assert(hp);
    assert(index >= 0);

    int parent       = 0;
    int grand_parent = 0;

    while(index != 0)
    {
        parent       = GetParent(index);
        grand_parent = GetGrandParent(index);

        if (FindLevel(index) == 1)                               // уровень минимумов
        {
            if (hp->arr[index] > hp->arr[parent])
            {
                swap(&(hp->arr[index]), &(hp->arr[parent]));    //свапать с максимумом

                index = parent;
            }

            else if (grand_parent != parent && hp->arr[index] < hp->arr[grand_parent])
            {
                swap(&(hp->arr[index]), &(hp->arr[grand_parent]));
                index = grand_parent;
            }

            else return;
        }

        else                                                     //уровень максимумов
        {
            if (hp->arr[index] < hp->arr[parent])
            {
                swap(&(hp->arr[index]), &(hp->arr[parent]));    //свапать с минимумом
                index = parent;
            }

            else if (grand_parent != parent && hp->arr[index] > hp->arr[grand_parent])
            {
                swap(&(hp->arr[index]), &(hp->arr[grand_parent]));
                index = grand_parent;
            }

            else return;
        }
    }
}

void HeapPrint(Heap* heap)
{
    assert(heap != NULL);

    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void HeapDtor(Heap* hp)
{
    assert(hp != NULL);

    free(hp->arr);
    hp->size = 0;
    hp->capacity = 0;
}

int GiveMax(Heap* hp)
{
    assert(hp != NULL);

    int max_i = MaxOfThree(hp, 0, 1, 2);
    return hp->arr[max_i];
}

int GiveMin(Heap* hp)
{
    assert(hp != NULL);

    int min_i = MinOfThree(hp, 0, 1, 2);
    return hp->arr[min_i];
}

int ExtractMin(Heap* hp)
{
    assert(hp != NULL);

    int i_min = MinOfThree(hp, 0, 1, 2);
    int root  = hp->arr[i_min];

    hp->arr[i_min] = hp->arr[hp->size - 1];
    hp->size--;

    SiftDown(hp, i_min);

    return root;
}

int ExtractMax(Heap* hp)
{
    assert(hp != NULL);

    int i_max = MaxOfThree(hp, 0, 1, 2);
    int root  = hp->arr[i_max];

    hp->arr[i_max] = hp->arr[hp->size - 1];
    hp->size--;

    SiftDown(hp, i_max);

    return root;
}

void HeapClear(Heap* hp)
{
    assert(hp != NULL);

    for (int i = 0; i < hp->size; i++)
    {
        hp->arr[i] = 0;
    }
    hp->size = 0;
}

void HeapInsert(Heap* hp, int data)
{
    assert(hp != NULL);

    if (hp->size >= hp->capacity) return;

    hp->arr[hp->size] = data;
    hp->size++;

    int i = hp->size;
    SiftUp(hp, i - 1);

}

void ReadCommands(Heap* heap)
{
   int number_of_commands = 0;
    scanf("%d", &number_of_commands);

    char operation[MAX_LEN_OF_LINE] = {};

    for(int i = 0; i < number_of_commands; i++)
    {
        scanf("%s", &operation);

        if (strcmp(operation, "insert") == 0)
        {
            int n = 0;
            scanf("%d", &n);
            HeapInsert(heap, n);
            printf("ok\n");
        }

        else if (strcmp(operation, "extract_min") == 0)
        {
            if (heap->size == 0)
            {
                printf("error\n");
            }
            else
            {
                printf("%d\n", ExtractMin(heap));
            }

        }

        else if (strcmp(operation, "get_min") == 0)
        {
            if (heap->size == 0)
            {
                printf("error\n");
            }
            else
            {
                printf("%d\n", GiveMin(heap));
            }
        }

        else if (strcmp(operation, "extract_max") == 0)
        {
            if (heap->size == 0)
            {
                printf("error\n");
            }
            else
            {
                printf("%d\n", ExtractMax(heap));
            }
        }

        else if (strcmp(operation, "get_max") == 0)
        {
            if (heap->size == 0)
            {
                printf("error\n");
            }
            else
            {
                printf("%d\n", GiveMax(heap));
            }
        }

        else if (strcmp(operation, "size") == 0)
        {
            printf("%d\n", heap->size);
        }

        else if (strcmp(operation, "clear") == 0)
        {
            HeapClear(heap);
            printf("ok\n");
        }
    }

}
