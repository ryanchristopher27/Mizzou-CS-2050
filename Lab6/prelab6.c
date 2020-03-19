//Ryan Christopher
//Prelab 6

#include <stdio.h>
#include <stdlib.h>

//Struct
typedef struct {
    int ID, jobType;
    float salary;
}   Employee;

//Prototype functions
Employee * readEmployeeInfo(FILE *fp, int *numElems);
Employee * getEmployeeByID(Employee *p, int numEmps, int ident, Employee *hold);
void setID(Employee *p, int id);
int getID(Employee *p);
void setSalary(Employee *p, float salary);
void displayEmployees(Employee *p, int numEmps);
void freeEmpArray(Employee *p);
float getSalary(Employee *p);
void setJobType(Employee *p, int jobType);
int getJobType(Employee *p);

//Main Function
int main(void)
{
    FILE *file;
    int numEmps;
    int holdID;
    float empSalary = 0;
    int empID = 0;
    int empJobType = 0;
    int selection = 0;
    Employee *emp = malloc(sizeof(Employee));

    //Opens the file and checks to make sure it opened correctly
    file = fopen("employeestruct.dat", "r");
    if (file == NULL) {
        printf("\nError: Could not open file\n");
        exit(-1);
    }

    //Creates the employee array from the file and displays all the employees
    Employee *empArray = readEmployeeInfo(file, &numEmps);
    displayEmployees(empArray, numEmps);

        //Displays the menu and does whatever the user prompts the program to do
        while (selection != 9) {
            printf("\n\n***Main Menu***\n");
            printf("\nSelect the number correlaed with the option you choose");
            printf("\n1: Print all Employees");
            printf("\n2: Select a Certain Employee");
            printf("\n3: Set a New ID");
            printf("\n4: Get the ID from the selected Employee");
            printf("\n5: Set a New Salary");
            printf("\n6: Get the Salary from the selected Employee");
            printf("\n7: Set a New Job Type");
            printf("\n8: Get the Job Type from the selected Employee");
            printf("\n9: Exit Program\n\nSelection: ");

            scanf("%d", &selection);

            switch (selection) {
                case 1: displayEmployees(empArray, numEmps);
                    break;
                case 2: printf("\n\nGive the ID of the employee you wish to display: ");
                        scanf("%d", &holdID);
                        emp = getEmployeeByID(empArray, numEmps, holdID, emp);
                        displayEmployees(emp, 1);
                    break;
                case 3: printf("\n\nWhat would you like to change the ID to?");
                        scanf("%d", &empID);
                        setID(emp, empID);
                        displayEmployees(emp, 1);
                    break;
                case 4: empID = getID(emp);
                        printf("\n\nID: %d", empID);
                    break;
                case 5: printf("\n\nWhat would you like to change the salary to?");
                        scanf("%f", &empSalary);
                        setSalary(emp, empSalary);
                        displayEmployees(emp, 1);
                    break;
                case 6: empSalary = getSalary(emp);
                        printf("\n\nSalary: %f", empSalary);
                    break;
                case 7: printf("\n\nWhat would you like to change the Job Type to?");
                        scanf("%d", &empJobType);
                        setJobType(emp, empJobType);
                        displayEmployees(emp, 1);
                    break;
                case 8: empJobType = getJobType(emp);
                        printf("\n\nJob Type: %d", empJobType);
                    break;
                case 9: selection = 9;
                    break;
                default: printf("You did not enter a valid number");
                    break;
    }
}

    //Frees the employee array and the single employee
    free(emp);
    freeEmpArray(empArray);

    //Closes the file
    fclose(file);

    //Checks to ensure that the program does not end with a seg fault
    printf("\n\nEnd of Program!\n\n");

    return 0;
}

Employee * readEmployeeInfo(FILE *fp, int *numElems)
{
    fscanf(fp, "%d", numElems);

    Employee *array;

    array = malloc(*numElems*sizeof(Employee)+(sizeof(int)));

    if (array == NULL) {
        printf("Error: Memory could not be allocated.");
        exit(-1);
    }

    *(int*)array = (*(int*)array)+1;
    ((int*)array)[-1] = *numElems;

    for(int i=0;i<*numElems;i++){
        fscanf(fp, "%d %d %f", &array[i].ID, &array[i].jobType, &array[i].salary);
    }

    return array;
}

Employee * getEmployeeByID(Employee *p, int numEmps, int ident, Employee *hold)
{
    int wait = 0;

    while (wait == 0) {
        for (int i=0;i<numEmps;i++) {
            if (p[i].ID == ident) {
                hold->ID = p[i].ID;
                hold->jobType = p[i].jobType;
                hold->salary = p[i].salary;
                wait = 1;
            }
        }
        if (wait == 0) {
            printf("There was no employee with that ID.\nPlease enter a new ID number: ");
            scanf("%d", &ident);
        }
    }

    return hold;
}

//Sets the employee ID to the desired ID
void setID(Employee *p, int id)
{
    p->ID = id;
}

//Returns the employee ID as an integer
int getID(Employee *p)
{
    return p->ID;
}

//Sets the employee salary to the desired salary
void setSalary(Employee *p, float salary)
{
    p->salary = salary;
}

//Returns the employee salary as a float
float getSalary(Employee *p)
{
    return p->salary;
}

//Sets the employee Job Type to the desired Job Type
void setJobType(Employee *p, int jobType)
{
    p->jobType = jobType;
}

//Returns the employee job type as a integer
int getJobType(Employee *p)
{
    return p->jobType;
}

//Displays the desired employee/employees
void displayEmployees(Employee *p, int numEmps)
{
    for (int i=0;i<numEmps;i++) {
        printf("\nEmployee #%d:\t", i+1);
        printf("ID: %4d    ", p[i].ID);
        printf("Job Type: %4d    ", p[i].jobType);
        printf("Salary: $%9.2f", p[i].salary);
    }
}

//Frees the entire employee array
void freeEmpArray(Employee *p)
{
    *(int*)p = (*(int*)p)-1;
    free(p);
}
