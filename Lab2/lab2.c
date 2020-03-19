//Ryan Christopher
//Pawprint: rdcb2f
//Lab 2
//Date: Jan 30, 2020

#include<stdlib.h>
#include<stdio.h>

//Prototype Functions
void computeSumAverage(float arr[], int size, float *sumPtr, float *avePtr);

//Main Function
int main(void)
{
	
	    float array[15] = {-3.8,10.6,-7.4,-8.8,12.2,13.4,1.6,-10.1,-3.8,7.5,4.3,-5.8,-9.1,11.6,1.8};
		int size = sizeof(array)/sizeof(array[0]);
		float sum = 0;
		float ave = 0;
		
		computeSumAverage(array, size, &sum, &ave);
		
		printf("Sum of the array is %.1f, average of all positive numbers is %.3f", sum, ave);
		
		return 0;
		
}

void computeSumAverage(float arr[], int size, float *sumPtr, float *avePtr)
{
	
	int i;
	int poscount = 0;
	float postotal = 0;
	
	for (i=0;i<size;i++) {
		*sumPtr = *sumPtr + arr[i];
		
		if(arr[i]>0) {
			poscount++;
			postotal = postotal + arr[i];
		}
	}
	
	*avePtr = postotal/poscount;
	
}