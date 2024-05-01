#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "IntroShellSort.h"

void IntroShellSort(int* arr, size_t size)
{
    int step = 1;
    while(step <= size / 9)
    {
        step = step * 3 + 1;
    }
    for(; step > 0; step /= 3)
    {
        for(int i = step; i < size; i += step)
        {
            int j = i;
            int tmp = arr[i];

            for (; j >= step && arr[j - step] > tmp; j-=step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = tmp;
        }
    }
}