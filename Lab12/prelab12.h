//CS 2050 Pre Lab 12 H File
//Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Strucutres
typedef struct nodestruct
{
   float priority;
   float data;
   struct nodestruct *next;
   struct nodestruct *previous;
}node;

typedef struct qstruct
{
   int size;
   node *head;
   node *tail;

}qinfo;

typedef struct q
{
   qinfo *info;
}PQueue;

//Prototype Functions
PQueue pqInit(); // Return empty priority queue
int insertPQ(float data, float priority, PQueue qmain); //priorities are floats
float deleteMin(PQueue qmain);
float deleteMax(PQueue qmain);
float returnMin(PQueue qmain);// returns but does not delete
float returnMax(PQueue qmain);// returns but does not delete
int getsizePQ(PQueue qmain); // returns # of items in queue
void pqFree(PQueue qmain); // Free all malloced space
void pqPrint(PQueue qmain);
