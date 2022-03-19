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
	int ID;//0���
	string Title;//1����
	vector<string> Author;//2���߲�ֹһ��
	string Press;//3������
	int Price;//4����
	int Status;//5״̬��ͼ���״̬���ѽ�1��δ��0����ʧδ�ɷ�2����ʧ�ѽɷ�3����ʧ4
	bool BorrowStatus;//6�Ƿ�ɽ裬1���ԣ�0������
	chrono::system_clock::time_point BorrowTime;//7����ʱ��
	chrono::system_clock::time_point ReturnTime;//8�黹ʱ��
	int BorrowerID;//10������ID�����ǵ����ļ���ȡʱ�Ĳ�����Ҫ�ȿ������ݵĶ�ȡ��������IDȥ���������˵Ĺ�ϵ
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


//TODO:���ȹ�����һ���鼮�����࣬Ȼ�󹹽�һ�����࣬�ô�����Դ������С�࣬���������С���Ҫ�õ��̳���������ࡣ
class Book
{
public:
	//չʾ����
	void display();
	//�޸ĺ���
	void modify();
	//���麯��
	bool borrow();
	bool borrow(int borrowerID);
	bool borrow(Person borrower);
	//���麯��
	void return_book();
	//���캯��
	Book(const InitBookStruct & book_list);
	//�ļ����溯��
	void save(ofstream& book_file);
	//�ļ���ȡ����
	void read(ifstream& book_file);
	//��������
	bool searchBookID(int bookID);
	//����Ƿ���Խ�
	bool borrowEnable();

	//���������
	bool operator< (const Book& b);

	bool operator> (const Book& b);

	void operator<<(Book& b);


	//��Ԫ����
	friend class Person;


	//�ļ���ȡ����
	friend void book_file_read(vector<Book>& books);

	//������麯��
	friend void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);

	friend void titleSearchBook(vector<Book>& Books);

	friend void authorSearchBook(vector<Book>& Books);

	friend void pressSearchBook(vector<Book>& Books);

protected:
	int ID;//0���
	string Title;//1����
	vector<string> Author;//2���߲�ֹһ��
	string Press;//3������
	int Price;//4����
	int Status;//5״̬��ͼ���״̬���ѽ�1��δ��0����ʧδ�ɷ�2����ʧ�ѽɷ�3����ʧ4
	bool BorrowStatus;//6�Ƿ�ɽ裬1���ԣ�0������
	chrono::system_clock::time_point BorrowTime;//7����ʱ��
	chrono::system_clock::time_point ReturnTime;//8�黹ʱ��

	Person *Borrower;//9������
	int BorrowerID;//10������ID�����ǵ����ļ���ȡʱ�Ĳ�����Ҫ�ȿ������ݵĶ�ȡ��������IDȥ���������˵Ĺ�ϵ
	string BorrowerName;//11����������
	//int AllNumber;//������
	//int RemainingNumber;//ʣ������
public:
	// ��һ��������vector���ҵ�ͬ��ID��ʵ�ֶ��ڽ����˵Ĺ���
	void BulidRelationship(vector <Person>& borrowers);
};



void display_book_title();// չʾbook���ı�ͷ
