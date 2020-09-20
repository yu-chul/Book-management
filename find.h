#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include "linkList.h"
#include "drawer.h"

extern int BF(char s[], char t[]);

//单关键词查找函数
extern int singleFind(BookList head, char n, Book*l, int t);

//多关键字查找
extern int doubleFind(BookList head, Book*l, char n, int t);

//全导出函数
extern int All_find(BookList head, Book*l, int t);

//生成临时数组：Book *l = (Book*)malloc(500 * sizeof(Book));
//查找主逻辑
//l是临时数组，n是数组里的元素个数（即数组最后一位下标+1）
extern int find(BookList head, Book* l, int n, char s[], int t, char isbn[], char name[], char author[], char pub[]);

extern int search(BookList head, Book* l, int n);

extern int insert_find(Book b[], BookList L, int n);//ljh