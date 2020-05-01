// Lab 14 H File
// Ryan Christopher
// CS 2050
//30 April 2020

#include <stdio.h>
#include <stdlib.h>

typedef struct statestruct{
    float populationInMillion;
    float area;
}State;

typedef struct statesdatabase{
    int sizeOfDB;
    State** array;
}StateDB;

State** readRecord(FILE* fp);
StateDB createDatabase(State** array, int size);
State* findStateByArea(StateDB database, float target);
void freeDatabase(StateDB database);
