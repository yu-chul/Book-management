#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include "linkList.h"
#include "drawer.h"

extern int BF(char s[], char t[]);

//���ؼ��ʲ��Һ���
extern int singleFind(BookList head, char n, Book*l, int t);

//��ؼ��ֲ���
extern int doubleFind(BookList head, Book*l, char n, int t);

//ȫ��������
extern int All_find(BookList head, Book*l, int t);

//������ʱ���飺Book *l = (Book*)malloc(500 * sizeof(Book));
//�������߼�
//l����ʱ���飬n���������Ԫ�ظ��������������һλ�±�+1��
extern int find(BookList head, Book* l, int n, char s[], int t, char isbn[], char name[], char author[], char pub[]);

extern int search(BookList head, Book* l, int n);

extern int insert_find(Book b[], BookList L, int n);//ljh