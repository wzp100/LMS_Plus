#include "Admin.h"
using namespace std;


Admin::Admin(Init_Admin& admin_list)
{
    ID = admin_list.id;
    Password = admin_list.password;
    Name = admin_list.name;
}

Admin::~Admin()
{

}

bool Admin::login(int ID)
{
    extern Admin* temp_admin;
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
            temp_admin = this;
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