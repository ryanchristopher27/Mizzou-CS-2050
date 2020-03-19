// Lab 9 H File

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct
typedef struct statestruct{
    float populationInMillion;
    struct statestruct *nextState;
}State;

// Prototype Functions
State* initListWithDummyNode();
int insertToHead(State* list, float pop);
int insertToTail(State* list, float pop);
void printList(State* list);
void emptyList(State* list);
void freeList(State* list);
