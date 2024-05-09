#include "AVL.h"
#include "../Common.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

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

Node* Insert(Node* node, int data) 
{
    if (node == NULL) 
    {
        return NewNode(data);
    }

    if (data < node->data) 
    {
        node->left = Insert(node->left, data);
    } 
    else if (data > node->data) 
    {
        node->right = Insert(node->right, data);
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

Node* MinValueNode(Node* root) 
{
    Node* current = root;

    while (current && current->left != NULL) 
    {
        current = current->left;
    }

    return current;
}

Node* Delete(Node* root, int data) 
{
    if (root == NULL) 
    {
        return root;
    }

    if (data < root->data) 
    {
        root->left = Delete(root->left, data);
    } else if (data > root->data) 
    {
        root->right = Delete(root->right, data);
    } 
    else 
    {
        if (root->left == NULL || root->right == NULL) 
        {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) 
            {
                temp = root;
                root = NULL;
            } 
            else 
            {
                *root = *temp;
            }

            free(temp);
        } 
        else 
        {
            Node* temp = MinValueNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    if (root == NULL) 
    {
        return root;
    }

    int leftHeight = (root->left) ? root->left->height : 0;
    int rightHeight = (root->right) ? root->right->height : 0;
    root->height = 1 + max(leftHeight, rightHeight);

    int balance = GetBalance(root);

    if (balance > 1 && GetBalance(root->left) >= 0) {
        root = RightRotate(root);
    }
    if (balance < -1 && GetBalance(root->right) <= 0) {
        root = LeftRotate(root);
    }
    if (balance > 1 && GetBalance(root->left) < 0) {
        root->left = LeftRotate(root->left);
        root = RightRotate(root);
    }
    if (balance < -1 && GetBalance(root->right) > 0) {
        root->right = RightRotate(root->right);
        root = LeftRotate(root);
    }

    return root;
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
