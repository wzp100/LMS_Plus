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
    int group;
    string password;
    string name;
    /* data */
    Init_User()
    {
        id = -1;
        group = 0;
        password = "";
        name = "";
    }
};




class User
{
protected:
    int ID;
    int Group;
    string Password;
    string Name;
    
public:

    User()
    {
        counter++;
        ID = -1;
        Group = 0;
        Password = "";
        Name = "";
    }
    User(int id,string password,string name):ID(id),Password(password),Name(name) ,Group(0)
    {
        counter++;
    }
    User(Init_User );
    bool login(int ID);
    void display();
    void modify();
    bool search_ID(int id);

    void save(ofstream &user_file);
    void read(ifstream &user_file);
    ~User();

    friend ostream& operator<< (ostream& ios, User user);


    static int counter;
    static void display_header();
    static void load_file();
    static void save_file();
    static User* Search_ID(int id);
    friend User;
    friend Person;

};

string get_password(char rch);
