#include "borrowingInformationQqueryMenu.h"


/// <summary>
/// 3.借阅信息查询菜单
/// </summary>
/// <param name="Books"></param>
/// <param name="Borrowers"></param>
void borrowingInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|********借阅信息查询模块********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.所有图书借阅情况      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.所有人员借阅情况      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        3.单书借阅信息查询      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        4.单人借阅信息查询      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.返回上级菜单          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   请选择功能序号(0~4):");
		//读入用户选择
		//scanf("%d", &nSortChoose);
		cin >> nSortChoose;
		system("CLS");
		switch (nSortChoose)
		{
		case 1:
			//3.1 所有图书借阅情况
			allBooksInformation(Books);
			system("PAUSE");
			break;
		case 2:
			//3.2 所有人员借阅情况
			allPersonsInformation(Borrowers, Books);
			system("PAUSE");
			break;
		case 3:
			//3.3 单书借阅信息查询
			singleBookInformation(Books);
			system("PAUSE");
			break;
		case 4:
			//3.4 单人借阅信息查询
			singlePersonInformation(Borrowers, Books);
			system("PAUSE");
			break;
		case 0:
			return;
			break;
		default:printf("\t\t选择有误，请重选！\n");
		}//switch结束
	}//while(1)结束
}

/// <summary>
/// 3.1 所有图书借阅情况
/// </summary>
/// <param name="Books"></param>
void allBooksInformation(vector<Book>& Books)
{
	cout << "当前书籍的信息" << endl;
	//测试展示函数
	display_book_title();
	for (Book temp_book : Books)
	{
		temp_book.display();
	}
}

/// <summary>
/// 3.2 所有人员借阅情况
/// </summary>
/// <param name="Borrowers"></param>
void allPersonsInformation(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "当前书籍的信息" << endl;
	//测试展示函数
	display_person_title();
	for (Person temp_person : Borrowers)
	{
		temp_person.display();
		temp_person.display_all_books(Books);
	}
}

/// <summary>
/// 3.3 单人借阅信息查询
/// </summary>
/// <param name="Books"></param>
void singleBookInformation(vector<Book>& Books)
{
	int temp_ID;
	cout << "请输入书籍ID:";
	cin >> temp_ID;
	for (Book temp_Book : Books)
	{
		if (temp_Book.searchBookID(temp_ID))
		{
			display_book_title();
			temp_Book.display();
			return;
			break;
		}
	}
	cout << "没有找到此书" << endl;
}

/// <summary>
/// 3.4 单人借阅信息查询
/// </summary>
/// <param name="Borrowers"></param>
void singlePersonInformation(vector<Person>& Borrowers, vector<Book>& Books)
{
	int temp_ID;
	cout << "请输入人员ID:";
	cin >> temp_ID;
	for (Person temp_Borrower : Borrowers)
	{
		if (temp_Borrower.searchPersonID(temp_ID))
		{
			display_person_title();
			temp_Borrower.display();
			temp_Borrower.display_all_books(Books);
			return;
			break;
		}
	}
	cout << "没有找到此人" << endl;
}

