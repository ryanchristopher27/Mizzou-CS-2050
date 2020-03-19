//Ryan Christopher
//CS 2050
//Lab 5
//20 February 2020

#include <stdio.h>
#include <stdlib.h>

//Prototype Functions
void** create2DArray(int numRows, int numCols, int elemSize);
double getRowSize(void** table);
double getColSize(void** table, int rowNo);
void printTable(void** table);
void freeTable(void** table);

//Main Function
int main(void)
{
    int numRows = 10;
    int numCols = 8;
    int hold = 1;
    int increment = 1;

    int **array;
    array = (int**)create2DArray(numRows, numCols, sizeof(int));

    //printf("%lf",((double*)array)[-1]);

    for (int i=0;i<numRows;i++) { //gives values to all the variables in the array and increments them 1 by 1
        for (int j=0;j<numCols;j++) {
            array[i][j] = hold;
            hold = hold + increment;
        }
    }

    printTable((void**)array); //Prints the table

    freeTable((void**)array); //Frees the table

}

//Creates a 2D Array by allocating memory for the primary array and the hidden value in it
//Then allocates memory for each secondary array and the hidden value in it
void** create2DArray(int numRows, int numCols, int elemSize)
{
    void **array = malloc(numRows*sizeof(void*)+(sizeof(double)));

    *array = ((double*)array)+1;
    ((double*)array)[-1] = (double)numRows;

    int i, j;
    int count = 0;

    for(i=0;i<numRows;i++) {
        *(array + i) = malloc(numCols*elemSize+sizeof(double));
        count ++;
        if (array == NULL) {
            printf("Memory not allocated 2.\n");
            for (j=0;j<count;j++) {
                free((void*)array[j]);
            }
            exit(-1);
        }
        *array = ((double*)array)+1;
        ((double*)array)[-1] = (double)numCols;
    }

    return array;
}

//Gets the row size from the primary array and returns it as a double
double getRowSize(void** table)
{
    return ((double*)table)[-1];
}

//Gets the column size from the chosen secondary array and returns it as a double
double getColSize(void** table, int rowNo)
{
    int i = 1;
    while (i != rowNo) {
        *table = *(table+1);
        i++;
    }
    if((*table+i) == NULL) {
        return -1;
    }
    else {
        return ((double*)table)[-1];
    }
}

//Prints the values of the table while also according to row and columns
//Also prints headers for each row and column
void printTable(void** table)
{
    int colCount = 1;
    int rowCount = 1;
    double numOfRows = getRowSize((void*)table);
    double numOfCols = getColSize((void*)table, 1);

    int **array = ((int**)table);

    printf("\nElements in this array are :\n\n");
    printf("\t");

    while (colCount < numOfCols+1) { //Prints the column headers
        printf("%5d      ", colCount);
        colCount++;
    }
    for (int i=0;i<numOfRows;i++) { //Prints the row headers
        printf("\n\n  %d  \t", rowCount);
        rowCount++;
        for (int j=0;j<numOfCols;j++) { //Prints the incremented data
            printf("%7d    ", (array)[i][j]);
        }
    }
}

//Frees the primary array and the hidden variable in front of it
//Then frees the secondary arrays and the hidden variables in front of each of them
void freeTable(void** table)
{
    double numRows = ((double*)table)[-1];

    for (int i=0;i<numRows;i++) {
        *table = ((double*)table)-1;
        free((void*)table[i]);
    }

    *table = ((double*)table)-1;
    free((void*)table);
}
