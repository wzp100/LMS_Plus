// LMS1.0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "TimeProcess.h"
#include "Book.h"
#include "FileProcess.h"
#include "Menu.h"
#include "TestSystem.h"
#include "User.h"
#include "Admin.h"
using namespace std;

//TODO:实现初始化以及菜单的循环以及程序的退出判断
//TODO:数据的保存与读取
//TODO:菜单的实现

size_t the_Number_of_Books = 0;
size_t the_Number_of_Persons = 0;
string file_name_books = "Book.txt";
string file_name_persons = "Person.txt";
string file_name_users = "User.txt";
string file_name_admins = "Admin.txt";
int  User::counter = 0;

vector<Person> Borrowers;
vector<Book> Books;
vector<User> Users;
vector<Admin> Admins;

User* present_user = NULL;
Admin* present_admin =NULL;
Person* present_borrower = NULL;
int main()
{

    //读取文件
    cout << "正在读取读者信息......." << endl;
    person_file_read(Borrowers);
    cout << "正在读取图书信息......." << endl;
    book_file_read(Books);
    the_Number_of_Books = Books.size();
    the_Number_of_Persons = Borrowers.size();
    cout << "读取完毕！" << endl;
    User::load_file();
    Admin::load_file();
    //建立关系
    for (Book& temp_book : Books)
    {
        temp_book.BulidRelationship(Borrowers);
    }
    //登录界面
    Login_Menu();
    //Main_Menu();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
