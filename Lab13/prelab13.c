// Pre Lab 13 C File
// Rya Christopher

#include "prelab13.h"

int compare(void *a, void *b)
{
    /*
    Employee *query, emp;
    query = a;
    emp = b;
    if (query->SSN < emp->SSN) {
        return -1;
    } else if (query->SSN > emp->SSN) {
        return 1;
    } else {
        return 0;
    }*/

    return (*(int *)a - *(int *)b);
}

int binarySearch(void * array, int low, int high, void * target)
{
    if (low > high) {
        return -1;
    }
    else {
        int mid = (low + high)/2;
        int result = compare(target, &((int *)array)[mid]);

        if(result < 0) { //Result in bottom half of list
            return binarySearch(array, low, mid-1, target);
        } else if(result > 0) { //Result in top half of list
            return binarySearch(array, mid+1, high, target);
        } else { //Result found
            return mid;
        }
    }
}
