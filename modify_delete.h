#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#ifndef _MODIFY_DELETE_H
#define _MODIFY_DELETE_H

#include <ctype.h>
#include "linkList.h"
#include "drawer.h"

extern int arrytolist(Book b[], int n);  //���Ƚ������ÿգ��ٽ�����Ԫ��ȫ���ӵ�����,������Ϊ0��Ϊɾ��������

extern int judgeisbn(char isbn[]);  //������isbn

extern int modify_name(Book b[], int n);
extern int modify_author(Book b[], int n);
extern int modify_publisher(Book b[], int n);
extern int modify_isbn(Book b[], int n);

extern int delete_m(Book b[], int n);	//ɾ��

#endif