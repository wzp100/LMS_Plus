#include"TestSystem.h"
void test_system()
{
    cout << "��ӭʹ�ñ�ϵͳ";
    chrono::system_clock::time_point now = *get_Now() + 30 * chrono::hours(24);
    time_display(now);

    cout << endl;
    //���ɲ���Book����ṹ��
    InitBookStruct  booklist {};
    /*
            10004,
        "����",
        {"����","�Ŷ�"},
        "����������",
        20,
        0,
        1
    */
    booklist.ID = 10004;
    booklist.Title = "����";
    booklist.Author = { "����","�Ŷ�" };
    booklist.Press = "����������";
    booklist.Price = 20;
    booklist.Status = 0;
    booklist.BorrowStatus = 1;

    vector<string> book_title = { "����","��ѧ","Ӣ��","����","��ѧ","����","��ʷ","����","����" };

    //���ɲ���Person����ṹ��
    InitPersonStruct personlist; 
    personlist.ID = 10001;
    personlist.Name = "��";
    personlist.Age = 18;
    personlist.Gender = Man;
    personlist.PhoneNumber = 1234567890;
    personlist.Type = StudentType;
    personlist.BooksID = {};
    personlist.BorrowedNumber = 0;


    booklist.BorrowerID = 10001;
    Book Book1(booklist);
    //�������ɶ���
    vector<Person> Persons;

    //���ɱ��Ψһ����
    vector<Book> Books;

    size_t j = 0;
    for (size_t i = 0; i < 20; i++)
    {
        booklist.ID++;
        personlist.ID++;
        personlist.Name = "��" + to_string(i);

        booklist.Title = book_title[j++];
        if (j == 8)
        {
            j = 0;
        }
        Book* p_temp_book = new Book(booklist);
        Books.push_back(*p_temp_book);
        delete(p_temp_book);


        Person* p_temp_person = new Person(personlist);
        Persons.push_back(*p_temp_person);
        delete(p_temp_person);
    }
    cout << "����Ϊ�����鼮��ʾ����" << endl;
    //����չʾ����
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "����Ϊ���Զ�����Ϣ��ʾ����" << endl;
    display_person_title();
    for (Person temp_person : Persons)
    {
        temp_person.display();
        temp_person.display_all_books(Books);
    }

    cout << "����Ϊ���Խ��麯��" << endl;
    //���Խ��麯��
    size_t i = 0;
    for (Person& temp_person : Persons)
    {
        temp_person.borrow(Books[i++]);
        if (i == 8)
        {
            i = 0;
        }
    }
    cout << "����Ϊ�����鼮��ʾ����" << endl;
    //����չʾ����
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "����Ϊ���Զ�����Ϣ��ʾ����" << endl;
    display_person_title();
    for (Person temp_person : Persons)
    {
        temp_person.display();
        temp_person.display_all_books(Books);
    }
    cout << "����Ϊ���Ի��麯��" << endl;
    for (Book& temp_book : Books)
    {
        for (Person& temp_person : Persons)
        {
            temp_person.return_book(temp_book);
        }
        //temp_book.return_book();
        //temp_book.display();
    }
    cout << "����Ϊ�����鼮��ʾ����" << endl;
    //����չʾ����
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "����Ϊ���Խ��麯��" << endl;
    //���Խ��麯��
    for (Person& temp_person : Persons)
    {
        temp_person.borrow(Books[i++]);
        if (i == 8)
        {
            i = 0;
        }
    }
    cout << "����Ϊ�����鼮��ʾ����" << endl;
    //����չʾ����
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    //�����ļ�����
    person_file_save(Persons);
    book_file_save(Books);

    //system("Book.txt");
    //�����ļ���ȡ
        //���ɱ��Ψһ����
    vector<Person>person_read_test;
    person_file_read(person_read_test);
    personlist.Name = "��չ��";
    person_read_test.push_back(Person(personlist));
    person_file_save(person_read_test);
    system("Person.txt");


    vector<Book>book_read_test;
    book_file_read(book_read_test);
    booklist.Title = "������ʷ";
    book_read_test.push_back(Book(booklist));
    //���Խ�����ϵ
    for (Book& temp_book : book_read_test)
    {
        temp_book.BulidRelationship(person_read_test);
    }
    cout << "����Ϊ�����鼮��ʾ����" << endl;
    //����չʾ����
    display_book_title();
    for (Book temp_book : book_read_test)
    {
        temp_book.display();
    }
    book_file_save(book_read_test);
    system("Book.txt");
    //���β��Զ���д
            //���ɱ��Ψһ����
    vector<Person>person_read_test_2;
    person_file_read(person_read_test_2);
    personlist.Name = "��չ��";
    personlist.ID = 3242;
    person_read_test_2.push_back(Person(personlist));
    person_file_save(person_read_test_2);


    system("Person.txt");
    system("pause");

    //cout << "����Ϊ�����޸ĺ���" << endl;
    //cout << "����Ϊ���Զ�����Ϣ��ʾ����" << endl;
    //display_person_title();
    //for (Person temp_person : Persons)
    //{
    //    temp_person.display();
    //    temp_person.display_all_books(Books);
    //}
    //cout << "����Ϊ���Զ�����Ϣ��ʾ����" << endl;
    //display_person_title();
    //for (Person temp_person : Persons)
    //{
    //    temp_person.modify();
    //    temp_person.display();
    //    temp_person.display_all_books(Books);
    //}
    //


}
