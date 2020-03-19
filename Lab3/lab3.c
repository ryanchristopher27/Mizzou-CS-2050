//Ryan Christopher
//CS 2050
//Lab 3
//6 February 2020

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
int * readIntIntoArray(FILE *fp, int *totalNum, int *numOfPos, int *numOfNeg);
void findMinMaxAverage(int *arr, int size, int *minPtr, int *maxPtr, float *avePtr);
void freeIntArray(int **arrPtr);

//Main Function - This function opens the file and then calls the other prototype functions to get the desired values. It then prints those values.
int main(void)
{
	
	FILE *file;
	
	file = fopen("integers.txt", "r");
	
	if (file == NULL) {
		printf("Error! Could not open file\n");
		exit(-1);
	}
	
	int total = 0;
	int pos = 0;
	int neg = 0;
	int min = 0;
	int max = 0;
	float ave = 0;
	
	int *array = readIntIntoArray(file, &total, &pos, &neg);
	findMinMaxAverage(array, total, &min, &max, &ave);
	
	printf("\nThere are in total %d integers, %d positive, %d negative. Minimum is %d, maximum is %d, average is %.2f\n\n", total, pos, neg, min, max, ave);
	
	freeIntArray(&array);
	
	return 0;
	
}

//This function scans the contents of the opened file into the array and then returns that array. It also counts the total number of positive integers and the total number of negative integers in the array.
int * readIntIntoArray(FILE *fp, int *totalNum, int *numOfPos, int *numOfNeg)
{
	
	int *array;
	
	fscanf(fp, "%d", totalNum);
	
	array = malloc(*totalNum*sizeof(int));
	
	if (array == NULL) {
		printf("Memory not allocated.\n");
		exit(-1);
	}
	
	for (int i=0;i<*totalNum;i++) {
		fscanf(fp, "%d", (array+i));
		
		if (array[i]>0) {
			*numOfPos = *numOfPos + 1;
		}
		else if (array[i]<0) {
			*numOfNeg = *numOfNeg + 1;
		}
	}
	
	return array;
	
}

//This function uses the integers from the array and finds the maximum integer and the minimum integer. It also adds up all the integers and then divides that sum by the total number of integers to find the average of all the integers in the array.
void findMinMaxAverage(int *arr, int size, int *minPtr, int *maxPtr, float *avePtr)
{
	
	float sum = 0;
	
	for (int i=0;i<size;i++) {
		
		if (arr[i]<*minPtr) {
			*minPtr = arr[i];
		}
		else if (arr[i]>*maxPtr) {
			*maxPtr = arr[i];
		}
		
		sum = sum + arr[i];
	}
	
	*avePtr = sum/size;
	
}

//This function free's the memory from the array that had been allocated and then sets that memory equal to NULL.
void freeIntArray(int **arrPtr)
{
	
	free(*arrPtr);
	*arrPtr = NULL;
	
}