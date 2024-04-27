#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LEN 30

#define ABOBA printf("%s - %d\n", __func__, __LINE__);

typedef struct Node
{
    struct Node* left;
    struct Node* right;

    int key;
    int priority;

    int size;
} Node;

enum Status
{
    NO_ERROR                   = 0,
    ERROR_KTH                  = -1,
    ERROR_OF_ALLOCATING_MEMORY = -2,
    ERROR_UNKNOWN_COMMAND      = -3,
    ERROR_FILE                 = -4
};

Node* NodeDelete(Node* root, int key);

int GiveSize(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->size;
}

void Resize(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    
    node->size = GiveSize(node->left) + GiveSize(node->right) + 1;
}

Node* NodeCtor(int key)
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        return (Node*)ERROR_OF_ALLOCATING_MEMORY;
    }

    node->key      = key;
    node->priority = rand();

    node->size     = 1;
    
    node->left     = NULL;
    node->right    = NULL;
    
    return node;
}

void TreeSplit(Node* node, int key, Node** left, Node** right)
{
    if (node == NULL)
    {
        *left  = NULL;
        *right = NULL;
        return;
    }
    if (node->key >= key)
    {
        *right = node;
        TreeSplit(node->left, key, left, &((*right)->left));
    }
    else
    {
        *left = node;
        TreeSplit(node->right, key, &((*left)->right), right);
    }
}

Node* RightRotate(Node* node)
{
    Node* new_node  = node->left;

    node->left      = new_node->right;
    new_node->right = node;

    Resize(node);
    Resize(new_node);
    return new_node;
}

Node* LeftRotate(Node* node)
{
    Node* new_node = node->right;

    node->right    = new_node->left;
    new_node->left = node;

    Resize(node);
    Resize(new_node);

    return new_node;
}

Node* PerformRotation(Node* node)
{
    Node* new_node = NULL;
    if (node->left != NULL && node->right != NULL)
    {
        if (node->left->priority > node->right->priority)
        {
            new_node = RightRotate(node);
        }
        else
        {
            new_node = LeftRotate(node);
        }
    }
    return new_node;
}

Node* TreeMerge(Node* left, Node* right)
{
    
    if (left == NULL || right == NULL)
    {
        if (right == NULL) 
        {
            return left;
        } 
        else 
        {
            return right;
        }
    }
    if (left->priority <= right->priority)
    {
        right->left = TreeMerge(left, right->left);
        return right;
    }
    else
    {
        left->right = TreeMerge(left->right, right);
        return left;
    }
}

Node* NodeInsert(Node* root, int key, int priority)
{    
    if (root == NULL)
    {
        Node* new_root = (Node*)calloc(1, sizeof(Node));
        if (new_root   == NULL)
        {
            return NULL;
        }

        new_root->key = key;
        new_root->priority = priority;
        
        new_root->size = 1;

        new_root->left =  NULL;
        new_root->right = NULL;
        
        return new_root;
    }

    if (key > root->key)
    {
        root->right = NodeInsert(root->right, key, priority);
        if (root->right != NULL && root->right->priority > root->priority)
        {
            root = LeftRotate(root);
        }
    }
    else if (key < root->key)
    {
        root->left = NodeInsert(root->left, key, priority);
        if (root->left != NULL && root->left->priority > root->priority)
        {
            root = RightRotate(root);
        }        
    }

    Resize(root);
    return root;
}

Node* DeleteLeaf(Node* node)
{
    free(node);
    return NULL;
}

Node* DeleteNodeWithOneChild(Node* node)
{
    Node* new_root = NULL;
    if (node->right == NULL)
    {
        new_root = node->left;
    }
    else 
    {
        new_root = node->right;
    }
    free(node);
    return new_root;
}

Node* FindMaxLeftChild(Node* node)
{
    Node* max_left_child = node->left;
    while (max_left_child->right != NULL)
    {
        max_left_child = max_left_child->right;
    }
    return max_left_child;
}

Node* NodeDelete(Node* root, int key)
{
    if (root  == NULL)
    {
        return NULL;
    }
    if (key > root->key)
    {
        root->right = NodeDelete(root->right, key);
    }
    else if (key < root->key)
    {
        root->left = NodeDelete(root->left, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            if (root->left == NULL && root->right == NULL) 
            {
                return DeleteLeaf(root); // удалить листовой узел
            } 
            else 
            {
                return DeleteNodeWithOneChild(root); // удалить узел с одним потомком
            }
        }
        else
        {
            Node* max_left_child = FindMaxLeftChild(root);
            root->key  = max_left_child->key;
            root->left = NodeDelete(root->left, max_left_child->key);
        }
    }
  
    if (root != NULL)
    {
        Node* left_child  = root->left;
        Node* right_child = root->right;
        
        if (left_child != NULL && left_child->priority > root->priority) 
        {
            root = PerformRotation(root);
        }
        else if (right_child != NULL && right_child->priority > root->priority)
        {
            root = PerformRotation(root);
        }
        
        Resize(root);
    }
    return root;
}

Node* FindNode(Node* root, int key)
{    
    while (root != NULL)
    {
        if (key == root->key)
        {
            return root;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

Node* NodeNext(Node* root, int key)
{
    
    Node* next_node = NULL;
    while (root != NULL)
    {
        if (key < root->key)
        {
            next_node = root;
            root      = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return next_node;
}

int TreeKTH(Node* root, int k)
{
    
    if (k < 0 || (root == NULL))
    {
        return ERROR_KTH;
    }
    int size      = GiveSize(root);
    int size_left = GiveSize(root->left);
    
    if (k >= size)
    {
        return ERROR_KTH;
    }

    if (k == size_left)
    {
        return root->key;
    }
    
    if (k < size_left)
    {
        return TreeKTH(root->left, k);
    }
    return TreeKTH(root->right, k - size_left - 1);
}

Node* NodePrev(Node* root, int key)
{
    Node* prev_node = NULL;
    
    while (root != NULL)
    {
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            prev_node = root;
            root      = root->right;
        }
        else
        {
            return root;
        }
    }
    return prev_node;
}

int ExecuteCommands(FILE* file_in, Node** root_ptr)
{
    char* operation = (char*)calloc(LINE_LEN, sizeof(char));
    if (operation   == NULL)
    {
        return ERROR_OF_ALLOCATING_MEMORY;
    }
    int value = 0;

    Node* root = *root_ptr;

    while(fscanf(file_in, "%30s %d", operation, &value) == 2)
    {
        if (strcmp(operation, "insert")    == 0)
        {
            if (FindNode(root, value)    == NULL)
            {
                int priority = rand();
                root = NodeInsert(root, value, priority);
            }
        }
        else if (strcmp(operation, "delete") == 0)
        {
            if (FindNode(root, value) != NULL)
            {
                root = NodeDelete(root, value);
            }
        }
        else if (strcmp(operation, "exists") == 0)
        {
            if (FindNode(root, value) != NULL)   
            {
                printf("true\n");
            } 
            else
            {
                printf("false\n");
            }
        }
        else if (strcmp(operation, "next") == 0)
        {
            Node* next = NodeNext(root, value);
            if (next == NULL)
            {
                printf("none\n");
            }
            else 
            {
                printf("%d\n", next->key);
            }
        }
        else if (strcmp(operation, "prev") == 0)
        {
            Node* previous = NodePrev(root, value);
            if (previous == NULL)
            {
                printf("none\n");
            }
            else
            {
                printf("%d\n", previous->key);
            }
        }
        else if (strcmp(operation, "kth") == 0)
        {
            int kth_value = TreeKTH(root, value);    
            if (kth_value >= 0)
            {
                printf("%d\n", kth_value);
            }
            else 
            {
                printf("none\n");
            }
        }
        else
        {
            free(operation);
            return ERROR_UNKNOWN_COMMAND;
        }
    }

    free(operation);
    
    *root_ptr = root;

    return NO_ERROR;
}

void RootDelete(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    RootDelete(root->left);  
    RootDelete(root->right); 
    free(root); 
}

int main()
{
    Node* root = NULL;
    FILE* file_in = fopen("input.txt", "r");
    if(file_in == NULL)
    {
        return ERROR_FILE;
    }

    ExecuteCommands(file_in, &root);
    RootDelete(root); 
    fclose(file_in);
    return 0;
}
