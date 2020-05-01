//CS 2050 Lab10 Main File
//Ryan Christopher

#include "lab10.h"

int main(void)
{
    StateList *list = initStack();

    printList(list);

    int test = 0;
    for (float i = 1.5;i<12;i++) {
        test = pushStack(list, i);
        if (test == -1) {
            printf("\nTrouble pushing stack\n");
            exit(-1);
        }
    }
    printList(list);

    State* Hold = popStack(list);

    printList(list);
    if (Hold != NULL){};
        printf("\nPopped Value: %f\n", Hold->populationInMillion);

    StateList* list2 = initQueue();

    int test2 = 0;
    for (float j = 1.5;j<12;j++) {
        test2 = enQueue(list2, j);
        if (test2 == -1) {
            printf("\nTrouble adding to queue\n");
            exit(-1);
        }
    }
    printList(list2);

    State* Hold2 = deQueue(list2);

    printList(list2);
    if (Hold2 != NULL)
        printf("\nDeQueued Value: %f\n", Hold2->populationInMillion);

    freeList(list);
    freeList(list2);

    printf("\nProgram is done\n");

    return 0;
}
