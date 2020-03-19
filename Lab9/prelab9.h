// Prelab 9 H File

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct nodeStruct{
    int key;
    struct nodeStruct *next;
}Node;

typedef struct linkedList{
    Node *head;
    Node *tail;
}List;

//Prototype Functions
List * createList();
void freeList(List * list);
int getListLength(List * list);
int insertAtHead(int key, List * list);
int insertAtTail(int key, List * list);
List * copyList(List * list);
void printList(List* list);
