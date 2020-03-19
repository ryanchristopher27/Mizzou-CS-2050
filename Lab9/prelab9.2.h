// Prelab 9 w/o 2 structs H Failed

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct nodeStruct{
    int key;
    struct nodeStruct *next;
}List;

//Prototype Functions
List * createList();
void freeList(List * list);
int getListLength(List * list);
int insertAtHead(int key, List * list);
int insertAtTail(int key, List * list);
List * copyList(List * list);
void printList(List* list);
void emptyList(List* list);
