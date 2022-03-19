#include"Menu.h"
#include<iostream>
#include "FileProcess.h"

using namespace std;
//输入图书结构体数组，人物结构体数组，返回值使用指针
extern User* present_user;
extern Person* present_borrower;
extern Admin* present_admin;
extern vector<Admin> Admins;
extern vector<User> Users;
extern vector<Person>Borrowers;
extern vector<Book> Books;

void Login_Menu()
{
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
			if (status)
			{
				User_Main_Menu();
			}
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
			present_admin = &temp_user;
			return true;
		}
	}
	cout<<"登录失败,未找到用户！"<<endl;
	return false;
}


/// <summary>
/// 用户登录
/// </summary>
/// <returns></returns>
bool User_Login()
{
	int ID;
	string Password;
	system("CLS");
	cout << "请输入用户ID：";
	cin >> ID;
	for (auto& temp_user : Users)
	{
		if (temp_user.login(ID))
		{
			for (auto& temp_borrower:Borrowers)
			{
				if (temp_borrower.searchPersonID(ID))
				{
					present_borrower = &temp_borrower;
					cout << "登录成功！" << endl;
					return true;
				}
			}
			cout << "数据错误，未找到有关账号的相关信息" << endl;
			return false;
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
		cout << "\t\t欢迎" << *present_user <<"使用本程序" << endl;
		//请用户输入选择的数字
		printf("\t\t   请选择功能序号:");
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
			personal_Center_Menu();
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


/// <summary>
/// 2.1.3个人中心
/// </summary>
void personal_Center_Menu()
{
	int nMainchoose;
	//主菜单无限循环
	while (1)
	{
		system("CLS"); //系统屏幕清空
		//输出菜单主界面
		printf("\t\t --------------------------------------\n");
		printf("\t\t             个人信息查询            \n");
		printf("\t\t                                     \n");
		printf("\t\t      1.图书借阅信息                \n");
		printf("\t\t                                     \n");
		printf("\t\t                                     \n");
		printf("\t\t      2.个人信息查询                \n");
		printf("\t\t                                    \n");
		cout << endl;
		cout <<"\t\t      3.个人信息修改                    " << endl;
		printf("\t\t                                     \n");
		cout << endl;
		printf("\t\t      0.返回                        \n");
		printf("\t\t --------------------------------------\n");
		//请用户输入选择的数字
		printf("\t\t   请选择功能序号:");
		//用户根据界面提示输入数字
		cin >> nMainchoose;
		//根据用户输入的数字看如何行动
		switch (nMainchoose)
		{
			//转到二级菜单：借阅归还图书菜单选项显示
		case 1:
			personal_borrowBook_Info();
			system("pause");
			break;

			//转到二级菜单：图书信息查询菜单选项显示
		case 2:
			personal_Informaton();
			system("pause");
			break;
		case 3:
			personal_Info_modify();
			system("pause");
			break;

		case 0:
			//用户退出
			cout << "\n\n\t\t感谢使用我们的软件，欢迎下次再来！" << endl;
			return;
			break;
			//用户选择有误
		default:
			printf("选择有误，请重选！\n");
		}//switch结束
	}//while(1)函数结束
}

void personal_borrowBook_Info()
{
	cout << "\t\t个人借阅信息查询" << endl;
	(*present_borrower).display_all_books_header();
	(*present_borrower).display_all_books();
}

void personal_Informaton()
{

	cout << "\t个人信息查询" << endl;

	(*present_borrower).display_header();
	(*present_borrower).display();
}







void personal_Info_modify()
{
	cout << "\t\t个人信息修改" << endl;
	cout << "\t1.修改密码" << endl
		<< "\t2.修改个人信息" << endl;
	cout << "\t\t请输入序号:";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		//修改密码
		present_user->modify();
		break;
	case 2:
		present_borrower->personal_modify();
		break;
	default:
		break;
	}
}

bool User_Register()
{
	Init_User user_list;
	InitPersonStruct person_list;

	extern vector<User> Users;
	extern vector<Person> Borrowers;
	extern User* present_user;
	cout << "\t\t当前为注册模块" << endl;
	cout << "请输入ID" << endl;
	cin >> user_list.id;
	cout << "请输入密码" << endl;
	cin >> user_list.password;
	cout << "请输入姓名" << endl;
	cin >> user_list.name;
	Users.push_back(user_list);
	addPersonInfo(user_list.id, user_list.name);
	present_user = &(Users.back());
	present_borrower = &(Borrowers.back());
	//保存用户文件以及相关的数据文件
	User::save_file();
	person_file_save(Borrowers);
	return true;
}




/// <summary>
/// 管理员主菜单界面
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void Main_Menu( )
{
	
	extern vector<Person> Borrowers;
	extern vector<Book> Books;
	extern vector<User> Users;
	extern size_t the_Number_of_Books;
	extern size_t the_Number_of_Persons;
	extern string file_name_books;
	extern string file_name_persons;
	extern Admin* present_admin;

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

		cout << "\n\t图书数据已从" << file_name_books << "导入,图书馆中目前共有" << the_Number_of_Books << "本书 \n\n";
		cout << "\n\t读者数据已从" << file_name_persons << "导入,图书馆中目前共有" << the_Number_of_Persons << "位读者 \n\n";
		cout << "\n\t欢迎" << *present_admin << "使用本系统" << endl;
		//请用户输入选择的数字
		printf("\t\t   请选择功能序号:");

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