#ifndef SPLAY_H
#define SPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#define NUMBER_TESTS 5

typedef struct Node 
{
    int key;

    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;


Node* Splay(Node* root, int key);
Node* Insert(Node* root, int key);
Node* Delete(Node* root, int key);

#endif