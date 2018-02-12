#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void printQuickSort(int *array,int start,int end) {
	for(int i = start;i<end;i++) {
		printf("%4d\n", array[i]);
	}
	printf("\n\n");
}

void swap(int *a,int *b){
	int m = *a;
	*a = *b;
	*b = m;
}

void normalSort(int *array,int length) {
	for(int i = 0;i < length;i++){
		for(int j = 0;j <= i;j++){
			if(array[j] > array[i]){
				swap(&array[j],&array[i]);
			}
		}
	}
}

void selectSort(int *array,int length) {
	int mix;
	for(int i = 0;i < length;i++){
		mix = i;
		for(int j = i;j < length;j++){
			if(array[mix] > array[j]){
				mix = j;
			}
		}
		swap(&array[mix],&array[i]);
	}
}

void insertSort(int *array,int length){
	for(int i = 1;i < length;i++){
		int cur = i;
		while(cur && array[cur] < array[cur-1]) {
			swap(&array[cur],&array[cur-1]);
			cur--;
		}
	}
}

void shellSort(int *array,int length) {
	int cur = 1;
	while(cur < length) {
		cur = cur * 3 + 1;
	}
	cur /= 3;

	while(cur) {
		for(int i = cur;i < length; i += cur) {
			int j = i;
			while(j-cur >= 0 && array[j] < array[j - cur]) {
				swap(&array[j],&array[j - cur]);
				j -= cur;
			}
		}
		printf("%d\n",cur );
		cur /= 3;
	}
}

void quickSort(int *array,int start,int end) {
	if(start >= end) {
		return;
	}
	int i = start + 1;
	int j = end;
	
	while(1) {
		while(array[i] <= array[start] && i < j) {
			i++;
		}

		while(array[j] > array[start] && j > i) {
			j--;
		}

		if(i < j) {
			swap(&array[i],&array[j]);
		} else {
			if(array[i] > array[start])
				i -= 1;
			swap(&array[i],&array[start]);
			break;
		}
	}
	quickSort(array,start,i-1);
	quickSort(array,i+1,end);
}

void mergeSort(int *array,int length) {
	if(length < 5) {
		insertSort(array,length);
		return;
	}

	int iLength = length / 2;
	int jLength = iLength + length % 2;
	mergeSort(array,iLength);
	mergeSort(array + iLength,jLength);

	int* tempArray = (int*)malloc(sizeof(int) * length);
	int index = 0;
	int i = 0,j = iLength;

	while(index < length) {
		if(i<iLength && j<length ) {
			if(array[i] <= array[j]) {
				tempArray[index++] = array[i];
				i ++;
			} else {
				tempArray[index++] = array[j];
				j ++;
			}
		} else if(i < iLength) {
			tempArray[index++] = array[i++];
		} else if(j < length) {
			tempArray[index++] = array[j++];
		} else {
			break;
		}
	}

	memcpy(array,tempArray,sizeof(int) * length);
}

void HeapSort(int *array,int length){
	int temp = 0;
	for(int i = length-1;i >= 0;i--){
		for(int j = i;j >= 0;j--){
			temp = j/2;
			if(array[temp] < array[j]){
				swap(&array[temp],&array[j]);
			}
		}
		swap(&array[i],&array[0]);
	}
}

int main() {
	int a[100];
	randArray(a,100);
	print(a,100);

	// normalSort(a,100);
	// print(a,100);

	// selectSort(a,100);
	// print(a,100);

	// insertSort(a,100);
	// print(a,100);

	// shellSort(a,100);
	// print(a,100);

	// quickSort(a,0,99);
	// print(a,100);

	// mergeSort(a,100);
	// print(a,100);

	HeapSort(a,100);
	print(a,100);



	return 0;
}