// Lab 13 H File
// Ryan Christopher
// CS 2050
// 23 April 2020

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct statestruct{
    float populationInMillion;
    float area;
}State;

//Prototype functions
State** readRecord(FILE* fp);
int comparison(void* a, void* b);
int binarySearch(void** array, int low, int high, void* target);
void freeArr(State** array, int size);
