#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void print(int *a,int length){
	for(int i = 0;i < length;i++){
		printf("%4d ",a[i]);
	}
}

void pushVector(int *a,int* length,int data){
	static int i = 0;
	if(i < *length){
		a[i] = data;
		i++;
	}else{
		*length = *length * 2;
		a = (int*)alloc(*length);
	}
	
}

int main(int argc, char const *argv[])
{
	int *a = (int*)malloc(32);
	int length = 32;
	for(int i = 0;i < length;i++){
		a[i] = 1;
	}
	int i = 0;
	int n;
	scanf("%d",&n);
	while(n--){
		int data;
		scanf("%d",&data);
		pushVector(a,&length,data);
	}

	print(a,length);
	printf("%d\n",length);

	return 0;
}