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
    int group;
    string password;
    string name;

    /* data */
    Init_Admin()
    {
        id = -1;
        password = "";
        name = "";
        group = 1;
    }
};

class Admin:public User
{
private:

public:
    Admin()
    {
        Group = 1;
    }
    Admin(Init_Admin& admin_list);
    Admin(Init_User& user_list) :User(user_list) 
    {
        Group = 1;
    }

    ~Admin();
    bool login(int ID);
    static void save_file();
    static void load_file();
};


