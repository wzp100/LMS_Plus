#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class BookPackage :
    protected Book
{
    //TODO:完善成员方法，重构显示函数，补充显示
public:
    virtual void modify(int);
    virtual void borrow();//借书函数，首先判断是否有书
    virtual void return_book();
    // 显示当前书籍种类的信息
    virtual void display();

private:
    int Location[4];//图书所在位置[房间][区域][列][层]
    int AllNumber;//总数量
    int RemainingNumber;//剩余数量
    vector <int> BooksID;//所包含的书ID
    vector<Book> P_Books;//所包含书的指针
};




