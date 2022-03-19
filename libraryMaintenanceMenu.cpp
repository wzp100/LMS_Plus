#include "libraryMaintenanceMenu.h"
using namespace std;
/// <summary>
/// 2.书库维护二级菜单
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void libraryMaintenance_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nManageChoose = 0;
	while (1)
	{
		system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********书库维护模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.增加图书信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.删除图书信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.修改图书信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------ \n");
		printf("\t\t   请选择功能序号(0~3):");
		//读入用户选择
		cin >> nManageChoose;

		switch (nManageChoose)
		{
		case 1:
			addBookInfo(Books);//转到增加图书信息函数
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//输出给用户看一下
			system("PAUSE");
			break;
		case 2:
			deleteBookInfo(Books);//转到删除图书信息函数
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//输出给用户看一下
			system("PAUSE");
			break;
		case 3:
			modifyBook(Books);//转到修改图书信息函数
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//输出给用户看一下
			system("PAUSE");
			break;
		case 0:
			//用户返回上一级
			return;
			break;
			//用户选择有误
		default:
			printf("\t\t选择有误，请重选！\n");
		}
	}
}


/// <summary>
/// 2.1 增加图书信息
/// </summary>
/// <param name="Books"></param>
void addBookInfo(vector<Book>& Books)
{
	InitBookStruct bookList;
	int length;
	bool status = false;
	while (true)
	{
		cout << "请输入ID:";
		cin >> bookList.ID;
		if (bookList.ID == 0)
		{
			return;
		}
		for (Book temp_Book : Books)
		{
			//判断当前ID是否已占用
			if (temp_Book.searchBookID(bookList.ID))
			{
				status = true;
				break;
			}
		}

		if (status == true)
		{
			cout << "当前ID已占用,请重新输入ID,（输入0退出）" << endl;
			status = false;
		}
		else
		{
			break;
		}
	}
	cout << "请输入书名:";
	cin >> bookList.Title;
	cout << "请输入有几位作者:";
	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		cout << "请输入作者" << i + 1 << ":";
		string author;
		cin >> author;
		bookList.Author.push_back(author);
	}
	cout << "请输入出版社:";
	cin >> bookList.Press;
	cout << "请输入图书价格:";
	cin >> bookList.Price;
	Book temp_book(bookList);

	cout << "请检查信息是否正确" << endl;
	display_book_title();
	temp_book.display();
	Books.push_back(temp_book);
	cout << "增加图书成功" << endl;
}


/// <summary>
/// 2.2 删除图书信息函数
/// </summary>
/// <param name="Books"></param>
void deleteBookInfo(vector<Book>& Books)
{
	cout << "  当前为图书信息删除模块  " << endl;

	int temp_ID;
	cout << "请输入要删除图书的ID(请确保当前图书没有被借):" << endl;
	cin >> temp_ID;
	for (vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++)
	{
		//从vector中删除指定的某一个元素

		if ((*iter).searchBookID(temp_ID))
		{
			if ((*iter).borrowEnable())
			{
				Books.erase(iter);//把当前书ID删除
				cout << "删除成功" << endl;
				return;
				break;
			}
			else
			{
				cout << "当前书已被借，无法删除" << endl;
				return;
			}
		}
	}
	cout << "未找到ID相关信息，请检查ID是否正确" << endl;
}


/// <summary>
/// 2.3 修改图书信息函数
/// </summary>
/// <param name="Books"></param>
void modifyBook(vector<Book>& Books)
{
	int temp_ID;
	cout << "请输入要修改的ID:" << endl;
	cin >> temp_ID;
	for (vector<Book>::iterator i = Books.begin(); i != Books.end(); i++)
	{
		if ((*i).searchBookID(temp_ID))
		{
			if ((*i).borrowEnable())
			{
				(*i).modify();
				cout << "请检查修改后的结果" << endl;
				display_book_title();
				(*i).display();
				return;
			}
			else
			{
				cout << "当前书已被借,无法修改" << endl;
				return;
			}
		}
	}
	cout << "没有找到ID" << endl;
}

