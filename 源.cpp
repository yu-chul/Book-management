#include "widget.h"

int main() {
	system("mode con cols=144 lines=38");	//初始化窗口大小
	while (1)
	{
		switch (goToWidget_Title())			//标题界面
		{
		case 1:				//1. 登录
		{
			char* username;
			username = goToWidget_LogIn();
			if (username == 0)
				break;		//登录失败则返回标题界面
			else
			{
				//switch (goToWidget_Menu(username));		//菜单界面
				//{
				case 3: goToWidget_EditAndChoose(); break;
				//}
			}
		}
		case 2: goToWidget_Register(); break;	//2. 注册
		case 0: return 0; break;				//3. 退出程序
		}
	}
	return 0;
}