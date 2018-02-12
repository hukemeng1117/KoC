#include <stdio.h>
#include <string.h>

//39 水仙花数
//描述
// 请判断一个数是不是水仙花数。
// 其中水仙花数定义各个位数立方和等于它本身的三位数。
// 输入
// 有多组测试数据，每组测试数据以包含一个整数n(100<=n<1000)
// 输入0表示程序输入结束。
// 输出
// 如果n是水仙花数就输出Yes
// 否则输出No

void flower(int m){
	int mm = m;
	if(m > 99 && m < 1000) {
		int extra = m % 10;
		m = m / 10;
		int temp = 0;
		while(m != 0){
			temp = temp + (extra * extra * extra);
			extra = m % 10;
			m = m / 10;
		}
		temp = temp + (extra * extra * extra);
		if(temp == mm){
			printf("%s\n","Yes");
		}else{
			printf("%s\n","No");
		}
	}
}
// int main()
// {
// int n;
// while(scanf("%d",&n))
// {
// int a,b,c;
// if(n==0)
// break;
// if(100>n||n>1000)
// break;
// if(n>=100&&n<=1000)
// {
// a=n%10;//gewei
// b=n%100/10;//shiwei
// c=n/100;//baiwei
// if(n==a*a*a+b*b*b+c*c*c)
// printf("Yes
// ");
// if(n!=a*a*a+b*b*b+c*c*c)
// printf("No
// ");
// }
// }
// }//这样做简单

//02 括号配对问题
//描述
// 现在，有一行括号序列，请你检查这行括号是否配对。
// 输入
// 第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[", "]", "(", ")" 四种字符
// 输出
// 每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No

// void pair(char *str){
// 	int a[100];
// 	int aa = 0;
// 	printf("%d\n", aa);
// 	for(int i=0;i<strlen(str);i++){
// 		switch(str[i]){
// 			case '[':
// 				a[aa++] = 1;
// 				break;
// 			case ']':
// 				a[aa++] = -1;
// 				break;
// 			case '(':
// 				a[aa++] = 2;
// 				break;
// 			case ')':
// 				a[aa++] = -2;
// 				break;
// 			default:
// 			break;
// 		}
// 		printf("%d\n", aa);
// 		while(a[aa] == a[aa-1]){
// 			a[aa] = 0;
// 			a[aa-1] = 0;
// 			aa = aa-2;				
// 		}
// 	}
// 	int sum = 0;
// 	for(int i=0;;i++){
// 		sum = sum +a[i];
// 		printf("%d\n",sum);
// 	}
// 	if(sum == 0){
// 			printf("%s\n","Yes");
// 		}else{
// 			printf("%s\n","No");
// 		}

// }

//33蛇形填数
// 描述
// 在n*n方陈里填入1,2,...,n*n,要求填成蛇形。例如n=4时方陈为：
// 10 11 12 1
// 9 16 13 2
// 8 15 14 3
// 7 6 5 4
// 输入
// 直接输入方陈的维数，即n的值。(n<=100)
// 输出
// 输出结果是蛇形方陈。

// void square(int a[100][100],int n,int begin){
// 	int temp = n;
// 	int m = 
// 	for(int i=0;i<n;i++){
// 		a[n-m][i] = begin+i;
// 		a[i][n-m] = begin+2*n+i+2;
// 		a[m][i] = begin+3*n+i+3;
// 		a[i][m] = begin+3*n-3+i;
// 	}
// 	m++;
// 	if(n>2){
// 		square(a[100][100],(n-2),(begin+4*(n-1)));
// 	}
// }

//37 回文字符串
// 描述
// 所谓回文字符串，就是一个字符串，从左到右读和从右到左读是完全一样的，比如"aba"。当然，我们给你的问题不会再简单到判断一个字符串是不是回文字符串。现在要求你，给你一个字符串，可在任意位置添加字符，最少再添加几个字符，可以使这个字符串成为回文字符串。
// 输入
// 第一行给出整数N（0<N<100）
// 接下来的N行，每行一个字符串，每个字符串长度不超过1000.
// 输出
// 每行输出所需添加的最少字符数

//40 公约数和公倍数
//描述
// 小明被一个问题给难住了，现在需要你帮帮忙。问题是：给出两个正整数，求出它们的最大公约数和最小公倍数。
// 输入
// 第一行输入一个整数n（0<n<=10000)，表示有n组测试数据;
// 随后的n行输入两个整数i,j（0<i,j<=32767)。
// 输出
// 输出每组测试数据的最大公约数和最小公倍数

//方法1:辗转相除求最大公约数
// 1.a÷b，令r为所得余数（0≤r＜b）。若r=0，算法结束；b即为答案。
// 2.互换：置a←b，b←r，并返回第一步。

void gcd(int a,int b){
	int r = a % b;
	if(r == 0){
		printf("%d\n",r );
	}else{
		a = b;
		b = r;
		gcd(a,b);
	}
}




//1的个数
// 描述
// 小南刚学了二进制，他想知道一个数的二进制表示中有多少个1，你能帮他写一个程序来完成这个任务吗？
// 输入
// 第一行输入一个整数N，表示测试数据的组数(1<N<1000)
// 每组测试数据只有一行，是一个整数M(0=<M<=10000)
// 输出
// 每组测试输出占一行，输出M的二进制表示中1的个数

int main(int argc, char const *argv[])
{
	int m;
	while(scanf("%d",&m)) {
		flower(m);
	}

	//pair("(");

	// int n;
	// int a[100][100];
	// square(a[][],scanf("%d",&n),1);
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		printf("%d\n", a[i][j]);
	// 	}
	// 	printf("%s\n\n");
	// }

	gcd(5,5);


	return 0;
}

