#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include "Common.h"

int main(int argc, char *argv[])
{
    char str[UCHAR_MAX];
    strcpy(str, argv[1]);         //size
    strcat(str, "_");
    strcat(str, argv[2]);         //k - number of test
    strcat(str, ".in");

    FILE* file = fopen(str, "w");
    if (file == NULL)
    {
        return ERROR_FILE;
    }

    if (argc <= 4)
    {
        printf("Usage: %s <number of elements> <max element value>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int max_val = atoi(argv[3]);  //max_val

    int my_rand = atoi(argv[4]);  //rand

    srand(my_rand);

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", rand() % (max_val + 1));
    }
    fprintf(file, "\n");

    fclose(file);
    return 0;
}
