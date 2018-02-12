#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_a = 10;

void func1() {
	g_a = 11;
}

void func2() {
	g_a = 12;
}

void func3() {
	static int a = 10;
	printf("%d\n",a);
	a += 10;
}

int main() {
	// 栈 
	int a = 10;
	int b = 11;
	char p1[100] = "12345";
	printf("%p %p\n",p1,&p1[0]);
	p1[1] = '5';
	printf("%s\n",p1);

	// 堆
	char* p2 = (char*)malloc(100);
	printf("%p \n",p2);
	p2[0] = '1';
	p2[1] = '5';
	p2[2] = '7';
	p2[3] = '5';
	printf("%s \n",p2);
	// free(p);
	//常量区
	char* p3 = "12345678";

	char* temp = (char*)malloc(strlen(p3));
	memcpy(temp,p3,strlen(p3));
	p3 = temp;
	p3[0]='2';

	char* p4 = "12345678";
	printf("%s %p\n", p3,p3);
	printf("%s %p\n", p4,p4);

	//全局
	printf("%d\n", g_a);
	func1();
	printf("%d\n", g_a);
	func2();
	printf("%d\n", g_a);

	//静态区
	func3();
	func3();
	func3();

	int i = 1;
	{
		int i = 2;
		int g_a = 10000;
		printf("%d %d\n",i,g_a);
	}
	printf("%d %d \n",i,g_a);
}