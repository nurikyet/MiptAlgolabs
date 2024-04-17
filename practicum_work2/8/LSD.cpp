#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "LSD.h"

#define MAX 256

static void swap(int* first, int* second);

static void swap(int* first, int* second)
{
    int temp = *first;
    *first   = *second;
    *second  = temp;
}

void LSD(int* arr, size_t size)
{
    int* temp = (int*) malloc(sizeof(int) * size);
    if (temp == NULL) 
    {
        return;
    }

    for (int mask = 0xff, shift = 0; mask > 0; mask <<= 8, shift += 8) {
        int pref_cnt[MAX] = {0};

        for (int i = 0; i < (int)size; i++) {
            pref_cnt[(arr[i] & mask) >> shift]++;
        }

        for (int i = 1; i < MAX; ++i) {
            pref_cnt[i] += pref_cnt[i - 1];
        }

        for (int i = (int)size - 1; i >= 0; --i) {
            temp[--pref_cnt[(arr[i] & mask) >> shift]] = arr[i];
        }

        memcpy(arr, temp, sizeof(int) * size);
    }

    free(temp);
}