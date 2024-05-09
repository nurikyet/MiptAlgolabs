#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#define MAX_LEN 100000
#define NUMBER_TESTS 5
#define BAMBUK_LEN 10000

typedef struct Node
{
    int data;
    int height;

    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

Node* Delete(Node* root, int data);
Node* Insert(Node* node, int data);
Tree* TreeCtor();
void TreeDtor(Node* root);

#endif