#include <stdlib.h>
#include <string.h>
#include "Common.h"

static void swap(void* first, void* second, size_t elem_size)
{
    void* temp = calloc(1, elem_size);
    if(temp == NULL)
    {
        return;
    }

    memcpy(temp, first, elem_size);
    memcpy(first, second, elem_size);
    memcpy(second, temp, elem_size);

    free(temp);
}