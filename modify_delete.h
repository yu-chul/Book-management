#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#ifndef _MODIFY_DELETE_H
#define _MODIFY_DELETE_H

#include <ctype.h>
#include "linkList.h"
#include "drawer.h"

extern int arrytolist(Book b[], int n);  //首先将链表置空，再将数组元素全部接到链表,若书名为0即为删除，跳过

extern int judgeisbn(char isbn[]);  //输入检测isbn

extern int modify_name(Book b[], int n);
extern int modify_author(Book b[], int n);
extern int modify_publisher(Book b[], int n);
extern int modify_isbn(Book b[], int n);

extern int delete_m(Book b[], int n);	//删除

#endif