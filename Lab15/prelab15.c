// Prelab 15 C File
// Ryan Christopher

#include "prelab15.h"

Node * createNode(int data)
{
    Node* node;
    node = malloc(sizeof(Node*));
    if (node == NULL) {
        printf("\nError Allocating Memory\n");
        return NULL;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node * insertBST(Node *mainTree, int data)
{
    if (mainTree != NULL) {
        if (mainTree->data > data) {
            //mainTree = mainTree->left;
            mainTree->left = insertBST(mainTree->left, data);
        }
        else if (mainTree->data < data) {
            //mainTree = mainTree->right;
            mainTree->right = insertBST(mainTree->right, data);
        }
        return mainTree;
        //return insertBST(mainTree, data);
    }
    else {
        return createNode(data);
    }
}

Node * searchBST(Node *mainTree, int data)
{
    if (mainTree == NULL) {
        printf("\nDesired value is not in list\n");
        return NULL;
    }
    else if (mainTree->data > data) {
        return searchBST(mainTree->left, data);
    }
    else if (mainTree->data < data) {
        return searchBST(mainTree->right, data);
    }
    else {
        return mainTree;
    }
}

void printTree(Node *mainTree)
{
    if (mainTree == NULL) {
        return;
        //printf("\nList is empty\n");
    }
    else {
        printTree(mainTree->left);
        printf("%d-->", mainTree->data);
        printTree(mainTree->right);
    }
}

void freeTree(Node *mainTree)
{
    if (mainTree == NULL) {
        //printf("\nList is empty\n");
        return;
    }
    else {
        freeTree(mainTree->left);
        freeTree(mainTree->right);
        free(mainTree);
    }
}

void print2DTree(Node * mainTree, int space)
{
    if (mainTree == NULL) {
        return;
    }
    space += 10;
    print2DTree(mainTree->right, space);

    printf("\n");
    for (int i=10;i<space;i++) {
        printf(" ");
    }
    printf("%d\n", mainTree->data);

    print2DTree(mainTree->left, space);
}

void print2D(Node * mainTree)
{
    print2DTree(mainTree, 0);
}
