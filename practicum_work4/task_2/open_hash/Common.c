#include "Common.h"

double  GiveLoadFactor(Table* table)
{
    double load_factor = (table->size) / (table->capacity); 
    return load_factor;
}

int hash1(int key, size_t table_size)
{  
    return (key % table_size);
}

Table* add(Table* table, int key, double load_factor) 
{
    assert(table != NULL);

    int hash_index = hash1(key, table->capacity);

    #ifdef OPEN_HASH_2  
    int i = 0;
    #elif defined(DOUBLE_HASH)
    int i = 1; 
    #endif

    while (table->hash_table[hash_index] != NULL) 
    {
        #ifdef  OPEN_HASH_1
        hash_index++;
        hash_index = hash1(hash_index, table->capacity);
        #elif defined(OPEN_HASH_2)
        i++;
        hash_index = (int)(hash1(key, table->capacity) + C1 * i + C2 * i * i) % table->capacity;
        #elif defined(DOUBLE_HASH)
        int hash2_value = hash2(key, table->capacity);
        hash_index = (hash1(key, table->capacity) + i * hash2_value) % table->capacity;
        i++;
        #endif
    }

    Node* new_node = (Node*)calloc(1, sizeof(Node));
    new_node->value = key;

    table->hash_table[hash_index] = new_node;
    table->size++;

    if (GiveLoadFactor(table) >= load_factor) 
    {
        table = Rehash(table, load_factor);
    }

    return table;
}

bool check(Table* table, int key) 
{
    assert(table != NULL);

    int hash_index = hash1(key, table->capacity);
    #ifdef OPEN_HASH_2
    int i = 0; 
    #elif defined(DOUBLE_HASH)
    int i = 1;
    #endif
    while (table->hash_table[hash_index] != NULL) 
    {
        if (table->hash_table[hash_index]->value == key) 
        {
            return true;
        }
        #ifdef OPEN_HASH_1
        hash_index++;
        hash_index = hash1(hash_index, table->capacity);
        #elif defined(OPEN_HASH_2)
        i++;
        hash_index = (int)(hash1(key, table->capacity) + C1 * i + C2 * i * i) % table->capacity;
        #elif defined(DOUBLE_HASH)
        int hash2_value = hash2(key, table->capacity);
        hash_index = (hash1(key, table->capacity) + i * hash2_value) % table->capacity;
        i++;
        #endif
    }

    return false; 
}


void delete(Table* table, int key) 
{
    assert(table != NULL);

    int hash_index = hash1(key, table->capacity);
    #ifdef OPEN_HASH_2
    int i = 0; 
    #elif defined(DOUBLE_HASH)
    int i = 1;
    #endif
    while (table->hash_table[hash_index] != NULL) 
    {
        if (table->hash_table[hash_index]->value == key) 
        {
            free(table->hash_table[hash_index]);
            table->hash_table[hash_index] = NULL;
            table->size--;
            break;
        }
        #ifdef OPEN_HASH_1
        hash_index++;
        hash_index = hash1(hash_index, table->capacity);
        #elif defined(OPEN_HASH_2)
        i++;
        hash_index = (int)(hash1(key, table->capacity) + C1 * i + C2 * i * i) % table->capacity;
        #elif defined(DOUBLE_HASH)
        int hash2_value = hash2(key, table->capacity);
        hash_index = (hash1(key, table->capacity) + i * hash2_value) % table->capacity;
        i++;
        #endif
    }
}

void TableDtor(Table* table) 
{    
    assert(table != NULL);

    table->size     = 0;
    table->capacity = 0;

    free(table->hash_table);
    free(table);
}

Table* TableCtor(size_t capacity) 
{
    assert(capacity > 0);

    Table* table      = (Table*)calloc(1, sizeof(Table));
    if (table == NULL)
    {
        return (Table*)ERROR_OF_ALLOCATING_MEMORY;
    }

    table->size       = 0;
    table->capacity   = capacity;

    table->hash_table = (Node**)calloc(table->capacity, sizeof(Node*));
    if (table->hash_table == NULL)
    {
        return (Table*)ERROR_OF_ALLOCATING_MEMORY;
    }
    return table;
}

Table* Rehash(Table* table, double load_factor)
{
    assert(table != NULL);

    int new_capacity  = 2 * (table->capacity);
    Table* new_table  = TableCtor(new_capacity);
    for (int i  = 0; i < table->capacity; i++)
    {
        if (table->hash_table[i] != NULL)
        {
            new_table = add(new_table, table->hash_table[i]->value, load_factor);
        }
    }
    TableDtor(table);
    return new_table;
}
