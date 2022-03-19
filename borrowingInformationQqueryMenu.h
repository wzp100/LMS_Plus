#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;
//3 借阅信息查询菜单选项显示
void borrowingInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//3.1 所有图书借阅情况
void allBooksInformation(vector<Book>& Books);
//3.2 所有人员借阅情况
void allPersonsInformation(vector<Person>& Borrowers, vector<Book>& Books);
//3.3 单书借阅信息查询
void singleBookInformation(vector<Book>& Books);
//3.4 单人借阅信息查询
void singlePersonInformation(vector<Person>& Borrowers, vector<Book>& Books);
