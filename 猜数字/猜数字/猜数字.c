#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int mean(){
	printf("================================================\n");
	printf("                      1.��ʼ��Ϸ                \n");
	printf("                      0.�˳���Ϸ                \n");
	printf("================================================\n");
	int choice = 0;
	printf("���������ѡ��:");
	scanf("%d", &choice);
	return choice;
}
void Game(){
	//����srand()�����Լ�time()��������ȡ�����
	srand(time(0));
	//�����ϵͳ���һ��100���ڵ�����
	int num1 = rand() % 100;
	while (1){
		int num2 = 0;
		//��ʾ�û�����һ��ֵ
		printf("��������һ������(0-100):");
		scanf("%d", &num2);
		//����if���������û�����������ж�
		if (num1 < num2){
			printf("����\n");
		}
		else if (num1>num2){
			printf("����\n");
		}
		else {
			printf("��ϲ��!�¶���!����Ϊ%d\n", num1);
			break;
		}
	}
}
int main(){
	while (1){
		int choice = mean();
		if (choice == 0){
			break;
		}
		else if (choice == 1){
			Game();
		}
	}
	system("pause");
	return 0;
}