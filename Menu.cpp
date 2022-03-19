#include"Menu.h"
#include<iostream>
#include "FileProcess.h"
using namespace std;
//输入图书结构体数组，人物结构体数组，返回值使用指针




void Login_Menu()
{
	extern vector<User> Users;
	int nMainChoose;
	bool status;
	system("cls");
	while (1)
	{
		cout << "\t\t --------------------------------------" << endl;
		cout<<  "\t\t         欢迎使用图书管理系统          " <<endl<<endl;

		cout << "\t\t            1.管理员登录" << endl<<endl;

		cout << "\t\t            2.用户登录" << endl<<endl;

		cout << "\t\t            3.用户注册" <<endl<<endl;

		cout << "\t\t            0.退    出" << endl<<endl;
		cout << "\t\t --------------------------------------" << endl;
		cout << "\t\t            请选择：";
		cin >> nMainChoose;
		switch (nMainChoose)
		{
		case 1:
			status = Admin_Login();
			if (status)
			{
				Main_Menu();
			}
			break;
		case 2:
			status = User_Login();
			if (status)
			{
				User_Main_Menu();
			}
			break;
		case 3:
			status = User_Register();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
		}
	}
	


}


bool Admin_Login()
{
	extern vector<Admin> Admins;
	int ID;
	string Password;
	system("CLS");
	cout<<"请输入用户ID：";
	cin>>ID;
	for(auto& temp_user:Admins)
	{
		if(temp_user.login(ID)) 
		{
			cout<<"登录成功！"<<endl;
			return true;
		}
	}
	cout<<"登录失败,未找到用户！"<<endl;
	return false;
}

bool User_Login()
{
	extern vector<User> Users;
	int ID;
	string Password;
	system("CLS");
	cout << "请输入用户ID：";
	cin >> ID;
	for (auto& temp_user : Users)
	{
		if (temp_user.login(ID))
		{
			cout << "登录成功！" << endl;
			return true;
		}
	}
	cout << "登录失败,未找到用户！" << endl;
	return false;
}


/// <summary>
/// 用户主菜单界面
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void User_Main_Menu()
{

	extern vector<Person> Borrowers;
	extern vector<Book> Books;
	extern vector<User> Users;
	int nMainchoose;
	//主菜单无限循环
	while (1)
	{
		system("CLS"); //系统屏幕清空
		//输出菜单主界面
		printf("\t\t --------------------------------------\n");
		printf("\t\t|             图书管理系统            |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   1.图书借阅归还     2.图书信息查询 |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   3.个人信息查询     4.文件保存     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   0.退出系统                        |\n");
		printf("\t\t --------------------------------------\n");
		//根据宏定义的文件名和书籍数目显示
		extern size_t the_Number_of_Books;
		extern size_t the_Number_of_Persons;
		extern string file_name_books;
		extern string file_name_persons;
		cout << "\n\t图书数据已从" << file_name_books << "导入,图书馆中目前共有" << the_Number_of_Books << "本书 \n\n";
		cout << "\n\t读者数据已从" << file_name_persons << "导入,图书馆中目前共有" << the_Number_of_Persons << "位读者 \n\n";

		//请用户输入选择的数字
		printf("\t\t   请选择功能序号(0~5):");
		//用户根据界面提示输入数字
		cin >> nMainchoose;
		//根据用户输入的数字看如何行动
		switch (nMainchoose)
		{
			//转到二级菜单：借阅归还图书菜单选项显示
		case 1:
			borrowAndReturnBook_Menu(Borrowers, Books);
			break;

			//转到二级菜单：图书信息查询菜单选项显示
		case 2:

			bookInformationQquery_Menu(Borrowers, Books);
			break;

			//转到二级菜单：个人信息菜单
		case 3:
			personInfo_Menu();
			break;

		case 4:
			//6.保存菜单
			save_Menu(Borrowers, Books);
			break;
		case 0:
			//用户退出
			cout << "\n\n\t\t感谢使用我们的软件，欢迎下次再来！" << endl;
			exit(0);
			break;
			//用户选择有误
		default:
			printf("选择有误，请重选！\n");
		}//switch结束
	}//while(1)函数结束
}
void personInfo_Menu()
{
	User::save_file();
	system("pause");
}
//主菜单函数结束






bool User_Register()
{
	extern vector<User> Users;
	return false;
}




/// <summary>
/// 主菜单界面
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void Main_Menu( )
{
	
	extern vector<Person> Borrowers;
	extern vector<Book> Books;
	extern vector<User> Users;
	int nMainchoose;
	//主菜单无限循环
	while (1)
	{
		system("CLS"); //系统屏幕清空
		//输出菜单主界面
		printf("\t\t --------------------------------------\n");
		printf("\t\t|             图书管理系统            |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   1.图书借阅归还   2.书库维护       |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   3.借阅信息查询   4.图书信息查询   |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   5.人员管理       6.文件保存       |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   0.退出系统                        |\n");
		printf("\t\t --------------------------------------\n");
		//根据宏定义的文件名和书籍数目显示
		//printf("\n\t图书馆中%s中目前共有%d本书 \n\n");//, //FILENAME, *npStudentNum);
		extern size_t the_Number_of_Books;
		extern size_t the_Number_of_Persons;
		extern string file_name_books;
		extern string file_name_persons;
		cout << "\n\t图书数据已从" << file_name_books << "导入,图书馆中目前共有" << the_Number_of_Books << "本书 \n\n";
		cout << "\n\t读者数据已从" << file_name_persons << "导入,图书馆中目前共有" << the_Number_of_Persons << "位读者 \n\n";

		//请用户输入选择的数字
		printf("\t\t   请选择功能序号(0~5):");
		//用户根据界面提示输入数字
		//scanf("%d", &nMainchoose);
		cin >> nMainchoose;
		//根据用户输入的数字看如何行动
		switch (nMainchoose)
		{
			//转到二级菜单：借阅归还图书菜单选项显示
		case 1:
			borrowAndReturnBook_Menu(Borrowers,Books);
			break;

			//转到二级菜单：书库维护菜单选项显示
		case 2:
			libraryMaintenance_Menu(Borrowers, Books);//定义函数
			break;

			//转到二级菜单：借阅信息查询菜单选项显示
		case 3:
			borrowingInformationQquery_Menu(Borrowers, Books);
			break;

			//转到二级菜单：图书信息查询菜单选项显示
		case 4:

			bookInformationQquery_Menu(Borrowers,Books);
			break;

			//转到二级菜单：人员管理菜单选项显示
		case 5:
			personnelManagement_Menu(Borrowers, Books);
			break;

		case 6:
			//6.保存菜单
			save_Menu(Borrowers, Books);
			break;
		case 0:
			//用户退出
			cout << "\n\n\t\t感谢使用我们的软件，欢迎下次再来！" << endl;
			exit(0);
			break;
			//用户选择有误
		default:
			printf("选择有误，请重选！\n");
		}//switch结束
	}//while(1)函数结束
}
//主菜单函数结束



























/// <summary>
/// .所有信息查询二级菜单
/// </summary>
/// <param name="Books"></param>
void allInformationQquery_Menu(vector<Book>& Books)
{
	int nMainchoose;
	//主菜单无限循环
	while (1)
	{
		system("CLS"); //系统屏幕清空
		//输出菜单主界面
		cout << "\t\t-----------------------------------" << endl;
		cout << "\t\t   1.输出所有图书信息" << endl;
		cout << "\t\t   0.返回上一级" << endl;
		cout << "\t\t-----------------------------------" << endl;
		//请用户输入选择的数字
		cout << "\t\t   请选择功能序号:";
		//用户根据界面提示输入数字
		cin >> nMainchoose;
		system("CLS");
		//根据用户输入的数字看如何行动
		switch (nMainchoose)
		{
			//转到二级菜单：借阅图书菜单选项显示
		case 1: //BorrowBook//(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum);//定义函数

			cout << "当前书籍的信息" << endl;
			//测试展示函数
			display_book_title();
			for (Book temp_book : Books)
			{
				temp_book.display();
			}
			system("pause");
			break;
			//转到二级菜单：归还图书菜单选项显示
		case 2: //ReturnBook //(stu, szCourseName, npStudentNum);//定义函数
			break;
			//转到二级菜单：书库维护菜单选项显示
		case 3: //LibraryMaintenance//(stu, szCourseName, *npStudentNum);//定义函数
			break;
			//转到二级菜单：借阅信息查询菜单选项显示
		case 4://Borrowing_InformationQquery//(stu, szCourseName, *npStudentNum);//定义函数
			break;
			//转到二级菜单：图书信息查询菜单选项显示
		case 5://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//定义函数
			break;
			//转到二级菜单：人员管理菜单选项显示
		case 6://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//定义函数
			break;
			//转到二级菜单：修改密码菜单选项显示
		case 7://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//定义函数
			break;
		case 0:
			//用户返回上一级
			return;
			break;
			//用户选择有误
		default:
			cout << "选择有误，请重选！\n";
		}//switch结束
	}//while(1)函数结束
}