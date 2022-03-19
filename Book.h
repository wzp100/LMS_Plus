#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<chrono>
#include<fstream>
#include<sstream>

#include"Person.h"
#include"TimeProcess.h"
using namespace std;

class Person;

 struct InitBookStruct
{
	int ID;//0编号
	string Title;//1标题
	vector<string> Author;//2作者不止一个
	string Press;//3出版社
	int Price;//4定价
	int Status;//5状态，图书的状态，已借1，未借0，遗失未缴费2，遗失已缴费3，遗失4
	bool BorrowStatus;//6是否可借，1可以，0不可以
	chrono::system_clock::time_point BorrowTime;//7借阅时间
	chrono::system_clock::time_point ReturnTime;//8归还时间
	int BorrowerID;//10借书人ID，考虑到在文件读取时的操作，要先考虑数据的读取，再依靠ID去建立书与人的关系
	InitBookStruct() {
		ID = -1;
		Title = "";
		Author = {};
		Press = "";
		Price = -1;
		Status = 0;
		BorrowStatus = 1;
		BorrowTime = chrono::system_clock::time_point();
		ReturnTime = chrono::system_clock::time_point();
		BorrowerID = -1;
	};
 };


//TODO:首先构建好一个书籍基本类，然后构建一个大类，让大类可以创建许多小类，包含在其中。需要用到继承这个基本类。
class Book
{
public:
	//展示函数
	void display();
	//修改函数
	void modify();
	//借书函数
	bool borrow();
	bool borrow(int borrowerID);
	bool borrow(Person borrower);
	//还书函数
	void return_book();
	//构造函数
	Book(const InitBookStruct & book_list);
	//文件保存函数
	void save(ofstream& book_file);
	//文件读取函数
	void read(ifstream& book_file);
	//搜索函数
	bool searchBookID(int bookID);
	//检查是否可以借
	bool borrowEnable();

	//运算符重载
	bool operator< (const Book& b);

	bool operator> (const Book& b);

	void operator<<(Book& b);


	//友元函数
	friend class Person;


	//文件读取函数
	friend void book_file_read(vector<Book>& books);

	//总体借书函数
	friend void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);

	friend void titleSearchBook(vector<Book>& Books);

	friend void authorSearchBook(vector<Book>& Books);

	friend void pressSearchBook(vector<Book>& Books);

protected:
	int ID;//0编号
	string Title;//1标题
	vector<string> Author;//2作者不止一个
	string Press;//3出版社
	int Price;//4定价
	int Status;//5状态，图书的状态，已借1，未借0，遗失未缴费2，遗失已缴费3，遗失4
	bool BorrowStatus;//6是否可借，1可以，0不可以
	chrono::system_clock::time_point BorrowTime;//7借阅时间
	chrono::system_clock::time_point ReturnTime;//8归还时间

	Person *Borrower;//9借书人
	int BorrowerID;//10借书人ID，考虑到在文件读取时的操作，要先考虑数据的读取，再依靠ID去建立书与人的关系
	string BorrowerName;//11借书人姓名
	//int AllNumber;//总数量
	//int RemainingNumber;//剩余数量
public:
	// 在一个借书人vector中找到同名ID以实现对于借书人的关联
	void BulidRelationship(vector <Person>& borrowers);
};



void display_book_title();// 展示book表格的表头
