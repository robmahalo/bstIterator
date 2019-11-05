/*
author: Robby M.
version: 3.0
Date: 10/29/19
\*

#include <iostream>

/* Node Structure */
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

/* NodeCreator */
BstNode *createNode(int data)
{
    BstNode *newNode = new BstNode();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* NodeInserter in BST */
BstNode *insertNode(BstNode *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

/* NodeSearcher in BST */
bool searchNode(BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (data == root->data)
        return true;
    else if (data <= root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

/* MinimalFinder in BST */
BstNode *findMinNode(BstNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

BstNode* findMaxNode(BstNode *node) {
while (node->right != NULL) {
node = node-> right;
}

return node;
}

int findHeight(BstNode* node) {
    if (node == NULL) {
    return -1;
    }

    int lefth = findHeight(node->left);
    int righth = findHeight(node->right);

    if (lefth > righth) {
     return lefth  + 1;
     } else {
     return righth + 1;
     }
}

/* NodeEraser in BST */
BstNode *deleteNode(BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            BstNode *min = findMinNode(root->right);
            root->data = min->data;
            root->right = deleteNode(root->right, min->data);
        }
    }
    return root;
}

int main()
{
    BstNode *root = NULL;

    /* Insert Node with Value */
    root = insertNode(root, 23);
    root = insertNode(root, 28);
    root = insertNode(root, 98);
    root = insertNode(root, 5);
    root = insertNode(root, 9);
    root = insertNode(root, 0);

    /* Search Node by Value */
    std::cout << searchNode(root, 3) << std::endl;
    std::cout << searchNode(root, 2) << std::endl;
    std::cout << searchNode(root, 1) << std::endl;

    /* Delete Node by Value */
    root = deleteNode(root, 5);
    root = deleteNode(root, 14);

    /* Search Node by Value */
    std::cout << searchNode(root, 43) << std::endl;
    std::cout << searchNode(root, 35) << std::endl;
    return 0;
}