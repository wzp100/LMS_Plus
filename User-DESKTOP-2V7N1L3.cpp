#include "User.h"

using namespace std;


/// <summary>
/// 获得密码不显示
/// </summary>
/// <param name="输出的字符"></param>
/// <returns>返回密码</returns>
string get_password(char rch)
{
    string ret;
    char ch;
    ch = _getch();
    while (ch != '\n' && ch != '\r')
    {
        _putch(rch);
        ret += ch;
        ch = _getch();
    }

    return ret;

}





User::User(Init_User user_list)
{
    ID = user_list.id;
    Password = user_list.password;
    Name = user_list.name;
}
bool User::login(int ID)
{
    extern User* temp_user;
    string temp_password;
    // 如果是当前ID，就判断密码并返回true
    if (ID == this->ID)
    {
        cout << "请输入密码：";
        temp_password = get_password('*');
        cout << endl;
        if (temp_password == this->Password)
        {
            cout << "欢迎" << Name << "进入系统" << endl;
            temp_user = this;
            return true;
        }
        else
        {
            cout << "密码错误,请重试" << endl;
            return false;
        }
    }
    else
    {
        return false;
    }
}

void User::display()
{
    cout << setw(10) << ID << setw(10) << Name << setw(10) << endl;
}

User::~User()
{

}

void User::display_header()
{
    cout <<setw(10)<<"ID" <<setw(10)<< "姓名" << "" << endl;
}

void User::load_file()
{
    extern vector<User>Users;
    display_header();
    for (auto temp_user:Users)
    {
        temp_user.display();
    }
}

void User::save_file()
{
    extern vector<User>Users;
    display_header();
    for (auto temp_user : Users)
    {
        temp_user.display();
    }
}




