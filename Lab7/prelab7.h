#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct nodestruct{
    int data;
    struct nodestruct *next;
} Node;

//Prototype Functions
Node * initIntegerList();
Node * initList();
int insertAtHead(int data, Node *list);
int insertAtTail(int data, Node *list);
Node * insertHead(int data, Node *list);
Node * insertTail(int data, Node *list);
void printList(Node *list);
void printListDummy(Node *list);
void freeList(Node *list);
