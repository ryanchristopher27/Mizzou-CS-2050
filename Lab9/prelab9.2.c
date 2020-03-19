// Prelab 9 w/o 2 structs C Failed

#include "prelab9.2.h"

List * createList(){
    List * dHead;
    dHead = (List*)malloc(sizeof(List*));
    List * dTail;
    dTail = (List*)malloc(sizeof(List*));

    if (!dHead || !dTail) {
        printf("\nMalloc Failed\n");
        return NULL;
    }

    dHead->next = dTail;
    dTail->next = NULL;
    return dHead;
}

void freeList(List * list)
{
    List* node;
    node = list;
    while (node != NULL) {
        list = node;
        node = node->next;
        free(list);
    }
    list = NULL;
}

int getListLength(List * list)
{
    int count = 0;
    List* node;
    node = list;
    if (node == NULL) {

        return 0;
    }

    node = node->next;
    while (node->next != NULL) {
        count = count+1;
        node = node->next;
    }
    return count;
}

int insertAtHead(int key, List * list)
{
    List* node;
    node = (List*)malloc(sizeof(List*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 1;
    }
    node->key = key;
    node->next = list->next;
    list->next = node;

    return 0;
}

int insertAtTail(int key, List * list)
{
    List* node;
    node = (List*)malloc(sizeof(List*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 1;
    }
    List* temp = list;

    node->key = key;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;

    return 0;
}

List * copyList(List * list)
{
    List* copy = createList();
    List* node = list;
    int test = 0;

    while (node->next->next != NULL) {
        node = node->next;
        test = insertAtTail(node->key, copy);
        if (test == 1) {
            printf("\nTrouble Copying List");
            freeList(copy);
            return NULL;
        }
    }
    return copy;
}

void printList(List* list)
{
    List* node = list;

    node = node->next;
    printf("\nList Values:\n");
    while (node->next != NULL) {
        printf("%.d\t", node->key);
        node = node->next;
    }
}

void emptyList(List* list)
{
    List* node;

    list = list->next;
    while(list->next != NULL) {
        node = list;
        list = list->next;
        //printf("%d\t", node->key);
        free(node);
    }
    printf("done");
}
