#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class BookPackage :
    protected Book
{
    //TODO:���Ƴ�Ա�������ع���ʾ������������ʾ
public:
    virtual void modify(int);
    virtual void borrow();//���麯���������ж��Ƿ�����
    virtual void return_book();
    // ��ʾ��ǰ�鼮�������Ϣ
    virtual void display();

private:
    int Location[4];//ͼ������λ��[����][����][��][��]
    int AllNumber;//������
    int RemainingNumber;//ʣ������
    vector <int> BooksID;//����������ID
    vector<Book> P_Books;//���������ָ��
};




