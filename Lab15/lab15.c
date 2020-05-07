// Lab 15 C File
// Ryan Christopher
// CS 2050
// 7 May 2020

#include "lab15.h"

//***Extra Functions***

//Creates a new node with data equal to the passed Employee
//It is passed the employee pointer
//It returns the created node
//If malloc fails, it prints and error statment and returns NULL;
Node * createNode(Employee * original)
{
    Node* node;
    node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("\nError Allocating Memory\n");
        return NULL;
    }

    node->data = original;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//***Prototype Functions***

//Checks if file was opened correectly
//Allocates memory for the array of Employee pointers
//Allocates memory for each separate employee Struct
//Scans the values into each struct from the opened File
//It is passed the file pointer
//It returns the Employee double pointer
//If the function fails at any point, it prints and error statment and returns NULL
Employee ** readRecord(FILE * file)
{
    Employee ** pArray;
    int size = 0;
    int id = 0;
    float sal  = 0;
    int soc = 0;

    if (!file) {
        printf("\nFile was not opened correctly\n");
        return NULL;
    }

    fscanf(file, "%d\n", &size);

    pArray = malloc(sizeof(Employee*)*size);
    if (!pArray) { //Malloc Check
        printf("\nError Allocating Memoroy Location 1\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0;i < size;i++) {
        pArray[i] = malloc(sizeof(Employee));
        if (!pArray[i]) { //Malloc Check
            printf("\nError Allocating Memory Location 2\n");
            for (int j = 0;j<i;j++) { //Frees previously allocated memory
                free(pArray[j]);
            }
            fclose(file);
            return NULL;
        }
        fscanf(file, "%d,%f,%d\n", &id, &sal, &soc);
        pArray[i]->ID = id;
        pArray[i]->salary = sal;
        pArray[i]->ssn = soc;
    }

    return pArray;
}

//Compares the salary values of the passed pointer structs
//Returns the correlating value to which struct salary value is larger
//It is passed the 2 pointer structs that are being compared
int comparison(void * mainTree, void * node)
{
    Employee * prime = mainTree;
    Employee * new = node;

    if (prime->salary > new->salary) { //main is larger
        return 1;
    } else if (prime->salary < new->salary) { //main is smaller
        return -1;
    } else {
        return 0;
    }
}

//Recursively inserts a new node into the BST by comparing the new node to the current node
//It is passed the BST and the data of the new node that is to be added
//It returns the new BST with the added node
Node * insertBST(Node * mainTree, Employee * newNode)
{
    if (mainTree != NULL) {
        if (comparison(mainTree->data, newNode) < 0) { //main is smaller
            mainTree->left = insertBST(mainTree->left, newNode);
        } else if (comparison(mainTree->data, newNode) > 0) { //main is larger
            mainTree->right = insertBST(mainTree->right, newNode);
        }
        return mainTree;
    } else {
        return createNode(newNode);
    }
}

//Recursively searches through the BST until the desired target value found
//It is passed the BST and the target float value
//It returns the Employee struct pointer of the found target value
//If the target value does not exist, it returns NULL;
Employee * searchBST(Node * mainTree, float target)
{
    if (mainTree == NULL) {
        printf("\nDesired value is not in list\n");
        return NULL;
    } else if (mainTree->data->salary < target) {
        return searchBST(mainTree->left, target);
    } else if (mainTree->data->salary > target) {
        return searchBST(mainTree->right, target);
    } else {
        return mainTree->data;
    }
}

//Recursively deletes all the memory that has been allocated for the BST
//It is passed the BST
void deleteTree(Node * mainTree)
{
    if (mainTree == NULL) {
        return;
    } else {
        deleteTree(mainTree->left);
        deleteTree(mainTree->right);
        free(mainTree);
    }
}
