#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_ELEMENTS 1000000 

#define MOD 1000

#define ERROR -1
#define NO_ERROR 0

#define RANDMAX 32767

#define MIN_LINE_LEN 5
#define MOD_LINE_LEN 16
#define NUMBER_OF_LETTERS_IN_ALPHABET 26

#define MY_RAND 42

static const char*  TESTS_INT     = "tests_int.txt";
static const char*  TESTS_FLOAT   = "tests_float.txt";
static const char*  TESTS_LINE    = "tests_line.txt";

int TestIntCtor()
{
    FILE* file = fopen(TESTS_INT, "w");
    if (file == NULL)
    {
        return ERROR;
    }

    srand(MY_RAND);
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        fprintf(file, "%d ", (rand() % (RANDMAX + 1) % MOD));
    }
    fprintf(file, "\n");

    fclose(file);
    return NO_ERROR;
}

int TestFloatCtor()
{
    FILE* file = fopen(TESTS_FLOAT, "w");
    if (file == NULL)
    {
        return ERROR;
    }
    
    srand(MY_RAND);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        float randomFloat = -10.0f + ((float)rand() / RAND_MAX) * (10.0f - (-10.0f)); // Генерация случайного числа float в диапазоне [-10, 10]
        fprintf(file, "%f ", randomFloat); // Запись числа в файл
    }

    fprintf(file, "\n");

    fclose(file);
    return NO_ERROR; 
}


int TestLineCtor()
{
    FILE* file = fopen(TESTS_LINE, "w");
    if (file == NULL)
    {
        return ERROR; 
    }
    
    srand(MY_RAND); 

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        int length = rand() % MOD_LINE_LEN + MIN_LINE_LEN; 
        char* line = (char*)calloc(length + 1, sizeof(char)); //+1 для нулевого завершающего символа
        for (int j = 0; j < length; j++)
        {
            line[j] = 'a' + rand() % NUMBER_OF_LETTERS_IN_ALPHABET; 
        }
        line[length] = '\0'; // Установка нулевого завершающего символа для строки
        fprintf(file, "%s ", line); 
        free(line);
    }

    fprintf(file, "\n");

    fclose(file);
}

int main()
{

    TestIntCtor();
    TestFloatCtor();
    TestLineCtor();

    return 0;
}