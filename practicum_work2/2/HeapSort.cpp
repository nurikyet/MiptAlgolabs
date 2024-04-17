#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include "HeapSort.h"

#define MAX_LEN 1000
#define NUMBER_K 5

static void swap(int* a, int* b);

int GiveKChild(int index, int k, int mod)
{
    return k * index + mod;
}

static void swap(int* first, int* second)
{
    int temp = *first;
    *first   = *second;
    *second  = temp;
}

int GetParent(int index, int k)
{
    if (index < 1) return 0;
    return (index - 1) / k;
}

int GetMax(Heap* hp, int index)
{
    int max_index = index;
    int max_value = INT_MIN;
    int k         = hp->children;

    for (int i = 1; i < k + 1; i++)
    {
        int child = index * k + i;
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
    if (index >= hp->size) return;
    int k = hp->children;
    while(index * k + 1 < hp->size)
    {
        int i_max = GetMax(hp, index);
        if (hp->arr[index] < hp->arr[i_max])
        {
            swap(&(hp->arr[index]), &(hp->arr[i_max]));
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
    assert(hp);
    int parent       = 0;
    int grand_parent = 0;

    while(index != 0)
    {
        parent       = GetParent(index, hp->children);

        if (hp->arr[index] > hp->arr[parent])
        {
            swap(&(hp->arr[index]), &(hp->arr[parent]));  

            index = parent;
        }
        else return;
    }
}

int ExtractMax(Heap* h)
{
    int root  = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    SiftDown(h, 0);

    return root;
}

void HeapInsert(Heap* hp, int data)
{
    if (hp->size >= hp->capacity) return;

    hp->arr[hp->size] = data;
    hp->size++;

    int i = hp->size;
    SiftUp(hp, i - 1);

}

void HeapDtor(Heap* h)
{
    free(h->arr);
    h->size = 0;
    h->capacity = 0;
}

void HeapSort(Heap* hp)
{
    int n = hp->capacity;
    for (int i = 0; i < n - 1; i++)
    {
        swap(&hp->arr[0], &hp->arr[hp->size - 1]);
        hp->size--;
        SiftDown(hp, 0);
    }
}

Heap* HeapCtor(FILE* file, int capacity, int k)
{
    Heap* h     = (Heap*)calloc(1, sizeof(Heap));
    if (h == NULL)
    {
        printf("Error of memory\n");
        return NULL;
    }
    h->size     = 0;
    h->capacity = capacity;
    h->children = k;
    h->arr      = (int*)calloc(1, (capacity  + 5)* sizeof(int));

    for(int i = 0; i < capacity; i++)
    {
        int data = 0;
        fscanf(file, "%d", &data);
        HeapInsert(h, data);
    }
    return h;
}

void HeapGiveTime(FILE* file, Heap* hp, int size)
{
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
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%d", &arr[i]);        
    }
}

void HeapTesting(int children_num, const char* res_name, FILE* file_in, FILE* file_out, int size)
{
    if (size == 0) return;

    Heap* hp = HeapCtor(file_in, size, children_num);  

    FILE* file_res = fopen(res_name, "a");
    if (file_res == NULL)
    {
        printf("I can't open file - %d\n", __LINE__);
        return;        
    }
    HeapGiveTime(file_res, hp, size);

    int* res = (int*)calloc(size + 1, sizeof(int));
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
            char file1[256];
            char file2[256];

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
            HeapTesting(children_number, res_name, file_in, file_out, i);

            fclose(file_in);
            fclose(file_out);
        }
    }
    
}
