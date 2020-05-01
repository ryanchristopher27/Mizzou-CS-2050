//CS 2050 Prelab 11 H File
//Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct EmployeeStruct{
    int id;
    struct EmployeeStruct *next;
} Employee;

typedef struct QueuePtr{
    Employee *head, *tail;
    int size;
} QueuePtr;

typedef struct QueueList{
    QueuePtr *qmain;
} Queue;

//Prototype Functions
Queue initQueue();// Return empty queue
int enqueue(Employee* node, Queue main);// Enqueue returns an int error code
Employee * dequeue(Queue main);
int getQsize(Queue main);// Returns # of items in queue
void printList(Queue main);
void freeQueue(Queue main);// Free all malloced space
