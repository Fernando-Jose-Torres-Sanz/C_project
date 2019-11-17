#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int mean(){
	printf("================================================\n");
	printf("                      1.开始游戏                \n");
	printf("                      0.退出游戏                \n");
	printf("================================================\n");
	int choice = 0;
	printf("请输入你的选择:");
	scanf("%d", &choice);
	return choice;
}
void Game(){
	//利用srand()函数以及time()函数来获取随机数
	srand(time(0));
	//随机从系统获得一个100以内的数字
	int num1 = rand() % 100;
	while (1){
		int num2 = 0;
		//提示用户输入一个值
		printf("请您输入一个数字(0-100):");
		scanf("%d", &num2);
		//利用if条件语句对用户的输入进行判定
		if (num1 < num2){
			printf("高了\n");
		}
		else if (num1>num2){
			printf("低了\n");
		}
		else {
			printf("恭喜你!猜对了!数字为%d\n", num1);
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