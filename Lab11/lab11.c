//Lab 11 C File
//Ryan Christopher
//CS 2050
//9 April 2020

#include "lab11.h"

//Creates a queue list with the head node and tail node initiated to NULL
//It returns the NULL terminated list
//If malloc fails, it prints and error statement and exits the program
Queue initQueue()
{
    Queue qmain;
    qmain.list = malloc(sizeof(StateList));
    if (qmain.list == NULL) {      //Malloc Check
        printf("\nError Allocating Memory\n");
        exit(-1);
    }

    qmain.list->numOfItems = 0;
    qmain.list->totalPopulationInMillion = 0;
    qmain.list->head = qmain.list->tail = NULL;

    return qmain;
}

//Adds a new node to the tail of the stack with the desired population value and updates the size and total pop of queue
//It is passed the Queue list and the desired population value
//It returns -1 if the function fails and 1 if it succeeds
//IF malloc fails, it also prints a error message before returning -1
int enQueue(float pop, Queue qmain)
{
    State* node;
    node = (State*)malloc(sizeof(State*));
    if (!node) {    //Malloc Check
        printf("\nMemory was not allocated correctly\n");
        return -1;
    }

    node->populationInMillion = pop;

    if (qmain.list->head == NULL) { //Checks if queue is empty
        node->nextState = NULL;
        qmain.list->head = node;
        qmain.list->tail = node;
        qmain.list->numOfItems++;
        qmain.list->totalPopulationInMillion += pop;
        return 1;
    }

    node->nextState = NULL;
    qmain.list->tail->nextState = node;
    qmain.list->tail = node;
    qmain.list->numOfItems++;
    qmain.list->totalPopulationInMillion += pop;
    return 1;
}

//Removes the node at the head of the queue and returns it
//Then updates the size of queue and total population
//It is passed the queue list
//It returns the pointer to the removed node
//If malloc fails, it prints and error statement and returns NULL
State* deQueue(Queue qmain)
{
    State* node = qmain.list->head;

    if (node == NULL) {     //Checks if queue is empty
        printf("\nList is empty\n");
        return NULL;
    }

    qmain.list->head = qmain.list->head->nextState;
    qmain.list->numOfItems--;
    qmain.list->totalPopulationInMillion -= node->populationInMillion;
    return node;
}

//Returns the size of the queue
//It is passed the queue list
int getQsize(Queue qmain)
{
    return qmain.list->numOfItems;
}

//Returns the total population of the queue
//It is passed the queue list
float getTotal(Queue qmain)
{
    return qmain.list->totalPopulationInMillion;
}

//Prints all the population values of the queue
//It is passed the queue list
//If the list is empty, it prints a statement saying so
void printQueue(Queue qmain)
{
    State* node = qmain.list->head;

    if (node == NULL) {     //Checks if queue is empty
        printf("\nList is empty\n");
    }
    else {
        printf("\nList Values:\n");
    }
    while (node != NULL) {
        printf("%.2f\t", node->populationInMillion);
        node = node->nextState;
    }
}

//Frees all the memory that is used in the queue including the main list
//It is passed the queue list
void emptyQueue(Queue qmain)
{
    State* node = qmain.list->head;

    while (node != NULL) {
        qmain.list->head = node;
        node = node->nextState;
        free(qmain.list->head);
    }
    free(qmain.list);
}
