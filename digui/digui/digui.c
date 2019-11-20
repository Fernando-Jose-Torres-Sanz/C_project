#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//递归的形式实现斐波那契数列
int Fub_digui(int n){
	if (n == 1 || n == 2){
		return 1;
	}

	return Fub_digui(n - 1) + Fub_digui(n - 2);
}

int main(){
	int n;
	Fub_digui(n);
	system("pause");
	return 0;
}
//非递归的形式实现斐波那契数列
//int Fub(int n){
//	int f1 = 1;
//	int f2 = 1;
//	if (n == 1 || n == 2){
//		return 1;
//	}
//	int ret = 0;
//	for (int i = 3; i <= n; ++i){
//		ret = f1 + f2;
//		f1 = f2;
//		f2 = ret;
//	}
//	return ret;
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	printf("%d:%d\n", n, Fub(n));
//	system("pause");
//	return 0;
//}
//递归求N的K次方
//int Cifang(int n,int k){
//	if (k == 0){
//		return 1;
//	}
//	else if (k == 1){
//		return n;
//	}
//	else {
//		return n * Cifang(n, k - 1);
//	}
//}
//int main(){
//	int n = 0;
//	int k = 0;
//	printf("请输入底数n:");
//	scanf("%d", &n);
//	printf("请输入指数k:");
//	scanf("%d", &k);
//	int ret = Cifang(n, k);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//// 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
////1729--->1729%10+f(172)-->1729%10+172%10+f(17)--->1729%10+172%10+17%10+f(1)--->1729%10+172%10+17%10+1
//
//int DigitSum(n){
//	if (n < 10){
//		return n;
//	}
//	else {
//		return n % 10 + DigitSum(n / 10);
//	}
//}


//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

//递归实现stelen
//int Strlen(char *str){
//	//出口为\0的时候
//	if (*str){
//		return 1 + Strlen(str + 1);
//	}
//	return 0;
//}
//
//int main(){
//	char *str = "1234567";
//	int count = Strlen(str);
//	printf("%d", count);
//	system("pause");
//	return 0;
//}

//n的阶乘
//int Jiecheng(int n){
//	int ret = 1;
//	for (int i = n; i > 0; i--){
//		ret = ret * i;
//    }
//	return ret;
//}
//
//
//int main(){
//	int ret;
//	ret = Jiecheng(6);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}
//递归形式
//int Jiecheng(int n){
//	if (n < 1){
//		return 1;
//	}
//	return n * Jiecheng(n - 1);
//
//}
//
//int main(){
//	int ret;
//	ret = Jiecheng(5);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}
