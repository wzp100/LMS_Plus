#include "User.h"

using namespace std;


/// <summary>
/// ������벻��ʾ
/// </summary>
/// <param name="������ַ�"></param>
/// <returns>��������</returns>
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
    // ����ǵ�ǰID�����ж����벢����true
    if (ID == this->ID)
    {
        cout << "���������룺";
        temp_password = get_password('*');
        cout << endl;
        if (temp_password == this->Password)
        {
            cout << "��ӭ" << Name << "����ϵͳ" << endl;
            temp_user = this;
            return true;
        }
        else
        {
            cout << "�������,������" << endl;
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
    cout <<setw(10)<<"ID" <<setw(10)<< "����" << "" << endl;
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




