// Lab 14 C File
// Ryan Christopher
// CS 2050
//30 April 2020

#include "lab14.h"

//Uses the insertion method to sort they array in ascending order
//It is passed the double pointer and the size of the array
//It sorts the array according to the area
void insertionSort(State** array, int size)
{
    int i, j;
    float keyArea, keyPop;

    for (i = 1; i < size; i++) {
        keyArea = array[i]->area;
        keyPop = array[i]->populationInMillion;
        j = i - 1;
        while (j >= 0 && array[j]->area > keyArea) {
            array[j + 1]->area = array[j]->area;
            array[j + 1]->populationInMillion = array[j]->populationInMillion;
            j = j - 1;
        }
        array[j + 1]->area = keyArea;
        array[j + 1]->populationInMillion = keyPop;
    }
}

//Recursively searches through the array to find a certain value
//It is passed the double pointer, the low and high integers, and the target float
//If the target value is found, it returns the position of the value
//If the target value is not found, it returns -1
int binarySearch(State** array, int beg, int end, float target)
{
    if (beg <= end) {
        int mid = (beg + end) / 2;

        if (array[mid]->area == target) {
            return mid;
        }
        if (array[mid]->area > target) {
            return binarySearch(array, beg, mid - 1, target);
        }
        return binarySearch(array, mid + 1, end, target);
    }
    return -1;
}

//Checks if file was opened correctly
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

    fscanf(fp, "%d,\n", &size);

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

//Creates a database with an array with values in ascending order by area
//It is passed the State double pointer and the size
//It returns the database
StateDB createDatabase(State** array, int size)
{
    StateDB database;
    database.sizeOfDB = size;

    //Other option for transfering data to array inside database struct
    /*
    database.array = malloc(sizeof(State*)*size);

    for (int i = 0; i < size; i++)
    {
        database.array[i] = malloc(sizeof(State));
        database.array[i]->populationInMillion = array[i]->populationInMillion;
        database.array[i]->area = array[i]->area;
    }
    */
    //Simple option for transfering data to array inside database struct
    database.array = array;
    insertionSort(database.array, size);

    return database;
}

//Uses a binary search to search through the array to find a target float value
//It is passed the database struct and the target float
//It returns the State pointer to the location off the struct with the target float
//If the target float does not exist in the array, it returns NULL
State* findStateByArea(StateDB database, float target)
{
    int count = binarySearch(database.array, 0, database.sizeOfDB, target);
    if (count == -1) { // Checks if target doesn't exist
      printf("\nCould not find target value\n");
      return NULL;
    }
    printf("\nposition: %d", count);
    return (database.array[count]);
}

//Frees all the memory previously allocated including the main State** in the database struct
//It is passed the database struct
void freeDatabase(StateDB database)
{
    for (int i = 0;i < database.sizeOfDB;i++) {
        free(database.array[i]);
    }
    free(database.array);
}
