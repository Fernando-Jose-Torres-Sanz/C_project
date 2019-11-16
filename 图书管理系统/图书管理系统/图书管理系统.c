#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
	//�鼮���
	int id;
	//�鼮����
	char name[31];
	//�鼮����
	char author[27];
	//�鼮������
	char publish[31];
	//�鼮��ͼ������е�����
	int store;
	//�鼮��������
	int total;
	//�����ߵĽ���֤���
	int usr[10];
	//���ĵĽ�ֹ����
	int days[10];
};
struct Book Books[100];
 //��ӡ�˵�
void mena(){
	printf("\n--����ѡ��--\n\n");
	printf("����������ѡ����Ҫ��������Ŀ\n");
	printf("\n\n\t\t\t\t 1.ע������\t\t\t\t2.��ʾͼ��\n");
	printf("\n\n\t\t\t\t 3.��ѯͼ����Ϣ\t\t\t\t4.�޸�ͼ����Ϣ\n");
	printf("\n\n\t\t\t\t 5.ɾ��ͼ��\t\t\t\t6.����ͼ��\n");
	printf("\n\n\t\t\t\t 7.�黹ͼ��\t\t\t\t8.�˳�ϵͳ\n");
	printf("\n\n�밴���ֽ���ѡ�� : \n");
}


void return_confirm(){
	printf("\n***************�����������********************\n");
	getchar();
}

//ע������
void book_add(){
	int i = 0;
	for (; i < 100; i++){
		if (Books[i].id == 0)
			break;
	}
		system("cls");
		printf("\n***************ע������*********************\n\n");
		printf("�鼮��� : ");
		scanf("%d", &Books[i].id);
		printf("�鼮���� : ");
		scanf("%s", &Books[i].name);
		printf("�鼮���� : ");
		scanf("%s", &Books[i].author);
		printf("�鼮������ : ");
		scanf("%s", &Books[i].publish);
		printf("���� : ");
		scanf("%d", &Books[i].total);
		Books[i].store = Books[i].total;
		FILE* fp;
		fp = fopen("book", "wb");
		if (fp == NULL)
			printf("���ļ�����\n");
		fwrite(Books, sizeof(Books[100]), sizeof(Books[100]), fp);
		return_confirm();
		system("cls");
}
//��ʾͼ����Ϣ
int book_show(){
	int i = 0; 
	int flag = 0;
	system("cls");
	printf("\n*****************��ʾͼ����Ϣ*********************\n\n");
	for (; i < 100; i++){
		if (strlen(Books[i].name) != 0){
			printf("���:%d\t", Books[i].id);
			printf("����:%s\t", Books[i].name);
			printf("�鼮����:%s\t", Books[i].author);
			printf("�鼮������:%s\t", Books[i].publish);
			printf("�鼮�ܹ�����:%d\t", Books[i].total);
			printf("�鼮�ִ�����:%d\n", Books[i].store);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("\nû���ҵ���صļ�¼\n");
	return i;
}
//��ѯͼ����Ϣ
int book_search(){
	char searchbook[31];
	int i = 0;
	int flag = 0;
	int n = -1;
	printf("\n*****************��ѯ�鼮��Ϣ*********************\n\n");
	printf("��������Ҫ��ѯ���鼮����:\n");
	scanf("%s", &searchbook);
	for (; i < 100; i++){
		if (strcmp(Books[i].name, searchbook) == 0){
			printf("���:%d\t", Books[i].id);
			printf("����:%s\t", Books[i].name);
			printf("�鼮����:%s\t", Books[i].author);
			printf("�鼮������:%s\t", Books[i].publish);
			printf("�鼮�ܹ�����:%d\t", Books[i].total);
			printf("�鼮�ִ�����:%d\n", Books[i].store);
			n = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("û���ҵ���Ҫ����\n");
	return n;
}
//�޸�ͼ�����Ϣ
void book_edit(){
	int i = 0;
	int id_change;
	printf("��������Ҫ�޸ĵ��鼮�ı��:\n");
	scanf("%d", &id_change);
	for (; i < 100; i++ ){
		if (Books[i].id == id_change){
			system("cls");
			printf("\n*****************�޸��鼮��Ϣ*********************\n\n");
			printf("�޸��鼮��� : ");
			scanf("%d", &Books[i].id);
			printf("�޸��鼮���� : ");
			scanf("%s", &Books[i].name);
			printf("�޸��鼮���� : ");
			scanf("%s", &Books[i].author);
			printf("�޸��鼮������ : ");
			scanf("%s", &Books[i].publish);
			printf("�޸��鼮���� : ");
			scanf("%d", &Books[i].total);
			Books[i].store = Books[i].total;
			break;
		}
	}
	return_confirm();
}
//ɾ��ͼ��
int book_del(){
	int i = 0;
	int id_del;
	int k = 0;
	system("cls");
	printf("\n*****************ɾ��ͼ��*********************\n\n");
	printf("��������Ҫɾ����ͼ�����Ʊ�� : ");	
	scanf("%d", &id_del);
	for (int num = 0; num < 100; num++){
		if (strlen(Books[num].name) != 0)
			k++;
	}
	for (; i < 100; i++){
		if (Books[i].id == id_del){
			for (int j = i; j <= k; j++){
				Books[j].id = Books[j + 1].id;
				strcpy(Books[j].name, Books[j + 1].name);
				strcpy(Books[j].publish, Books[j + 1].publish);
				return i;
			}
		}
	}
	printf("û����Ҫɾ������\n");
	return -1;
}
//����ͼ��
void book_out(){
	int out_usr;
	int out_days;
	int n = -1; 
	while (1){
		n = book_search();
		if (n >= 0)
			break;
		else
			printf("\nû���ҵ���Ҫ������\n\n");
	}

	printf("\n*****************����ͼ��*********************\n\n");
	printf("���������Ľ���֤��� : \n");
	scanf("%d", &out_usr);
	printf("��������Ҫ������� : \n");
	scanf("%d", &out_days);
	for (int i = 0; i < 10; i++){
		if (n != -1 && Books[n].store>0){
			Books[n].usr[i] = out_usr;
			Books[n].days[i] = out_days;
			Books[n].store--;
			break;
		}
	}
}
//�黹ͼ��
void book_in(){
	int n = -1;
	int in_usr;
	system("cls");
	printf("\n*****************�黹ͼ��*********************\n\n");
	while (1){
		n = book_search();
		if (n >= 0)
			break;
		else
			printf("\nû���ҵ���Ҫ�黹����\n\n");
	}
	printf("���������Ľ���֤��� : \n");
	scanf("%d", &in_usr);
	for (int i = 0; i < 10; i++){
		if (Books[n].usr[i] == in_usr){
			Books[n].usr[i] = 0;
			Books[n].days[i] = 0;
			break;
		}
	}
	Books[n].store++;
}
int main(){
	while (1){
		mena();
		//����switch����ѡ��
		switch (getch())
		{
		case '1':book_add();
			break;
		case '2':book_show();
			break;
		case '3':book_search();
			break;
		case '4':book_edit();
			break;
		case '5':book_del();
			break;
		case '6':book_out();
			break;
		case '7':book_in();
			break;
		case '8':exit(0);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
