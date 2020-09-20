#include "linkList.h"
#include"file.h"
int sum;
FILE* fp;
BookList head;

void Init_List()
{
	head = (BookList)malloc(sizeof(BookNode));
	head->next = NULL;
}

//创建一个单链表(尾插法)
void CreatList_L(BookList L, int n)
{
	int i;
	BookList p, q;
	q = L;
	for (i = 1; i <= n; i++) {
		p = (BookList)malloc(sizeof(BookNode));
		scanf("%s %s %s %d %s %s", p->data.author, p->data.borrower, p->data.isbn, &p->data.is_borrowed, p->data.name, p->data.publisher);
		p->next = q->next;
		q->next = p;
		q = q->next;//q=p;
	}
	sum = i - 1;
}
//输出线性表(递归与非递归)
void TraverList_L(BookList head)
{

	BookList p;
	p = head->next;
	while (p != NULL) {

		printf("书名：%s 作者：%s 出版社：%s ISBN号：%s ", p->data.name, p->data.author, p->data.publisher, p->data.isbn);
		if (strcmp(p->data.is_borrowed, "0") == 0)
			printf("该书在馆\n");
		else
			printf("该书不在馆,借走时间为%s,最晚归还时间为%s\n", p->data.borrowtime, p->data.returntime);
		printf("\n");
		p = p->next;
	}
}

void initLibrary()		//书库的初始化过程
{
	Init_List();
	file_read(head);
}

void bubble_sort(Book b[], int n)
{
	Book temp_book;
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 0; k < n - i - 1; k++)
		{

			if (strcmp(b[k].isbn, b[k + 1].isbn) > 0)
			{
				temp_book = b[k];
				b[k] = b[k + 1];
				b[k + 1] = temp_book;
			}
		}
	}
}