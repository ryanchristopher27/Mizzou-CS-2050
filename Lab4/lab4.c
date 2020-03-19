//Ryan Christopher
//Pawprint: rdcb2f
//CS 2050 Lab 4
//13 February 2020

#include <stdio.h>
#include <stdlib.h>

//Prototype functions
void* createArray(int size, int elemSize);
int getArraySize(void* array);
void freeArray(void* array);
void storeMinMax(void* array);

//Main Function
int main(void)
{

    int arraySize = 10; // size of array

    float *array = createArray(arraySize, sizeof(float));

    float hold = 6.2;
    for (int i=0;i<arraySize;i++) { //Initiallizes values into the array
        ((float*)array)[i] = hold;
        hold = hold + 1;
    }

    storeMinMax(array);

    printf("\nElements in array are: ");
    for (int i=0;i<arraySize;i++) { //Prints all the values inside the array
        printf("%.2f  ", array[i]);
    }

    int size = getArraySize(array);
    float min = array[-2];
    float max = array[-3];

    //Prints the 3 hidden values that are in the array
    printf("\n\nArray size is %d, min value is %.2f, and max value is %.2f", size, min, max);

    freeArray(array);

    printf("\n\nEnd of Program\n");

    return 0;

}

//Creates the desired array with the correct size and allocates the right amount of memory for that array
//Then hides the first 3 locations in the array and sets the size equal to the -1 spot
void* createArray(int size, int elemSize)
{
    void *array = malloc(size*elemSize+(2*sizeof(float))+sizeof(int));

    if (array == NULL) {
        printf("Memory not allocated.\n");
        exit(-1);
    }

    //array = ((float*)array)+3;
    //During the lab I put the line above instead of the 2 lines below
    array = ((float*)array)+2;
    array = ((int*)array)+1;
    ((int*)array)[-1]=size;

    return array;
}

//Returns the size of the array as an integer by refering to the hidden location that the size was stored at
int getArraySize(void* array)
{
    return ((int*)array)[-1];
}

//Frees all of the memory that was allocated for the array and then sets the array equal to NULL
void freeArray(void* array)
{
    //free(((float*)array)-3);
    array = ((int*)array)-1;
    array = ((float*)array)-2;
    free((void*)array);
    array = NULL;
}

//Finds the minimum and maximum values of the array and then stores those values in the hidden locations in the array
void storeMinMax(void* array)
{
    float min= ((float*)array)[0];
    float max= ((float*)array)[0];
    int size = getArraySize(array);

    for (int i=0;i<size;i++) {
        if (((float*)array)[i]>max) {
            max = ((float*)array)[i];
        }
        else if(((float*)array)[i]<min) {
            min = ((float*)array)[i];
        }
    }

    ((float*)array)[-3] = min;
    ((float*)array)[-2] = max;

}
