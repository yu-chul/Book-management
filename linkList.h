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

typedef struct Book {    //��Ľṹ��
	char name[100];      //����
	char publisher[100]; //������
	char isbn[100];      //���
	char author[100];    //����
	char borrower[100]="��";  //������
//	int is_borrowed=0;    //����״̬ 0�ڹ�  ��0���
	char is_borrowed[5];    //���˿ո�
	char borrowtime[32];   //����ʱ��
	char returntime[32];   //�黹ʱ��
}Book_ ;

typedef struct BookNode {   //������Ԫ�صĴ洢�ṹ
	Book data;              //Ԫ��������
	struct BookNode *next;    //Ԫ��ָ����
}BookNode, *BookList;
extern BookList head;

extern void Init_List();

//����һ��������(β�巨)
extern void CreatList_L(BookList L, int n);

//������Ա�(�ݹ���ǵݹ�)
extern void TraverList_L(BookList head);

extern void initLibrary();
//���ĳ�ʼ������

extern void bubble_sort(Book b[], int n);

#endif // LINKLIST_H_INCLUDED
