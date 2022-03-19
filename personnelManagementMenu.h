#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
//5.人员管理模块二级菜单
void personnelManagement_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//5.1 增加人员信息
void addPersonInfo(vector<Person>& Borrowers);
//5.2 删除人员信息
void deletePersonInfo(vector<Person>& Borrowers);
//5.3 修改人员信息
void modifyPerson(vector<Person>& Borrowers);
//5.4 按编号查询 
void idSearchPerson(vector<Person>& Borrowers);
//5.5 按姓名查询
void nameSearchPerson(vector<Person>& Borrowers);

