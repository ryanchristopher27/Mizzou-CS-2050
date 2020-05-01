//Lab 12 C File
//Ryan Christopher
//CS 2050
//16 April 2020

#include "lab12.h"

//Creates a queue list with the head node and tail node initiated to NULL
//It also sets the size of the queue to 0
//It returns the NULL terminated list
//If malloc fails, it prints and error statement and exits the program
PQueue initPQueue()
{
    PQueue qmain;
    qmain.list = malloc(sizeof(StateList));
    if (qmain.list == NULL) {      //Malloc Check
        printf("\nError Allocating Memory\n");
        exit(-1);
    }

    qmain.list->numOfItems = 0;
    qmain.list->head = qmain.list->tail = NULL;

    return qmain;
}

//Creates a node with the data and priority set to the desired values
//Sets nextState and previousState equal to NULL
//It is passed the desired data and priority values
//It returns the created node
//If malloc fails, it prints an error statment and returns NULL
State* createNode(float priority, float data)
{
    State* node;
    node = malloc(sizeof(State*));
    if (node == NULL) {
        printf("\nError Allocating Memory\n");
        return NULL;
    }

    node->populationInMillion = data;
    node->priority = priority;
    node->nextState = NULL;
    node->previousState = NULL;

    return node;
}

//Creates a new node with the desired data and priority values
//Inserts that new node into the priority queue in the correct position
//Updates head, tail, and numOfItems
//It is passed the desired data and priority values plus the priority queue
//Returns 1 if the node is inserted correectly and -1 if it isn't
int insertPQ(float priority, float data, PQueue qmain)
{

    State* qnode = createNode(priority, data);
    State* temp = qmain.list->head;

    if (temp == NULL) { //Checks if queue is empty
        qnode->nextState = qnode->previousState = NULL;
        qmain.list->head = qnode;
        qmain.list->tail = qnode;
        qmain.list->numOfItems++;
        return 1;
    }
    else if (temp->nextState == NULL) { //Checks if queue has 1 member
        if ((temp->priority < qnode->priority) || (temp->priority == qnode->priority)) { //Node is less than or equal
            temp->previousState = qnode;
            qnode->nextState = temp;
            qnode->previousState = NULL;
            qmain.list->tail = temp;
            qmain.list->head = qnode;
            qmain.list->numOfItems++;
            return 1;
        }
        else if (temp->priority > qnode->priority) { //Node is greater than
            temp->nextState = qnode;
            qnode->previousState = temp;
            qnode->nextState = NULL;
            qmain.list->head = temp;
            qmain.list->tail = qnode;
            qmain.list->numOfItems++;
            return 1;
        }
    }
    while (temp->nextState != NULL) { //Iterates through queue

        if (temp->priority < qnode->priority || temp->priority == qnode->priority) { //Node is less than or equal to
            qnode->previousState = temp->previousState;
            temp->previousState = qnode;
            qnode->nextState = temp;
            qmain.list->numOfItems++;
            if (qnode->previousState == NULL) { //Checks if qnode is head
                qmain.list->head = qnode;
            }
            else {
                qnode->previousState->nextState = qnode;
            }
            qmain.list->tail->nextState = NULL;
            return 1;
        }
        else { //Node is greater than
            temp = temp->nextState;
        }
    }

    if (temp->priority < qnode->priority || temp->priority == qnode->priority) { //Node is less than or equal to
        qnode->previousState = temp->previousState;
        temp->previousState = qnode;
        qnode->previousState->nextState = qnode;
        qnode->nextState = temp;
        qmain.list->numOfItems++;
        return 1;
    }
    else { //Node is greater than
        qnode->nextState = NULL;
        qnode->previousState = temp;
        temp->nextState = qnode;
        qmain.list->tail = qnode;
        qmain.list->numOfItems++;
        return 1;
    }
}

//Deletes the value from the queue with the lowest priority
//It then updates the tail and size of the priority queue
//It is passed the priority queue
//If the priority queue is empty, it returns NULL
//Else it returns the pointer to the deleted node
State* deleteMin(PQueue qmain)
{
    if (qmain.list->tail == NULL) {
        return NULL;
    }
    else {
        State* temp = qmain.list->tail;
        if (qmain.list->tail->previousState == NULL) {
            qmain.list->tail = qmain.list->head = NULL;
            qmain.list->numOfItems--;
            return temp;
        }
        qmain.list->tail = qmain.list->tail->previousState;
        qmain.list->tail->nextState = NULL;
        qmain.list->numOfItems--;
        return temp;
    }
}

//Deletes the value from the queue with the highest priority
//It then updateds the head and size of the priority queue
//It is passed the priority queue
//If the priority queue is empty, it returns NULL
//Else it returns the pointer to the deleted node
State* deleteMax(PQueue qmain)
{
    if (qmain.list->head == NULL) {
        return NULL;
    }
    else {
        State* temp = qmain.list->head;
        if (qmain.list->head->nextState == NULL) {
            qmain.list->head = qmain.list->tail = NULL;
            qmain.list->numOfItems--;
            return temp;
        }
        qmain.list->head = qmain.list->head->nextState;
        qmain.list->head->previousState = NULL;
        qmain.list->numOfItems--;
        return temp;
    }
}

//Returns the value from the queue with the lowest priority
//It is passed the priority queue
//If the priority queue is empty, it returns NULL
State* returnMin(PQueue qmain) // returns but does not delete
{
    if (qmain.list->tail == NULL) {
        return NULL;
    }
    else {
        return qmain.list->tail;
    }
}

//Returns the value from the queue with the hightest priority
//It is passed the priority queue
//If the priority queue is empty, it returns NULL
State* returnMax(PQueue qmain) // returns but does not delete
{
    if (qmain.list->head == NULL) {
        return NULL;
    }
    else {
        return qmain.list->head;
    }
}

//Frees all the memory that was allocated for the priority queue includeing the qmain.list
//It is passed the priority queue
void freePQueue(PQueue qmain) // Free all malloced space
{
    State* qnode = qmain.list->head;

    while (qnode != NULL) {
        qmain.list->head = qnode;
        qnode = qnode->nextState;
        free(qmain.list->head);
    }
    free(qmain.list);
}

//Prints out all the values in the queue with their respective priorities
//It is passed the priority queue
//If the list is empty, it returns a message saying so
void printPQueue(PQueue qmain)
{
    State* qnode = qmain.list->head;

    if (qnode == NULL) {     //Checks if queue is empty
        printf("\nList is empty\n");
    }
    else {
        printf("\nList Values:\n");
        while (qnode != NULL) {
            printf("%.2f (%.2f) --> ", qnode->priority, qnode->populationInMillion);
            qnode = qnode->nextState;
        }
        printf("End\n");
    }
}
