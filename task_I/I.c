#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ABOBA printf("%s(%d)\n", __func__, __LINE__);

#define LINE_LEN 1000

enum Status
{
    NO_ERROR                   =  0,
    ERROR_SCANF                = -1,
    ERROR_OF_ALLOCATING_MEMORY = -2
};

typedef struct Node 
{
    char* key;
    char* value;

    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* root = NULL;

Node* NodeCtor(char* key, char* value) 
{
    assert(key   != NULL);
    assert(value != NULL);
    
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    if(new_node == NULL)
    {
        return (Node*)ERROR_OF_ALLOCATING_MEMORY;
    }
    
    new_node->key   = key;
    new_node->value = value;
    
    new_node->left   = NULL;
    new_node->right  = NULL;
    
    new_node->parent = NULL;
    return new_node;
}

void RightRotate(Node *node) 
{
    assert(node != NULL);
    
    Node *left_child = node->left;
    node->left = left_child->right;
    
    if (left_child->right != NULL) 
    {
        left_child->right->parent = node;
    }
    left_child->parent = node->parent;
    
    if (node->parent == NULL) 
    {
        root = left_child;
    } 
    
    else if (node == node->parent->left) 
    {
        node->parent->left = left_child;
    } 
    
    else 
    {
        node->parent->right = left_child;
    }
    
    left_child->right = node;
    node->parent = left_child;    
}

void LeftRotate(Node *node) 
{
    assert(node != NULL);
    
    Node *right_child = node->right;
    node->right = right_child->left;

    if (right_child->left != NULL) 
    {
        right_child->left->parent = node;
    }    
    right_child->parent = node->parent;
    
    if (node->parent == NULL) 
    {
        root = right_child;
    } 

    else if (node == node->parent->left) 
    {
        node->parent->left = right_child;
    } 
    
    else 
    {
        node->parent->right = right_child;
    }
    
    right_child->left = node;
    node->parent = right_child;
    
}

void Splay(Node *node) 
{
    assert(node != NULL);
    while (node->parent != NULL) 
    {
        if (node->parent->parent == NULL) 
        {
            // Zig-операция (одиночный поворот)
            if (node == node->parent->left) 
            {
                RightRotate(node->parent);
            } 
            else 
            {
                LeftRotate(node->parent);
            }
        } 

        else if (node == node->parent->left && node->parent == node->parent->parent->left) 
        {
            // Zig-zig-операция (двойной поворот влево)
            RightRotate(node->parent->parent);
            RightRotate(node->parent);
        } 
        
        else if (node == node->parent->right && node->parent == node->parent->parent->right) 
        {
            // Zig-zig-операция (двойной поворот вправо)
            LeftRotate(node->parent->parent);
            LeftRotate(node->parent);
        } 
        
        else if (node == node->parent->right && node->parent == node->parent->parent->left) 
        {
            // Zig-zag-операция (двойной поворот)
            LeftRotate(node->parent);
            RightRotate(node->parent);
        } 
        
        else 
        {
            // Zig-zag-операция (двойной поворот)
            RightRotate(node->parent);
            LeftRotate(node->parent);
        }
    }
}

void NodeInsert(Node *current, Node *new_node) 
{
    assert(current  != NULL);
    assert(new_node != NULL);

    if (strcmp(new_node->key, current->key) < 0) 
    {        
        if (current->left == NULL) 
        {            
            current->left    = new_node;
            new_node->parent = current;
        } 
        
        else 
        {            
            NodeInsert(current->left, new_node);
        }
    } 
    else 
    {
        if (current->right == NULL) 
        {            
            current->right   = new_node;
            new_node->parent = current;
        } 
        
        else 
        {            
            NodeInsert(current->right, new_node);
        }
    }
}

void Insert(char* key, char* value) 
{
    assert(key   != NULL);
    assert(value != NULL);
    
    Node *new_node = NodeCtor(key, value);
    if (root == NULL) 
    {
        root = new_node;
    } 
    
    else 
    {        
        NodeInsert(root, new_node);
    }
}

Node* NodeSearch(Node* current, char* key) 
{
    assert(current != NULL);
    assert(key     != NULL);

    if (current == NULL || strcmp(current->key, key) == 0) 
    {        
        return current;
    } 
    
    else if (strcmp(key, current->key) < 0) 
    {        
        return NodeSearch(current->left, key);
    } 
    
    else 
    {        
        return NodeSearch(current->right, key);
    }
}

Node* Search(char* key) 
{
    assert(key != NULL);
    
    Node *found_node = NodeSearch(root, key);

    if (found_node != NULL) 
    {        
        Splay(found_node);
        return found_node;
    }
    return NULL;
}

void Clear(Node *node) 
{
    if (node == NULL) 
    {
        return;
    }

    Clear(node->left);
    Clear(node->right);

    free(node);
}

int main()
{
    int number_of_elements = 0;
    if (scanf("%d", &number_of_elements) != 1)
    {
        return ERROR_SCANF;
    }

    for (int i = 0; i < number_of_elements; i++) 
    {
        char* pilot  = (char*)calloc(LINE_LEN, sizeof(char));
        if (pilot == NULL)
        {
            return ERROR_OF_ALLOCATING_MEMORY;
        }

        char* ship   = (char*)calloc(LINE_LEN, sizeof(char));
        if (ship == NULL)
        {
            return ERROR_OF_ALLOCATING_MEMORY;
        }
        
        if (scanf("%1000s %1000s", pilot, ship) != 2)
        {
            return ERROR_SCANF;
        }

        Insert(pilot, ship);
        Insert(ship, pilot);
    }

    int number_of_requests = 0;
    if (scanf("%d", &number_of_requests) != 1)
    {
        return ERROR_SCANF;
    }

    for (int i = 0; i < number_of_requests; i++) 
    {
        char* request = (char*)calloc(LINE_LEN, sizeof(char));
        if (request == NULL)
        {
            return ERROR_OF_ALLOCATING_MEMORY;
        }

        if (scanf("%1000s", request) != 1)
        {
            return ERROR_SCANF;
        }
        Node* found_node = Search(request);
        if (found_node != NULL) 
        {
            printf("%s\n", found_node->value);
        }
        free(request);
    }

    Clear(root);

    return 0;
}