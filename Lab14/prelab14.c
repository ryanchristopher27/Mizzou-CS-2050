                                                                                                                                            // Prelab 14 C File
// Ryan Christopher

#include "prelab14.h"

/*
empDatabase createSearchableEmployeeDB(Employee ** empArray, int size)
{
    empDatabase database;
    database.size = size;
    database.IDarray = malloc(sizeof(Employee*)*size);
    database.SSNarray = malloc(sizeof(Employee*)*size);
    empArray = malloc(sizeof(Employee*)*size);

    int i;

    for(i=0;i<size;i++)  {
        empArray[i] = malloc(sizeof(Employee));
    }

    for(i=0;i<size;i++) {
        empArray[i]->ID = 58-i;
        empArray[i]->SSN = 99-i;
    }

    printf("test3");
    for(i=0; i<size; i++) {
        database.IDarray[i].ID = empArray[i]->ID;
        database.SSNarray[i].SSN = empArray[i]->SSN;
    }

    insertionSort(database.IDarray, size);

    printArray(database.IDarray, size);

    return database;
}*/

empDatabase createSearchableEmployeeDB(Employee** array, int size)
{
    empDatabase empDB;
    int i;

    empDB.size=size;
    empDB.IDarray = malloc(size*sizeof(Employee));
    empDB.SSNarray = malloc(size*sizeof(Employee));
    array = malloc(size * sizeof(Employee*));
  for(i=0;i<size;i++)
    {
        array[i] = malloc(sizeof(Employee));


    }
  for(i=0;i<size;i++)
      {
        array[i]->ID = 58-i;
      array[i]->SSN = 99-i;
    }

  for (i = 0; i < size; i++)
    {
       empDB.IDarray[i].ID = array[i]->ID;
       empDB.IDarray[i].SSN = array[i]->SSN;
       empDB.SSNarray[i].SSN = array[i]->SSN;
       empDB.SSNarray[i].ID = array[i]->ID;
    }
    insertionSort(empDB.SSNarray, size);
    //insertionSortSSN(empDB.SSNarray, size);

//qsort(empDB.IDarray,size,sizeof(Employee),compare);
//qsort(empDB.SSNarray->SSN,size,sizeof(int),compare);
  /*for (i = 0; i < size; i++)
    {
      printf("%d\n", empDB.IDarray[i].ID);
    }*/
    printArray(empDB.IDarray, size);

    return empDB;
}
/*
Employee * findEmpBySSN(int target, empDatabase empDB)
{

}

Employee * findEmpByID(int target, empDatabase empDB)
{

}
*/
void freeEmpDatabase(empDatabase empDB)
{
    /*
    Employee * hold1;
    Employee * hold2;
    for (int i=0;i<empDB.size;i++) {
        hold1 = empDB.IDarray[i];
        hold2 = empDB.SSNarray[i];
        free((void*)hold1);
        free(hold2);
    }
    */
    free(empDB.IDarray);
    free(empDB.SSNarray);
    //free(empDB);
}

void insertionSort(Employee * empArray, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = empArray[i].SSN;
        j = i - 1;

        while (j >= 0 && empArray[j].SSN > key) {
            empArray[j + 1].SSN = empArray[j].SSN;
            j = j - 1;
        }
        empArray[j + 1].SSN = key;
    }
    /*
    int i, j;
    Employee * key;

    for (i=1;i<size;i++) {
        key = empArray[i];
        j = i - 1;

        while (j >= 0 && empArray[j]->ID > key->ID) {
            empArray[j+1] = empArray[j];
            j = j - 1;
        }
        empArray[j+1] = key;
    }
    */
}

void printArray(Employee * empArray, int size)
{
    printf("\nArray:\n");
    for (int i=0;i<size;i++) {
        printf("\nSSN: %d,  ID: %d", empArray[i].SSN, empArray[i].ID);
    }
}
