// Prelab 15 Main File
// Ryan Christopher

#include "prelab15.h"

int main(void)
{
    Node *mainRoot = NULL;
    //printf("\ntest1\n");
    mainRoot = insertBST(mainRoot, 50);

    //printf("\nRoot: %d\n", mainRoot->data);
    //if (mainRoot->left == NULL && mainRoot->right == NULL) {
        //printf("\nCorrect\n");
    //}

    //printf("\ntest2\n");
    //printTree(mainRoot);
    insertBST(mainRoot, 60);
    //printf("\nRoot: %d\n", mainRoot->right->data);
    insertBST(mainRoot, 20);
    insertBST(mainRoot, 40);
    insertBST(mainRoot, 17);
    insertBST(mainRoot, 70);
    insertBST(mainRoot, 55);

    //printf("\ntest3\n");
    //printTree(mainRoot);

    Node *test = NULL;

    test = searchBST(mainRoot, 21);

    print2D(test);

    print2D(mainRoot);

    printf("DONE\n");
    freeTree(mainRoot);

    printf("\nEnd of Program");

    return 0;
}
