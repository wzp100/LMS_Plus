#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"



//6.�ļ���������˵�
void save_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//6.1 �ļ����溯��
void fileSave(vector<Person>& Borrowers, vector<Book>& Books);
//6.2 �ļ�������
void fileSort(vector<Person>& Borrowers, vector<Book>& Books);
