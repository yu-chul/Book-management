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

typedef struct User {    //用户结构体
	char name[100];      //用户名
	char password[100];  //密码
};

int goToWidget_Title();
//标题界面
char* goToWidget_LogIn();
//登录界面
bool goToWidget_Register();
//注册界面
//int goToWidget_Menu(char* username);
//菜单界面
void goToWidget_EditAndChoose();
//管理与选择界面
#endif // !_WIDGET_H
