#include "file.h"

//���ݵĶ�ȡ���������ļ�
int file_read(BookList L)
{
	
	BookList p, q;
	q = L;
	if ((fp = fopen("book_list.txt", "rb")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	p = (BookList)malloc(sizeof(BookNode));
	memset(p, 100, sizeof(BookNode));
	char str[512];
	char ch;
	int temp = 0;
	char buffer[1000];
	while (fgets(buffer, 512, fp))//�ȶ��ļ���һ������
	{
		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.name, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.author, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.publisher, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.isbn, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.borrower, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.is_borrowed, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.borrowtime, str);

		fscanf(fp, "%[^`]%*c", str);
		strcpy(p->data.returntime, str);

		p->next = q->next;
		q->next = p;
		q = q->next;
		p = (BookList)malloc(sizeof(BookNode));

	}
	BookList m, n;
	m = L;
	while (m != NULL && m->next != NULL)
	{
		if (strcmp(m->next->data.isbn, "0") == 0)
		{
			n = m->next;
			m->next = n->next;
			free(n);

		}
		m = m->next;
	}
	fclose(fp);
	return 0;
}
//���ݱ��溯��,д�ļ�
void file_save(BookList L)
{
	BookList p;
	p = L->next;
	if ((fp = fopen("book_list.txt", "wb")) == NULL) {
		printf("Save failed!\n");
		exit(0);
	}
	while (p != NULL) {
		fprintf(fp, "%s`%s`%s`%s`%s`%s`%s`%s` \r\n ", p->data.name, p->data.author, p->data.publisher, p->data.isbn, p->data.borrower, p->data.is_borrowed, p->data.borrowtime, p->data.returntime);
		p = p->next;
	}
	printf("����ɹ���\n");
	fclose(fp);
	fp = NULL;
}
void file_save_borrow_return(BookList L)
{
	BookList p;
	p = L->next;
	if ((fp = fopen("book_list.txt", "wb")) == NULL) {
		printf("Save failed!\n");
		exit(0);
	}
	fprintf(fp, "\n");
	int num = 0;
	while (p != NULL) {
		if ((strcmp(p->data.name, "0") != 0))//strcmp(p->data.is_borrowed,"0")==0|| strcmp(p->data.is_borrowed, "1") == 0) 
		{
			if (strcmp(p->data.is_borrowed, "0") == 0 || strcmp(p->data.is_borrowed, "1") == 0)
				fprintf(fp, "%s`%s`%s`%s`%s`%s`%s`%s`\r\n", p->data.name, p->data.author, p->data.publisher, p->data.isbn, p->data.borrower, p->data.is_borrowed, p->data.borrowtime, p->data.returntime);
		}
		p = p->next;


	}
	printf("����ɹ���\n");
	fclose(fp);
	fp = NULL;
}

void new_library()
{
	fp = fopen("book_list123.txt", "wb");
}

void suanfa()
{
	fp = fopen("lizi.txt", "wb");
	int a;
	int i, k;
	for (i = 1; i <= 20; i++)
		for (k = 1; k <= 20; k++)
		{
			if (k == i)
				a = 0;
			else
			{
				a = rand() % 10 + 1;
			}
			if (k != i)
				fprintf(fp, "%d %d %d\n", i, k, a);
		}
	fclose(fp);
}
