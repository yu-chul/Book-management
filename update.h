#ifndef _UPDATE_H
#define _UPDATE_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include "linkList.h"
#include "drawer.h"
#include "modify_delete.h"

//���뺯��
extern void insert_book(BookList head);

extern int delete_book(BookList head);//ɾ������

#endif
