#include <stdio.h>
#include <stdlib.h>



void print(int *array,int length) {
	for(int i = 0;i<length;i++) {
		printf("%4d",array[i] );
	}
	printf("\n\n");
}

int minInorder(int* array,int start,int end){
    int min = array[start];
    for(int i = start+1;i <= end;i++){
        if(array[i] < min){
            min = array[i];

        }
    }
    return min;
}
int minMumber(int* array,int length){
	if(array == NULL || length <= 0){
		return -1;
	}
	int start = 0;
	int end = length - 1;
	int middle = start;
	//考虑到旋转数字为0个
	if(array[start] < array[end]){
        return array[start];
	}
	while(end > (start+1)){
		middle = (start + end)/2;
		//考虑到三个值相等的情况
		if(array[start] == array[middle] && array[start] == array[end]){
            return minInorder(array,start,end);
		}
		if(array[middle] >= array[start] && array[middle] >= array[end]){
			start = middle;
		}
		if(array[middle] <= array[start] && array[middle] <= array[end]){
			end = middle;
		}
	}
	return array[end];

}


int main(int argc, char const *argv[])
{

	//int array[10] = {5,6,7,8,9,0,1,2,3,4};
	//print(array,10);
	int array[5] = {1,0,1,1,1};

	printf("%d\n",minMumber(array,5));

	return 0;
}
