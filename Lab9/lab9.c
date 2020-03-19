// Lab 9 C File

#include "lab9.h"

//Creates a list with the head node and tail node initiated to NULL
//It returns the list of the 2 dummy nodes
//If malloc failes, it prints an error statement and returns NULL
State* initListWithDummyNode()
{
    State * dHead;
    dHead = (State*)malloc(sizeof(State*));
    State * dTail;
    dTail = (State*)malloc(sizeof(State*));

    if (!dHead || !dTail) {
        printf("\nMalloc Failed\n");
        return NULL;
    }

    dHead->nextState = dTail;
    dTail->nextState = NULL;
    return dHead;
}

//Inserts a new node at the head of the list right behind the head dummy node
//It is passed the desired key and the linked List
//It returns 0 if the function failed and 1 if it worked
//It also prints an error statement if malloc fails before it returns 0
int insertToHead(State* list, float pop)
{
    State * node;
    node = (State*)malloc(sizeof(State*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 0;
    }
    node->populationInMillion = pop;
    node->nextState = list->nextState;
    list->nextState = node;

    return 1;
}

//Inserts a new node at the end of the list right before the tail dummy node
//It is passed the desired key and the linked List
//It returns 0 if the function failed and 1 if it worked
//It also prints an error statement if malloc fails before it returns 0
int insertToTail(State* list, float pop)
{
    State * node;
    node = (State*)malloc(sizeof(State*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 0;
    }
    node->populationInMillion = pop;

    State * temp = list;
    while (temp->nextState->nextState != NULL) {
        temp = temp->nextState;
    }
    node->nextState = temp->nextState;
    temp->nextState = node;

    return 1;
}

//Prints the values in the linked list
//It is passed the linked list
//If the list has been emptied and only contains the dummy nodes, it prints a statement saying so
void printList(State* list)
{
     State * node = list;

    node = node->nextState;
    if (node->nextState == NULL) {
        printf("\nNo Values Inside the List\n");
    }
    else {
        printf("\nList Values (Population):\n");
    }
    while (node->nextState != NULL) {
        printf("%.2f\t", node->populationInMillion);
        node = node->nextState;
    }
}

//Emptys the nodes that have been added to the list leaving only the dummy nodes
//It is passed the linked list
//If the list is already empty, it prints a statement saying so
void emptyList(State* list)
{
    State* node;
    State* temp = list;

    temp = temp->nextState;
    if (temp->nextState == NULL) {
        printf("\nList is already empty\n");
    }
    else {
        while (temp->nextState != NULL) {
            node = temp;
            temp = temp->nextState;
            free(node);
        }
        list->nextState = temp;
        printf("\nList has been emptied\n");
    }
}

//Frees all the memory that is used in the list
//It is passed the linked list
void freeList(State* list)
{
    State * node = list;

    while (node!= NULL) {
        list = node;
        node = node->nextState;
        free(list);
    }
    printf("\nList has been freed\n");
}
