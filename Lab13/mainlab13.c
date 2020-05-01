// Lab 13 Main File
// Ryan Christopher
// CS 2050
// 23 April 2020

#include "lab13.h"

int main(void)
{
    FILE * fp = fopen("states.csv", "r");
    if(fp)
    {
        State ** array = readRecord(fp);
        fclose(fp);
        for (int m=0;m<10;m++) {
            printf("\narray[%d] = %.6f", m, array[m]->area);
        }
        if(array)
        {
            State target;
            printf("Enter a area to search for: ");
            scanf("%f", &(target.area));
            //printf("%f", target.area);
            int result = binarySearch((void **)array, 0, 9999, &target);
            if(result != -1)
                printf("%f was found in position %d.\n", target.area, result);
            else
                printf("%f was not found within the array.\n", target.area);

            freeArr(array, 10000);
        }
        else
            printf("Error... (1)\n");
    }
    else
        printf("Error... (2)\n");

    printf("Success.\n");
    return 0;
}
