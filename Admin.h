#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Book.h"
#include "Person.h"
#include "User.h"

using namespace std;

struct Init_Admin
{
    int id;
    string password;
    string name;
    /* data */
    Init_Admin()
    {
        id = -1;
        password = "";
        name = "";
    }
};

class Admin:public User
{
private:

public:
    Admin(){}
    Admin(Init_Admin& admin_list);
    Admin(Init_User user_list):User(user_list){}
    ~Admin();
    bool login(int ID);
};


