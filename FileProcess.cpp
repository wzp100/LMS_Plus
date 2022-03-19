#include "FileProcess.h"
//����person
void person_file_save(vector<Person> &persons)
{
    ofstream person_file("Person.txt");
    if (person_file.is_open())
    {
        for (Person temp_person:persons)
        {
            temp_person.save(person_file);
        }

    }
    else
    {
        cout << "Person.txt��ʧ��" << endl;
    }
    person_file.close();
}

//��ȡperson
void person_file_read(vector<Person>& persons)
{

    ifstream person_file("Person.txt");
    if (person_file.is_open())
    {
        while (!person_file.eof())
        {
            InitPersonStruct person_list;
            //person_list.ID = -1;
            Person temp_person(person_list);
            temp_person.read(person_file);
            if (temp_person.ID >=0)
            {
                persons.push_back(temp_person);

            }
        }
    }
    else
    {
        cout << "Person.txt��ʧ��" << endl;
    }
    person_file.close();
}

//����book
void book_file_save(vector<Book>& books)
{
    ofstream book_file("Book.txt");
    if (book_file.is_open())
    {
        for (Book temp_book : books)
        {
            temp_book.save(book_file);
        }

    }
    else
    {
        cout << "Book.txt��ʧ��" << endl;
    }
    book_file.close();
}

void book_file_read(vector<Book>& books)
{
    ifstream book_file("Book.txt");
    if (book_file.is_open())
    {
        while (!book_file.eof())
        {
            InitBookStruct book_list;
            book_list.ID = -1;
            book_list.Author = {  };
            book_list.BorrowStatus = 1;
            book_list.Press = "��";
            book_list.Price = 0;
            book_list.Status = 0;
            book_list.Title = "��";
           
            Book temp_book(book_list);
            temp_book.read(book_file);
            if (temp_book.ID >= 0)//�ж��Ƿ���ļ�����ȷ��ȡ
            {
                books.push_back(temp_book);
                
            }
        }

    }
    else
    {
        cout << "Book.txt��ʧ��" << endl;
    }
    book_file.close();

}
