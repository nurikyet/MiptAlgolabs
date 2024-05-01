void swap(void* a, void* b, size_t elem_size);

enum Status 
{
    NO_ERROR                   =  0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_FILE                 = -2,
    ERROR_SCANF                = -3
};