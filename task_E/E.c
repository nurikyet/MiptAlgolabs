#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MOD 1000000000

typedef struct Node
{
    int data;
    int height;

    struct Node* left;
    struct Node* right;
}Node;

#define max(a, b) (((a) > (b)) ? (a) : (b))

enum Status
{
    NO_ERROR                   = 0,
    ERROR_SCANF                = -1,
    ERROR_OF_ALLOCATING_MEMORY = -2,
    ERROR_UNKNOWN_COMMAND      = -3 
};

int GiveHeight(Node* node) 
{
    if (node == NULL) 
    {
        return 0;
    }
    return node->height;
}

int GetBalance(Node* node) 
{
    assert(node != NULL);

    if (node == NULL) 
    {
        return 0;
    }
    return GiveHeight(node->left) - GiveHeight(node->right);
}

Node* NewNode(int data) 
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    if (node == NULL)
    {
        return (Node*)ERROR_OF_ALLOCATING_MEMORY;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

//правый поворот вокруг node
Node* RightRotate(Node* node) 
{
    assert(node != NULL);

    Node* left_child        = node->left;
    Node* right_grandchild  = left_child->right;

    left_child->right       = node;
    node->left              = right_grandchild;

    node->height            = max(GiveHeight(node->left), GiveHeight(node->right)) + 1;
    left_child->height      = max(GiveHeight(left_child->left), GiveHeight(left_child->right)) + 1;

    return left_child;
}

// Левый поворот вокруг node
Node* LeftRotate(Node* node) 
{
    assert(node != NULL);

    Node* right_child     = node->right;
    Node* left_grandchild = right_child->left;

    right_child->left     = node;
    node->right           = left_grandchild;

    node->height          = max(GiveHeight(node->left), GiveHeight(node->right)) + 1;
    right_child->height   = max(GiveHeight(right_child->left), GiveHeight(right_child->right)) + 1;

    return right_child;
}

Node* AVLInsert(Node* node, int data) 
{
    if (node == NULL) 
    {
        return NewNode(data);
    }

    if (data < node->data) 
    {
        node->left = AVLInsert(node->left, data);
    } 
    else if (data > node->data) 
    {
        node->right = AVLInsert(node->right, data);
    } 
    else 
    {
        return node; 
    }

    node->height = 1 + max(GiveHeight(node->left), GiveHeight(node->right));

    int balance = GetBalance(node);

    if (balance > 1 && data < node->left->data) 
    {
        return RightRotate(node);
    }

    if (balance < -1 && data > node->right->data) 
    {
        return LeftRotate(node);
    }

    if (balance > 1 && data > node->left->data) 
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && data < node->right->data) 
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

int FindNext(Node* root, int time) 
{
    Node* current = root;
    Node* result  = NULL;

    while (current != NULL) 
    {
        if (current->data >= time) 
        {
            result = current;
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }

    if (result == NULL) 
    {
        return -1;
    } 
    else 
    {
        return result->data;
    }
}

int ExecuteCommands(Node* root, int number_of_commands)
{
    int last_add = 0; 
    for (int i = 0; i < number_of_commands; i++) 
    {
        char operation;
        int data = 0;
        if (scanf(" %c %d", &operation, &data) != 2)
        {
            return ERROR_SCANF;
        }

        if (operation == '+') 
        {
            data = (data + last_add) % MOD; 
            root = AVLInsert(root, data);
            last_add = 0; 
        } 
        else if (operation == '?') 
        {
            int result = FindNext(root, data);
            printf("%d\n", result);
            last_add = result; 
        }
        else 
        {
            return ERROR_UNKNOWN_COMMAND;
        }
    }
}

int main() 
{
    int number_of_commands = 0;
    if (scanf("%d", &number_of_commands) != 1)
    {
        return ERROR_SCANF;
    }

    Node* root = NULL;

    ExecuteCommands(root, number_of_commands);

    return 0;
}
