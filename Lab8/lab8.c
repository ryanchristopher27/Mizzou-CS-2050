//Lab 8
//Ryan Christopher
//Pawprint: rdcb2f
//12 March 2020

#include "lab8.h"

//Creates a singular node with the float value  passed to it
//It is passed a population float
//It returns the pointer to the node
//If malloc fails, it returns NULL
State* createNode(float pop)
{
    State* node;
    node = malloc(sizeof(State));
    if (!node) {
        printf("\nMalloc Failed\n");
        return NULL;
    }
    node->populationInMillion = pop;
    node->nextState = NULL;

    return node;
}

//Creates an empty list initialized to NULL
//No parameters
//It returns NULL
State* initList()
{
    return NULL;
}

//Creates a node that is added to the head of the linked list
//It is passed a pointer to the beginning of the list and a population float
//It returns the pointer to the node
//If malloc fails, it returns NULL
State* addToHead(State* list, float pop)
{
    State* node;
    node = (State*)malloc(sizeof(State));
    if (!node) {
        printf("\nMalloc Failed\n");
        return NULL;
    }
    node->populationInMillion = pop;
    node->nextState = list;

    return node;
}

//Creates a node that is added to the tail(end) of the linked list
//It is passed a pointer to the beginning of the list and a population float
//It returns the pointer to the node
//If malloc fails, it returns NULL
State* addToTail(State* list, float pop)
{
    State* node;
    State* p = list;
    node = (State*)malloc(sizeof(State));
    if (!node) {
        printf("\nMalloc Failed\n");
        return NULL;
    }
    node->populationInMillion = pop;
    node->nextState = NULL;

    if (list == NULL) {
        return node;
    }

    while (p->nextState != NULL) {
        p = p->nextState;
    }
    p->nextState = node;

    return list;
}

//Prints the values in the list of nodes by iterating through the list
//It is passed a pointer to the beginning of the list
//It returns nothing
void printList(State* list)
{
    State* node = list;

    printf("\nList Values (Populations):\n");
    while (node != NULL) {
        printf("%.2f\t", node->populationInMillion);
        node = node->nextState;
    }
}

//Iterates through the list until the node that correlates with the index is found
//Then returns the float value from the chosen node
//It is passed a pointer to the beginning of the list and an index integer
//If no node correlates with the index, it returns -1.0
float searchPopulationByIdx(State* list, int index)
{
    State* node = list;

    if (index < 0) {
        return -1.0;
    }

    for (int i=0;i<index;i++) {
        node = node->nextState;
        if (node == NULL) {
            return -1.0;
        }
    }

    return node->populationInMillion;
}

//Frees all the memory allocated to the list by iterating and freeing each node
//Then sets the freed list equal to NULL
//It returns the pointer to the list
//It is passed a pointer to the beginning of the list
State* freeList(State* list)
{
    State* node;
    node = list;

    while (node != NULL) {
        list = node;
        node = node->nextState;
        free(list);
    }
    list = NULL;

    return list;
}
