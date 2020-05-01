//CS 2050 Pre Lab 12 C File
//Ryan Christopher

#include "prelab12.h"

//Functions
PQueue pqInit()  // Return empty priority queue
{
    PQueue qmain;
    qmain.info = malloc(sizeof(qinfo));
    if (qmain.info == NULL) {      //Malloc Check
        printf("\nError Allocating Memory\n");
        exit(-1);
    }

    qmain.info->size = 0;
    qmain.info->head = qmain.info->tail = NULL;

    return qmain;
}

int insertPQ(float data, float priority, PQueue qmain) //priorities are floats
{
    node* qnode;
    node* temp = qmain.info->head;
    qnode = (node*)malloc(sizeof(node*));
    if (!qnode) {    //Malloc Check
        printf("\nMemory was not allocated correctly\n");
        return -1;
    }
    qnode->data = data;
    qnode->priority = priority;

    if (temp == NULL) { //Checks if queue is empty
        //printf("test1");
        qnode->next = qnode->previous = NULL;
        qmain.info->head = qnode;
        qmain.info->tail = qnode;
        qmain.info->size++;
        return 1;
    }
    else if (temp->next == NULL) { //Checks if queue has 1 member
        if ((temp->priority > qnode->priority) || (temp->priority == qnode->priority)) { //Node is less than or equal
            //printf("test2");
            temp->previous = qnode;
            qnode->next = temp;
            qnode->previous = NULL;
            qmain.info->tail = temp;
            qmain.info->head = qnode;
            qmain.info->size++;
            return 1;
        }
        else if (temp->priority < qnode->priority) { //Node is greater than
            //printf("test3");
            temp->next = qnode;
            qnode->previous = temp;
            qnode->next = NULL;
            qmain.info->head = temp;
            qmain.info->tail = qnode;
            qmain.info->size++;
            return 1;
        }
    }
    while (temp->next != NULL) { //Iterates through queue

        if (temp->priority > qnode->priority || temp->priority == qnode->priority) { //Node is less than or equal to
            //printf("\ntest4\n");
            qnode->previous = temp->previous;
            temp->previous = qnode;
            qnode->next = temp;
            qmain.info->size++;
            if (qnode->previous == NULL) { //Checks if qnode is head
                qmain.info->head = qnode;
            }
            else {
                qnode->previous->next = qnode;
            }
            qmain.info->tail->next = NULL;
            return 1;
        }
        else { //Node is greater than
            //printf("\ntest5\n");
            temp = temp->next;
        }
    }

    if (temp->priority > qnode->priority || temp->priority == qnode->priority) { //Node is less than or equal to
        //printf("\ntest6\n");
        qnode->previous = temp->previous;
        temp->previous = qnode;
        qnode->previous->next = qnode;
        qnode->next = temp;
        qmain.info->size++;
        return 1;
    }
    else { //Node is greater than
        //printf("\ntest7\n");
        qnode->next = NULL;
        qnode->previous = temp;
        temp->next = qnode;
        qmain.info->tail = qnode;
        qmain.info->size++;
        return 1;
    }
}

float deleteMin(PQueue qmain)
{
    node* temp = qmain.info->head;

    qmain.info->head = qmain.info->head->next;
    qmain.info->head->previous = NULL;
    qmain.info->size--;

    float hold = temp->data;
    free(temp);

    return hold;
}

float deleteMax(PQueue qmain)
{
    node*temp = qmain.info->tail;

    qmain.info->tail = qmain.info->tail->previous;
    qmain.info->tail->next = NULL;

    float hold = temp->data;
    free(temp);
    return hold;
}

float returnMin(PQueue qmain)// returns but does not delete
{
    return qmain.info->head->data;
}

float returnMax(PQueue qmain)// returns but does not delete
{
    return qmain.info->tail->data;
}

int getsizePQ(PQueue qmain) // returns # of items in queue
{
    return qmain.info->size;
}

void pqFree(PQueue qmain)
{
    node* qnode = qmain.info->head;

    while (qnode != NULL) {
        qmain.info->head = qnode;
        qnode = qnode->next;
        free(qmain.info->head);
    }
    free(qmain.info);
}

void pqPrint(PQueue qmain)
{
    node* qnode = qmain.info->head;

    if (qnode == NULL) {     //Checks if queue is empty
        printf("\nList is empty\n");
    }
    else {
        printf("\nList Values:\n");
    }
    while (qnode != NULL) {
        printf("%.2f\t", qnode->data);
        qnode = qnode->next;
    }
}
