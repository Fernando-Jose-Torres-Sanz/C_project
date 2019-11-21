#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int count_one_bits(unsigned int value){
//	int count = 0;
//	while (value){
//		if (value % 2 == 1){
//			++count;
//			value =value >>  1;
//		}
//	}
//	return count;
//}
//
//int main(){
//	int num = 0;
//	int count = 0;
//	printf("请输入一个数:");
//	scanf("%d", &num);
//	count = count_one_bits(num);
//	printf("1的个数为:%d\n", count);
//	system("pause");
//	return 0;
//}

// /*void Gainerjinzhi(unsigned num){
//	int count = 0;
//	int arr[1024] = { 0 };
//	int i = 0;
//	while (num){
//		arr[i++] = num % 2;
//		num = num / 2;
//		++count;
//	}
//	printf("奇数序列为:\n");
//	for ( i = count; i >= 0; i -= 2){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("偶数序列为:\n");
//	for (i = count - 1; i >= 0; i -= 2) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//}*/

void Ptintnum(int num){
	if (num > 9){
		Ptintnum(num / 10);
	}
	printf("%d  ", num % 10);
}


int main(){
	int num = 0;
	printf("input:");
	scanf("%d", &num);
	Ptintnum(num);
	system("pause");
	return 0;
}


