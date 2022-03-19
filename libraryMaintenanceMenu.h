#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;
//2.书库维护二级菜单
void libraryMaintenance_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//2.1 增加图书信息
void addBookInfo(vector<Book>& Books);
//2.2 删除图书信息函数
void deleteBookInfo(vector<Book>& Books);
//2.3 修改图书信息函数
void modifyBook(vector<Book>& Books);