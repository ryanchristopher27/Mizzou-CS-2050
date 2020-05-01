//Lab 11 H File
//Ryan Christopher
//CS 2050
//9 April 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Strucutres
typedef struct statestruct{
    float populationInMillion;
    struct statestruct *nextState;
}State;

typedef struct linkedlist{
    State *head, *tail;
    int numOfItems;
    float totalPopulationInMillion;
}StateList;

typedef struct queuelist{
    StateList* list;
}Queue;

//Prototype Functions
Queue initQueue();
int enQueue(float pop, Queue qmain);
State* deQueue(Queue qmain);
int getQsize(Queue qmain);
float getTotal(Queue qmain);
void printQueue(Queue qmain);
void emptyQueue(Queue qmain);
