//Lab 2
//Week of January 27th
//Computer Science 2050
//Ryan Christopher

#include <stdlib.h>
#include <stdio.h>

//Prototype Functions
void GetInteger(int *compare);
void CompareArray(int *compare, int *array, int *less, int *more, int *size);
void GetArraySize(int *size);
void ScanInArray(int *array, int *size);

//Main Function
int main(void)
{
	int size;
	
	GetArraySize(&size);
	
	int array[size];
	
	printf("\nEnter the integers you want in the array:\n");
	
	ScanInArray(array, &size);
	
	int compare = 0;
	int less = 0;
	int more = 0;
	
	
	GetInteger(&compare);
	CompareArray(&compare, array, &less, &more, &size);
	
	printf("The number that those integers are compared to is %d\n", compare);
	printf("\n%d of those integers are less than %d\n", less, compare);
	printf("%d of those integers are more than %d\n", more, compare);
	
}

void GetArraySize(int *size)
{
	
	int hold;
	
	printf("How many integers are in your array?	");
	scanf("%d", &hold);
	
	*size = hold;
	
}

void ScanInArray(int *array, int *size)
{
	
	int i;
	
	for (i=0;i<*size;i++) {
		
		printf("#%2d = ", i+1);
		scanf("%d", &array[i]);
		
	}
}

void GetInteger(int *compare)
{
	
	int hold;
	
	printf("Enter the integer you would like to compare the array with: ");
	scanf("%d", &hold);
	
	*compare = hold;
	
}

void CompareArray(int *compare, int *array, int *less, int *more, int *size)
{
	
	int i;
	
	for (i=0;i<*size;i++) {
		
		if (array[i] > *compare) {
			
			*more = *more + 1;
			
		}
		else if (array[i] < *compare) {
			
			*less = *less + 1;
			
		}
		else {
			
			break;
			
		}
	}
	
}