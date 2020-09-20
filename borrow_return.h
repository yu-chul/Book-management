#ifndef _BORROW_RETURN_H
#define _BORROW_RETURN_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <time.h>
#include "linkList.h"
#include "file.h"
#include "drawer.h"

int borrow(Book b[], int n);

int return_book(Book b[], int n);
#endif