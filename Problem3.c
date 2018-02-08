#include <stdio.h>

#define bool int
#define true 1
#define false 0

// bool numberFind(int* a,int findNumber,int rows,int columns){
// 	static int rowBegin = 0;

// 	static int column = 1;
// 	if(a == NULL || columns <= 0 || rows <= 0 || rowBegin >=rows){
// 		return false;
// 	}
	
// 	printf("%4d%4d\n",rowBegin,column);
// 	printf("%4d%4d\n",a[rowBegin,column],findNumber);
// 	if(a[rowBegin,column] == findNumber){
// 		printf("%d\n",a[rowBegin,column]);
// 		return true;
// 	}
	
// 	if(a[rowBegin,column] > findNumber){
// 		column--;
// 		numberFind(a,findNumber,columns,rows);
// 	}
// 	if(a[rowBegin,column] < findNumber){
// 		rowBegin++;
// 		numberFind(a,findNumber,columns,rows);
// 	}
// }

bool numberFind(int a[][5],int findNumber,int rows,int columns) {
	if(a == NULL || columns <= 0 || rows <= 0){
		return false;
	}
	int i = 0;
	int j = columns-1;
	while(1) {

		while(j>=0 && a[i][j] > findNumber) {
			j--;
		}

		if(j == -1) {
			return false;
		}

		while(i<rows && a[i][j] < findNumber) {
			i++;
		}

		if(i == rows) {
			return false;
		}

		if(a[i][j] == findNumber) {
			return true;
		}
	}
}



int main(int argc, char const *argv[])
{
	int array[2][5] = {{1,2,3,6,9},{3,8,9,11,12}};
	printf("%d\n",array[1][1]);
	printf("%d\n",numberFind(array,7,2,5));
	return 0;
}