#include "borrow_return.h"

#define TIME_MAX 32

int borrow(Book b[], int n)
{
	if (strcmp(b[n].is_borrowed, "0") == 0)
	{
		time_t now;
		time(&now);
		struct tm tmTmp;
		struct tm tmTmp_return;
		char stTmp[TIME_MAX];
		char stTmp_return[TIME_MAX];
		char bo_name[100];
		localtime_s(&tmTmp, &now);
		asctime_s(stTmp, &tmTmp);
		tmTmp_return = tmTmp;
		//++tmTmp_return.tm_year;
		tmTmp_return.tm_mon = tmTmp.tm_mon + 4;
		asctime_s(stTmp_return, &tmTmp_return);//疑问??
		pos(2, 35); printf("请输入借阅者者姓名：");
		pos(2, 36); 
		scanf("%s", bo_name);
		stTmp[strlen(stTmp) - 1] = ' ';
		pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 35); printf("从%s开始借阅，最晚归还时间为%s", stTmp, stTmp_return);
		Sleep(5000);
		strcpy(b[n].is_borrowed, "1");
		stTmp[strlen(stTmp) - 1] = ' ';
		stTmp_return[strlen(stTmp_return) - 1] = ' ';
		strcpy(b[n].borrowtime, stTmp);
		strcpy(b[n].returntime, stTmp_return);
		strcpy(b[n].borrower, bo_name);
		return 1;
	}
	else
	{
		pos(2, 35); printf("该书已被借阅！");
		Sleep(1000);
	}
	return 1;
}

int return_book(Book b[], int n)
{
	if (strcmp(b[n].is_borrowed, "0") != 0)
	{
		strcpy(b[n].is_borrowed, "0");
		strcpy(b[n].borrowtime, "0");
		strcpy(b[n].returntime, "0");
		strcpy(b[n].borrower, "0");
		pos(2, 35); printf("该书已归还！");
		Sleep(1000);
	}
	else
	{
		pos(2, 35); printf("该书已被借阅！");
		Sleep(1000);
	}
	return 1;
}