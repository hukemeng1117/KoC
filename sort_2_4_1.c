#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void randArray(int *array,int length) {
	for(int i = 0;i<length;i++) {
		array[i] = rand() % 100;
	}
}

void print(int *array,int length) {
	for(int i = 0;i<length;i++) {
		printf("%4d",array[i] );
	}
	printf("\n\n");
}



void sortAge(int* testArray,int length){	
	int temp = 0;
	int array[100];
	for(int i =0;i < 100;i++){
		array[i] = 0;
	}

	for(int i = 0;i < length;i++){
		if(testArray[i] < 0  || testArray[i] >= 100){		
			return;
		}
		temp = testArray[i];
		array[temp] = array[temp] + 1;
	}
	int index = 0;
	for(int i = 0;i < 100;i++){
		while(array[i] != 0){
			testArray[index++] = i;
			array[i]--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int testArray[1000];
	randArray(testArray,1000);

	print(testArray,1000);

	

	sortAge(testArray,1000);
	print(testArray,1000);

	return 0;
}