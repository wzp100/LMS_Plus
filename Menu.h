#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "User.h"
#include "Person.h"
#include "Book.h"
#include "borrowAndReturnBookMenu.h"
#include "libraryMaintenanceMenu.h"
#include "borrowingInformationQqueryMenu.h"
#include "bookInformationQqueryMenu.h"
#include "personnelManagementMenu.h"
#include "saveMenu.h"
#include "Admin.h"
using namespace std;
// 登录页面
void Login_Menu();

// 1.管理员登录函数
bool Admin_Login();





// 2.用户登录函数
bool User_Login();
// 2.1 用户主界面
void User_Main_Menu();

// 2.1.3 个人中心
void personal_Center_Menu();
//2.1.3.1 图书借阅信息
void personal_borrowBook_Info();

//2.1.3.2 个人信息查询
void personal_Informaton();

//2.1.3.3 个人信息修改
void personal_Info_modify();
// 3.用户注册函数
bool User_Register();

//主菜单
void Main_Menu();









//待定函数

// .所有信息查询二级菜单
void allInformationQquery_Menu(vector<Book>& Books);
//
