#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <fstream>

#include "Book.h"

const int Man =1;
const int  Woman =0;
const int StudentType = 0;
const int TeacherType =1;

using namespace std;
//TODO:完善变量

class Book;
//初始化结构体
struct InitPersonStruct
{
	int ID;//编号
	string Name;//姓名
	int Age;//年龄
	bool Gender;//性别，男为1，女为0
	size_t PhoneNumber;//电话
	//int BookNumberLimit;//图书借阅数量限制
	int BorrowedNumber;//已借数目
	vector <int> BooksID;//接到的书的ID数组
	int Type;//借书人类型
	InitPersonStruct()
	{
		ID = -1;
		Name = "无";
		Age = -1;
		Gender = Man;
		PhoneNumber = -1;
		BorrowedNumber = 0;
		BooksID = {};
		Type = StudentType;

	}
};

class Person
{
public:
	//通过结构体构建类
	Person(const InitPersonStruct& person_list);
	
	//展示函数
	void display();

	//通过输入相应的序号修改相应的变量
	void modify();
	
	//借书函数,输入书的ID，将其纳入存储ID中
	void borrow(Book &  borrowing_book);
	
	//还书函数
	void return_book(Book& returning_book);
	
	//TODO:通过所有的书ID找到书名，并显示
	void display_all_books( vector<Book>& books);
	
	//搜索人员ID函数
	bool searchPersonID(int personID);
	//搜索人员姓名函数
	bool searchPersonName(string name);


	//保存读取函数
	void save(ofstream &person_file);
	
	void read(ifstream & person_file);

	//字符的重载
	bool operator< (const Person& b);
	void operator<< ( Person& b);
	bool operator> (const Person& b);




	//友元
	friend Book;

	//友元函数

	//人员数据读取
	friend void person_file_read(vector<Person>& persons);
	
	//借书函数
	friend void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);
	
	//搜索函数
	friend int searchPerson(vector<Person>& Borrowers, int ID);

	//还书函数
	friend void returnBook(vector<Person>& Borrowers, vector<Book>& Books);
	//人员信息删除
	friend void deletePersonInfo(vector<Person>& Borrowers);
	//人员信息修改函数
	friend void modifyPerson(vector<Person>& Borrowers);
private:
	int ID;//0编号
	string Name;//1姓名
	int Age;//2年龄
	bool Gender;//3性别，男为1，女为0
	size_t PhoneNumber;//4电话
	int BookNumberLimit;//5图书借阅数量限制
	int BorrowedNumber;//6已借数目
	vector <int> BooksID ;//7接到的书的ID数组
	int Type;//8组别，表示人的类型，不同人有不同的借书数目，以及借书的时长,0学生,1老师,其他
	chrono::system_clock::duration BorrowDuration;//9借书的时长
};


void display_person_title();// 展示person表格的表头

