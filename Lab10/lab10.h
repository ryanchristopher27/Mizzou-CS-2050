//CS 2050 Lab10 H File
//Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct statestruct{
    float populationInMillion;
    struct statestruct *nextState;
}State;

typedef struct linkedlist{
    State *head, *tail;
}StateList;

//Prototype Functions
StateList* initStack();
int pushStack(StateList* list, float pop);
State* popStack(StateList* list);
StateList* initQueue();
int enQueue(StateList* list, float pop);
State* deQueue(StateList* list);
void printList(StateList* list);
void freeList(StateList* list);
