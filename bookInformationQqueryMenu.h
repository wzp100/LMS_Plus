#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
//4.ͼ����Ϣ��ѯ�����˵�
void bookInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books);

//4.1 ����Ų�ѯ
void idSearchBook(vector<Book>& Books);
//4.2 �������ѯ
void titleSearchBook(vector<Book>& Books);
//4.3 �����߲�ѯ
void authorSearchBook(vector<Book>& Books);
//4.4 ���������ѯ
void pressSearchBook(vector<Book>& Books);
