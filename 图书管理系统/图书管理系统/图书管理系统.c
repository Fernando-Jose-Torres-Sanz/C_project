#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
	//书籍编号
	int id;
	//书籍名称
	char name[31];
	//书籍作者
	char author[27];
	//书籍出版社
	char publish[31];
	//书籍在图书馆现有的数量
	int store;
	//书籍总体数量
	int total;
	//借阅者的借书证序号
	int usr[10];
	//借阅的截止日期
	int days[10];
};
struct Book Books[100];
 //打印菜单
void mena(){
	printf("\n--操作选单--\n\n");
	printf("请输入数字选择您要操作的项目\n");
	printf("\n\n\t\t\t\t 1.注册新书\t\t\t\t2.显示图书\n");
	printf("\n\n\t\t\t\t 3.查询图书信息\t\t\t\t4.修改图书信息\n");
	printf("\n\n\t\t\t\t 5.删除图书\t\t\t\t6.借阅图书\n");
	printf("\n\n\t\t\t\t 7.归还图书\t\t\t\t8.退出系统\n");
	printf("\n\n请按数字进行选择 : \n");
}


void return_confirm(){
	printf("\n***************按任意键返回********************\n");
	getchar();
}

//注册新书
void book_add(){
	int i = 0;
	for (; i < 100; i++){
		if (Books[i].id == 0)
			break;
	}
		system("cls");
		printf("\n***************注册新书*********************\n\n");
		printf("书籍序号 : ");
		scanf("%d", &Books[i].id);
		printf("书籍名称 : ");
		scanf("%s", &Books[i].name);
		printf("书籍作者 : ");
		scanf("%s", &Books[i].author);
		printf("书籍出版社 : ");
		scanf("%s", &Books[i].publish);
		printf("数量 : ");
		scanf("%d", &Books[i].total);
		Books[i].store = Books[i].total;
		FILE* fp;
		fp = fopen("book", "wb");
		if (fp == NULL)
			printf("打开文件错误\n");
		fwrite(Books, sizeof(Books[100]), sizeof(Books[100]), fp);
		return_confirm();
		system("cls");
}
//显示图书信息
int book_show(){
	int i = 0; 
	int flag = 0;
	system("cls");
	printf("\n*****************显示图书信息*********************\n\n");
	for (; i < 100; i++){
		if (strlen(Books[i].name) != 0){
			printf("序号:%d\t", Books[i].id);
			printf("书名:%s\t", Books[i].name);
			printf("书籍作者:%s\t", Books[i].author);
			printf("书籍出版社:%s\t", Books[i].publish);
			printf("书籍总共数量:%d\t", Books[i].total);
			printf("书籍现存数量:%d\n", Books[i].store);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("\n没有找到相关的记录\n");
	return i;
}
//查询图书信息
int book_search(){
	char searchbook[31];
	int i = 0;
	int flag = 0;
	int n = -1;
	printf("\n*****************查询书籍信息*********************\n\n");
	printf("请输入您要查询的书籍名称:\n");
	scanf("%s", &searchbook);
	for (; i < 100; i++){
		if (strcmp(Books[i].name, searchbook) == 0){
			printf("序号:%d\t", Books[i].id);
			printf("书名:%s\t", Books[i].name);
			printf("书籍作者:%s\t", Books[i].author);
			printf("书籍出版社:%s\t", Books[i].publish);
			printf("书籍总共数量:%d\t", Books[i].total);
			printf("书籍现存数量:%d\n", Books[i].store);
			n = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("没有找到您要的书\n");
	return n;
}
//修改图书的信息
void book_edit(){
	int i = 0;
	int id_change;
	printf("请输入您要修改的书籍的编号:\n");
	scanf("%d", &id_change);
	for (; i < 100; i++ ){
		if (Books[i].id == id_change){
			system("cls");
			printf("\n*****************修改书籍信息*********************\n\n");
			printf("修改书籍序号 : ");
			scanf("%d", &Books[i].id);
			printf("修改书籍名称 : ");
			scanf("%s", &Books[i].name);
			printf("修改书籍作者 : ");
			scanf("%s", &Books[i].author);
			printf("修改书籍出版社 : ");
			scanf("%s", &Books[i].publish);
			printf("修改书籍数量 : ");
			scanf("%d", &Books[i].total);
			Books[i].store = Books[i].total;
			break;
		}
	}
	return_confirm();
}
//删除图书
int book_del(){
	int i = 0;
	int id_del;
	int k = 0;
	system("cls");
	printf("\n*****************删除图书*********************\n\n");
	printf("请输入您要删除的图书名称编号 : ");	
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
	printf("没有您要删除的书\n");
	return -1;
}
//借阅图书
void book_out(){
	int out_usr;
	int out_days;
	int n = -1; 
	while (1){
		n = book_search();
		if (n >= 0)
			break;
		else
			printf("\n没有找到您要借阅书\n\n");
	}

	printf("\n*****************借阅图书*********************\n\n");
	printf("请输入您的借书证序号 : \n");
	scanf("%d", &out_usr);
	printf("请输入您要借的天数 : \n");
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
//归还图书
void book_in(){
	int n = -1;
	int in_usr;
	system("cls");
	printf("\n*****************归还图书*********************\n\n");
	while (1){
		n = book_search();
		if (n >= 0)
			break;
		else
			printf("\n没有找到您要归还的书\n\n");
	}
	printf("请输入您的借书证序号 : \n");
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
		//利用switch进入选择
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
