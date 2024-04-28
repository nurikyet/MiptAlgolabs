#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

const int MAX_LEN = 1000000;

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    char str[UCHAR_MAX];
    strcpy(str, argv[1]);
    strcat(str, "_");
    strcat(str, argv[2]);

    char file_in_name[UCHAR_MAX];
    char file_out_name[UCHAR_MAX];

    strcpy(file_in_name, str);
    strcat(file_in_name, ".in");

    strcpy(file_out_name, str);
    strcat(file_out_name, ".out");

    FILE* file_in = fopen(file_in_name, "r");
    FILE* file_out = fopen(file_out_name, "w");


    int n = 0;
    int* array = (int*)calloc(MAX_LEN, sizeof(int));
    if (array == NULL)
    {
        return;
    }

    while (fscanf(file_in, "%d", &array[n]) == 1)
    {
        n++;
    }
    qsort(array, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
    {
        fprintf(file_out, "%d ", array[i]);
    }
    fprintf(file_out, "\n");
    free(array);

    fclose(file_in);
    fclose(file_out);
    
    return 0;
}
