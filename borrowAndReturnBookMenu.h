#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;

//1.�軹������˵�
void borrowAndReturnBook_Menu(vector<Person>& Borrowers, vector<Book>& Books);

//������������
int searchPerson(vector<Person>& Borrowers, int ID);
//1.1���麯��
void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);
//1.2���麯��
void returnBook(vector<Person>& Borrowers, vector<Book>& Books);

