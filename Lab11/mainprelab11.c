//CS 2050 Prelab 11 Main File
//Ryan Christopher

#include "prelab11.h"

int main(void)
{
    int comp;
    Queue test = initQueue();
    Employee* node = NULL;

    while (comp != -1) {
        for(int i = 0;i<20;i++) {

            comp = enqueue(node, test);
        }
        comp = -1;
    }
    printList(test);

    int size = getQsize(test);
    printf("\nSize of Queue is: %d\n", size);

    Employee* node2 = dequeue(test);
    free(node2);
    printList(test);

    size = getQsize(test);
    printf("\nSize of Queue is: %d\n", size);

    freeQueue(test);
    return 0;
}
