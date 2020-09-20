#include "modify_delete.h"

int arrytolist(Book b[], int n)  //���Ƚ������ÿգ��ٽ�����Ԫ��ȫ���ӵ�����,������Ϊ0��Ϊɾ��������
{
	Init_List();
	BookList q;
	q = head;
	int i;
	BookList p;
	for (i = 0; i < n; i++) {
		if (strcmp(b[i].name, "0") != 0)
		{
			p = (BookList)malloc(sizeof(BookNode));
			strcpy(p->data.author, b[i].author);
			strcpy(p->data.borrower, b[i].borrower);
			strcpy(p->data.borrowtime, b[i].borrowtime);
			strcpy(p->data.isbn, b[i].isbn);
			strcpy(p->data.is_borrowed, b[i].is_borrowed);
			strcpy(p->data.name, b[i].name);
			strcpy(p->data.publisher, b[i].publisher);
			strcpy(p->data.returntime, b[i].returntime);
			p->next = q->next;
			q->next = p;
			q = q->next;//q=p;
		}
	}
	return 1;
}

int judgeisbn(char isbn[])  //������isbn
{
	for (int i = 0; i < strlen(isbn); i++)
	{
		if (isdigit(isbn[i]) && strlen(isbn) == 13)
			continue;
		else return 0;
	}
	return 1;
}

int modify_name(Book b[], int n)
{
	char name_m[100] = "";
	while (strlen(name_m) == 0)
	{
		pos(2, 35); printf("�������µ�������");
		pos(2, 36);
		gets_s(name_m);
	}
	strcpy(b[n].name, name_m);
	return 1;
}

int modify_author(Book b[], int n)
{
	char author_m[100] = "";
	while (strlen(author_m) == 0)
	{
		pos(2, 35); printf("�������µ����ߣ�");
		pos(2, 36);
		gets_s(author_m);
	}
	strcpy(b[n].author, author_m);
	return 1;
}

int modify_isbn(Book b[], int n)
{
	char isbn_m[100] = "";
	while (strlen(isbn_m) == 0)
	{
		pos(2, 35); printf("�������µ�ISBN�ţ�");
		pos(2, 36);
		fflush(stdin);
		gets_s(isbn_m);
		if (judgeisbn(isbn_m) == 1)
		{
			strcpy(b[n].isbn, isbn_m);
		}
		else
		{
			pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 35); printf("���������������������룡");
			strcpy(isbn_m, "");
			Sleep(1000);
			pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
			continue;
		}
	}
	return 1;
}

int modify_publisher(Book b[], int n)
{
	char publisher_m[100] = "";
	while (strlen(publisher_m) == 0)
	{
		pos(2, 35); printf("�������µĳ����磺");
		pos(2, 36);
		gets_s(publisher_m);
	}
	strcpy(b[n].publisher, publisher_m);
	return 1;
}

int delete_m(Book b[], int n) //ɾ��
{
	char yn[100];
	int flag = 0;
	while (flag == 0)
	{
		pos(2, 35); printf("ȷ��ɾ���Ȿ�鼮����Y/N��");
		pos(2, 36);
		gets_s(yn);
		if (strlen(yn) == 0)
			continue;
		if (strcmp(yn, "Y") == 0)
		{
			strcpy(b[n].name, "0");
			flag = 1;
		}
		else if (strcmp(yn, "N") == 0)
		{
			pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 35); printf("�鼮δɾ����");
			Sleep(1000);
			flag = 1;
		}
		else
		{
			pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
			pos(2, 35); printf("���������������������룡");
			Sleep(1000);
			pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
		}
	}
	return 1;
}