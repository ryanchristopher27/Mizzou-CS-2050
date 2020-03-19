// Prelab 9 C File

#include "prelab9.h"

//Creates a list with the head node and tail node initiated to NULL
//It returns the NULL terminated List
//If malloc fails, it prints an error statement and exits the program
List * createList()
{
    List* list;
    list = (List*)malloc(sizeof(List*));
    if (!list) {
        printf("\nCould not create list\n");
        exit(-1);
    }
    list->head = NULL;
    list->tail = NULL;

    return list;
}

//Frees all the memory that is used in the List
//It is passed the linked List
void freeList(List * list)
{
    Node* node;
    node = list->head;

    while (node != NULL) {
        list->head = node;
        node = node->next;
        free(list->head);
    }
    list->head = NULL;
}

//Gets the length of the list as an integer
//It is passed the linked List
//It returns the integer with the length
int getListLength(List * list)
{
    int count = 0;
    Node* node;
    node = list->head;

    while (node != NULL) {
        count = count+1;
        node = node->next;
    }
    return count;
}

//Inserts a new node at the head of the List
//It is passed the desired key and the linked List
//It returns 1 if the function failed and 0 is it worked
//Also prints an error statement if malloc fails
int insertAtHead(int key, List * list)
{
    Node* node;
    node = (Node*)malloc(sizeof(Node*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 1;
    }
    node->key = key;
    node->next = list->head;
    list->head = node;

    return 0;
}

//Inserts a new node at the tail of the List
//It is passed the desired key and the linked List
//It returns 1 if the function failed and 0 is it worked
//Also prints an error statement if malloc fails
int insertAtTail(int key, List * list)
{
    Node* node;
    Node* temp = list->head;
    node = (Node*)malloc(sizeof(Node*));
    if (!node) {
        printf("\nMemory was not allocated correctly\n");
        return 1;
    }

    node->key = key;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return 0;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    list->tail = node;
    return 0;
}

//Makes an exact copy of the list but at a new memory location
//It is passed the linked List
//It returns the new copy of the linked List
//If it fails it prints an error statement and exits the program
List * copyList(List * list)
{
    List* copy = createList();
    Node* node = list->head;
    int test = 0;

    while (node != NULL) {
        test = insertAtTail(node->key, copy);
        node = node->next;
        if (test == 1) {
            printf("\nTrouble Copying List\n");
            exit(-1);
        }
    }
    return copy;
}

//Prints the values in the linked List
//It is passed the linked List
void printList(List* list)
{
    Node* node = list->head;

    printf("\nList Values:\n");
    while (node != NULL) {
        printf("%d\t", node->key);
        node = node->next;
    }
}
