//Ryan Christopher
//Lab 6
//CS 2050 Section F
//27 February 2020

#include <stdio.h>
#include <stdlib.h>

//struct
typedef struct {
    int empID, age;
    float salary;
} Record;

//Prototype functions
Record * readRecordFile(FILE * fp);
int getSize(Record * array);
Record * getEmpBySalary(Record * array, float salary);
float computeAgeAverage(Record * array);
void freeRecordArray(Record * array);

//Main Function
int main(void)
{
    FILE *file;
    file = fopen("employee.csv", "r");
    if (file == NULL) {
        printf("\nError: Could not open file\n");
        exit(-1);
    }

    int size = 0;
    float average = 0;

    Record *recArray = readRecordFile(file);

    size = getSize(recArray);
    printf("\n\nSize: %d", size);

    average = computeAgeAverage(recArray);
    printf("\n\nAverage: %.2f", average);

    Record *emp = getEmpBySalary(recArray, 25215.4055);

    if (emp == NULL) {
        printf("\n\nNULL\n\n");
    }
    else {
        printf("\nID: %d\nSalary: %f\nAge: %d\n", emp->empID, emp->salary, emp->age);
    }

    freeRecordArray(recArray);

    printf("\n\nEnd of Program\n");
    return 0;
}

//Makes the first value in the file equal to the number of records in the file
//Allocates memory for the array and checks to make sure it is allocated correctly
//Puts the number of records value hidden in front of the array
//Scans the rest of the records into the array and returns the array
Record * readRecordFile(FILE * fp)
{
    int numRecs = 0;

    fscanf(fp, "%d", &numRecs);

    Record * array;

    array = malloc(numRecs*sizeof(Record)+(sizeof(int)));
    if (array == NULL) {
        printf("Error: Memory could not be allocated.");
        exit(-1);
    }

    *(int*)array = (*(int*)array)+1;
    ((int*)array)[-1] = numRecs;

    for (int i=0;i<numRecs;i++) {
        fscanf(fp, "%d,%f,%d\n", &array[i].empID, &array[i].salary, &array[i].age);
    }

    return array;

}

//Gets the size from the hidden location in the passed array and returns it as an int
int getSize(Record * array)
{
    return ((int*)array)[-1];
}

//Goes through the array and tests to see if any of the array salary values match the requested salary value
//If it does then it returns the location in the array where they matched
//If not, the function returns NULL
Record * getEmpBySalary(Record * array, float salary)
{
    int size = getSize(array);
    int hold = 0;
    int i;

    for (i=0;i<size;i++) {
        if (array[i].salary == salary) {
            //*array = *(array+i);
            hold = 1;
            break;
        }
    }
    if (hold == 0) {
        return NULL;
    }
    else {
        return (array + i);
    }

}

//Goes through the array and adds up all of the ages from every record in the array
//Divides that value by the size of the array which is found using the get size function
//Returns the calculated average as a float
float computeAgeAverage(Record * array)
{
    int size = getSize(array);
    int count = 0;
    for (int i=0;i<size;i++) {
        count = count + array[i].age;
    }
    float avg = (float)count / (float)size;

    return avg;
}

//Resets the array to the initial position that it was malloced at
//Frees all the memory included in the array
void freeRecordArray(Record * array)
{
    *(int*)array = (*(int*)array)-1;
    free(array);
}
