// Lab 14 Main File
// Ryan Christopher
// CS 2050
//30 April 2020

#include "lab14.h"

int main(void)
{
    FILE * fp = fopen("states.csv", "r");
    if(fp)
    {
        State ** array = readRecord(fp);
        fclose(fp);
        StateDB database = createDatabase(array, 10000);

        //printf("\n%f\n", database.array[500]->area);

        for (int i = 0; i < 20; i++)
        {
            printf("%f  ", database.array[i]->area);
        }

        State* value = findStateByArea(database, 4014.56);

        printf("\npop: %f\n", value->populationInMillion);
        printf("\narea: %f\n", value->area);

        freeDatabase(database);

        printf("\nEnd of Program\n");

    }
    return 0;
}
