#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

enum Status
{
    NO_ERROR                   = 0,
    ERROR_SIZE                 = 1,
    ERROR_OF_SCANF             = 2,
    ERROR_OF_ALLOCATING_MEMORY = 3 
};

void quickSort(int* array, int low, int high);
void printNumbers(int* array, int number_of_elements);
int readNumbers(int* array, int number_of_elements);

int main()
{
    int number_of_elements = 0;
    if (scanf("%d", &number_of_elements) <= 0)
    {
        return ERROR_OF_SCANF;
    }
    if (number_of_elements <= 0)
    {
        return ERROR_SIZE;
    }

    int* array = calloc(number_of_elements, sizeof(int));
    if (array == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    if (readNumbers(array, number_of_elements) != NO_ERROR)
    {
        return ERROR_OF_SCANF;
    }

    quickSort(array, 0, number_of_elements - 1);

    printNumbers(array, number_of_elements);

    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
          *a = *b;
          *b = temp;
}

void quickSort(int* array, int low, int high)
{
    assert(array != NULL);

    if (low < high)
    {
        int i = low;
        int j = high;

        int pivot = array[(low + high)/2];

        while(i <= j)
        {
            while (array[i] < pivot)
            {
                i++;
            }
            while (array[j] > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                swap(&array[i++], &array[j--]);
            }
        }

        quickSort(array, low, j);
        quickSort(array, i, high);
    }
}

int readNumbers(int* array, int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        if (scanf("%d", &array[i]) <= 0)
        {
            return ERROR_OF_SCANF;
        }
    } 
    return NO_ERROR;
}

void printNumbers(int* array, int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d ", array[i]);
    }
}
