#include "Drawer.h"

void pos(int x, int y)	//设置光标位置
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void col(unsigned short ForeColor)	//颜色设置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor);			//设置颜色
}

void highLight()	//高亮输出
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	//获取当前窗口句柄
	SetConsoleTextAttribute(handle, 15 | 8 | 15 | 128);	//设置颜色
}

void unHighLight()	//高亮取消
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	//获取当前窗口句柄
	SetConsoleTextAttribute(handle, 15);	//设置颜色
}