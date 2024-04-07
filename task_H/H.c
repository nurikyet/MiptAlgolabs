#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void quickSort(int* array, int low, int high);

int main()
{
    int number_of_elements = 0;
    scanf("%d", &number_of_elements);

    int array[number_of_elements];
    for (int i = 0; i < number_of_elements; i++)
    {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, number_of_elements - 1);

    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d ", array[i]);
    }

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
