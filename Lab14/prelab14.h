// Prelab 14 H File
// Ryan Christopher

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct empstruct{
    int SSN, ID;
} Employee;

typedef struct empDBstruct{
    Employee* IDarray;
    Employee* SSNarray;
    int size;
} empDatabase;

//Prototype Functions
empDatabase createSearchableEmployeeDB(Employee ** array, int size);
//Employee * findEmpBySSN(int target, empDatabase empDB);
//Employee * findEmpByID(int target, empDatabase empDB);
void freeEmpDatabase(empDatabase empDB);
void insertionSort(Employee * empArray, int size);
void printArray(Employee *empArray, int size);
