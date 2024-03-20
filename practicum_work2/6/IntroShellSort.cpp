#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "../Common.h"
#include "IntroShellSort.h"

void IntrosortShellSort(int* arr, size_t size, int block_size)
{
    for (int step = block_size; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= step && arr[j - step] > temp)
            {
                arr[j] = arr[j - step];
                j -= step;
            }

            arr[j] = temp;
        }
    }
}