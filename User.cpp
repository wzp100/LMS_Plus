#include "User.h"
#include "Admin.h"

using namespace std;
extern User* present_user;
extern Person* present_borrower;
extern Admin* present_admin;
extern vector<Admin> Admins;
extern vector<User> Users;
extern vector<Person>Borrowers;
extern vector<Book> Books;

ostream& operator<<(ostream& ios, User user)
{
    ios << user.ID << ":" << user.Name;
    return ios;
}

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
    counter++;
    ID = user_list.id;
    Password = user_list.password;
    Name = user_list.name;
    Group = user_list.group;

}
bool User::login(int ID)
{
    extern User* present_user;
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
            present_user = this;
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

void User::modify()
{
    cout << "������������:";
    cin >> Password;
    cout << "�޸ĳɹ�";
}

bool User::search_ID(int id)
{
    if (ID==id)
    {
        return true;
    }
    return false;
}

void User::save(ofstream &user_file)
{
    user_file <<setiosflags(ios::left)
    <<setw(10)<<ID
    <<setw(20)<<Password
    <<setw(10)<<Name
    <<setw(10)<<Group
    <<endl;
}

void User::read(ifstream &user_file)
{
    user_file >> ID;
    user_file >> Password;
    user_file >> Name;
    user_file >> Group;
}


User::~User()
{
    counter--;
}

void User::display_header()
{
    cout <<setw(10)<<"ID" <<setw(10)<< "����" << "" << endl;

}

void User::load_file()
{
    extern vector<User>Users;
    ifstream user_file("User.txt");
    if(user_file.is_open())
    {
        while(!user_file.eof())
        {
            User temp_user;
            temp_user.read(user_file);
            if (temp_user.ID<0)
            {
                continue;
            }
            Users.push_back(temp_user);
        }
        user_file.close();
    }
    else
    {
        cout << "���ļ�ʧ��" << endl;
    }
    user_file.close();

}

void User::save_file()
{
    extern vector<User>Users;
    extern vector<Admin>Admins;
    ofstream user_file("User.txt");
    if(user_file.is_open())
    {
        for(User temp_user:Users)
        {
            temp_user.save(user_file);
        }
        user_file.close();
    }
    else
    {
        cout << "���ļ�ʧ��" << endl;
    }
    user_file.close();
}

User* User::Search_ID(int id)
{
    for (auto &temp_user:Users)
    {
        if (temp_user.search_ID(id))
        {
            return &temp_user;
        }
    }
    return NULL;
}




