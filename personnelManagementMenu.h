#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
//5.��Ա����ģ������˵�
void personnelManagement_Menu(vector<Person>& Borrowers, vector<Book>& Books);
//5.1 ������Ա��Ϣ
void addPersonInfo(vector<Person>& Borrowers);
//5.2 ɾ����Ա��Ϣ
void deletePersonInfo(vector<Person>& Borrowers);
//5.3 �޸���Ա��Ϣ
void modifyPerson(vector<Person>& Borrowers);
//5.4 ����Ų�ѯ 
void idSearchPerson(vector<Person>& Borrowers);
//5.5 ��������ѯ
void nameSearchPerson(vector<Person>& Borrowers);

