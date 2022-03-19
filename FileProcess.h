#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Book.h"
#include "Person.h"
using namespace std;


void person_file_save(vector<Person>& persons);
void person_file_read(vector<Person>& persons);
void book_file_save(vector<Book>& books);
void book_file_read(vector<Book>& books);
