
#include "bookInformationQqueryMenu.h"

/// <summary>
/// 4.图书信息查询二级菜单
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void bookInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|********图书信息查询模块********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.按编号查询            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.按标题查询            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        3.按作者查询            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        4.按出版社查询          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.返回上级菜单          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   请选择功能序号(0~4):");
		//读入用户选择
		//scanf("%d", &nSortChoose);
		cin >> nSortChoose;
		switch (nSortChoose)
		{
		case 1:
			//4.1 按编号查询
			idSearchBook(Books);
			system("PAUSE");
			break;
		case 2:
			//4.2 按标题查询
			titleSearchBook(Books);
			system("PAUSE");
			break;
		case 3:
			//4.3 按作者查询
			authorSearchBook(Books);
			system("PAUSE");
			break;
		case 4:
			//4.4 按出版社查询
			pressSearchBook(Books);
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
/// 4.1 按编号查询
/// </summary>
/// <param name="Books"></param>
void idSearchBook(vector<Book>& Books)
{
	int temp_ID;
	cout << "当前为ID搜索图书模式" << endl;
	cout << "请输入要搜索的ID:";
	cin >> temp_ID;
	for (Book temp_book : Books)
	{
		if (temp_book.searchBookID(temp_ID))
		{
			cout << "搜索成功" << endl;
			display_book_title();
			temp_book.display();
			return;
		}
	}
	cout << "搜索失败，请检查ID是否正确" << endl;
}

/// <summary>
/// 4.2 按标题查询
/// </summary>
/// <param name="Books"></param>
void titleSearchBook(vector<Book>& Books)
{
	bool status = false;
	string title;
	cout << "当前为书名搜索图书模式" << endl;
	cout << "请输入要搜索的书名:";
	cin >> title;

	display_book_title();
	for (Book temp_book : Books)
	{
		if (temp_book.Title == title)
		{
			temp_book.display();
			status = true;
		}
	}
	if (status)
	{
		cout << "搜索完毕" << endl;
		return;
	}
	else
	{
		cout << "未搜索到结果" << endl;
	}

}


/// <summary>
/// 4.3 按作者查询
/// </summary>
/// <param name="Books"></param>
void authorSearchBook(vector<Book>& Books)
{
	bool status = false;
	string author;
	cout << "当前为作者搜索图书模式" << endl;
	cout << "请输入要搜索的作者:";
	cin >> author;

	display_book_title();
	for (Book temp_book : Books)
	{
		for (string temp_author : temp_book.Author)
		{
			if (temp_author == author)
			{
				temp_book.display();
				status = true;
				continue;
			}
		}

	}
	if (status)
	{
		cout << "搜索完毕" << endl;
		return;
	}
	else
	{
		cout << "未搜索到结果" << endl;
	}
}


/// <summary>
/// 4.4 按出版社查询
/// </summary>
/// <param name="Books"></param>
void pressSearchBook(vector<Book>& Books)
{
	bool status = false;
	string press;
	cout << "当前为出版社搜索图书模式" << endl;
	cout << "请输入要搜索的出版社:";
	cin >> press;

	display_book_title();
	for (Book temp_book : Books)
	{
		if (temp_book.Press == press)
		{
			temp_book.display();
			status = true;
		}
	}
	if (status)
	{
		cout << "  搜索完毕" << endl;
		return;
	}
	else
	{
		cout << "  未搜索到结果" << endl;
	}
}
