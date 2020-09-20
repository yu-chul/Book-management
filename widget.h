#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#ifndef _WIDGET_H
#define _WIDGET_H

#include <conio.h>
#include "drawer.h"
#include "find.h"
#include "linkList.h"
#include "modify_delete.h"
#include "file.h"
#include "update.h"
#include "borrow_return.h"

typedef struct User {    //�û��ṹ��
	char name[100];      //�û���
	char password[100];  //����
};

int goToWidget_Title();
//�������
char* goToWidget_LogIn();
//��¼����
bool goToWidget_Register();
//ע�����
//int goToWidget_Menu(char* username);
//�˵�����
void goToWidget_EditAndChoose();
//������ѡ�����
#endif // !_WIDGET_H
