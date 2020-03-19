#include "prelab7.h"

int main(void)
{
    Node *head;
    Node *head1;
    int check = 0;

    head1 = initIntegerList();
    head = initList();

    while (check != 1) {
        check = insertAtHead(5, head1);
        check = insertAtTail(6, head1);
        check = insertAtTail(7, head1);
        check = insertAtHead(4, head1);
        check = insertAtHead(3, head1);
        check = insertAtTail(8, head1);
        check = insertAtHead(2, head1);
        check = insertAtHead(1, head1);
        check = insertAtTail(9, head1);
        check = 1;
    }

    head = insertHead(2, head);
    head = insertTail(3, head);
    head = insertHead(1, head);

    printf("\nCheck\n");

    printListDummy(head1);
    printf("\n");
    printList(head);

    freeList(head1);
    freeList(head);

    printf("\nEnd Program\n");

    return 0;
}
