// Lab 15 H File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structures
typedef struct nodeStruct {
    int data;
    struct nodeStruct *left;
    struct nodeStruct *right;
} Node;

typedef struct statestruct{
    float populationInMillion;
    //float priority;
    //struct statestruct *previousState, *nextState;
}State;

//Prototype Functions
Node * createNode(int data);
Node * insertBST(Node * mainTree, State * list);
Node * searchBST(Node * mainTree, int data);
void printTree(Node * mainTree);
void freeTree(Node * mainTree);
//void print2DTree(Node * mainTree, int space);
//void print2D(Node * mainTree);
