#ifndef COMMON_H
#define COMMON_H

enum Status 
{
    NO_ERROR = 0,
    ERROR_SCANF = -1,
    ERROR_OF_ALLOCATING_MEMORY = -2
};

#define ABOBA printf("%d %s\n", __LINE__, __func__);

#endif