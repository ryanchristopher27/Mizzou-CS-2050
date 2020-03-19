//Ryan Christopher
//CS 2050
//Prelab 4

#include <stdio.h>
#include <stdlib.h>

//Prototypes Function
void * createArray(int size, int sizeofdata);
int getArraySize(FILE *fp);
void freeArray(void **array);

//Main Function
int main(void)
{

    FILE *file;
    int size = 0;

	  file = fopen("prelab3.dat", "r");

	  if (file == NULL) {
		    printf("Error! Could not open file\n");
		    exit(-1);
	  }

    size = getArraySize(file);

    float * array = createArray(size, sizeof(float));

    for (int i = 0;i<size;i++) {
      fscanf(file, "%f", (array+i));
    }

    for (int i=0;i<size;i++) {
      printf("%.2f\n", *(array+i));
    }

    freeArray(&(float*)array);

    return 0;

}

int getArraySize(FILE *fp)
{

    int size = 0;

    fscanf(fp, "%d", &size);

    return size;

}

void * createArray(int size, int sizeofdata)
{

    void *array = malloc(size*sizeofdata);

    if (array == NULL) {
        printf("Memory not allocated.\n");
        exit(-1);
    }

    /*
    for (int i = 0;i<size;i++) {
      fscanf(fp, "%", *(array+i));
    }
    */

    return array;

}

void freeArray(void **array)
{

free(*array);
*array = NULL;

}
