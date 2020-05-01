// Lab 13 C File
// Ryan Christopher
// CS 2050
// 23 April 2020

#include "lab13.h"

//Checks if file was opened correectly
//Allocates memory for the array of State pointers
//Allocates memory for each separate state Struct
//Scans the values into each struct from the opened File
//It is passed the file pointer
//It returns the State double pointer
//If the function fails at any point, it returns NULL
State** readRecord(FILE* fp)
{
    State** pArray;
    int size = 0;
    float pop = 0;
    float area = 0;

    if (!fp) {
        printf("\nFile was not opened correctly\n");
        return NULL;
    }

    fscanf(fp, "%d\n", &size);

    pArray = malloc(sizeof(State*)*size);
    if (!pArray) { //Malloc Check
        printf("\nError Allocating Memoroy Location 1\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0;i < size;i++) {
        pArray[i] = malloc(sizeof(State));
        if (!pArray[i]) { //Malloc Check
            printf("\nError Allocating Memory Location 2\n");
            for (int j = 0;j<i;j++) { //Frees previously allocated memory
                free(pArray[j]);
            }
            fclose(fp);
            return NULL;
        }
        fscanf(fp, "%f,%f\n", &pop, &area);
        pArray[i]->populationInMillion = pop;
        pArray[i]->area = area;
    }

    return pArray;
}

//Compares the two values from the passed pointers
//It is passed the target pointer and the mid pointer
//It returns the corresponding value
int comparison(void* a, void* b)
{
    State* first = a;
    State* sec = b;

    if (first->area < sec->area) {
        return -1;
    } else if (first->area > sec->area) {
        return 1;
    } else {
        return 0;
    }
}

//Recursively searches through the array to find a certain value
//It is passed the double pointer, the low and high integers, and the target pointer
//If the target value is found, it returns the position of the value
//If the target value is not found, it returns -1
int binarySearch(void** array, int low, int high, void* target)
{
    int mid = (high+low)/2;
    if (low > high) {
        return -1;
    } else {
        int test = comparison(array[mid], target);

        if (test > 0) {
            return binarySearch(array, mid+1, high, target);
        } else if (test < 0) {
            return binarySearch(array, low, mid-1, target);
        } else {
            return mid;
        }
    }
}

//Frees all the memory previously allocated including the main State** 
//It is passed the double pointer array and the size of the array
void freeArr(State** array, int size)
{
    for (int i = 0;i < size;i++) {
        free(array[i]);
    }
    free((State**)array);
}
