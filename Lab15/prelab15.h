// Prelab 15 H File
// Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct nodeStruct {
    int data;
    struct nodeStruct *left;
    struct nodeStruct *right;
} Node;

//Prototype Functions
Node * createNode(int data);
Node * insertBST(Node * mainTree, int data);
Node * searchBST(Node * mainTree, int data);
void printTree(Node * mainTree);
void freeTree(Node * mainTree);
void print2DTree(Node * mainTree, int space);
void print2D(Node * mainTree);
