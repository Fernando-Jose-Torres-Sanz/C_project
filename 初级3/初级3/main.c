//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
#include<stdio.h>
#include<stdlib.h>
int Nnmnine(int n){
	if (n > 0 && n < 9){
		return 0;
	}
	if (n == 9){
		return 1;
	}
	if ((n >= 10&&n<99)&&((n%10==9)||(n%10)/10==9)){
		return 1;
	}
}
//void Exchange(int* arr1[],int* arr2[],int len){
//	int t;
//	for (int i = 0; i < len; ++i){
//		t = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = t;
//	}
//	for (int i = 0; i < len; ++i){
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < len; ++i){
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//}

int main(){
	int sum = 0;
	for (int i = 1; i < 101; ++i){
		
		if (Nnmnine(i)){
			++sum;
		}
	}
	printf("9�ĸ����ܹ���:%d\n", sum);
	/*double sum = 0;
	for (int n = 1; n <= 100; ++n){
		if (n % 2 == 1){
			sum = sum + (1.0 / n);
		}
		else{
			sum = sum - (1.0 / n);
		}
	}
	printf("sum=%f \n", sum);*/
	/*int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[] = { 7, 6, 5, 4, 3, 2, 1 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	Exchange(arr1, arr2, len);*/
	system("pause");
	return 0;
}