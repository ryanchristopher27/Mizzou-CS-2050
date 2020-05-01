//CS 2050 Pre Lab 12 Main File
//Ryan Christopher

#include "prelab12.h"

//Main Function
int main(void)
{
    int comp = 1;
    float hold = 0;
    PQueue test = pqInit();

/////////////////////////
    comp = insertPQ(1, 5, test);
    if (comp == -1) {
        printf("\nInsertion Failed\n");
    }
    //printf("\ntest\n");

//////////////////////////
    comp = insertPQ(0, 3, test);
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
    comp = insertPQ(2, 8, test);
    if (comp == -1) {
        printf("\nInsertion Failed\n");
    }
    //printf("\ntest\n");

    comp = insertPQ(4, 10, test);

    //printf("\nNumber 1: %f", test.info->head->data);
    //printf("\nNumber 2: %f", test.info->head->next->data);
    //printf("\nNumber 3: %f", test.info->head->next->next->data);
    //printf("\nTail: %f", test.info->tail->data);
    //printf("\nTail.Next: %f", test.info->tail->next->data);
    //printf("\nTail.Next: %s", test.info->tail->next);

/////////////////////////
    pqPrint(test);

    hold = returnMin(test);
    printf("\n\nReturned valeu: %.2f\n", hold);

    hold = returnMax(test);
    printf("\n\nReturned value: %.2f\n", hold);

    hold = deleteMin(test);
    printf("\n\nRemoved valeu: %.2f\n", hold);

    hold = deleteMax(test);
    printf("\n\nRemoved value: %.2f\n", hold);

    pqPrint(test);

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

    pqFree(test);

    printf("\nEnd of Program\n");
    return 0;
}
