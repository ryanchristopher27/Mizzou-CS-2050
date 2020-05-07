// Lab 15 H File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include <stdio.h>
#include <stdlib.h>

//Structures
typedef struct {
    int ID;
    float salary;
    int ssn;
} Employee;

typedef struct node {
    Employee *data;
    struct node *left, *right;
} Node;

//Prototype Functions
Employee ** readRecord(FILE * file);
int comparison(void * mainTree, void * node);
Node * insertBST(Node * mainTree, Employee * newNode);
Employee * searchBST(Node * mainTree, float target);
void deleteTree(Node * mainTree);
