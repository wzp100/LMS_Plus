#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;
//3 ������Ϣ��ѯ�˵�ѡ����ʾ
void borrowingInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//3.1 ����ͼ��������
void allBooksInformation(vector<Book>& Books);
//3.2 ������Ա�������
void allPersonsInformation(vector<Person>& Borrowers, vector<Book>& Books);
//3.3 ���������Ϣ��ѯ
void singleBookInformation(vector<Book>& Books);
//3.4 ���˽�����Ϣ��ѯ
void singlePersonInformation(vector<Person>& Borrowers, vector<Book>& Books);
