#define _CRT_SECURE_NO_DEPRECATE

#include "widget.h"

/*
int hightLightSlctr(int n, int allSlcts[][][]) {
	int slct = 1;
	for
}
*/

int goToWidget_Title() {	//�������
	system("cls");
	pos(55, 4); printf("===================================");
	pos(55, 5); printf("       ͼ  ��  ��  ��  ϵ  ͳ");
	pos(55, 6); printf("      Library Management System");
	pos(55, 7); printf("===================================");
	char slct1[20] = "1. ��  ¼";
	char slct2[20] = "2. ע  ��";
	char slct3[20] = "3. �˳�����";
	int slct_left = 68;		//��ѡ����������
	//��ѡ��߶ȶ���
	int pos_slct1 = 14;
	int pos_slct2 = 18;
	int pos_slct3 = 22;
	pos(slct_left, pos_slct1); printf(slct1);		//��ӡ��ѡ��
	pos(slct_left, pos_slct2); printf(slct2);
	pos(slct_left, pos_slct3); printf(slct3);
	int slctr = 1;		//��ʼ�����������
	int pos_slctr;		//������߶�
	char txt_slctr[20];	//�������ı�
	char ch = 0;			//��������
	while (ch != 0x1B) {	// ESC to quit
		switch (slctr) {
		case 1: pos_slctr = pos_slct1; strcpy_s(txt_slctr, slct1); break;
		case 2: pos_slctr = pos_slct2; strcpy_s(txt_slctr, slct2); break;
		case 3: pos_slctr = pos_slct3; strcpy_s(txt_slctr, slct3); break;
		}	//��ʼ����ǰ������
		pos(slct_left, pos_slctr); highLight(); printf(txt_slctr);	//��Ⱦ������
		unHighLight(); //ȡ��drawer����״̬
		switch (ch = _getch()) {
		case 72: if (slctr > 1) slctr--; break;
		case 80: if (slctr < 3) slctr++; break;
		case 13:
			switch (slctr) {
			case 1: return 1; break;		//��¼����
			case 2: return 2; break;		//ע�����
			case 3: return 0; break;		//�˳�����
			}
		default:
			break;
		}	//�����̷��������
		pos(slct_left, pos_slctr); printf(txt_slctr); //��ԭ������
		pos(0, 30); printf("   ");
		pos(0, 30); printf("%d", ch);
	}
}

char* goToWidget_LogIn() {	//��¼����
	FILE* fp;
	errno_t err;
	User user;
	char name[20], code[20];      //�����������飬��ż���������û���������
	system("cls");
	pos(58, 4); printf("============================");
	pos(58, 5); printf("       ��  ��  ��  ¼");
	pos(58, 6); printf("============================");
	pos(44, 12); printf("�û�����");
	scanf_s("%s", name, sizeof(name));
	pos(44, 18); printf("���룺");
	scanf_s("%s", code, sizeof(code));

	/*�û����Ƿ�淶*/				//��ʼ����
	int num;
	err = 0;
	for (int i = 0; i < strlen(name); i++)
	{
		num = name[i];
		if (num < 48 || (num > 57 && num < 97) || (num > 122))
		{
			printf("\n\t\t\t\t\t\t\t�û�������δ֪��,���������룡");
			Sleep(1000);
			return 0;
			break;
		}
	}
	if (strlen(name) > 18)
	{
		printf("\n\t\t\t\t\t\t\t�û������������������룡");
		Sleep(1000);
		return 0;
	}
	/*�����Ƿ�淶*/									
	for (int i = 0; i < strlen(name); i++)
	{
		num = code[i];
		if (num < 48 || (num > 57 && num < 65) || (num > 90 && num < 97) || (num > 122))
		{
			printf("\n\t\t\t\t\t\t\t���뺬��δ֪��,���������룡");
			Sleep(1000);
			return 0;
		}
	}
	if (strlen(name) > 18)
	{
		printf("\n\t\t\t\t\t\t\t������������������룡");
		Sleep(1000);
		return 0;
	}

	/*�ж��û����Ƿ����*/
	fp = fopen(name, "rb");
	if (fp == NULL && !err)        
	{
		printf("\n\t\t\t\t\t\t\t�û�������,���µ�½");
	}
	else
	{										
		for (int i = 0; i < strlen(name); i++)
		{
			num = code[i];
			if (num < 48 || (num > 57 && num < 97) || (num > 122))
			{
				printf("\n\t\t\t\t\t\t\t���뺬��δ֪��,���������룡");
				return 0;
			}
		}
		if (strlen(name) > 18)
		{
			printf("\n\t\t\t\t\t\t\t������������������룡");
			return 0;
		}
	}//����


	if (fp != NULL)
	{
		fscanf(fp, "%s %s", user.name, user.password); //��ȡ�û���Ϣ�����û���������
		if (strcmp(user.password, code) == 0)
		{
			system("cls");
			pos(67, 18); printf("��¼�ɹ���");
			Sleep(1000);
			fclose(fp);                           //�ر��ļ�
			char* username;
			username = (char*)malloc(20);
			strcpy(username, user.name);
			return username;
		}
		else
		{
			system("cls");
			pos(53, 18); printf("��������û������������������µ�¼��");
			Sleep(1000);
			return 0;
		}
	}
	else
	{
		system("cls");
		pos(53, 18); printf("��������û������������������µ�¼��");
		Sleep(1000);
		return 0;
	}
}

bool goToWidget_Register() {	//ע�����
	FILE* fp;
	User user;
	bool err;
	char temp[20];        //��ż�����������
start: system("cls");
	pos(58, 4); printf("============================\n");
	pos(58, 5); printf("       ��  ��  ע  ��\n");
	pos(58, 6); printf("============================\n");
	pos(44, 12); printf("�˺ţ�");
	scanf("%s", user.name);
	pos(44, 18); printf("���룺");
	/*ȷ���������������Ƿ�һ��*/
	scanf("%s", user.password);
	pos(44, 24); printf("ȷ�����룺");
	scanf("%s", temp, sizeof(temp));


	/*�û����Ƿ���Ϲ淶*/				//��ʼ��
	int num;
	err = 0;
	for (int i = 0; i < strlen(user.name); i++)
	{
		num = user.name[i];
		if (num < 48 || (num > 57 && num < 97) || (num > 122))
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t�û�������δ֪��,���������룡");
			Sleep(1000);
			goto start;
			break;
		}
	}
	if (strlen(user.name) > 18)						  //�û�������
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t�û������������������룡");
		Sleep(1000);
		goto start;
	}

	/*�����Ƿ���Ϲ淶*/				
	for (int i = 0; i < strlen(user.password); i++)
	{
		num = user.password[i];
		if (num < 48 || (num > 57 && num < 65) || (num > 90 && num < 97) || (num > 122))
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t���뺬��δ֪��,���������룡");
			Sleep(1000);
			goto start;
			break;
		}
	}
	if (strlen(user.password) > 18)						  //�û�������
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t������������������룡");
		Sleep(1000);
		goto start;
	}//����


	fp = fopen(user.name, "rb+");
	/*�ж��û����Ƿ��ظ�*/
	if (fp != NULL)
	{
		system("cls");
		pos(58, 18); printf("���û����Ѵ��ڣ�������ע�ᣡ");
		Sleep(1000);
		fclose(fp);
		goto start;
	}
	
	if (!err && strcmp(user.password, temp) != 0)
	{
		system("cls");
		pos(56, 18); printf("��ǰ����������벻һ�£�������ע�ᣡ");
		Sleep(1000);
		fclose(fp);
		goto start;
	}
	/*�û�����������д���ĵ������û���Ϣ*/
	fp = fopen(user.name, "wb");
	system("cls");
	fprintf(fp, "%s %s", user.name, user.password);//if (fwrite(&user, sizeof(User), 1, fp) != 1)
	pos(67, 18); printf("ע��ɹ���");
	Sleep(1000);
	fclose(fp);
	return 0;
}
/*
int goToWidget_Menu(char* username) {	//�˵�����
	system("cls");
	pos(1, 1); printf("��ǰ�û���%s", username);
	pos(58, 4); printf("============================\n");
	pos(58, 5); printf("         ��  ��  ��\n");
	pos(58, 6); printf("============================\n");
	pos(65, 12); printf("1. �� �� �� ��\n");
	pos(65, 16); printf("2. �� �� �� ��\n");
	pos(65, 20); printf("3. �� ѯ �� ��\n");
	pos(65, 24); printf("4. �� �� �� ¼\n");
	char slct1[20] = "1. �� �� �� ��";
	char slct2[20] = "2. �� �� �� ��";
	char slct3[20] = "3. �� ѯ �� ��";
	char slct4[20] = "4. �� �� �� ¼";
	int slct_left = 65;		//��ѡ����������
	//��ѡ��߶ȶ���
	int pos_slct1 = 12;
	int pos_slct2 = 16;
	int pos_slct3 = 20;
	int pos_slct4 = 24;
	pos(slct_left, pos_slct1); printf(slct1);		//��ӡ��ѡ��
	pos(slct_left, pos_slct2); printf(slct2);
	pos(slct_left, pos_slct3); printf(slct3);
	pos(slct_left, pos_slct4); printf(slct4);
	int slctr = 1;		//��ʼ�����������
	int pos_slctr;		//������߶�
	char txt_slctr[20];	//�������ı�
	char ch = 0;			//��������
	while (ch != 0x1B) {	// ESC to quit
		switch (slctr) {
		case 1: pos_slctr = pos_slct1; strcpy_s(txt_slctr, slct1); break;
		case 2: pos_slctr = pos_slct2; strcpy_s(txt_slctr, slct2); break;
		case 3: pos_slctr = pos_slct3; strcpy_s(txt_slctr, slct3); break;
		case 4: pos_slctr = pos_slct4; strcpy_s(txt_slctr, slct4); break;
		}	//��ʼ����ǰ������
		pos(slct_left, pos_slctr); highLight(); printf(txt_slctr);	//��Ⱦ������
		unHighLight(); //ȡ��drawer����״̬
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
		}	//�����̷��������
		pos(slct_left, pos_slctr); printf(txt_slctr); //��ԭ������
	}
}
*/
void goToWidget_EditAndChoose()		//������ѡ�����
{
	fflush(stdin);
	init:
	initLibrary();		//��ʼ������
	Book* searchResult = (Book*)malloc(500 * sizeof(Book));
	int total = 0;			//�鼮����
	total = All_find(head, searchResult, total);
	bubble_sort(searchResult, total);
	search:
	system("cls");
	pos(58, 1); printf("============================");
	pos(58, 2); printf("       ��  ��  ��  ��");
	pos(58, 3); printf("============================");
	pos(2, 5); for (int i = 0; i < 140; i++) { printf("="); }
	pos(2, 6); printf("         ISBN|                                            ����|                                       ����|                           ������");
	pos(2, 7); for (int i = 0; i < 140; i++) { printf("-"); }
	pos(2, 28); for (int i = 0; i < 140; i++) { printf("="); }
	pos(2, 37); printf("[F1]�޸�ISBN [F2]�޸����� [F3]�޸����� [F4]�޸ĳ����� [F5]�����鼮 [F6]�����鼮 [F7]�黹�鼮 [Del]ɾ���鼮 [F12]����");
	int col0 = 2;
	int col1 = 15;
	int col2 = 64;
	int col3 = 108;
	pos(col1, 7); printf("|");
	pos(col2, 7); printf("|");
	pos(col3, 7); printf("|");
	int n;					//�б����
	int page = 0;			//��ǰҳ��
	int page_max;			//ҳ������
	if (total % 20 == 0)
		page_max = total / 20;
	else
		page_max = total / 20 + 1;
	int n_max;				//ÿҳ�������
	int slctr = 0;			//��ʼ�����������
	int ch = -1919;			//��������
	while (ch != 0x1B) {	// ESC to quit
		if (page + 1 == page_max)
			n_max = total % 20;
		else
			n_max = 20;
		if (ch == -1919 || ch == 73 || ch == 81)		//��ҳʱ�Ĳ���
		{
			slctr = 0;
			for (n = 0; n < 20; n++)		//���ҳ��
			{
				for (int i = col0 - 1; i < col1; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col1; i < col2; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col2; i < col3; i++) { pos(i + 1, 8 + n); printf(" "); }
				for (int i = col3; i < 144; i++) { pos(i + 1, 8 + n); printf(" "); }
			}
			for (n = 0; n < n_max; n++)		//����ı�
			{
				pos(col0, 8 + n); printf("%s", searchResult[n + page * 20].isbn);
				for (int i = col1; i < col2; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col1 + 1, 8 + n); printf("%s", searchResult[n + page * 20].name);
				for (int i = col2; i < col3; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col2 + 1, 8 + n); printf("%s", searchResult[n + page * 20].author);
				for (int i = col3; i < 144; i++) { pos(i + 1, 8 + n); printf(" "); }
				pos(col3 + 1, 8 + n); printf("%s", searchResult[n + page * 20].publisher);
			}
			for (n = 0; n < 20; n++)		//��������
			{
				pos(col1, 8 + n); printf("|");
				pos(col2, 8 + n); printf("|");
				pos(col3, 8 + n); printf("|");
			}
			pos(2, 4); printf("���ҵ���Ŀ%d������%dҳ����%dҳ", total, page + 1, page_max);
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
		pos(col3, 8 + slctr); printf("|");	//��Ⱦ������
		pos(2, 29); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 30); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 31); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 32); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 33); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 34); for (int i = 0; i < 140; i++) { printf(" "); }
		pos(2, 29); printf("ISBN��%s", searchResult[slctr + page * 20].isbn);
		pos(2, 30); printf("������%s", searchResult[slctr + page * 20].name);
		pos(2, 31); printf("���ߣ�%s", searchResult[slctr + page * 20].author);
		pos(2, 32); printf("�����磺%s", searchResult[slctr + page * 20].publisher);
		if (strcmp(searchResult[slctr + page * 20].is_borrowed, "1") == 0)
		{
			pos(2, 33); printf("�����ˣ�%s", searchResult[slctr + page * 20].borrower);
			pos(2, 34); printf("����ʱ�䣺%s�� %s", searchResult[slctr + page * 20].borrowtime, searchResult[slctr + page * 20].returntime);
		}
		ch = _getch();
		if (ch == 224)
			ch = _getch();		//����������
		fflush(stdin);
		unHighLight();		//ȡ��drawer����״̬
		pos(col0, 8 + slctr); printf("%s", searchResult[slctr + page * 20].isbn);
		for (int i = col1; i < col2; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col1 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].name);
		for (int i = col2; i < col3; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col2 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].author);
		for (int i = col3; i < 144; i++) { pos(i + 1, 8 + slctr); printf(" "); }
		pos(col3 + 1, 8 + slctr); printf("%s", searchResult[slctr + page * 20].publisher);
		pos(col1, 8 + slctr); printf("|");
		pos(col2, 8 + slctr); printf("|");
		pos(col3, 8 + slctr); printf("|");	 //��ԭ������
		switch (ch)
		{
		case 72:
		{
			if (slctr > 0) slctr--;			//���ƹ��
			if (slctr == 1 && page > 0)
			{
				page--;
				slctr = page_max;
			}
			break;
		}
		case 80: if (slctr < n_max - 1) slctr++; break;		//���ƹ��
		case 73: if (page > 0) page--; break;			//�Ϸ�ҳ
		case 81: if (page < page_max - 1) page++; break;	//�·�ҳ
		case 59:	//F1
		{
			if (modify_isbn(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�޸�ISBN
		}
		case 60:	//F2
		{	
			if (modify_name(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�޸�����
		}
		case 61:	//F3
		{
			if (modify_author(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�޸�����
		}
		case 62:	//F4
		{
			if (modify_publisher(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�޸ĳ�����
		}
		case 63:	//F5
		{
			arrytolist(searchResult, total);
			file_save_borrow_return(head);//????
			total = search(head, searchResult, 0);
			goto search;
			break;	//�����鼮
		}
		case 64:	//F6
		{
			if (borrow(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�����鼮
		}
		case 65:	//F7
		{
			if (return_book(searchResult, slctr + page * 20) == 1)
			{
				insert_find(searchResult, head, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//�����鼮
		}
		case 82:	//INS
		{	
			initLibrary();
			insert_book(head);
			//arrytolist(searchResult, total);
			file_save_borrow_return(head);
			goto init;
			break;	//�����鼮
		}
		case 83:	//DEL
		{
			if (delete_m(searchResult, slctr + page * 20) == 1)
			{
				arrytolist(searchResult, total);
				file_save_borrow_return(head);
			}
			goto init;
			break;	//ɾ���鼮
		}
		case 134:	//F12
		{
			insert_find(searchResult, head, total);
			file_save_borrow_return(head);
			goto init;
			break;	//����
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