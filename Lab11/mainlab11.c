//Lab 11 Main File
//Ryan Christopher
//CS 2050
//9 April 2020

#include "lab11.h"

int main(void)
{
    int comp = 1;
    Queue test = initQueue();

    deQueue(test);

    while (comp != -1) {
        for(int i = 1;i<20;i++) {

            comp = enQueue(i, test);
        }
        comp = -1;
    }
    printQueue(test);
    printf("\nNumber of Items: %d\n", getQsize(test));
    printf("\nTotal Population: %.2f\n", getTotal(test));

    State* dvalue = deQueue(test);
    printf("\nDequeued value: %.2f\n", dvalue->populationInMillion);
    free(dvalue);

    printQueue(test);
    printf("\nNumber of Items: %d\n", getQsize(test));
    printf("\nTotal Population: %.2f\n", getTotal(test));

    dvalue = deQueue(test);
    printf("\nDequeued value: %.2f\n", dvalue->populationInMillion);
    free(dvalue);

    printQueue(test);
    printf("\nNumber of Items: %d\n", getQsize(test));
    printf("\nTotal Population: %.2f\n", getTotal(test));

    emptyQueue(test);

    printf("\nEnd of Program\n");
    return 0;
}
