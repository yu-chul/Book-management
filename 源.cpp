#include "widget.h"

int main() {
	system("mode con cols=144 lines=38");	//��ʼ�����ڴ�С
	while (1)
	{
		switch (goToWidget_Title())			//�������
		{
		case 1:				//1. ��¼
		{
			char* username;
			username = goToWidget_LogIn();
			if (username == 0)
				break;		//��¼ʧ���򷵻ر������
			else
			{
				//switch (goToWidget_Menu(username));		//�˵�����
				//{
				case 3: goToWidget_EditAndChoose(); break;
				//}
			}
		}
		case 2: goToWidget_Register(); break;	//2. ע��
		case 0: return 0; break;				//3. �˳�����
		}
	}
	return 0;
}