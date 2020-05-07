// Lab 15 Main File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include "lab15.h"

int main(void)
{
    FILE * fp = fopen("employee.csv", "r");
    if (fp)
    {
        Employee ** array = readRecord(fp);
        fclose(fp);

        if (array)
        {
            Node * mainRoot = NULL;
            mainRoot = insertBST(mainRoot, array[0]);

            //printf("\nArray[0] = %f\n", mainRoot->data->salary);

            for (int i=0;i<10000;i++) {
                mainRoot = insertBST(mainRoot, array[i]);
            }

            Employee *test = NULL;

            test = searchBST(mainRoot, 3600.4);

            if (test == NULL) {
                printf("\nNo value\n");
            } else {
            printf("\nTest value: %f\n", test->salary);
            }

            deleteTree(mainRoot);

            printf("\nEnd of Program\n");
        }
    }

    return 0;
}
