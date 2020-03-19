// Prelab 9 w/o 2 structs Main File

#include "prelab9.2.h"

int main(void)
{
    List *list;
    list = createList();
    int test = 0;

    for (int i = 0;i<10;i++) {
        test = insertAtTail(i, list);
        if (test == 1) {
            printf("\nTrouble adding to head\n");
            exit(-1);
        }
    }
    printList(list);

    List *copy = copyList(list);
    printList(copy);

    //emptyList(list);
    //printList(list);

    printf("\nLength of List: %d\n", getListLength(list));

    freeList(list);
    freeList(copy);

    printf("\nEnd Program\n");

    return 0;
}
