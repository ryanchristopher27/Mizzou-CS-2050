//Ryan Christopher
//Prelab 5

#include <stdio.h>
#include <stdlib.h>

//Prototype Functions
void * createTable(int numRows, int numCols, int elemSize);
int getNumRows(void **array);
int getNumCols(void **array);
void freeArray(void **array);
void getData(int *numRows, int *numCols, double *begNum, double *increment);

//Main Function
int main(void)
{
    int numRows, numCols;
    double hold, increment;
    int rowCount = 1;
    int colCount = 1;

    getData(&numRows, &numCols, &hold, &increment);

    double **array = createTable(numRows, numCols, sizeof(double));
    for (int i=0;i<numRows;i++) {
        for (int j=0;j<numCols;j++) {
            array[i][j] = hold;
            hold = hold + increment;
        }
    }

    printf("\nElements in this array are :\n\n");
    printf("\t");
    while (colCount < numCols+1) {
        printf("%5d      ", colCount);
        colCount++;
    }
    for (int i=0;i<numRows;i++) {
        printf("\n\n  %d  \t", rowCount);
        rowCount++;
        for (int j=0;j<numCols;j++) {
            printf("%7.2lf    ", array[i][j]);
        }
    }

    printf("\n\nNumber of Rows: %d\n\n", (int)getNumRows((void*)array));
    printf("Number of Columns: %d\n\n", (int)getNumCols((void*)array));

    freeArray((void*)array);

    printf("Program is Done!\n\n");

    return 0;
}

//Allocates memory for a void table and creates it
//Then it hides the number of rows and columns in front of the array
void * createTable(int numRows, int numCols, int elemSize)
{
    void **array = malloc(numRows*sizeof(void*));

    int i, j;
    int count = 0;
    int hold = 0;

    for(i=0;i<numRows;i++) {
        if (hold == 0) {
            *(array + i) = malloc(numCols*elemSize+(2*sizeof(int)));
            hold = 1;
        }
        else {
            array[i] = malloc(numCols*elemSize);
        }
        count ++;
        if (array == NULL) {
            printf("Memory not allocated.\n");
            for (j=0;j<count;j++) {
                free((void*)array[j]);
            }
            exit(-1);
        }
    }

    *array = ((int*)*array)+2;
    ((int*)array)[-2] = numRows;
    ((int*)array)[-1] = numCols;

    return array;
}

//Gets the number of rows from the hidden spot in the array and returns it as an integer
int getNumRows(void **array)
{
    return ((int*)array)[-2];
}

//Gets the number of columns from the hidden spot in the array and returns it as an integer
int getNumCols(void **array)
{
    return ((int*)array)[-1];
}

//Frees the 2D array by going through the array of the different inner arrays and freeing each one of them
void freeArray(void **array)
{
    int numRows = getNumRows(array);

    *array = ((int*)*array)-2;

    for (int i=0;i<numRows;i++) {
        free((void*)array[i]);
        //array[i] = NULL;
    }
    free((void*)array);
}

//Gets the desired data from the user and changes the desired values using pass by reference
void getData(int *numRows, int *numCols, double *begNum, double *increment)
{
    int numRows1, numCols1;
    double begNum1, increment1;

    printf("How many Rows do you want?\t");
    scanf("%d", &numRows1);
    printf("\nHow many Columns do you want?\t");
    scanf("%d", &numCols1);
    printf("\nWhat do you want the First Number to be?\t");
    scanf("%lf", &begNum1);
    printf("\nHow much do you want that number to be incremented by?\t");
    scanf("%lf", &increment1);

    *numRows = numRows1;
    *numCols = numCols1;
    *begNum = begNum1;
    *increment = increment1;
}
