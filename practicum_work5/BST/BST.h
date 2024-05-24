#ifndef BST_H
#define BST_H

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
    struct Node* left;
    struct Node* right;
    int key;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

Tree* TreeCtor();
void TreeDtor(Node* root);
Node* Insert(Node* node, int key);
Node* Delete(Node* root, int key);
Node* Search(Node* node, int key);
Node* TreeMin(Node* node);
Node* NodeCtor(int key);
void PrintTreeInorder(Node* node);

#endif