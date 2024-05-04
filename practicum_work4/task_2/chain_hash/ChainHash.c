#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <limits.h>

#include "ChainHash.h"

int hash(int number)
{  
    return NUMBER_OF_ELEMENTS * (number * A - (int)(number*A));
}

double  GiveLoadFactor(Table* table)
{
    double load_factor = (table->size) / (table->capacity); 
    return load_factor;
}

Table* Rehash(Table* table, double load_factor)
{
    int new_capacity  = 2 * (table->capacity);
    Table* new_table  = TableCtor(new_capacity);
    for (int i  = 0; i < table->size; i++)
    {
        Node* current = table->hash_table[i].next;
        while(current != NULL)
        {
            int value = current->value;
            add(new_table, value, load_factor);
            current   = current->next;
        }
    }
    TableDtor(table);
    return new_table;
}

bool check(Table* table, int value)
{
    int index      = hash(value) % (table->capacity);
    Node* current  = table->hash_table[index].next;

    while(current != NULL)
    {
        if (current->value == value)
        {
            return true;
        }
        current    = current->next;
    }
    return false;
}

Table* add(Table* table, int value, double load_factor)
{
    int index = hash(value)%(table->capacity);

    if (GiveLoadFactor(table) >= load_factor)
    {
        table = Rehash(table, load_factor);
    }
    if (check(table, value))
    {
        return table;
    }
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    if (new_node == NULL)
    {
        return (Table*)ERROR_OF_ALLOCATING_MEMORY;
    }
    new_node->value = value;
    new_node->next  = NULL;
    table->size++;
    if (table->hash_table[index].next == NULL)
    {
        table->hash_table[index].next = new_node;
    }
    else
    {
        Node* current = table->hash_table[index].next;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    if (GiveLoadFactor(table) >= MAX_LOAD_FACTOR)
    {
        table = Rehash(table, MAX_LOAD_FACTOR);
    }
    return table;
}

void delete(Table* table, int value)
{
    if (check(table, value) == 0)
    {
        return;
    }
    int index_in_hash  = hash(value) % (table->capacity);
    Node* current      = table->hash_table[index_in_hash].next;
    Node* previous     = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            if (previous == NULL)
            {
                table->hash_table[index_in_hash].next = current->next;
                free(current);
                current = table->hash_table[index_in_hash].next;
            }
            else
            {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current  = current->next;
        }
    }
    table->size--;
}

Table* TableCtor(int capacity)
{
    Table* table      = (Table*)calloc(1, sizeof(Table));
    if (table == NULL)
    {
        return (Table*)ERROR_OF_ALLOCATING_MEMORY;
    }
    table->capacity   = capacity;
    Node* hashtable   = (Node*)calloc(capacity + 1, sizeof(Node));
    if (hashtable == NULL)
    {
        return (Table*)ERROR_OF_ALLOCATING_MEMORY;
    }
    table->hash_table = hashtable;
    return table;
}

void TableDtor(Table* table)
{
    for (int i = 0; i < table->capacity; i++) 
    {
        Node* current   = table->hash_table[i].next;
        while (current != NULL) 
        {
            Node* temp  = current;
            current     = current->next;
            free(temp);
        }
    }
    table->capacity     = POISON;
    table->size         = POISON;
    free(table->hash_table);
    free(table);
}

void LoadFactorTester(FILE* res_file, int capacity, double load_factor)
{
    Table* table = TableCtor(capacity);

    double time_spent = 0.0;
    clock_t begin     = clock();
    
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        int data = i;
        table = add(table, data, load_factor);        
    }

    clock_t end       = clock();
    time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(res_file, "%lg %lg\n", load_factor, time_spent);

    TableDtor(table);
}

void FirstTest()
{
    FILE* test_file = fopen(FIRST_TEST_FILE, "w");
    if (test_file == NULL)
    {
        return;
    }
    for (int size = 10000; size < 1000000; size += 10000)
    {
        Table* table = TableCtor(size);

        double time_spent = 0.0;
        clock_t begin     = clock();

        for (int i = 0; i < size; i++)
        {
            int data      = rand() % LEN;
            int operation = rand();

            if (operation % FIRST_MOD == 0)
            {
                add(table, data, MAX_LOAD_FACTOR);
            }
            else if (operation % FIRST_MOD == 1)
            {
                check(table, data);
            }
            else
            {
                delete(table, data);
            }
        }

        clock_t end       = clock();
        time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(test_file, "%d %lg\n", size, time_spent);
        TableDtor(table);
    }
    fclose(test_file);
}

void SecondTest()
{
    FILE* test_file = fopen(SECOND_TEST_FILE, "w");
    if (test_file == NULL) 
    {
        return;
    }
    for (int size = 10000; size < 1000000; size += 10000)
    {
        Table* table = TableCtor(size);

        double time_spent = 0.0;
        clock_t begin     = clock();

        for (int i = 0; i < size; i++)
        {
            int data      = rand();
            int operation = rand();

            if (operation % (SECOND_MOD / 2) == 0)
            {
                add(table, data, MAX_LOAD_FACTOR);
            }
            else if (operation % SECOND_MOD == 1)
            {
                check(table, data);
            }
            else
            {
                delete(table, data);
            }
        }

        clock_t end       = clock();
        time_spent       += (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(test_file, "%d %lg\n", size, time_spent);
        TableDtor(table);
    }
    fclose(test_file);
}


int main()
{
    FirstTest();
    SecondTest();

    return 0;
}
