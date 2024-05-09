#include "Splay.h"
#include "../Common.h"

Node* RotateRight(Node* node) 
{
    Node* new_node  = node->left;
    node->left      = new_node->right;
    new_node->right = node;
    return new_node;
}

Node* RotateLeft(Node* node) 
{
    Node* new_node = node->right;
    node->right    = new_node->left;
    new_node->left = node;
    return new_node;
}

Node* Splay(Node* root, int key) 
{
    if (root == NULL || root->key == key) 
    {
        return root;
    }
    
    if (key < root->key) {
        if (root->left == NULL) {
            return root;
        }
        
        if (key < root->left->key) 
        {
            root->left->left = Splay(root->left->left, key);
            root = RotateRight(root);
        } 
        else if (key > root->left->key) 
        {
            root->left->right = Splay(root->left->right, key);
            if (root->left->right != NULL) 
            {
                root->left = RotateLeft(root->left);
            }
        }
        
        return (root->left == NULL) ? root : RotateRight(root);
    } 
    else 
    {
        if (root->right == NULL) 
        {
            return root;
        }
        
        if (key < root->right->key) 
        {
            root->right->left = Splay(root->right->left, key);
            if (root->right->left != NULL) 
            {
                root->right = RotateRight(root->right);
            }
        } 
        else if (key > root->right->key) 
        {
            root->right->right = Splay(root->right->right, key);
            root = RotateLeft(root);
        }
        
        return (root->right == NULL) ? root : RotateLeft(root);
    }
}

Node* Insert(Node* root, int key) 
{
    if (root == NULL) 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->key = key;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    
    root = Splay(root, key);
    
    if (key == root->key) 
    {
        return root;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    
    if (key < root->key) {
        new_node->left = root->left;
        new_node->right = root;
        root->left = NULL;
    } else {
        new_node->right = root->right;
        new_node->left = root;
        root->right = NULL;
    }
    
    return new_node;
}

Node* Delete(Node* root, int key) 
{
    if (root == NULL) 
    {
        return NULL;
    }
    
    root = Splay(root, key);
    
    if (key != root->key) 
    {
        return root;
    }
    
    Node* new_root = NULL;
    
    if (root->left == NULL) 
    {
        new_root = root->right;
    } 
    else 
    {
        new_root = root->left;
        new_root = Splay(new_root, key);
        new_root->right = root->right;
    }
    
    free(root);
    return new_root;
}

Node* Search(Node* root, int key) 
{
    return Splay(root, key);
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}
/*
int main() {
    Node* root = NULL;
    
    root = Insert(root, 100);
    root = Insert(root, 50);
    root = Insert(root, 200);
    
    printf("Inorder traversal of the Splay tree: ");
    inOrderTraversal(root);
    
    printf("\n");
    
    root = Delete(root, 50);
    
    printf("Inorder traversal after deleting key 50: ");
    inOrderTraversal(root);
    
    return 0;
}
*/