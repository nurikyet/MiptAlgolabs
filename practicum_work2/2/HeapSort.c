#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "HeapSort.h"
#include "../Common.h"

#define MAX_LEN 1000
#define NUMBER_K 5

int GiveKChild(int index, int k, int mod)
{
    return k * index + mod;
}

int GetParent(int index, int k)
{
    if (index < 1) return 0;
    return (index - 1) / k;
}

int GetChild(int index, int k, int i)
{
    return index * k + i;
}

int GetMax(Heap* hp, int index)
{
    assert(hp != NULL);
 
    int max_index = index;
    int max_value = INT_MIN;
    int k         = hp->children;

    for (int i = 1; i < k + 1; i++)
    {
        int child = GetChild(index, k, i);
        if (child < hp->size && hp->arr[child] > max_value)
        {
            max_index = child;
            max_value = hp->arr[child];
        }
    }

    return max_index;
}

void SiftDown(Heap* hp, int index)
{
    assert(hp != NULL);

    if (index >= hp->size) return;
    int k = hp->children;
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

void SiftUp(Heap* hp, int index)
{
    assert(hp != NULL);

    int parent       = 0;
    int grand_parent = 0;

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

    int root  = hp->arr[0];

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

    int i = hp->size;
    SiftUp(hp, i - 1);

}

void HeapDtor(Heap* hp)
{
    assert(hp != NULL);

    free(hp->arr);
    hp->size     = 0;
    hp->capacity = 0;
}

void HeapSort(Heap* hp)
{
    assert(hp != NULL);

    int n = hp->capacity;
    for (int i = 0; i < n - 1; i++)
    {
        swap(&hp->arr[0], &hp->arr[hp->size - 1], sizeof(int));
        hp->size--;
        SiftDown(hp, 0);
    }
}

void Heapify(Heap* heap)
{
    for (int i = heap->capacity / 2 - 1; i >= 0; i--) 
    {
        SiftDown(heap, i);
    }
}

Heap* HeapCtor(int* arr, int capacity, int k)
{
    Heap* heap     = (Heap*)calloc(1, sizeof(Heap));
    if (heap == NULL)
    {
        return;
    }
    heap->size     = capacity;
    heap->capacity = capacity;
    heap->children = k;

    heap->arr = arr;

    Heapify(heap);
    return heap;
}

void HeapGiveTime(FILE* file, Heap* hp, int size)
{
    assert(hp != NULL);

    if (size == 0) return;

    double time_spent = 0.0;
    clock_t begin = clock();

    HeapSort(hp);  
    
    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(file, "%d %lf\n", size, time_spent);

}

void HeapArrCtor(FILE* file, int* arr, int size)
{
    assert(arr != NULL);

    for (int i = 0; i < size; i++)
    {
        if (fscanf(file, "%d", &arr[i]) <= 0)
        {
            return;
        }        
    }
}

void HeapTesting(int* arr, int children_num, const char* res_name, FILE* file_out, int size)
{
    if (size == 0) return;

    Heap* hp = HeapCtor(arr, size, children_num);  

    FILE* file_res = fopen(res_name, "a");
    if (file_res == NULL)
    {
        printf("I can't open file - %d\n", __LINE__);
        return;        
    }
    HeapGiveTime(file_res, hp, size);

    int* res = (int*)calloc(size + 1, sizeof(int));
    if (res == NULL)
    {
        return;
    }

    HeapArrCtor(file_out, res, size);

    for (int i = 0; i < size; i++)
    {
        if(hp->arr[i] != res[i])
        {
            printf("arr = %d, res = %d\n", hp->arr[i], res[i]); 

            printf("your algorithm is incorrect, it fails on the test %d\n", i);
            assert(false);        
        }
    }
    fclose(file_res);
    HeapDtor(hp);
    free(res);
}

void HeapTester(const int from, const int to, const int step,
                const char* src_path, const char* res_name, int children_number)
{
    for(int i = from; i < to; i += step)
    {        
        for (int j = 0; j < NUMBER_K; j++)
        {
            char file1[UCHAR_MAX];
            char file2[UCHAR_MAX];

            sprintf(file1, "%s%d_%d.in", src_path, i, j);
            sprintf(file2, "%s%d_%d.out", src_path, i, j);
            
            FILE* file_in  = fopen(file1, "rb");
            if (file_in == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            }

            FILE* file_out = fopen(file2, "rb");
            if (file_out == NULL)
            {
                printf("I can't open file - %d\n", __LINE__); 
                return;       
            } 


            int* array = (int*)calloc(i, sizeof(int));
            if (array == NULL)
            {
                return;
            }

            for(int k = 0; k < i; k++)
            {
                int data = 0;
                if (fscanf(file_in, "%d", &data) <= 0)
                {
                    return;
                }
                array[k] = data;
            }

            HeapTesting(array, children_number, res_name, file_out, i);

            fclose(file_in);
            fclose(file_out);
        }
    }
    
}
