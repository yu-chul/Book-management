
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED


#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include"linkList.h"

//���ݵĶ�ȡ���������ļ�
 int file_read(BookList L);

//���ݱ��溯��,д�ļ�
extern void file_save(BookList L);

extern void file_save_borrow_return(BookList L);

extern void new_library();

extern void suanfa();

#endif // FILE_H_INCLUDED
