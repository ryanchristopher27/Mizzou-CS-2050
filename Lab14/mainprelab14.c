// Prelab 14 Main File
// Ryan Christopher

#include "prelab14.h"

int main(void)
{
    empDatabase test;
    test.IDarray = NULL;
    test.SSNarray = NULL;
    test.size = 0;
    Employee ** emptest = NULL;

    test = createSearchableEmployeeDB(emptest, 10);

    freeEmpDatabase(test);

    return 0;
}
