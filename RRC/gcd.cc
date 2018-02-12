#include <stdio.h>


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

//方法2:更相减损数求最大公约数
// (24,15)->(9,15)->(9,6)->(3,6)->(3,3)

//最小公倍数=两整数的乘积÷最大公约数

//辗转相除法--递归

int gcd(int a,int b)
{
    if(b==0)
       return a;
    else
       return gcd(b,a%b);
}

//辗转相除法--纯循环

int gcd2(int a,int b)
{
    int r;
    while(b!=0)
    {
       r=a%b;
       a=b;
       b=r;
    }
    return a;
}


int gcd3(int a,int b){
	while(a != b){
		if(a > b){
			a = a-b;
		}else{
			b = b-a;
		}
	}
	return a;
}

int mul(int a,int b){
	return a*b/gcd(a,b);
}

int main(int argc, char const *argv[])
{
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&i,&j);
		printf("%d\n",gcd(i,j));
		printf("%d\n",mul(i,j));
	}
	return 0;
}