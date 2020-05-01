//CS 2050 Lab10 C File
//Ryan Christopher
//Section F
//4-2-2020

#include "lab10.h"

//Creates a stack list with the head node and tail node initiated to NULL
//It returns the NULL terminated list
//If malloc fails, it prints and error statement and returns NULL
StateList* initStack()
{
    StateList* list;
    list = (StateList*)malloc(sizeof(StateList*));
    if (!list) {
        printf("\nCould not create list\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

//Adds a new node to the tail of the stack with the desired population value
//It is passed the stack list and the desired population value
//It returns -1 if the function fails and 1 if it succeeds
//IF malloc fails, it also prints a error message before returning -1
int pushStack(StateList* list, float pop)
{
    State* node;
    node = (State*)malloc(sizeof(State*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return -1;
    }

    node->populationInMillion = pop;

    if (list->head == NULL) { //Checks if stack is empty
        list->head = node;
        list->tail = node;
        return 1;
    }

    node->nextState = NULL;
    list->tail->nextState = node;
    list->tail = node;
    return 1;
}

//Removes the most recently added node from the stack and returns it
//It is passed the stack list
//It returns the pointer to the removed node
//If malloc fails, it prints and error statement and returns NULL
State* popStack(StateList* list)
{
    State* node = list->head;
    State* hold;

    if (node == NULL) { //Checks if stack is empty
        printf("\nList is empty\n");
        return NULL;
    }

    while (node->nextState->nextState != NULL) { //Iterates through stack
        node = node->nextState;
    }
    hold = node->nextState;
    node->nextState = node->nextState->nextState;
    list->tail = node;
    return hold;
}

//Creates a queue list with the head node and tail node initiated to NULL
//It returns the NULL terminated list
//If malloc fails, it prints and error statement and exits the program
StateList* initQueue()
{
    StateList* list;
    list = (StateList*)malloc(sizeof(StateList*));
    if (!list) {
        printf("\nCould not create list\n");
        exit(-1);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

//Adds a new node to the tail of the stack with the desired population value
//It is passed the Queue list and the desired population value
//It returns -1 if the function fails and 1 if it succeeds
//IF malloc fails, it also prints a error message before returning -1
int enQueue(StateList* list, float pop)
{
    State* node;
    node = (State*)malloc(sizeof(State*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return -1;
    }

    node->populationInMillion = pop;

    if (list->head == NULL) { //Checks if queue is empty
        list->head = node;
        list->tail = node;
        return 1;
    }

    node->nextState = NULL;
    list->tail->nextState = node;
    list->tail = node;
    return 1;
}

//Removes the node at the head of the queue and returns it
//It is passed the queue list
//It returns the pointer to the removed node
//If malloc fails, it prints and error statement and returns NULL
State* deQueue(StateList* list)
{
    State* node = list->head;

    if (node == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }

    list->head = list->head->nextState;
    return node;
}

//Prints the values in the linked list
//It is passed the linked list
void printList(StateList* list)
{
    State* node = list->head;

    if (node == NULL) {
        printf("\nList is empty\n");
    }
    else {
        printf("\nList Values:\n");
    }
    while (node != NULL) {
        printf("%.2f\n", node->populationInMillion);
        node = node->nextState;
    }
}

//Frees all the memory that is used in the list
//It is passed the linked list
void freeList(StateList* list)
{
    State* node = list->head;

    while (node != NULL) {
        list->head = node;
        node = node->nextState;
        free(list->head);
    }
}
