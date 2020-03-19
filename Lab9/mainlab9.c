// Lab 9 Main File

#include "lab9.h"

int main(void)
{
    State *list;
    list = initListWithDummyNode();
    printList(list);
    emptyList(list);
    int test = 1;
    float count = 1;

    for (int i = 0;i<10;i++) {
        test = insertToTail(list, count);
        count++;
        if (test == 0) {
            printf("\nTrouble adding to head\n");
            exit(-1);
        }
    }
    printList(list);

    emptyList(list);
    emptyList(list);

    //printf("list->pop = %f\n", list->populationInMillion);
    //printf("list->next->pop = %f\n", list->nextState->populationInMillion);
    //printf("list->next->next->pop = %f\n", list->nextState->nextState->populationInMillion);
    printList(list);

    test = insertToTail(list, 2);
    test = insertToHead(list, 1);
    if (test == 0) {
        printf("\nTrouble adding to Tail\n");
        exit(-1);
    }
    printList(list);

    emptyList(list);
    printList(list);

    freeList(list);

    printf("\nEnd Program\n");

    return 0;
}
