#include "Person.h"


vector <string> PersonWord{ "编号","姓名","年龄","性别","电话","数量限制" ,"已借书数目","已借的所有书ID","组别"};

//显示标题


/// <summary>
/// 显示标题
/// </summary>
void display_person_title() {
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << setw(10) << PersonWord[0]
		<< setw(10) << PersonWord[1]
		<< setw(8) << PersonWord[2]
		<< setw(8) << PersonWord[3]
		<< setw(15) << PersonWord[4]
		<< setw(10) << PersonWord[5]
		<< setw(12) << PersonWord[6]
		<< setw(10) << PersonWord[8];
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}
//新增一个对象函数
void add_a_person() {
	//TODO:增加一个person对象函数
}

Person::Person(const InitPersonStruct& person_list)
{
	ID=person_list.ID;//0编号
	Name =person_list.Name;//1姓名
	Age = person_list.Age;//2年龄
	Gender = person_list.Gender;//3性别，男为1，女为0
	PhoneNumber = person_list.PhoneNumber;//4电话
	BorrowedNumber = person_list.BorrowedNumber;//6已借数目
	BooksID=person_list.BooksID;//7接到的书的ID数组
	Type=person_list.Type;//8组别，表示人的类型，不同人有不同的借书数目，以及借书的时长
	switch (Type)
	{
	case 0 ://学生
		BookNumberLimit = 10;
		BorrowDuration = 30 * chrono::hours(24);//30天
		break;
	case 1://老师
		BookNumberLimit = 20;
		BorrowDuration = 50 * chrono::hours(24);//50天
		break;

	default:
		BookNumberLimit = 5;
		BorrowDuration = 15 * chrono::hours(24);//15天
		break;
	}


}
//"编号","姓名","年龄","性别","电话","图书借阅数量限制" ,"已借书数目","已借的所有书ID","组别"
void Person::display()
{
	string sex;
	(Gender) ? (sex = "男") : (sex = "女");
	cout << setw(10) << ID
		<< setw(10) << Name
		<< setw(8) << Age
		<< setw(8) << sex
		<< setw(15) << PhoneNumber
		<< setw(10) << BookNumberLimit
		<< setw(12) << BorrowedNumber;
	switch (Type)
	{
	case 0://学生
		cout <<setw(10) << "学生";
		break;
	case 1://老师
		cout <<setw(10) << "老师";
		break;

	default:
		cout <<setw(10)<< "其他";
		break;
	}

	cout<< endl;
}

//Person修改函数的接口
void person_modify(Person & person)
{

}


//"编号","姓名","年龄","性别","电话","数量限制" ,"已借书数目","已借的所有书ID","组别"
void Person::modify()
{
	size_t i = 0;
	int SNumber = 0;
	cout << "选择修改相应的序号" << endl;

	for (string temp : PersonWord)
	{
		if (i == 8)
		{
			continue;
		}
		cout << "[" << i++ << "]" << ":" << temp << endl;

	}
	cin >> SNumber;

	switch (SNumber)
	{
	case 0:
		cout << PersonWord[SNumber]<<":"; cin >> ID;
		break;
	case 1:
		cout << PersonWord[SNumber]<<":"; cin >> Name;
		break;
	case 2:
		cout << PersonWord[SNumber] << ":"; cin >> Age;
		break;
	case 3:
		cout << PersonWord[SNumber] <<"(男“1”，女“0”)" << ":"; cin >> Gender;
		break;
	case 4:
		cout << PersonWord[SNumber] << ":"; cin >> PhoneNumber;
		break;
	case 5:
		cout << PersonWord[SNumber] << ":"; cin >> BookNumberLimit;
		break;
	case 6:
		cout << PersonWord[SNumber] << ":"; cin >> BorrowedNumber;
		break;
	case 7:
		SNumber = SNumber + 1;
		cout << PersonWord[SNumber] <<"(学生“0”，老师“1”)" << ":"; cin >> Type;
		break;
	default:
		cout << "输入数字错误，请重新选择" << endl;
		break;

	}

}


/// <summary>
/// 借书函数
/// </summary>
/// <param name="borrowing_book"></param>
void Person::borrow( Book& borrowing_book)
{
	//TODO:后续添加判断是否有书过期，如有过期就不允许借书


	//判断当前是否可以借书
	if (BorrowedNumber<BookNumberLimit)
	{
		//再通过book类的借书函数判断当前书是否可以借
		if (borrowing_book.borrow())
		{
			borrowing_book.ReturnTime = borrowing_book.BorrowTime + BorrowDuration;
			borrowing_book.BorrowerID = ID;//把借书人的ID传到book中
			borrowing_book.Borrower = this;
			BooksID.push_back(borrowing_book.ID);
			BorrowedNumber++;
			cout << "借书成功" << endl;
		}
	}
	else
	{
		cout << "当前借书数量超出范围，借书操作失败" << endl;
	}
}


//还书函数，通过指定书的ID来实现对书的还
void Person::return_book(Book& returning_book)
{
	//首先判断书是否是自己借的
	bool return_status;
	if (BorrowedNumber==0)//当前没有借书
	{
		return_status = false;
		cout << "当前没有借书" << endl;
	}
	else
	{
		//判断当前书是否已借
		for (vector<int>::iterator iter = BooksID.begin(); iter != BooksID.end(); iter++)
		{        //从vector中删除指定的某一个元素
			if (*iter == returning_book.ID)
			{

				BooksID.erase(iter);//把当前书ID删除
				BorrowedNumber--;
				return_status = true;

				//处理book类
				returning_book.return_book();
				return;
				break;

			}
		}
		return_status = false;
		cout << "当前的书并没有借" << endl;
	}



}


/// <summary>
/// 显示所有已经借过的书
/// </summary>
/// <param name="books"></param>
void Person::display_all_books( vector<Book> &books)
{
	cout << "当前已借的书:";
	for (auto temp_bookID:BooksID)
	{
		for  (Book temp_book:books)
		{
			if (temp_book.ID==temp_bookID)
			{
				cout << "(" << temp_book.ID << ")"
					<< temp_book.Title<<"  ";
			}
		}
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}

/// <summary>
/// 搜索人员ID函数
/// </summary>
/// <param name="personID"></param>
/// <returns>
/// 正确返回true
/// 失败返回false
/// </returns>
bool Person::searchPersonID(int personID)
{
	if (personID==ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Person::searchPersonName(string name)
{
	if (name==Name)
	{
		return true;
	}
	return false;
}


//"编号","姓名","年龄","性别","电话","数量限制" ,"已借书数目","已借的所有书ID","组别"
void Person::save(ofstream &person_file)
{
	person_file <<setiosflags(ios::left)
		<<setw(8) << ID << " "
		<<setw(10) << Name << " "
		<<setw(5) << Age << " "
		<<setw(15) << PhoneNumber << " "

		<<setw(3) << BorrowedNumber << " "
		<<setw(3) << Type << " "
		<< "/"<<" ";
	for (int temp_ID : BooksID) {
		person_file << temp_ID << " ";
	}
	person_file << endl;
}

void Person::read(ifstream& person_file)
{
	string temp;
	person_file >> ID >> Name >> Age >> PhoneNumber >> BorrowedNumber >> Type>>temp;
	if (temp=="/")
	{
		if (BorrowedNumber>0)
		{
			for (size_t i = 0; i < BorrowedNumber; i++)
			{
				int temp_ID;
				person_file >> temp_ID;
				BooksID.push_back(temp_ID);
			}
		}
	}
	switch (Type)
	{
	case 0://学生
		BookNumberLimit = 10;
		BorrowDuration = 30 * chrono::hours(24);//30天
		break;
	case 1://老师
		BookNumberLimit = 20;
		BorrowDuration = 50 * chrono::hours(24);//50天
		break;

	default:
		BookNumberLimit = 5;
		BorrowDuration = 15 * chrono::hours(24);//15天
		break;
	}
}

bool Person::operator<(const Person& b)
{
	if (ID<b.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Person::operator<<( Person& b)
{
	InitPersonStruct personlist;
	Person temp_Person(personlist);
	if (*this < b)
	{
		return;
	}
	else
	{
		temp_Person = b;
		b = *this;
		*this = b;
	}
}

bool Person::operator>(const Person& b)
{
	if (ID>b.ID)
	{
		return true;
	}
	else
	{
		return false;
	}

}
