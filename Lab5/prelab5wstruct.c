//Ryan Christopher
//Prelab 5

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numOfRows, numOfCols;
} TableDims;

//Prototype Functions
void * createTable(int numRows, int numCols, int elemSize);
int getNumRows(void **array);
int getNumCols(void **array);
void freeArray(void **array);
void getData(int *numRows, int *numCols, double *begNum, double *increment);

//Main Function
int main(void)
{
    TableDims user;
    double hold, increment;
    int rowCount = 1;
    int colCount = 1;

    getData(&user.numOfRows, &user.numOfCols, &hold, &increment);

    double **array = createTable(user.numOfRows, user.numOfCols, sizeof(double));

    for (int i=0;i<user.numOfRows;i++) { //Inserts the incremented values into the array
        for (int j=0;j<user.numOfCols;j++) {
            array[i][j] = hold;
            hold = hold + increment;
        }
    }

    printf("\nElements in this array are :\n\n");
    printf("\t");
    while (colCount < user.numOfCols+1) { //Prints the column headers
        printf("%5d      ", colCount);
        colCount++;
    }
    for (int i=0;i<user.numOfRows;i++) { //Prints the row headers
        printf("\n\n  %d  \t", rowCount);
        rowCount++;
        for (int j=0;j<user.numOfCols;j++) { //Prints the incremented data
            printf("%7.2lf    ", array[i][j]);
        }
    }

    printf("\n\nNumber of Rows: %d\n\n", (int)getNumRows((void*)array)); //Prints the number of rows
    printf("Number of Columns: %d\n\n", (int)getNumCols((void*)array)); //Prints the number of columns

    freeArray((void*)array); //Frees the array

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
            *(array + i) = malloc(numCols*elemSize+(2*sizeof(int))); //Allocates memory for the first row plus 2 ints
            hold = 1;
        }
        else {
            array[i] = malloc(numCols*elemSize); //Allocates memory for every row after the first one
        }
        count ++;
        if (array == NULL) { //Checks to make sure memory was allocated correctly
            printf("Memory not allocated.\n");
            for (j=0;j<count;j++) {
                free((void*)array[j]); //Frees any memory that was allocated before malloc failed
            }
            exit(-1);
        }
    }

    *array = ((int*)*array)+2; //Moves the array pointer over 2 spaces allowing 2 ints to be stored in front of the array
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

    *array = ((int*)*array)-2; //Moves the array pointer back to the very beginning of the array

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
