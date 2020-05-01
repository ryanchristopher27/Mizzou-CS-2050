//Lab 12 H File
//Ryan Christopher
//CS 2050
//16 April 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct statestruct{
    float populationInMillion;
    float priority;
    struct statestruct *previousState, *nextState;
}State;

typedef struct linkedlist{
    State *head, *tail;
    int numOfItems;
}StateList;

typedef struct queuelist{
    StateList* list;
}PQueue;

//Prototype Functions
PQueue initPQueue();
State* createNode(float priority, float data);
int insertPQ(float priority, float data, PQueue qmain);
State* deleteMin(PQueue qmain);
State* deleteMax(PQueue qmain);
State* returnMin(PQueue qmain); // returns but does not delete
State* returnMax(PQueue qmain); // returns but does not delete
void freePQueue(PQueue qmain); // Free all malloced space
void printPQueue(PQueue qmain);
