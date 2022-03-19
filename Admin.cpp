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
    // 如果是当前ID，就判断密码并返回true
    if (ID == this->ID)
    {
        cout << "请输入密码：";
        temp_password = get_password('*');
        cout << endl;
        if (temp_password == this->Password)
        {
            cout << "欢迎" << Name << "进入系统" << endl;
            present_admin = this;
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
        cout << "打开文件失败" << endl;
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
        cout << "打开文件失败" << endl;
    }
}
