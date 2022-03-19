#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include<ctime>
#include<chrono>
#include <vector>
#include <chrono>
#include <fstream>


#include "Book.h"

const int Man =1;
const int  Woman =0;
const int StudentType = 0;
const int TeacherType =1;



using namespace std;
//TODO:���Ʊ���

class Book;
//��ʼ���ṹ��
struct InitPersonStruct
{
	int ID;//���
	string Name;//����
	int Age;//����
	bool Gender;//�Ա���Ϊ1��ŮΪ0
	size_t PhoneNumber;//�绰
	//int BookNumberLimit;//ͼ�������������
	int BorrowedNumber;//�ѽ���Ŀ
	vector <int> BooksID;//�ӵ������ID����
	int Type;//����������
	InitPersonStruct()
	{
		ID = -1;
		Name = "��";
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
	//ͨ���ṹ�幹����
	Person(const InitPersonStruct& person_list);
	
	//չʾ����
	void display();

	//ͨ��������Ӧ������޸���Ӧ�ı���
	void modify();
	void personal_modify();
	
	//���麯��,�������ID����������洢ID��
	void borrow(Book &  borrowing_book);
	
	//���麯��
	void return_book(Book& returning_book);
	
	//TODO:ͨ�����е���ID�ҵ�����������ʾ
	void display_all_books( vector<Book>& books);
	void display_all_books();
	
	//������ԱID����
	bool searchPersonID(int personID);
	//������Ա��������
	bool searchPersonName(string name);


	//�����ȡ����
	void save(ofstream &person_file);
	
	void read(ifstream & person_file);

	//�ַ�������
	bool operator< (const Person& b);
	void operator<< ( Person& b);
	bool operator> (const Person& b);


	static void display_header();
	static void display_all_books_header();
	static void add_a_Borrower();
	static void delete_a_Borrower();
	//��Ԫ
	friend Book;

	//��Ԫ����

	//��Ա���ݶ�ȡ
	friend void person_file_read(vector<Person>& persons);
	
	//���麯��
	friend void borrowBook(vector<Person>& Borrowers, vector<Book>& Books);
	
	//��������
	friend int searchPerson(vector<Person>& Borrowers, int ID);

	//���麯��
	friend void returnBook(vector<Person>& Borrowers, vector<Book>& Books);
	//��Ա��Ϣɾ��
	friend void deletePersonInfo(vector<Person>& Borrowers);
	//��Ա��Ϣ�޸ĺ���
	friend void modifyPerson(vector<Person>& Borrowers);
	//�����ƶ����ݺ���
	friend void mov_data_from_person_to_user();
	//���ʱ��

private:
	int ID;//0���
	string Name;//1����
	int Age;//2����
	bool Gender;//3�Ա���Ϊ1��ŮΪ0
	size_t PhoneNumber;//4�绰
	int BookNumberLimit;//5ͼ�������������
	int BorrowedNumber;//6�ѽ���Ŀ
	vector <int> BooksID ;//7�ӵ������ID����
	int Type;//8��𣬱�ʾ�˵����ͣ���ͬ���в�ͬ�Ľ�����Ŀ���Լ������ʱ��,0ѧ��,1��ʦ,����
	chrono::system_clock::duration BorrowDuration;//9�����ʱ��
};


void display_person_title();// չʾperson����ı�ͷ