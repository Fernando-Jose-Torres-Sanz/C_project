#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char g_sanziqi[ROW][COL];
//��������Ϸ
//��������

//���̵ĳ�ʼ��
void  Init(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_sanziqi[row][col] = ' ';
		}
	}
  }

//��ӡ����
void ChessBoard(){
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n", g_sanziqi[row][0], 
			g_sanziqi[row][1], g_sanziqi[row][2]);
		if (row != ROW - 1){
			printf("|---|---|---|\n");
		}
	}
}

//�������
void Plar_move(){
	//1.��ʾ�������(���������ϵ�һ������)
	while (1){
		printf("��������һ������:");
		//2.��ȡ��ҵ�����
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//3.������ҵ������Ƿ�Ϸ�
		//��һ�����Ϊ������������̫�����̫С
		if (row<0 || row >= ROW||col < 0 || col >= COL){
			printf("��������Ƿ�!!!����������!!\n");
			continue;
		}
		//�ڶ������Ϊ���������������Ѿ�����
		if (g_sanziqi[row][col] != ' '){
			printf("�������λ���Ѿ�����!!����������!!\n");
			continue;
		}
		//4.����������ĺϷ�,�򽫶�Ӧ��������Ϊ'x'
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

//�ж�˭��Ӯ��
char Checkwineer(){
	//�ж��Ƿ�ȡʤ
    //1.������Ƿ�����һ��
	for (int row = 0; row < ROW; ++row){
		if (g_sanziqi[row][0] == g_sanziqi[row][1] &&
			g_sanziqi[row][1] == g_sanziqi[row][2]
			&& g_sanziqi[row][0] != ' '){
			return g_sanziqi[row][0];
		}
	}
    //2.������Ƿ�����һ��
	for (int col = 0; col < COL; ++col){
		if (g_sanziqi[0][col] == g_sanziqi[1][col] &&
			g_sanziqi[1][col] == g_sanziqi[2][col]
			&& g_sanziqi[0][col] != ' '){
			return g_sanziqi[1][col];
		}
	}
    //3.��������Խ����Ƿ�����һ��
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
	//1.��ʾ������������
	printf("������������:\n");
	srand(time(0));
	//2.��ϵͳ������һ������
	while (1){
		int row = -1;
		int col = -1;
		row = rand() % ROW;
		col = rand() % COL;
		//3.�жϻ�õ����������Ƿ��Ѿ�����
		if (g_sanziqi[row][col] == ' '){
			g_sanziqi[row][col] = 'o';
			break;
		}
	}
}

//1.����һ����ά����������ʾ����
//2.��Ҫ�����̽��г�ʼ��(���Ƚ������ж�����ո�)
//��ҵ�����x��ʾ,���Ե�����o��ʾ,���������Ļ�����q��ʾ

//5.��������,˳�������Ϸ�Ƿ����
int main(){
	char wineer = ' ';
	//��Ϸ�����
	Init();
	while (1){
		//3.�����̴�ӡ��
		ChessBoard();
		//4.�������,˳�������Ϸ�Ƿ����
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
			printf("��һ�ʤ\n");
		}
		else if (wineer == 'o'){
			printf("���Ի�ʤ\n");
		}
		else if (wineer == 'q'){
			printf("ƽ��\n");
		}
	}
	system("pause");
	return 0;

}