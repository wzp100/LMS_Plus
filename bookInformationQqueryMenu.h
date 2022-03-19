#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
//4.图书信息查询二级菜单
void bookInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books);

//4.1 按编号查询
void idSearchBook(vector<Book>& Books);
//4.2 按标题查询
void titleSearchBook(vector<Book>& Books);
//4.3 按作者查询
void authorSearchBook(vector<Book>& Books);
//4.4 按出版社查询
void pressSearchBook(vector<Book>& Books);
