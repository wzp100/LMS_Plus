#include "borrowAndReturnBookMenu.h"


/// <summary>
/// 1.借书的二级菜单
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void borrowAndReturnBook_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nMainchoose;
	//主菜单无限循环
	while (1)
	{
		system("CLS"); //系统屏幕清空
		//输出菜单主界面
		printf("\t\t------------------------------\n");
		printf("\t\t|********借书还书模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.借阅图书          |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.归还图书          |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------ \n");
		printf("\t\t   请选择功能序号:");


		//用户根据界面提示输入数字
		cin >> nMainchoose;
		system("CLS");
		//根据用户输入的数字看如何行动
		switch (nMainchoose)
		{
			//转到借书函数
		case 1:
			borrowBook(Borrowers, Books);
			system("PAUSE");
			break;

			//转到还书函数
		case 2:
			returnBook(Borrowers, Books);
			system("PAUSE");
			break;

			//转到二级菜单：书库维护菜单选项显示
		case 3:
			break;

		case 0:
			return;
			break;
			//用户选择有误
		default:
			printf("选择有误，请重选！\n");
		}//switch结束
	}//while(1)函数结束
}



int searchPerson(vector<Person>& Borrowers, int ID)
{
	int n = 0;
	for (Person& temp_Person : Borrowers)
	{
		if (ID == temp_Person.ID)
		{
			return n;//找到返回编号
		}
		n++;
	}
	return -1;//没有找到返回-1
}

/// <summary>
/// 1.1借书函数
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void borrowBook(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  当前为借书模块  " << endl;

	int temp_ID;//暂存ID
	int temp_BookID;
	int temp_Number;//序号
	bool searchStatus = false;
	cout << "请输入用户ID:";
	cin >> temp_ID;

	//得到当前的序号
	temp_Number = searchPerson(Borrowers, temp_ID);
	if (temp_Number > 0)
	{
		display_person_title();//显示表头
		Borrowers[temp_Number].display();//显示信息
		cout << "请检查信息是否正确" << endl;
		cout << "请输入要借书的ID:";
		cin >> temp_BookID;
		//检查当前书的ID是否可以找到
		for (Book& temp_book : Books)
		{
			if (temp_book.searchBookID(temp_BookID))
			{
				searchStatus = true;
				Borrowers[temp_Number].borrow(temp_book);
				//显示当前的信息
				cout << "请检查以下信息是否正确" << endl;
				display_book_title();
				temp_book.display();
				display_person_title();
				Borrowers[temp_Number].display();
				Borrowers[temp_Number].display_all_books(Books);
				break;
			}

		}
		//找到了书
		if (searchStatus == true)
		{

		}
		//没有找到
		else
		{
			cout << "没有找到对应书ID，请重试" << endl;
		}

	}
	//没有找到ID
	else
	{
		cout << "没有找到对应ID，请重试" << endl;
	}

}


/// <summary>
/// 1.2总体还书函数
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void returnBook(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  当前为还书模块  " << endl;

	int temp_ID;//暂存ID
	int temp_BookID;
	int temp_Number;//序号
	bool searchStatus = false;
	cout << "请输入用户ID:";
	cin >> temp_ID;

	//得到当前的序号
	temp_Number = searchPerson(Borrowers, temp_ID);
	//如果没有借书直接结束
	if (Borrowers[temp_Number].BooksID.size() == 0)
	{
		cout << "当前没有借书" << endl;
		return;
	}
	if (temp_Number > 0)
	{
		display_person_title();//显示表头
		Borrowers[temp_Number].display();//显示信息
		Borrowers[temp_Number].display_all_books(Books);
		cout << "请检查信息是否正确" << endl;
		cout << "请输入要还书的ID:";
		cin >> temp_BookID;
		//检查当前书的ID是否可以找到
		for (Book& temp_book : Books)
		{
			if (temp_book.searchBookID(temp_BookID))
			{
				searchStatus = true;
				Borrowers[temp_Number].return_book(temp_book);
				//显示当前的信息
				cout << "请检查以下信息是否正确" << endl;
				display_book_title();
				temp_book.display();
				display_person_title();
				Borrowers[temp_Number].display();
				Borrowers[temp_Number].display_all_books(Books);
				break;
			}

		}
		//找到了书
		if (searchStatus == true)
		{

		}
		//没有找到
		else
		{
			cout << "没有找到对应书ID，请重试" << endl;
		}

	}
	//没有找到ID
	else
	{
		cout << "没有找到对应ID，请重试" << endl;
	}
}




