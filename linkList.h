#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

extern int sum;
extern FILE* fp;

typedef struct Book {    //书的结构体
	char name[100];      //书名
	char publisher[100]; //出版社
	char isbn[100];      //书号
	char author[100];    //作者
	char borrower[100]="无";  //借阅人
//	int is_borrowed=0;    //借阅状态 0在馆  非0借出
	char is_borrowed[5];    //过滤空格
	char borrowtime[32];   //借阅时间
	char returntime[32];   //归还时间
}Book_ ;

typedef struct BookNode {   //链表单个元素的存储结构
	Book data;              //元素数据域
	struct BookNode *next;    //元素指针域
}BookNode, *BookList;
extern BookList head;

extern void Init_List();

//创建一个单链表(尾插法)
extern void CreatList_L(BookList L, int n);

//输出线性表(递归与非递归)
extern void TraverList_L(BookList head);

extern void initLibrary();
//书库的初始化过程

extern void bubble_sort(Book b[], int n);

#endif // LINKLIST_H_INCLUDED
