#include"TestSystem.h"
void test_system()
{
    cout << "欢迎使用本系统";
    chrono::system_clock::time_point now = *get_Now() + 30 * chrono::hours(24);
    time_display(now);

    cout << endl;
    //生成测试Book对象结构体
    InitBookStruct  booklist {};
    /*
            10004,
        "语文",
        {"张三","张二"},
        "教育出版社",
        20,
        0,
        1
    */
    booklist.ID = 10004;
    booklist.Title = "语文";
    booklist.Author = { "张三","张二" };
    booklist.Press = "教育出版社";
    booklist.Price = 20;
    booklist.Status = 0;
    booklist.BorrowStatus = 1;

    vector<string> book_title = { "语文","数学","英语","物理","化学","生物","历史","政治","地理" };

    //生成测试Person对象结构体
    InitPersonStruct personlist; 
    personlist.ID = 10001;
    personlist.Name = "张";
    personlist.Age = 18;
    personlist.Gender = Man;
    personlist.PhoneNumber = 1234567890;
    personlist.Type = StudentType;
    personlist.BooksID = {};
    personlist.BorrowedNumber = 0;


    booklist.BorrowerID = 10001;
    Book Book1(booklist);
    //生成若干读者
    vector<Person> Persons;

    //生成编号唯一的书
    vector<Book> Books;

    size_t j = 0;
    for (size_t i = 0; i < 20; i++)
    {
        booklist.ID++;
        personlist.ID++;
        personlist.Name = "张" + to_string(i);

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
    cout << "以下为测试书籍显示函数" << endl;
    //测试展示函数
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "以下为测试读者信息显示函数" << endl;
    display_person_title();
    for (Person temp_person : Persons)
    {
        temp_person.display();
        temp_person.display_all_books(Books);
    }

    cout << "以下为测试借书函数" << endl;
    //测试借书函数
    size_t i = 0;
    for (Person& temp_person : Persons)
    {
        temp_person.borrow(Books[i++]);
        if (i == 8)
        {
            i = 0;
        }
    }
    cout << "以下为测试书籍显示函数" << endl;
    //测试展示函数
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "以下为测试读者信息显示函数" << endl;
    display_person_title();
    for (Person temp_person : Persons)
    {
        temp_person.display();
        temp_person.display_all_books(Books);
    }
    cout << "以下为测试还书函数" << endl;
    for (Book& temp_book : Books)
    {
        for (Person& temp_person : Persons)
        {
            temp_person.return_book(temp_book);
        }
        //temp_book.return_book();
        //temp_book.display();
    }
    cout << "以下为测试书籍显示函数" << endl;
    //测试展示函数
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    cout << "以下为测试借书函数" << endl;
    //测试借书函数
    for (Person& temp_person : Persons)
    {
        temp_person.borrow(Books[i++]);
        if (i == 8)
        {
            i = 0;
        }
    }
    cout << "以下为测试书籍显示函数" << endl;
    //测试展示函数
    display_book_title();
    for (Book temp_book : Books)
    {
        temp_book.display();
    }
    //测试文件保存
    person_file_save(Persons);
    book_file_save(Books);

    //system("Book.txt");
    //测试文件读取
        //生成编号唯一的书
    vector<Person>person_read_test;
    person_file_read(person_read_test);
    personlist.Name = "王展鹏";
    person_read_test.push_back(Person(personlist));
    person_file_save(person_read_test);
    system("Person.txt");


    vector<Book>book_read_test;
    book_file_read(book_read_test);
    booklist.Title = "儒林外史";
    book_read_test.push_back(Book(booklist));
    //测试建立关系
    for (Book& temp_book : book_read_test)
    {
        temp_book.BulidRelationship(person_read_test);
    }
    cout << "以下为测试书籍显示函数" << endl;
    //测试展示函数
    display_book_title();
    for (Book temp_book : book_read_test)
    {
        temp_book.display();
    }
    book_file_save(book_read_test);
    system("Book.txt");
    //二次测试读与写
            //生成编号唯一的书
    vector<Person>person_read_test_2;
    person_file_read(person_read_test_2);
    personlist.Name = "王展鹏";
    personlist.ID = 3242;
    person_read_test_2.push_back(Person(personlist));
    person_file_save(person_read_test_2);


    system("Person.txt");
    system("pause");

    //cout << "以下为测试修改函数" << endl;
    //cout << "以下为测试读者信息显示函数" << endl;
    //display_person_title();
    //for (Person temp_person : Persons)
    //{
    //    temp_person.display();
    //    temp_person.display_all_books(Books);
    //}
    //cout << "以下为测试读者信息显示函数" << endl;
    //display_person_title();
    //for (Person temp_person : Persons)
    //{
    //    temp_person.modify();
    //    temp_person.display();
    //    temp_person.display_all_books(Books);
    //}
    //


}
