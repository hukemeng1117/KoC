#include <stdio.h>
int main() {
	char c[4] = {1,2,3,4};
	printf("%p %p %p %p\n",&c[0],&c[1],&c[2],&c[3]);
	int *d = c;
	printf("%x\n",*d);
}