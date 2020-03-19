//Prelab 2
//Week of February 3rd
//Computer Science 2050
//Ryan Christopher

#include <stdio.h>
#include <stdlib.h>

//Prototype Functions
float * readFloatFileIntoArray(FILE *fptr, int *length);
void getLength(FILE *fptr, int *length);
void freeArray(float **array);

//Main Function
int main(void)
{
	
	FILE * file;
	int length;
	
	file = fopen("prelab3.dat", "r");
	
	if (file == NULL) {
		printf("Error! Could not open file\n");
		exit(-1);
	}
	
	getLength(file, &length);
	
	float *array = readFloatFileIntoArray(file, &length);
	
	printf("Size of array: %.0f\n", *(array - 1));
	
	for (int i=0;i<length;i++) {
		printf("%.2f\t", *(array + i));
	}
	
	free(file);
	
	freeArray(&array);
	
}

float * readFloatFileIntoArray(FILE *fptr, int *length)
{	
	float *array;
	
	array = malloc(*length*sizeof(float) + sizeof(float));
	*array = *length;
	array++;
	
	for (int i=0;i<*length;i++) {
		fscanf(fptr, "%f", (array + i));
	}
	
	return array;
	
}

void getLength(FILE *fptr, int *length)
{
	
	fscanf(fptr, "%d", length);
	
}

void freeArray(float **array)
{
	
	free(*array);
	*array = NULL;
	
}