#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LeftRevolve(char arr[], int len, int k){
	//1.首先将字符串的第一个元素保存下来
	
	int j = 0;
	while (j < k){
		char tem = arr[0];
		int i;
		//2.利用循环将字符串中的其他元素整体向前移动
		for (i = 0; i < len - 1; ++i){
			arr[i] = arr[i + 1];
		}
		//3.将保存下来的第一个元素放到字符串的后面
		if (i == len - 1){
			arr[len - 1] = tem;
		}
		//利用递归实现k次
		++j;
	}
	
}


int main(){
	char arr[10] = "ABCDE";
	int len = strlen(arr);
	int k = 0;
	printf("请输入您要左旋的字符个数:");
	scanf("%d", &k);
	LeftRevolve(arr, len, k);
	printf("%s\n", arr);
	system("pause");
	return 0;
}



