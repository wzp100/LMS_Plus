#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"



//6.文件保存二级菜单
void save_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//6.1 文件保存函数
void fileSave(vector<Person>& Borrowers, vector<Book>& Books);
//6.2 文件排序函数
void fileSort(vector<Person>& Borrowers, vector<Book>& Books);
