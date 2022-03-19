#pragma once
#include "Person.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct Init_User
{
    int id;
    string password;
    string name;
    /* data */
    Init_User()
    {
        id = -1;
        password = "";
        name = "";
    }
};




class User
{
protected:
    int ID;

    string Password;
    string Name;

public:
    User()
    {
        ID = -1;
        Password = "";
        Name = "";
    }
    User(int id,string password,string name):ID(id),Password(password),Name(name) {}
    User(Init_User );
    bool login(int ID);
    void display();
    ~User();
    static void display_header();
    static void load_file();
    static void save_file();
    
};

string get_password(char rch);
