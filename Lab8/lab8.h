//Lab 8 H File
//Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Strctures
typedef struct statestruct{
    float populationInMillion;
    struct statestruct *nextState;
}State;

//Prototype Functions
State* createNode(float pop);
State* initList();
State* addToHead(State* list, float pop);
State* addToTail(State* list, float pop);
void printList(State* list);
float searchPopulationByIdx(State* list, int index);
State* freeList(State* list);
