#include "update.h"

//���뺯��
void insert_book(BookList L)
{
	int i;
	int m = 0;
	sum++;
	BookList p = (BookList)malloc(sizeof(BookNode));
	//memset(p, 0, sizeof(BookNode));
isbn:
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("������������鼮��ISBN�ţ�");
	pos(2, 36);
	gets_s(p->data.isbn);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	if (strlen(p->data.isbn) == 0)
	{
		pos(2, 35); printf("��������Ϊ�գ�");
		Sleep(1000);
		goto isbn;
	}
	if (judgeisbn(p->data.isbn) != 1)
	{
		pos(2, 35); printf("��������ȷ��ISBN�ţ�");
		Sleep(1000);
		goto isbn;
	}
name:
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("������������鼮��������");
	pos(2, 36);
	gets_s(p->data.name);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	if (strlen(p->data.name) == 0)
	{
		pos(2, 35); printf("��������Ϊ�գ�");
		Sleep(1000);
		goto name;
	}
author:
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("������������鼮�����ߣ�");
	pos(2, 36);
	gets_s(p->data.author);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	if (strlen(p->data.author) == 0)
	{
		pos(2, 35); printf("��������Ϊ�գ�");
		Sleep(1000);
		goto author;
	}
publisher:
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("������������鼮�ĳ����磺");
	pos(2, 36);
	gets_s(p->data.publisher);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	if (strlen(p->data.publisher) == 0)
	{
		pos(2, 35); printf("��������Ϊ�գ�");
		Sleep(1000);
		goto publisher;
	}
	strcpy(p->data.borrower, "0");
	strcpy(p->data.is_borrowed, "0");
	strcpy(p->data.returntime, "0");
	strcpy(p->data.borrowtime, "0");
	BookList q;
	q = L;
	while (q != NULL && q->next != NULL)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	q = q->next;//q=p;
}

int delete_book(BookList head)//ɾ������
{
	printf("��������");
	char s[100];
	scanf("%s", s);
	BookList p, q;
	p = head;
	while (p != NULL && p->next != NULL)
	{
		q = p->next;
		if (strcmp(q->data.name, s) == 0)
		{
			p->next = q->next;
			free(q);
			q = NULL;
			p = p->next;
			return 1;
		}
		else
			p = p->next;
	}
	return 1;
}
