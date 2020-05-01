// Pre Lab 13 main File
// Ryan Christopher

#include "prelab13.h"

int main(void)
{
    int array[11] = {1, 3, 6, 18, 25, 33, 39, 42, 51, 67, 99};
    int target;

    printf("Enter a number to search for: ");
    scanf("%d", &target);

    int result = binarySearch(array, 0, 10, &target);

    if(result != -1)
        printf("%d found at position %d.\n", target, result);
    else
        printf("%d not found in array.\n", target);

    printf("Success.\n");
    return 0;
}
