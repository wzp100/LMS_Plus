#include "Book.h"

vector<string> StatusWord{ "未借","已借","遗失未缴费","遗失已缴费" ,"遗失"};//状态，图书的状态，未借0，已借1，遗失未缴费2，遗失已缴费3，遗失4
vector<string>BookWord{ "编号","标题","作者","出版社","定价","状态","是否可借","借阅时间","归还时间","借书人","借书人ID"};//字段，方便打印

void display_book_title() {
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << BookWord[0]
		<< setw(10) << BookWord[1];

	cout << setw(8) << BookWord[2];
	cout << setw(8) << " ";

	cout << setw(15) << BookWord[3]
		<< setw(5) << BookWord[4];

		cout << setw(8) << BookWord[5];
		cout << setw(10) << BookWord[6];

	//显示借书时间,还书时间

		cout << setw(25) << BookWord[7];
		cout << setw(25) << BookWord[8];
		cout << setw(8) << BookWord[9];
		cout << setw(8) << BookWord[10];
	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Book::display()
{
	cout <<setiosflags(ios::left) << setw(10) << ID
		<< setw(10) << Title;
	int temp_i=0;
	for (string author:Author)
	{
		cout << setw(8) << author;
		temp_i++;
		if (temp_i>2)//如果有两个以上的作者就省略
		{
			break;
		}
	}
	if (temp_i==1)//将每一行显示的信息补齐，以保证显示的作者信息上下一致。
	{
		cout << setw(8)<<" ";
	}
	if (temp_i==0)
	{
		cout << setw(8) << " " << setw(8) << " ";
	}
	cout << setw(15) << Press
		<< setw(5) << Price ;
	switch (Status)
	{
	case 0:
		cout << setw(8) << StatusWord[Status]; break;
	case 1:
		cout << setw(8) << StatusWord[Status]; break;
	case 2:
		cout << setw(8) << StatusWord[Status]; break;
	case 3:
		cout << setw(8) << StatusWord[Status]; break;
	case 4:
		cout << setw(8) << StatusWord[Status]; break;

	default:
		cout<<setw(8)<<"未知"; break;
	}
	//显示借书状态
	if (BorrowStatus)
	{
		cout << setw(10) << "可借";
	}
	else
	{
		cout << setw(10) << "不可借";
	}
	//显示借书时间,还书时间
	if (BorrowStatus==0)
	{
		time_display(BorrowTime);
		cout << setw(6) << " ";
		time_display(ReturnTime);
		cout << setw(6) << " ";
		cout << setw(8) << Borrower->Name;//借书人的名字
		cout << setw(8) << BorrowerID;
	}
	else
	{
		cout << setw(25) << " ";
		cout << setw(25) << " ";
		cout << setw(8) << " ";

	}
	cout << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Book::modify()
{
	size_t i;
	int SNumber;

	while (true)
	{
		i = 0;
		cout << "选择修改相应的序号" << endl;

		for (string temp : BookWord)
		{
			if (i == 5)
			{
				break;
			}
			cout << "[" << i++ << "]" << ":" << temp << endl;

		}

		cout << "[" << i++ << "]" << ":" << "退出" << endl;


		cin >> SNumber;
		//"编号","标题","作者","出版社","定价","状态","是否可借","借阅时间","归还时间","借书人","借书人ID"
		switch (SNumber)
		{
		case 0:
			cout << "请确保修改后的ID没有被占用" << endl;
			cout << BookWord[SNumber] << ":";
			cin >> ID;
			break;
		case 1:
			cout << BookWord[SNumber] << ":";
			cin >> Title;
			break;
		case 2:
			cout << BookWord[SNumber] << ":";
			for (string temp_author : Author) {
				cout << "请输入:";
				cin >> temp_author;
			}
			break;
		case 3:
			cout << BookWord[SNumber] << ":";
			cin >> Press;
			break;
		case 4:
			cout << BookWord[SNumber] << ":";
			cin >> Price;
			break;
		case 5:
			return;
			break;
		default:
			cout << "输入序号错误，请重试" << endl;
			break;
		}
	}


}


bool Book::borrow()
{
	chrono::system_clock::time_point* p_temp_time;
	//先判断是否可以借
	if (BorrowStatus)
	{
		BorrowStatus = false;//将可借状态转为不可借
		Status = 1;
		//先得到当前的借阅时间
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//释放时间内存

		return true;
	}
	else
	{
		cout << "当前不可借," << setw(10) << "原因:" << StatusWord[Status] << endl;
		if (Status == 1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//如果已经借走就显示归还时间
			cout << endl;
		}
		return false;
	}
}

/// <summary>
/// 借书函数
/// 必须保证借书人ID可以找到，在使用前需要判断
/// </summary>
/// <param name="borrowerID"></param>
/// <returns>
/// 返回借书的情况
/// </returns>
bool Book::borrow(int borrowerID)
{
	chrono::system_clock::time_point* p_temp_time;
	//先判断是否可以借
	if (BorrowStatus)
	{
		BorrowStatus = false;//将可借状态转为不可借
		Status = 1;
		//先得到当前的借阅时间
		BorrowerID = borrowerID;
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//释放时间内存

		return true;
	}
	else
	{
		cout << "当前不可借,"<<setw(10) << "原因:" << StatusWord[Status] << endl;
		if (Status==1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//如果已经借走就显示归还时间
			cout << endl;
		}
		return false;
	}

}

bool Book::borrow(Person borrower)
{
	chrono::system_clock::time_point* p_temp_time;
	//先判断是否可以借
	if (BorrowStatus)
	{
		BorrowStatus = false;//将可借状态转为不可借
		Status = 1;
		//先得到当前的借阅时间
		BorrowerID = borrower.ID;
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//释放时间内存

		return true;
	}
	else
	{
		cout << "当前不可借," << setw(10) << "原因:" << StatusWord[Status] << endl;
		if (Status == 1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//如果已经借走就显示归还时间
			cout << endl;
		}
		return false;
	}
}

/// <summary>
/// 还书函数
///
/// </summary>
void Book::return_book()
{
	if (Status==1)
	{
		Status = 0;
		BorrowStatus = 1;
		chrono::system_clock::time_point* p_temp_time = get_Now();
		if (BorrowTime>*p_temp_time)
		{
			cout << "当前还书时间已超出，请缴费" << endl;
		}
		else
		{
			cout << "还书成功" << endl;
		}
	}
}

Book::Book(const InitBookStruct& book_list)
{
	ID = book_list.ID;//由bookpackage创建
	Title = book_list.Title;
	Author = book_list.Author;
	Press = book_list.Press;
	Price = book_list.Price;
	Status = book_list.Status;
	BorrowStatus = book_list.BorrowStatus;
	if (BorrowStatus==0)//如果已经有人借了
	{
		BorrowTime = book_list.BorrowTime;
		ReturnTime = book_list.ReturnTime;
		BorrowerID = book_list.BorrowerID;
	}

}

void Book::save(ofstream& book_file)
{

	book_file << setiosflags(ios::left) << setw(10) << ID
		<< setw(10) << Title;
	int temp_i = 0;
	book_file << " / ";
	for (string author : Author)
	{
		book_file << setw(8) << author;
	}
	book_file << " / ";
	if (temp_i == 1)//将每一行显示的信息补齐，以保证显示的作者信息上下一致。
	{
		book_file << setw(8) << " ";
	}
	if (temp_i == 0)
	{
		book_file << setw(8) << " " << setw(8) << " ";
	}
	book_file << setw(15) << Press
		<< setw(5) << Price;

	book_file << setw(8) << Status;

	//显示借书状态
		book_file << setw(8)<<BorrowStatus;
	//显示借书时间,还书时间
	if (BorrowStatus == 0)
	{
		time_display_file(BorrowTime,book_file);
		book_file << setw(6) << " ";
		time_display_file(ReturnTime,book_file);
		book_file << setw(6) << " ";
		book_file << setw(8) << Borrower->Name;//借书人的名字
		book_file << setw(8) << BorrowerID;
	}
	else
	{
		book_file << setw(5) << "*";

	}
	book_file << endl;
}

void Book::read(ifstream& book_file)
{
	//读取ID与标题
	book_file >> ID
		>> Title;
	//设置一个temp用来判断当前的字符
	string temp_string,temp_string1;
	book_file >> temp_string;
	if (temp_string=="/")
	{
		while (1)//用来读取作者，直到遇到“/”
		{
			book_file >> temp_string;
			if (temp_string == "/")
			{
				break;
			}
			else
			{
				Author.push_back(temp_string);
			}
		}
	}

	book_file >> Press
		>> Price
		>> Status
		>> BorrowStatus;//读取出版社，价格以及状态
	if (BorrowStatus==1)//没人借，就不读取
	{
		//book_file.ignore();//直接到下一行
		book_file >> temp_string;
	}
	else
	{
		tm borrowed_time{}, return_time{};

		//book_file >> get_time(&borrowed_time, "%y-%m-%d") >> get_time(&borrowed_time, "%H-%M-%S")
		//	>> get_time(&return_time, "%y-%m-%d") >> get_time(&return_time, "%H-%M-%S");
		book_file >> temp_string >> temp_string1;
		string ss,ss1;
		ss = temp_string + " " + temp_string1;
		stringstream borrow_time_string(ss);

		book_file >> temp_string >> temp_string1;
		ss1 = temp_string + " " + temp_string1;
		stringstream return_time_string(ss1);

		borrow_time_string >> get_time(&borrowed_time, "%Y-%m-%d %H:%M:%S");
		return_time_string >> get_time(&return_time, "%Y-%m-%d %H:%M:%S");

		//std::stringstream ss;
		//ss << "2021-01-06 18:47:35";

		//std::tm tm{};
		//ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

		BorrowTime = chrono::system_clock::from_time_t(mktime(&borrowed_time));

		ReturnTime = chrono::system_clock::from_time_t(mktime(&return_time));
		book_file >> BorrowerName
			>> BorrowerID;



		//cout << tp.time_since_epoch().count() << endl;

		//book_file >> temp_string>>temp_string1;//分别读取日期时间
		//temp_string = temp_string +" "+ temp_string1;//将日期与时间组合
		//int len = temp_string.length();
		//const char* d = " -:";
		//char* p;
		//char* s=new char[len+1];
		//char* ptr=NULL;

		//strcpy_s(s, len+1,temp_string.c_str());
		//p = strtok_s(s, d,&ptr);
		//tm temp_time;
		//
		//int n = 0;
		//while (p!=NULL)
		//{
		//	stringstream temp_sstream(p);
		//	switch (n++)
		//	{
		//	case 0 :
		//		temp_sstream >> temp_time.tm_year;
		//		cout << temp_time.tm_year;
		//		break;
		//	case 1:
		//		temp_sstream >> temp_time.tm_mon;
		//		cout << temp_time.tm_mon;
		//		break;
		//	case 2:
		//		temp_sstream >> temp_time.tm_wday;
		//		cout << temp_time.tm_wday;
		//		break;
		//	case 3:
		//		temp_sstream >> temp_time.tm_hour;
		//		cout << temp_time.tm_hour;
		//		break;
		//	case 4:
		//		temp_sstream >> temp_time.tm_min;
		//		cout << temp_time.tm_min;
		//		break;
		//	case 5:
		//		temp_sstream >> temp_time.tm_sec;
		//		cout << temp_time.tm_sec;
		//		break;
		//	default:
		//		break;
		//	}

		//	cout << p << endl;
		//	p = strtok_s(NULL, d,&ptr);
		//}




	}
}

/// <summary>
/// 搜索函数，用于判断ID与当前图书是否一致
/// </summary>
/// <param name="图书的ID"></param>
/// <returns>
/// 搜索是否成功
/// </returns>
bool Book::searchBookID(int bookID)
{
	if (bookID==ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// <summary>
/// 判断是否可以借
/// </summary>
/// <returns>
/// 可以:true
/// 不可以:false
/// </returns>
bool Book::borrowEnable()
{
	if (BorrowStatus)
	{
		return true;//可以借
	}
	return false;
}

bool Book::operator<(const Book& b)
{
	if (this->ID<b.ID)
	{
		return true;
	}
	return false;
}

bool Book::operator>(const Book& b)
{
	if (this->ID>b.ID)
	{
		return true;
	}
	return false;
}

void Book::operator<<(Book& b)
{
	if (*this<b)
	{
		return;
	}
	else
	{
		InitBookStruct booklist;
		Book temp_book(booklist);
		temp_book = *this;
		*this = b;
		b = temp_book;
	}
}



/// <summary>
/// 在一个借书人vector中找到同名ID以实现对于借书人的关联
/// </summary>
/// <param name="借书人容器"></param>
void Book::BulidRelationship(vector <Person>& borrowers)
{
	if (BorrowStatus==false)
	{

		bool build_realationship_success = false;
		for (Person& temp_person : borrowers)
		{
			if (temp_person.ID == ID)
			{
				Borrower = &temp_person;
				BorrowerName = temp_person.Name;
				build_realationship_success = true;
				break;
			}
		}

		if (!build_realationship_success)
		{
			cout << "关系建立不成功,未找到ID:" << BorrowerID << "姓名:" << BorrowerName << endl;

		}
	}
}
