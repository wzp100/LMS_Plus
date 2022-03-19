#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;

//1.借还书二级菜单
void borrowAndReturnBook_Menu(vector<Person>& Borrowers, vector<Book>& Books);

//读者搜索函数
int searchPerson(vector<Person>& Borrowers, int ID);
//1.1借书函数
void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);
//1.2还书函数
void returnBook(vector<Person>& Borrowers, vector<Book>& Books);

