//CS 2050 Prelab 11 C File
//Ryan Christopher

#include "prelab11.h"

Queue initQueue()
{
    Queue list;
    list.qmain = malloc(sizeof(QueuePtr));
    if (list.qmain == NULL) {
        printf("\nError Allocating Memory\n");
        exit(-1);
    }

    list.qmain->size = 0;
    list.qmain->head = list.qmain->tail = NULL;

    return list;
}

int enqueue(Employee* node, Queue main)
{
    node = malloc(sizeof(Employee*));
    if (node == NULL) {
        printf("\nError Allocating Memory\n");
        return -1;
    }

    static int i = 0;
    node->id = i;
    i++;
    node->next = NULL;

    if (main.qmain->head == NULL) {
        main.qmain->head = node;
        main.qmain->tail = node;
        //main.qmain->head->next = NULL;
        main.qmain->size++;
        return 1;
    }
    main.qmain->tail->next = node;
    main.qmain->tail = node;
    main.qmain->size++;
    return 1;
}

Employee * dequeue(Queue main)
{
    Employee* node = main.qmain->head;

    if (main.qmain->head == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }

    main.qmain->head = main.qmain->head->next;
    main.qmain->size--;
    printf("\n%d was deQueued\n", node->id);
    return node;
}

int getQsize(Queue main)
{
    return main.qmain->size;
}

void printList(Queue main)
{
    Employee* node = main.qmain->head;

    if (node == NULL) {
        printf("\nList is empty\n");
    }
    else {
        printf("\nList Values:\n");
    }
    while (node != NULL) {
        printf("%.2d\n", node->id);
        node = node->next;
    }
}

void freeQueue(Queue main)
{
    Employee* node = main.qmain->head;

    while (node != NULL) {
        main.qmain->head = node;
        node = node->next;
        free(main.qmain->head);
    }
}
