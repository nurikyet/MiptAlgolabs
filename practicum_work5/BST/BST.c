#include "BST.h"
#include "../Common.h"

Node* Search(Node* node, int key)
{
    if ((node == NULL) || (node->key == key))
    {
        return node;
    }
    if (node->key < key)
    {
        return Search(node->right, key);
    }
    if (node->key > key)
    {
        return Search(node->left, key);
    }
}
 
Node* TreeMin(Node* node)
{
    if (node->left == NULL)
    {
        return node;
    }
    return TreeMin(node->left);
}

Node* Delete(Node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = Delete(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = Delete(root->right, key);
    }
    else if ((root->left != NULL) && (root->right != NULL))
    {
        root->key   = TreeMin(root->right)->key;
        root->right = Delete(root->right, key);
    }
    else 
    {
        if (root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
        else 
        {
            root = NULL;
        }
    }
    return root;
}

Node* NodeCtor(int key)
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        return (Node*)ERROR_OF_ALLOCATING_MEMORY;
    }

    node->left  = NULL;
    node->right = NULL;
    node->key   = key;

    return node;
}

Node* Insert(Node* node, int key)
{
    if (node == NULL)
    {
        return NodeCtor(key);
    }
    else if (key < node->key)
    {
        node->left = Insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = Insert(node->right, key);
    }
    return node;
}

Tree* TreeCtor()
{
    Tree* tree = (Tree*)calloc(1, sizeof(Tree));
    if (tree == NULL)
    {
        return (Tree*)ERROR_OF_ALLOCATING_MEMORY;
    }
    tree->root = NULL;
    return tree;
}

void TreeDtor(Node* root) 
{
    if (root == NULL) 
    {
        return;
    }

    TreeDtor(root->left);
    TreeDtor(root->right);

    free(root);
}

void PrintTreeInorder(Node* node)
{
    if (node != NULL)  
    {
        PrintTreeInorder(node->left);
        printf("%d ", node->key);
        PrintTreeInorder(node->right);
    }  
    printf("\n");
}

