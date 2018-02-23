#include <stdio.h>
#include <stdlib.h>

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

void swap(int *a,int *b){
	int m = *a;
	*a = *b;
	*b = m;
}


void reorderOddEven(int* pData,int length){
	int begin = 0;
	int end = length - 1;
	while(begin <= end){
		while((begin <= end) && (pData[begin] % 2 == 1)){
			begin++;
		}
		while((begin <= end) && (pData[end] % 2 == 0)){
			end--;
		}
		swap(&pData[begin],&pData[end]);
	}
}

int main(int argc, char const *argv[])
{
	int pData[100];
	randArray(pData,100);
	print(pData,100);
	printf("%s\n","");

	reorderOddEven(pData,100);
	print(pData,100);

	return 0;
}