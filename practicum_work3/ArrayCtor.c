#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const unsigned int SEED = 42;

int main(int argc, char *argv[])
{
    char str[100];
    strcpy(str, argv[1]);         //size
    strcat(str, "_");
    strcat(str, argv[2]);         //k - number of test
    strcat(str, ".in");

    FILE* file = fopen(str, "w");

    if (argc <= 3)
    {
        printf("Usage: %s <number of elements> <max element value>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int max_val = atoi(argv[3]);  //max_val

    srand(SEED);

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", rand() % (max_val + 1));
    }
    fprintf(file, "\n");
    return 0;
}
