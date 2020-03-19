//Lab 8 Main Failed
//Ryan Christopher

#include "lab8.h"

int main(void)
{
    State *head;
    State *single = createNode(5);
    float temp = 0;
    head = initList();

    head = addToHead(head, 2);
    head = addToHead(head, 1);
    head = addToHead(head, 0);
    head = addToTail(head, 3);
    head = addToTail(head, 4);
    head = addToTail(head, 5);
    head = addToTail(head, 6);

    printList(head);

    temp = searchPopulationByIdx(head, 5);

    printf("\nIndexed Population: %.2f", temp);

    printList(single);

    head = freeList(head);
    single = freeList(single);

    printf("\n\nEnd Program\n");

    return 0;
}
