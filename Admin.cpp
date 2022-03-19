#include "Admin.h"
using namespace std;


Admin::Admin(Init_Admin& admin_list)
{
    ID = admin_list.id;
    Password = admin_list.password;
    Name = admin_list.name;
    Group = admin_list.group;
}

Admin::~Admin()
{

}

bool Admin::login(int ID)
{
    extern Admin* present_admin;
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
            present_admin = this;
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

void Admin::save_file()
{
    extern vector<Admin>Admins;
    ofstream admin_file("Admin.txt");
    if (admin_file.is_open())
    {
        for (User temp_admin : Admins)
        {
            temp_admin.save(admin_file);
        }
    }
    else
    {
        cout << "���ļ�ʧ��" << endl;
    }
    admin_file.close();
}

void Admin::load_file()
{
    extern vector<Admin>Admins;
    ifstream user_file("Admin.txt");
    if (user_file.is_open())
    {
        while (!user_file.eof())
        {
            Admin temp_user;
            temp_user.read(user_file);
            if (temp_user.ID<0)
            {
                continue;
            }
            Admins.push_back(temp_user);
        }
        user_file.close();
    }
    else
    {
        cout << "���ļ�ʧ��" << endl;
    }
}
