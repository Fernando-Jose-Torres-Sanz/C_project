#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LeftRevolve(char arr[], int len, int k){
	//1.���Ƚ��ַ����ĵ�һ��Ԫ�ر�������
	
	int j = 0;
	while (j < k){
		char tem = arr[0];
		int i;
		//2.����ѭ�����ַ����е�����Ԫ��������ǰ�ƶ�
		for (i = 0; i < len - 1; ++i){
			arr[i] = arr[i + 1];
		}
		//3.�����������ĵ�һ��Ԫ�طŵ��ַ����ĺ���
		if (i == len - 1){
			arr[len - 1] = tem;
		}
		//���õݹ�ʵ��k��
		++j;
	}
	
}


int main(){
	char arr[10] = "ABCDE";
	int len = strlen(arr);
	int k = 0;
	printf("��������Ҫ�������ַ�����:");
	scanf("%d", &k);
	LeftRevolve(arr, len, k);
	printf("%s\n", arr);
	system("pause");
	return 0;
}



