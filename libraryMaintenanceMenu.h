#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;
//2.���ά�������˵�
void libraryMaintenance_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//2.1 ����ͼ����Ϣ
void addBookInfo(vector<Book>& Books);
//2.2 ɾ��ͼ����Ϣ����
void deleteBookInfo(vector<Book>& Books);
//2.3 �޸�ͼ����Ϣ����
void modifyBook(vector<Book>& Books);