#define _CRT_SECURE_NO_DEPRECATE

#include "widget.h"

/*
int hightLightSlctr(int n, int allSlcts[][][]) {
	int slct = 1;
	for
}
*/

int goToWidget_Title() {	//标题界面
	system("cls");
	pos(55, 4); printf("===================================");
	pos(55, 5); printf("       图  书  管  理  系  统");
	pos(55, 6); printf("      Library Management System");
	pos(55, 7); printf("===================================");
	char slct1[20] = "1. 登  录";
	char slct2[20] = "2. 注  册";
	char slct3[20] = "3. 退出程序";
	int slct_left = 68;		//各选项缩进度量
	//各选项高度度量
	int pos_slct1 = 14;
	int pos_slct2 = 18;
	int pos_slct3 = 22;
	pos(slct_left, pos_slct1); printf(slct1);		//打印各选项
	pos(slct_left, pos_slct2); printf(slct2);
	pos(slct_left, pos_slct3); printf(slct3);
	int slctr = 1;		//初始化高亮项个数
	int pos_slctr;		//高亮项高度
	char txt_slctr[20];	//高亮项文本
	char ch = 0;			//键盘输入
	while (ch != 0x1B) {	// ESC to quit
		switch (slctr) {
		case 1: pos_slctr = pos_slct1; strcpy_s(txt_slctr, slct1); break;
		case 2: pos_slctr = pos_slct2; strcpy_s(txt_slctr, slct2); break;
		case 3: pos_slctr = pos_slct3; strcpy_s(txt_slctr, slct3); break;
		}	//初始化当前高亮项
		pos(slct_left, pos_slctr); highLight(); printf(txt_slctr);	//渲染高亮项
		unHighLight(); //取消drawer高亮状态
		switch (ch = _getch()) {
		case 72: if (slctr > 1) slctr--; break;
		case 80: if (slctr < 3) slctr++; break;
		case 13:
			switch (slctr) {
			case 1: return 1; break;		//登录界面
			case 2: return 2; break;		//注册界面
			case 3: return 0; break;		//退出程序
			}
		default:
			break;
		}	//侦测键盘方向键输入
		pos(slct_left, pos_slctr); printf(txt_slctr); //还原高亮项
		pos(0, 30); printf("   ");
		pos(0, 30); printf("%d", ch);
	}
}

char* goToWidget_LogIn() {	//登录界面
	FILE* fp;
	errno_t err;
	User user;
	char name[20], code[20];      //定义两个数组，存放键盘输入的用户名和密码
	system("cls");
	pos(58, 4); printf("============================");
	pos(58, 5); printf("       用  户  登  录");
	pos(58, 6); printf("============================");
	pos(44, 12); printf("用户名：");
	scanf_s("%s", name, sizeof(name));
	pos(44, 18); printf("密码：");
	scanf_s("%s", code, sizeof(code));

	/*用户名是否规范*/				//开始改了
	int num;
	err = 0;
	for (int i = 0; i < strlen(name); i++)
	{
		num = name[i];
		if (num < 48 || (num > 57 && num < 97) || (num > 122))
		{
			printf("\n\t\t\t\t\t\t\t用户名含有未知符,请重新输入！");
			Sleep(1000);
			return 0;
			break;
		}
	}
	if (strlen(name) > 18)
	{
		printf("\n\t\t\t\t\t\t\t用户名过长，请重新输入！");
		Sleep(1000);
		return 0;
	}
	/*密码是否规范*/									
	for (int i = 0; i < strlen(name); i++)
	{
		num = code[i];
		if (num < 48 || (num > 57 && num < 65) || (num > 90 && num < 97) || (num > 122))
		{
			printf("\n\t\t\t\t\t\t\t密码含有未知符,请重新输入！");
			Sleep(1000);
			return 0;
		}
	}
	if (strlen(name) > 18)
	{
		printf("\n\t\t\t\t\t\t\t密码过长，请重新输入！");
		Sleep(1000);
		return 0;
	}

	/*判断用户名是否存在*/
	fp = fopen(name, "rb");
	if (fp == NULL && !err)        
	{
		printf("\n\t\t\t\t\t\t\t用户不存在,重新登陆");
	}
	else
	{										
		for (int i = 0; i < strlen(name); i++)
		{
			num = code[i];
			if (num < 48 || (num > 57 && num < 97) || (num > 122))
			{
				printf("\n\t\t\t\t\t\t\t密码含有未知符,请重新输入！");
				return 0;
			}
		}
		if (strlen(name) > 18)
		{
			printf("\n\t\t\t\t\t\t\t密码过长，请重新输入！");
			return 0;
		}
	}//改完


	if (fp != NULL)
	{
		fscanf(fp, "%s %s", user.name, user.password); //读取用户信息，即用户名和密码
		if (strcmp(user.password, code) == 0)
		{
			system("cls");
			pos(67, 18); printf("登录成功！");
			Sleep(1000);
			fclose(fp);                           //关闭文件
			char* username;
			username = (char*)malloc(20);
			strcpy(username, user.name);
			return username;
		}
		else
		{
			system("cls");
			pos(53, 18); printf("您输入的用户名或密码有误，请重新登录！");
			Sleep(1000);
			return 0;
		}
	}
	else
	{
		system("cls");
		pos(53, 18); printf("您输入的用户名或密码有误，请重新登录！");
		Sleep(1000);
		return 0;
	}
}

bool goToWidget_Register() {	//注册界面
	FILE* fp;
	User user;
	bool err;
	char temp[20];        //存放键盘输入密码
start: system("cls");
	pos(58, 4); printf("============================\n");
	pos(58, 5); printf("       用  户  注  册\n");
	pos(58, 6); printf("============================\n");
	pos(44, 12); printf("账号：");
	scanf("%s", user.name);
	pos(44, 18); printf("密码：");
	/*确认两次密码输入是否一致*/
	scanf("%s", user.password);
	pos(44, 24); printf("确认密码：");
	scanf("%s", temp, sizeof(temp));


	/*用户名是否符合规范*/				//开始改
	int num;
	err = 0;
	for (int i = 0; i < strlen(user.name); i++)
	{
		num = user.name[i];
		if (num < 48 || (num > 57 && num < 97) || (num > 122))
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t用户名含有未知符,请重新输入！");
			Sleep(1000);
			goto start;
			break;
		}
	}
	if (strlen(user.name) > 18)						  //用户名过长
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t用户名过长，请重新输入！");
		Sleep(1000);
		goto start;
	}

	/*密码是否符合规范*/				
	for (int i = 0; i < strlen(user.password); i++)
	{
		num = user.password[i];
		if (num < 48 || (num > 57 && num < 65) || (num > 90 && num < 97) || (num > 122))
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t密码含有未知符,请重新输入！");
			Sleep(1000);
			goto start;
			break;
		}
	}
	if (strlen(user.password) > 18)						  //用户名过长
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t密码过长，请重新输入！");
		Sleep(1000);
		goto start;
	}//改了


	fp = fopen(user.name, "rb+");
	/*判断用户名是否重复*/
	if (fp != NULL)
	{
		system("cls");
		pos(58, 18); printf("该用户名已存在，请重新注册！");
		Sleep(1000);
		fclose(fp);
		goto start;
	}
	
	if (!err && strcmp(user.password, temp) != 0)
	{
		system("cls");
		pos(56, 18); printf("您前后输入的密码不一致，请重新注册！");
		Sleep(1000);
		fclose(fp);
		goto start;
	}
	/*用户名密码无误，写入文档储存用户信息*/
	fp = fopen(user.name, "wb");
	system("cls");
	fprintf(fp, "%s %s", user.name, user.password);//if (fwrite(&user, sizeof(User), 1, fp) != 1)
	pos(67, 18); printf("注册成功！");
	Sleep(1000);
	fclose(fp);
	return 0;
}
/*
int goToWidget_Menu(char* username) {	//菜单界面
	system("cls");
	pos(1, 1); printf("当前用户：%s", username);
	pos(58, 4); printf("============================\n");
	pos(58, 5); printf("         主  菜  单\n");
	pos(58, 6); printf("============================\n");
	pos(65, 12); printf("1. 导 入 书 籍\n");
	pos(65, 16); printf("2. 管 理 书 籍\n");
	pos(65, 20); printf("3. 查 询 书 籍\n");
	pos(65, 24); printf("4. 退 出 登 录\n");
	char slct1[20] = "1. 导 入 书 籍";
	char slct2[20] = "2. 管 理 书 籍";
	char slct3[20] = "3. 查 询 书 籍";
	char slct4[20] = "4. 退 出 登 录";
	int slct_left = 65;		//各选项缩进度量
	//各选项高度度量
	int pos_slct1 = 12;
	int pos_slct2 = 16;
	int pos_slct3 = 20;
	int pos_slct4 = 24;
	pos(slct_left, pos_slct1); printf(slct1);		//打印各选项
	pos(slct_left, pos_slct2); printf(slct2);
	pos(slct_left, pos_slct3); printf(slct3);
	pos(slct_left, pos_slct4); printf(slct4);
	int slctr = 1;		//初始化高亮项个数
	int pos_slctr;		//高亮项高度
	char txt_slctr[20];	//高亮项文本
	char ch = 0;			//键盘输入
	while (ch != 0x1B) {	// ESC to quit
		switch (slctr) {
		case 1: pos_slctr = pos_slct1; strcpy_s(txt_slctr, slct1); break;
		case 2: pos_slctr = pos_slct2; strcpy_s(txt_slctr, slct2); break;
		case 3: pos_slctr = pos_slct3; strcpy_s(txt_slctr, slct3); break;
		case 4: pos_slctr = pos_slct4; strcpy_s(txt_slctr, slct4); break;
		}	//初始化当前高亮项
		pos(slct_left, pos_slctr); highLight(); printf(txt_slctr);	//渲染高亮项
		unHighLight(); //取消drawer高亮状态
		switch (ch = _getch()) {
		case 72: if (slctr > 1) slctr--; break;
		case 80: if (slctr < 4) slctr++; break;
		case 13:
			switch (slctr) {
			case 1: return 1; break;
			case 2: return 2; break;
			case 3: return 3; break;
			case 4: return 0; break;
			}
		default:
			break;
		}	//侦测键盘方向键输入
		pos(slct_left, pos_slctr); printf(txt_slctr); //还原高亮项
	}
}
*/
void goToWidget_EditAndChoose()		//管理与选择界面
{
	fflush(stdin);
	init:
	initLibrary();		//初始化链表
	Book* searchResult = (Book*)malloc(500 * sizeof(Book));
	int total = 0;			//书籍总数
	total = All_find(head, searchResult, total);
	bubble_sort(searchResult, total);
	search:
	system("cls");
	pos(58, 1); printf("============================");
	pos(58, 2); printf("       书  籍  管  理");
	pos(58, 3); printf("============================");
	pos(2, 5); for (int i = 0; i < 140; i++) { printf("="); }
	pos(2, 6); printf("         ISBN|                                            书名|                                       作者|                           出版社");
	pos(2, 7); for (int i = 0; i < 140; i++) { printf("-"); }
	pos(2, 28); for (int i = 0; i < 140; i++) { printf("="); }
	pos(2, 37); printf("[F1]修改ISBN [F2]修改书名 [F3]修改作者 [F4]修改出版社 [F5]搜索书籍 [F6]借阅书籍 [F7]归还书籍 [Del]删除书籍 [F12]重置");
	int col0 = 2;
	int col1 = 15;
	int col2 = 64;
	int col3 = 108;
	pos(col1, 7); printf("|");
	pos(col2, 7); printf("|");
	pos(col3, 7); printf("|");
	int n;					//列表序号
	int page = 0;			//当前页数
	int page_max;			//页数上限
	if (total % 20 == 0)
		page_max = total / 20;
	else
		page_max = total / 20 + 1;
	int n_max;				//每页序号上限
	int slctr = 0;			//初始化高亮项序号
	int ch = -1919;			//键盘输入
	while (ch != 0x1B) {	// ESC to quit
		if (page + 1 == page_max)
			n_max = total % 20;
		else
			n_max = 20;
		if (ch == -1919 || ch == 73 || ch == 81)		//翻页时的操作
		{
			slctr = 0;
			for (n = 0; n < 20; n++)		//清空页面
			{
				for (int i = col0 - 1; i < col1; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col1; i < col2; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col2; i < col3; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col3; i < 144; i++) { pos(i + 1, 8 + n); printf(" "); }
			}
			for (n = 0; n < n_max; n++)		//输出文本
			{
				pos(col0, 8 + n); printf("%s", searchResult[n + page * 20].isbn);
				for (int i = col1; i < col2; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col1 + 1, 8 + n); printf("%s", searchResult[n + page * 20].name);
				for (int i = col2; i < col3; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col2 + 1, 8 + n); printf("%s", searchResult[n + page * 20].author);
				for (int i = col3; i < 144; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col3 + 1, 8 + n); printf("%s", searchResult[n + page * 20].publisher);
			}
			for (n = 0; n < 20; n++)		//绘制栏线
			{
				pos(col1, 8 + n); printf("|");
				pos(col2, 8 + n); printf("|");
				pos(col3, 8 + n); printf("|");
			}
			pos(2, 4); printf("共找到条目%d条，第%d页，共%d页", total, page + 1, page_max);
		}
		highLight();
		pos(col0, 8 + slctr); printf("%s", searchResult[slctr + page * 20].isbn);
		for (int i = col1; i < col2; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col1 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].name);
		for (int i = col2; i < col3; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col2 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].author);
		for (int i = col3; i < 141; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col3 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].publisher);
		pos(col1, 8 + slctr); printf("|");
		pos(col2, 8 + slctr); printf("|");
		pos(col3, 8 + slctr); printf("|");	//渲染高亮项
		pos(2, 29); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 30); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 31); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 32); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 33); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 34); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 29); printf("ISBN：%s", searchResult[slctr + page * 20].isbn);
		pos(2, 30); printf("书名：%s", searchResult[slctr + page * 20].name);
		pos(2, 31); printf("作者：%s", searchResult[slctr + page * 20].author);
		pos(2, 32); printf("出版社：%s", searchResult[slctr + page * 20].publisher);
		if (strcmp(searchResult[slctr + page * 20].is_borrowed, "1") == 0)
		{
			pos(2, 33); printf("借阅人：%s", searchResult[slctr + page * 20].borrower);
			pos(2, 34); printf("借阅时间：%s～ %s", searchResult[slctr + page * 20].borrowtime, searchResult[slctr + page * 20].returntime);
		}
		ch = _getch();
		if (ch == 224)
			ch = _getch();		//侦测键盘输入
		fflush(stdin);
		unHighLight();		//取消drawer高亮状态
		pos(col0, 8 + slctr); printf("%s", searchResult[slctr + page * 20].isbn);
		for (int i = col1; i < col2; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col1 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].name);
		for (int i = col2; i < col3; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col2 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].author);
		for (int i = col3; i < 144; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col3 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].publisher);
		pos(col1, 8 + slctr); printf("|");
		pos(col2, 8 + slctr); printf("|");
		pos(col3, 8 + slctr); printf("|");	 //还原高亮项
		switch (ch)
		{
		case 72:
		{
			if (slctr > 0) slctr--;			//上移光标
			if (slctr == 1 && page > 0)
			{
				page--;
				slctr = page_max;
			}
			break;
		}
		case 80: if (slctr < n_max - 1) slctr++; break;		//下移光标
		case 73: if (page > 0) page--; break;			//上翻页
		case 81: if (page < page_max - 1) page++; break;	//下翻页
		case 59:	//F1
		{
			if (modify_isbn(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//修改ISBN
		}
		case 60:	//F2
		{	
			if (modify_name(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//修改书名
		}
		case 61:	//F3
		{
			if (modify_author(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//修改作者
		}
		case 62:	//F4
		{
			if (modify_publisher(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//修改出版社
		}
		case 63:	//F5
		{
			arrytolist(searchResult, total);
			file_save_borrow_return(head);//????
			total = search(head, searchResult, 0);
			goto search;
			break;	//搜索书籍
		}
		case 64:	//F6
		{
			if (borrow(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//借阅书籍
		}
		case 65:	//F7
		{
			if (return_book(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//借阅书籍
		}
		case 82:	//INS
		{	
			initLibrary();
			insert_book(head);
			//arrytolist(searchResult, total);
			file_save_borrow_return(head);
			goto init;
			break;	//插入书籍
		}
		case 83:	//DEL
		{
			if (delete_m(searchResult, slctr + page * 20) == 1)
			{
				arrytolist(searchResult, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//删除书籍
		}
		case 134:	//F12
		{
			insert_find(searchResult, head, total);
			file_save_borrow_return(head);
			goto init;
			break;	//重置
		}
		//case 13:
		default:
			break;
		}
		pos(1, 1);  printf("   ");
		pos(1, 1);  printf("%d", ch);
	}
	exit;
}