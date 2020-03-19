#include "lab7.h"

Node * initIntegerList()
{
    Node *dnode;
    dnode = malloc(sizeof(Node));
    if (!dnode) {
        printf("\nOriginal Malloc Failed.\n");
        exit(-1);
    }
    dnode->data = '\0';
    dnode->next = NULL;

    return(dnode);
}

Node * initList()
{
    return NULL;
}

int insertAtHead(int data, Node *list)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if (!p) {
        return 1;
    }
    p->data = data;
    p->next = list->next;
    list->next = p;

    return 0;
}

Node * insertHead(int data, Node *list)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("\nMalloc was not allocated correctly.\n");
        return NULL;
    }
    p->data = data;
    p->next = list;

    return p;
}

int insertAtTail(int data, Node *list)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if (!p) {
        return 1;
    }
    p->data = data;
    p->next = NULL;

    Node *temp = list;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;

    list = temp;

    return 0;
}

Node * insertTail(int data, Node *list)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("\nMalloc was not allocated correctly.\n");
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    if (list == NULL) {
        return p;
    }

    Node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;

    return list;
}

void printList(Node *list)
{
    Node *p = list;

    while (p != NULL) {
        printf("\t%d->", p->data);
        p = p->next;
    }
}

void printListDummy(Node *list)
{
    Node *p = list;

    p = p->next;
    while (p != NULL) {
        printf("\t%d->", p->data);
        p = p->next;
    }
}

void freeList(Node *list)
{
    Node *p;
    p = list;

    while (p != NULL) {
        list = p;
        p = p->next;
        free(list);
    }
    list = NULL;
}
