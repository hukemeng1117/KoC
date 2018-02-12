#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
//行参
void swap(int a,int b) {
	int m = a;
	a = b;
	b = m;
}

void swap2(int* a,int* b) {
	int m = *a;
	*a = *b;
	*b = m;
}

#define NTOHL(x) (((x)&0x000000FF) << 24)|(((x)&0x0000FF00) << 8)|(((x)&0x00FF0000) >> 8)|(((x)&0xFF000000) >> 24)
#define NTOHS(x) (((x)&0x00FF)<<8)|(((x)&0xFF00)>>8)


//斐波纳西数列 递归
int fibFunc(int n) {
	if(n == 1) {
		return 1;
	}
	else if(n == 2) {
		return 2;
	}
	return fibFunc(n-1) + fibFunc(n-2);
}
//斐波纳西数列
int fibFunc2(int n) {
	if(n == 1) {
		return 1;
	}
	else if(n == 2) {
		return 2;
	}
	int a[100];
	a[0] = 1;
	a[1] = 2;
	for(int i = 3;i<=n;i++){
		a[i-1] = a[i-2] + a[i-3];
	}
	return a[n-1];
}

//将字符串转化为数字
bool strToInt(char* str,int* data) {
	//int* data
	// int a[1000];
	// int m = 0;
	// for(int i=0;i<strlen(str);i++){
	// 	a[i] = str[i] - '0';
	// 	m = a[i] * 10^(strlen(str)-i+1) + m;
	// }
	// *data = m;
	// return true;
	if(str == NULL || data == NULL ){
		return false;
	}
	int m = 0;
	int flag = '-' == str[0] ? 1 : 0;

	int max = 0x7FFFFFFF / 10;
	int extra = 0x7FFFFFFF % 10;

	for(int i = flag;i<strlen(str);i++){
		if(str[i]<='9' && str[i]>='0'){
			if(m > max) {
				return false;
			}
			if(m == max) {
				if(str[i] - '0' > extra){
					return false;
				}
			}
			m = (str[i]-'0')+ m*10;
		}else{
			return false;
		}
	}

	*data = flag == 0 ? m : -m;
	// if (t == 0){
	// 	*data = m ;
	// }else{
	// 	*data = -m;
	// }	
	return true;
}

//int转字符串
bool intToStr(int n,char* str){
	int a[10];
	int count = 0;
	for(int i = 0;i < 10;i++){
		a[i] = n % 10;
		n = n/10;
		if(n == 0){
			count = i + 1;
			break;
		}
	}
	// strncpy(str,char(a[count-1]),1);
	for(int i = 0;i < count;i++){
		// strcat(str,char(a[count-1-i]));
		str[i] = a[count-1-i] + '0';
	}
	str[count] = '\0';
	return true;
}


//字符串求和
bool sum2(char* str,int* data){
	if(str == NULL || data == NULL ){
		return false;
	}
	int m = 0;
	*data = 0;
	int count = 0;
	for(int i = 0;i<strlen(str);i++){
		if(str[i] == '+' || str[i] == '-'){
			*data = *data + m;
			break;
		}else{
			m = (str[i]-'0')+ m*10;
		}
		count ++;
	}
	if(count == strlen(str)){
		*data = m;
	}
	int flag = 0;
	for(int i = count - 1;i<strlen(str);i++){
		if(str[i] == '+'){
			m = 0;
			flag = 1;
		}else if(str[i] == '-'){
			m = 0;
			flag = -1;
		}else if(str[i]<='9' && str[i]>='0'){
			m = (str[i]-'0')+ m*10;
			if(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '\0'){
				*data = *data + flag * m;
			}
		}
	}	
	return true;
}

int main(int argc, char const *argv[])
{
	int a = 3;
	int b = 4;
	swap(a,b);
	printf("%d %d\n",a,b );
	swap2(&a,&b);
	printf("%d %d\n",a,b );

	int c = 0x12345678;
	printf("%x %x\n",c,NTOHL(c));

	int d = 0x1234;
	printf("%x %x\n",d,NTOHS(d));

	for(int i = 1;i<10;i++) {
		printf("%d ", fibFunc(i));
	}
	for(int i = 1;i<10;i++) {
		printf("%d ", fibFunc2(i));
	}
	int intMax = 0x7FFFFFFF;
	int intMin = 0x80000000;
	printf("%d %d \n", intMax,intMin);
 
 	char* str = "48";
 	int data = 8767;
 	strToInt(str,&data);
	//strToInt(str,int* data);
	printf("%d\n",data);

	int n = 534642645;
	char* str3 = (char*)malloc(15);
	intToStr(n,str3);
	printf("%s\n",str3);



	char* str2 = "12+3+23+3";
	int data2 = 8767;
	sum2(str2,&data2);
	printf("%d\n",data2 );

	char s_1_27[] = "12345";
	char *s_1_27_2 = "12345";
	printf("%d %d\n",strlen(s_1_27), strlen(s_1_27_2));
	return 0;


}