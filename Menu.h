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
// ��¼ҳ��
void Login_Menu();

// 1.����Ա��¼����
bool Admin_Login();





// 2.�û���¼����
bool User_Login();
// 2.1 �û�������
void User_Main_Menu();

// 2.1.3 ��������
void personal_Center_Menu();
//2.1.3.1 ͼ�������Ϣ
void personal_borrowBook_Info();

//2.1.3.2 ������Ϣ��ѯ
void personal_Informaton();

//2.1.3.3 ������Ϣ�޸�
void personal_Info_modify();
// 3.�û�ע�ắ��
bool User_Register();

//���˵�
void Main_Menu();









//��������

// .������Ϣ��ѯ�����˵�
void allInformationQquery_Menu(vector<Book>& Books);
//
