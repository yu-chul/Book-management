#include "find.h"

//BF算法
int BF(char s[], char t[])
{
	int i = 0;
	int j = 0;
	int n = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (t[j] != '\0')
	{
		j++;
	}
	int ss = i;
	int ts = j;
	i = 0, j = 0;
	while (i < ss)
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == ts)
		{
			n++;
		}
	}
	if (n >= 1)
		return 1;
	else
		return 0;
}
//单关键词查找函数
int singleFind(BookList head, char n, Book*l, int t,char s[])
{
	BookList p, q;
	p = head;
	switch (n)
	{
	case '1':
	{
		while (p != NULL && p->next != NULL)
		{
			q = p->next;
			if (BF(q->data.name, s) == 1)
			{
				l[t] = q->data;
				p->next = q->next;
				q = NULL;
				t++;
			}
			else
				p = p->next;
		}
	}
	break;
	case '2':
	{
		while (p != NULL && p->next != NULL)
		{
			q = p->next;
			if (BF(q->data.author, s) == 1)
			{
				l[t] = q->data;
				p->next = q->next;
				q = NULL;
				t++;
			}
			else
				p = p->next;
		}
	}
	break;
	case '3':
	{
		while (p != NULL && p->next != NULL)
		{
			q = p->next;
			if (BF(q->data.publisher, s) == 1)
			{
				l[t] = q->data;
				p->next = q->next;
				q = NULL;
				t++;
			}
			else
				p = p->next;
		}
	}
	break;
	case '4':
	{
		while (p != NULL && p->next != NULL)
		{
			q = p->next;
			if (BF(q->data.isbn, s) == 1)
			{
				l[t] = q->data;
				p->next = q->next;
				q = NULL;
				t++;
			}
			else
				p = p->next;
		}
	}
	break;
	}
	return t;
}
//多关键字查找
int doubleFind(BookList head, Book*l, char n, int t,char s[])
{
	BookList p;
	p = head;
	int k = 0;
	while (p != NULL && p->next != NULL)
	{
		p = p->next;
	}
	switch (n)
	{
	case '1':
	{
		for (int i = 0; i < t; i++)
		{
			if (BF(l[i].name, s) == 0)
			{
				BookList x = (BookList)malloc(sizeof(BookNode));
				x->data = l[i];
				x->next = p->next;
				p->next = x;
				p = p->next;
				for (int j = i; j < t - 1; j++)
					l[j] = l[j + 1];
				k++;
				i--;
			}
		}
		t -= k;
	}
	break;
	case '2':
	{
		for (int i = 0; i < t; i++)
		{
			if (BF(l[i].author, s) == 0)
			{
				BookList x = (BookList)malloc(sizeof(BookNode));
				x->data = l[i];
				x->next = p->next;
				p->next = x;
				p = p->next;
				for (int j = i; j < t - 1; j++)
					l[j] = l[j + 1];
				k++;
				i--;
			}
		}
		t -= k;
	}
	break;
	case '3':
	{
		for (int i = 0; i < t; i++)
		{
			if (BF(l[i].publisher, s) == 0)
			{
				BookList x = (BookList)malloc(sizeof(BookNode));
				x->data = l[i];
				x->next = p->next;
				p->next = x;
				p = p->next;
				for (int j = i; j < t - 1; j++)
					l[j] = l[j + 1];
				k++;
				i--;
			}
		}
		t -= k;
	}
	break;
	case '4':
	{
		for (int i = 0; i < t; i++)
		{
			if (BF(l[i].isbn, s) == 0)
			{
				BookList x = (BookList)malloc(sizeof(BookNode));
				x->data = l[i];
				x->next = p->next;
				p->next = x;
				p = p->next;
				for (int j = i; j < t - 1; j++)
					l[j] = l[j + 1];
				k++;
				i--;
			}
		}
		t -= k;
	}
	break;
	}
	return t;
}

//全导出函数
int All_find(BookList head, Book*l, int t)
{
	BookList p, q;
	p = head;
	while (p != NULL && p->next != NULL)
	{
		q = p->next;
		l[t] = q->data;
		p->next = q->next;
		q = NULL;
		//p = p->next;
		t++;
	}
	return t;
}
//规范输入辅助函数1
int ha(char arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (arr[j] == arr[i])
				return 1;

	return 0;
}
//规范输入辅助函数2
int hb(char n[])
{
	int i = 0;
	while (n[i] != '\0')
	{
		if (n[i] <= '0' || n[i] > '4')
			return 1;
		i++;
	}
	return 0;
}
//规范输入辅助函数3
int hc(char s[])
{
	int i = 0, t = 0;
	while (s[i] != '\0')
	{
		if ('0' <= s[i] && s[i] <= '9')
			t++;
		i++;
	}
	int j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == '0'&&t == 1)
			return 1;
		j++;
	}
	return 0;
}
//生成临时数组：Book *l = (Book*)malloc(500 * sizeof(Book));
//查找主逻辑
//l是临时数组，n是数组里的元素个数（即数组最后一位下标+1
int find(BookList head, Book*l, int n, char s[], int t, char isbn[], char name[], char author[], char pub[])
{
	/*
	printf("请输入要选择的检索关键字(仅输入编号)");
	printf("输入编号:");
	char s[100];
	scanf("%s", s);
	int t = 0, i = 0;
	if (hc(s) == 1)
		t = 0;
	else
	{
		do
		{
			if (t >= 5 || ha(s, t) || hb(s))
			{
				printf("您的输入有误，请重新输入");
				scanf("%s", s);
				t = 0;
				i = 0;
			}
			if (hc(s) == 1)
			{
				t = 0;
				break;
			}
			while (s[i] != '\0')
			{
				if ('0' <= s[i] && s[i] <= '9')
					t++;
				i++;
			}
			printf("%d", t);
		} while (t >= 5 || ha(s, t) || hb(s));
	}
	*/
	int i = 0, m = 0;
	switch (t)
	{
	case 0:
	{
		n = All_find(head, l, n);
	}
	break;
	case 1:
	{
		char s2;
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] <= '4'&&s[i] >= '1')
				s2 = s[i];
			i++;
		}
		switch (s2)
		{
		case '1':
			n = singleFind(head, s2, l, n, name);
			break;
		case '2':
			n = singleFind(head, s2, l, n, author);
			break;
		case '3':
			n = singleFind(head, s2, l, n, pub);
			break;
		case '4':
			n = singleFind(head, s2, l, n, isbn);
			break;
		default:
			break;
		}
	}
	break;
	case 2:
	{
		char s3[2];
		i = 0; m = 0;
		while (s[i] != '\0')
		{
			if (s[i] <= '4'&&s[i] >= '1')
			{
				s3[m] = s[i];
				m++;
			}
			i++;
		}
		switch (s3[0])
		{
		case '1':
			n = singleFind(head, s3[0], l, n, name);
			break;
		case '2':
			n = singleFind(head, s3[0], l, n, author);
			break;
		case '3':
			n = singleFind(head, s3[0], l, n, pub);
			break;
		case '4':
			n = singleFind(head, s3[0], l, n, isbn);
			break;
		default:
			break;
		}
		switch (s3[1])
		{
		case '1':
			n = doubleFind(head, l, s3[1], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s3[1], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s3[1], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s3[1], n, isbn);
			break;
		default:
			break;
		}
	}
	break;
	case 3:
	{
		char s4[3];
		i = 0; m = 0;
		while (s[i] != '\0')
		{
			if (s[i] <= '4'&&s[i] >= '1')
			{
				s4[m] = s[i];
				m++;
			}
			i++;
		}
		switch (s4[0])
		{
		case '1':
			n = singleFind(head, s4[0], l, n, name);
			break;
		case '2':
			n = singleFind(head, s4[0], l, n, author);
			break;
		case '3':
			n = singleFind(head, s4[0], l, n, pub);
			break;
		case '4':
			n = singleFind(head, s4[0], l, n, isbn);
			break;
		default:
			break;
		}
		switch (s4[1])
		{
		case '1':
			n = doubleFind(head, l, s4[1], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s4[1], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s4[1], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s4[1], n, isbn);
			break;
		default:
			break;
		}
		switch (s4[2])
		{
		case '1':
			n = doubleFind(head, l, s4[2], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s4[2], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s4[2], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s4[2], n, isbn);
			break;
		default:
			break;
		}
	}
	break;
	case 4:
	{
		char s5[4];
		i = 0; m = 0;
		while (s[i] != '\0')
		{
			if (s[i] <= '4'&&s[i] >= '1')
			{
				s5[m] = s[i];
				m++;
			}
			i++;
		}
		switch (s5[0])
		{
		case '1':
			n = singleFind(head, s5[0], l, n, name);
			break;
		case '2':
			n = singleFind(head, s5[0], l, n, author);
			break;
		case '3':
			n = singleFind(head, s5[0], l, n, pub);
			break;
		case '4':
			n = singleFind(head, s5[0], l, n, isbn);
			break;
		default:
			break;
		}
		switch (s5[1])
		{
		case '1':
			n = doubleFind(head, l, s5[1], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s5[1], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s5[1], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s5[1], n, isbn);
			break;
		default:
			break;
		}
		switch (s5[2])
		{
		case '1':
			n = doubleFind(head, l, s5[2], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s5[2], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s5[2], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s5[2], n, isbn);
			break;
		default:
			break;
		}
		switch (s5[3])
		{
		case '1':
			n = doubleFind(head, l, s5[3], n, name);
			break;
		case '2':
			n = doubleFind(head, l, s5[3], n, author);
			break;
		case '3':
			n = doubleFind(head, l, s5[3], n, pub);
			break;
		case '4':
			n = doubleFind(head, l, s5[3], n, isbn);
			break;
		default:
			break;
		}
	}
	break;
	}
	return n;
}

int search(BookList head, Book* l, int n)
{
	fflush(stdin);
	char isbn[100], name[100], author[100], pub[100], temp[100];
	gets_s(temp);
	pos(2, 35); printf("请输入欲搜索的ISBN号：");
	pos(2, 36);
	gets_s(isbn);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("请输入欲搜索的书名：");
	pos(2, 36);
	gets_s(name);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("请输入欲搜索的作者：");
	pos(2, 36);
	gets_s(author);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 35); printf("请输入欲搜索的出版社：");
	pos(2, 36);
	gets_s(pub);
	pos(2, 35); for (int i = 0; i < 140; i++) { printf(" "); }
	pos(2, 36); for (int i = 0; i < 140; i++) { printf(" "); }
	int count = 0;
	char slctr[50] = "";
	if (strlen(isbn) != 0)
	{
		strcat(slctr, "4 ");
		count++;
	}
	if (strlen(name) != 0)
	{
		strcat(slctr, "1 ");
		count++;
	}
	if (strlen(author) != 0)
	{
		strcat(slctr, "2 ");
		count++;
	}
	if (strlen(pub) != 0)
	{
		strcat(slctr, "3 ");
		count++;
	}
	if (count == 0)
		strcpy(slctr, "0");
	n = find(head, l, n, slctr, count, isbn, name, author, pub);
	return n;
}

int insert_find(Book b[], BookList L, int n)//ljh
{
	BookList q;
	q = L;
	while (q != NULL && q->next != NULL)
	{
		q = q->next;
	}

	int i;
	BookList p;
	for (i = 0; i < n; i++) {
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
	return 1;
}