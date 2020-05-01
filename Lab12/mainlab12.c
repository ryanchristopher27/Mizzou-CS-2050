//Lab 12 Main File
//Ryan Christopher
//CS 2050
//16 April 2020

#include "lab12.h"

//Main Function
int main(void)
{
    int comp = 1;
    PQueue test = initPQueue();

    printPQueue(test);

/////////////////////////
    comp = insertPQ(1, 5, test);
    if (comp == -1) {
        printf("\nInsertion Failed\n");
    }
    //printf("\ntest\n");

//////////////////////////
    comp = insertPQ(0, 7, test);
    if (comp == -1) {
        printf("\nInsertion Failed\n");
    }
    //printf("\ntest\n");
    /*
    if (test.info->tail->next == NULL) {
        printf("tail.next = NULL");
    }
    */

//////////////////////////
    comp = insertPQ(2, 5, test);
    if (comp == -1) {
        printf("\nInsertion Failed\n");
    }
    //printf("\ntest\n");

    comp = insertPQ(3, 5, test);
    comp = insertPQ(7, 5, test);
    comp = insertPQ(4, 5, test);
    comp = insertPQ(3.9, -5, test);
    comp = insertPQ(2.9, -6, test);

    //printf("\nNumber 1: %f", test.info->head->data);
    //printf("\nNumber 2: %f", test.info->head->next->data);
    //printf("\nNumber 3: %f", test.info->head->next->next->data);
    //printf("\nTail: %f", test.info->tail->data);
    //printf("\nTail.Next: %f", test.info->tail->next->data);
    //printf("\nTail.Next: %s", test.info->tail->next);

/////////////////////////
    printPQueue(test);

    printf("\nNumber of Items: %d\n", test.list->numOfItems);

    State* hold1;
    State* hold2;
    State* hold3;
    State* hold4;

    hold1 = returnMin(test);
    printf("\n\nReturned valeu: %.2f\n", hold1->populationInMillion);

    hold2 = returnMax(test);
    printf("\n\nReturned value: %.2f\n", hold2->populationInMillion);

    hold3 = deleteMin(test);
    printf("\n\nRemoved value: %.2f\n", hold3->populationInMillion);
    free(hold3);

    hold4 = deleteMax(test);
    printf("\n\nRemoved value: %.2f\n", hold4->populationInMillion);
    free(hold4);

    printPQueue(test);

    printf("\nNumber of Items: %d\n", test.list->numOfItems);


    /*
    if (test.info->head->previous == NULL) {
        printf("\nHead Previous: NULL");
    }
    printf("\nHead: %f", test.info->head->data);
    printf("\nNumber 1: %f", test.info->head->data);
    printf("\nNumber 2: %f", test.info->head->next->data);
    printf("\nNumber 3: %f", test.info->head->next->next->data);
    printf("\nTail: %f", test.info->tail->data);
    if (test.info->tail->next == NULL) {
        printf("\nTail Next: NULL");
    }
    */

    freePQueue(test);

    printf("\nEnd of Program\n");
    return 0;
}
