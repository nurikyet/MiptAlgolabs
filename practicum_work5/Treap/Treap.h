#ifndef TREAP_H
#define TREAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

typedef struct Node
{
    struct Node* left;
    struct Node* right;

    int key;
    int priority;

    int size;
} Node;

void RootDelete(Node* root);
Node* NodeInsert(Node* root, int key, int priority);
Node* NodeDelete(Node* root, int key);
Node* FindNode(Node* root, int key);
#endif