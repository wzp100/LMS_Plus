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
    // 如果是当前ID，就判断密码并返回true
    if (ID == this->ID)
    {
        cout << "请输入密码：";
        temp_password = get_password('*');
        cout << endl;
        if (temp_password == this->Password)
        {
            cout << "欢迎" << Name << "进入系统" << endl;
            temp_admin = this;
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