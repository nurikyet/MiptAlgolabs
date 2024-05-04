#ifndef INT_HASH_FUNCTIONS_H
#define INT_HASH_FUNCTIONS_H

#define ABOBA printf("%s %d\n", __func__, __LINE__);

#define DEVISION 1543
#define MOD 1000
#define INT_NUMBER_LEN 32

enum Status
{
    NO_ERROR                   = 0,
    ERROR_OF_ALLOCATING_MEMORY = -1,
    ERROR_SCANF                = -2,
    ERROR_FILE                 = -3
};

const double A = 0.6180339887;

int DivisionMethod(int number);
int BitRepresentationMethod(int number);
int MultiplicationMethod(int number);
#endif 