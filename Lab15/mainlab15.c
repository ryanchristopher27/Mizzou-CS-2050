// Lab 15 Main File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include "lab15.h"

int main(void)
{
    Node *mainRoot = NULL;

    mainRoot = insertBST(mainRoot, 50);

    insertBST(mainRoot, 60);
    insertBST(mainRoot, 20);
    insertBST(mainRoot, 40);
    insertBST(mainRoot, 17);
    insertBST(mainRoot, 70);
    insertBST(mainRoot, 55);

    Node *test = NULL;

    test = searchBST(mainRoot, 17);

    printf("\ntest search: %d\n", test->data);

    printTree(mainRoot);

    freeTree(mainRoot);

    printf("\nEnd of program\n");

    return 0;
}
