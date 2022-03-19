
#include "saveMenu.h"
#include "FileProcess.h"
#include "Admin.h"


/// <summary>
/// 6.文件保存二级菜单
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void save_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|**********文件保存模块**********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.文件保存              |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.文件排序              |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.返回上级菜单          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   请选择功能序号:");

		//读入用户选择
		cin >> nSortChoose;

		switch (nSortChoose)
		{
		case 1:
			//按编号查询
			fileSave(Borrowers, Books);
			system("PAUSE");
			break;
		case 2:
			//按编号查询
			fileSort(Borrowers, Books);
			system("PAUSE");
			break;
		case 0:
			//返回
			return;
			break;
		default:printf("\t\t选择有误，请重选！\n");
		}//switch结束
	}//while(1)结束
}

/// <summary>
/// 6.1 文件保存函数
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void fileSave(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  当前是文件保存模块" << endl;
	person_file_save(Borrowers);
	cout << "读者信息已保存,保存在Person.txt" << endl;
	book_file_save(Books);
	cout << "图书信息已保存,保存在Book.txt" << endl;
	User::save_file();
	Admin::save_file();
	cout << "账户信息已保存" << endl;

}
/// <summary>
/// 6.2 文件排序函数
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void fileSort(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "正在为读者信息排序" << endl;
	size_t length = Borrowers.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length - 1; j++)
		{
			Borrowers[j] << Borrowers[j + 1];//升序
		}
	}
	cout << "正在为书籍信息排序" << endl;
	length = Books.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length - 1; j++)
		{
			Books[j] << Books[j + 1];//升序
		}
	}
	cout << "排序已完成" << endl;
}
