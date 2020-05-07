// Lab 15 C File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include "lab15.h"

// Comparison Function
int comparison(Node * mainTree, int data)
{
    if (mainTree->data > data) {
        return 1;
    } else if (mainTree->data < data) {
        return -1;
    } else {
        return 0;
    }
}

// Prototype Functions
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

Node * insertBST(Node * mainTree, State * list)
{
    if (mainTree != NULL) {
        if (comparison(mainTree, list->populationInMillion) > 0) {
            //mainTree = mainTree->left;
            mainTree->left = insertBST(mainTree->left, list);
        }
        else if (comparison(mainTree, list->populationInMillion) < 0) {
            //mainTree = mainTree->right;
            mainTree->right = insertBST(mainTree->right, list);
        }
        return mainTree;
        //return insertBST(mainTree, data);
    }
    else {
        return createNode(data);
    }
}

Node * searchBST(Node * mainTree, State * list)
{
    if (mainTree == NULL) {
        printf("\nDesired value is not in list\n");
        return NULL;
    }
    else if (comparison(mainTree, list->populationInMillion) > 0) {
        return searchBST(mainTree->left, list);
    }
    else if (comparison(mainTree, list->populationInMillion) < 0) {
        return searchBST(mainTree->right, list);
    }
    else {
        return mainTree;
    }
}

void printTree(Node * mainTree)
{
    if (mainTree == NULL) {
        return;
    }

    printTree(mainTree->right);

    printf("\n");
    /*
    for (int i=10;i<10;i++) {
        printf(" ");
    }
    */
    printf("%d\n", mainTree->data);

    printTree(mainTree->left, space);
}

void freeTree(Node * mainTree)
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
