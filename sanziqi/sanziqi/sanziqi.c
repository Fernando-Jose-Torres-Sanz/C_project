#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char g_sanziqi[ROW][COL];
//三子棋游戏
//电脑落子

//棋盘的初始化
void  Init(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_sanziqi[row][col] = ' ';
		}
	}
  }

//打印棋盘
void ChessBoard(){
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n", g_sanziqi[row][0], 
			g_sanziqi[row][1], g_sanziqi[row][2]);
		if (row != ROW - 1){
			printf("|---|---|---|\n");
		}
	}
}

//玩家落子
void Plar_move(){
	//1.提示玩家落子(输入棋盘上的一个坐标)
	while (1){
		printf("请您输入一个坐标:");
		//2.读取玩家的输入
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//3.检验玩家的输入是否合法
		//第一种情况为玩家输入的坐标太大或最太小
		if (row<0 || row >= ROW||col < 0 || col >= COL){
			printf("您的输入非法!!!请重新输入!!\n");
			continue;
		}
		//第二种情况为玩家所输入的坐标已经有子
		if (g_sanziqi[row][col] != ' '){
			printf("您输入的位置已经有子!!请重新输入!!\n");
			continue;
		}
		//4.如果玩家输入的合法,则将对应的坐标视为'x'
		if (g_sanziqi[row][col] == ' '){
			g_sanziqi[row][col] = 'x';
			break;
		}
	}
}

int Heqi(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < ROW; ++col){
			if (g_sanziqi[row][col] != ' '){
				return 0;
			}
		}
	}
	return 1;
}

//判断谁是赢家
char Checkwineer(){
	//判断是否取胜
    //1.检查行是否连在一起
	for (int row = 0; row < ROW; ++row){
		if (g_sanziqi[row][0] == g_sanziqi[row][1] &&
			g_sanziqi[row][1] == g_sanziqi[row][2]
			&& g_sanziqi[row][0] != ' '){
			return g_sanziqi[row][0];
		}
	}
    //2.检查列是否连在一起
	for (int col = 0; col < COL; ++col){
		if (g_sanziqi[0][col] == g_sanziqi[1][col] &&
			g_sanziqi[1][col] == g_sanziqi[2][col]
			&& g_sanziqi[0][col] != ' '){
			return g_sanziqi[1][col];
		}
	}
    //3.检查两条对角线是否连在一起
	if (g_sanziqi[0][0] == g_sanziqi[1][1]
		&& g_sanziqi[1][1] == g_sanziqi[2][2]
		&& g_sanziqi[1][1] != ' '){
		return g_sanziqi[0][0];
	}
	if (g_sanziqi[2][0] == g_sanziqi[1][1]
		&& g_sanziqi[1][1] == g_sanziqi[2][0] 
		&& g_sanziqi[1][1] != ' '){
		return g_sanziqi[2][0];
	}
	if (Heqi()){
		return 'q';
	}
	else {
		return ' ';
	}
}

void Computer_move(){
	//1.提示请电脑随机落子
	printf("请电脑随机落子:\n");
	srand(time(0));
	//2.从系统随机获得一个数字
	while (1){
		int row = -1;
		int col = -1;
		row = rand() % ROW;
		col = rand() % COL;
		//3.判断获得的数字坐标是否已经有子
		if (g_sanziqi[row][col] == ' '){
			g_sanziqi[row][col] = 'o';
			break;
		}
	}
}

//1.定义一个二维数字用来表示棋盘
//2.需要对棋盘进行初始化(首先将棋盘中都放入空格)
//玩家的子用x表示,电脑的子用o表示,倘若和气的话就用q表示

//5.电脑落子,顺便检验游戏是否结束
int main(){
	char wineer = ' ';
	//游戏的入口
	Init();
	while (1){
		//3.将棋盘打印出
		ChessBoard();
		//4.玩家落子,顺便检验游戏是否结束
		Plar_move();
		wineer = Checkwineer();
		if (wineer != ' '){
			break;
		}
		Computer_move();
		wineer = Checkwineer();
		if (wineer != ' '){
			break;
		}

		if (wineer == 'x'){
			printf("玩家获胜\n");
		}
		else if (wineer == 'o'){
			printf("电脑获胜\n");
		}
		else if (wineer == 'q'){
			printf("平局\n");
		}
	}
	system("pause");
	return 0;

}