#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void** create2DArray(int, int, int);
double getRowSize(void**);
double getColSize(void**, int);
void printTable(void** );
void freeTable(void**);

int main(void){

	srand(time(NULL));

	int numRows = 5, numCols = 10;
	int** table = (int**)create2DArray(numRows,numCols,sizeof(int));

	if (table == NULL){
		return -1;
	}

	for (size_t i = 0; i < numRows; i++){
		for (size_t j = 0; j < numCols; j++){
			table[i][j] = rand() % 10 + 1;
		}
	}

	printTable((void**)table);
	freeTable((void**)table);
	table = NULL;

	printf("Program done\n");
	return 0;

}

/* this function receives number of rows, and number of columns in a 2D table, and the size of each element.
It creates a table like above, hides the number of rows in front of first column, then hides the number of columns in front of each column*/
void** create2DArray(int numRows, int numCols, int elemSize){

	double** table = malloc(sizeof(void*)*numRows+sizeof(double));
	if (table == NULL){
		printf("First column allocation failed\n");
		return NULL;
	}
	*((double*)table) = (double)numRows; // hide num of rows as float
	table = (double**)((double*)table+1); // move

	for (size_t i = 0; i < numRows; i++){
		table[i] = malloc(elemSize*numCols+sizeof(double));
		if (table[i] == NULL){
			printf("Row allocation failed\n");

			// this is tricky but necessary, if allocation failed, they need to free all previously allocated memories.
			// maybe deduct 1 point if this is missing, guess majority of students won't have this
			for (size_t j = 0; j < i; j++){
				free(table[j]-1);
			}

			// then free the table itself
			free((double*)table-1);

			return NULL;

		} else {
			// hide the size of columu
			*(table[i]) = (double)numCols;
			table[i] = table[i] + 1;
		}
	}

	return (void**)table;

}

/* just return the number of rows in this table, return -1 if the table is null*/
double getRowSize(void** table){
	if (table == NULL){
		return -1;
	}

	return *((double*)table-1);
}

/* get the size of certain column, return -1 if the table is NULL, or the query column doesn't exist. rowNo is 0-based*/
double getColSize(void** table, int rowNo){
	if (table == NULL){
		return -1; // table is NULL
	} else if ((int)getRowSize(table) <= rowNo){
		return -1; // query column doesn't exist in this table
	} else {
		int* temp = ((int**)table)[rowNo];
		return *((double*)temp - 1);
	}
}

/* prints out the numbers in this table in row-wise, need to be changed based on lab requirement*/
void printTable(void** table){
	// let's do int for this lab
	// deduct points if any hard-coded values exist
	printf("Table is:\n");
	for (size_t i = 0; i < (int)getRowSize(table);i++){
		printf("Row %d: ",(int)i);
		for (size_t j = 0; j < (int)getColSize(table,i); j++){
			printf("%d ",((int**)table)[i][j]);
		}
		printf("\n");
	}
}

/* frees all allocated memories*/
void freeTable(void** table){
	if (table == NULL){
		return;
	} else {
		for (size_t i = 0; i < getRowSize(table); i++){
			double* temp = (double*)(table[i])-1;
			free(temp);
			temp = NULL;
		}
		free((double*)table-1);
	}
}
