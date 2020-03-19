// Prelab 9 Main File

#include "prelab9.h"

int main(void)
{
    List *list;
    list = createList();
    int test = 0;

    for (int i = 0;i<20;i++) {
        test = insertAtTail(i, list);
        if (test == 1) {
            printf("\nTrouble adding to head\n");
            exit(-1);
        }
    }
    printList(list);

    List *copy = copyList(list);
    printList(copy);

    printf("\nLength of List: %d\n", getListLength(list));

    printf("\nTail of List: %d\n", list->tail->key);

    freeList(list);
    freeList(copy);

    printf("\nEnd Program\n");

    return 0;
}
