#include "Book.h"

vector<string> StatusWord{ "δ��","�ѽ�","��ʧδ�ɷ�","��ʧ�ѽɷ�" ,"��ʧ"};//״̬��ͼ���״̬��δ��0���ѽ�1����ʧδ�ɷ�2����ʧ�ѽɷ�3����ʧ4
vector<string>BookWord{ "���","����","����","������","����","״̬","�Ƿ�ɽ�","����ʱ��","�黹ʱ��","������","������ID"};//�ֶΣ������ӡ

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

	//��ʾ����ʱ��,����ʱ��

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
		if (temp_i>2)//������������ϵ����߾�ʡ��
		{
			break;
		}
	}
	if (temp_i==1)//��ÿһ����ʾ����Ϣ���룬�Ա�֤��ʾ��������Ϣ����һ�¡�
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
		cout<<setw(8)<<"δ֪"; break;
	}
	//��ʾ����״̬
	if (BorrowStatus)
	{
		cout << setw(10) << "�ɽ�";
	}
	else
	{
		cout << setw(10) << "���ɽ�";
	}
	//��ʾ����ʱ��,����ʱ��
	if (BorrowStatus==0)
	{
		time_display(BorrowTime);
		cout << setw(6) << " ";
		time_display(ReturnTime);
		cout << setw(6) << " ";
		cout << setw(8) << Borrower->Name;//�����˵�����
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
		cout << "ѡ���޸���Ӧ�����" << endl;

		for (string temp : BookWord)
		{
			if (i == 5)
			{
				break;
			}
			cout << "[" << i++ << "]" << ":" << temp << endl;

		}

		cout << "[" << i++ << "]" << ":" << "�˳�" << endl;


		cin >> SNumber;
		//"���","����","����","������","����","״̬","�Ƿ�ɽ�","����ʱ��","�黹ʱ��","������","������ID"
		switch (SNumber)
		{
		case 0:
			cout << "��ȷ���޸ĺ��IDû�б�ռ��" << endl;
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
				cout << "������:";
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
			cout << "������Ŵ���������" << endl;
			break;
		}
	}


}


bool Book::borrow()
{
	chrono::system_clock::time_point* p_temp_time;
	//���ж��Ƿ���Խ�
	if (BorrowStatus)
	{
		BorrowStatus = false;//���ɽ�״̬תΪ���ɽ�
		Status = 1;
		//�ȵõ���ǰ�Ľ���ʱ��
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//�ͷ�ʱ���ڴ�

		return true;
	}
	else
	{
		cout << "��ǰ���ɽ�," << setw(10) << "ԭ��:" << StatusWord[Status] << endl;
		if (Status == 1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//����Ѿ����߾���ʾ�黹ʱ��
			cout << endl;
		}
		return false;
	}
}

/// <summary>
/// ���麯��
/// ���뱣֤������ID�����ҵ�����ʹ��ǰ��Ҫ�ж�
/// </summary>
/// <param name="borrowerID"></param>
/// <returns>
/// ���ؽ�������
/// </returns>
bool Book::borrow(int borrowerID)
{
	chrono::system_clock::time_point* p_temp_time;
	//���ж��Ƿ���Խ�
	if (BorrowStatus)
	{
		BorrowStatus = false;//���ɽ�״̬תΪ���ɽ�
		Status = 1;
		//�ȵõ���ǰ�Ľ���ʱ��
		BorrowerID = borrowerID;
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//�ͷ�ʱ���ڴ�

		return true;
	}
	else
	{
		cout << "��ǰ���ɽ�,"<<setw(10) << "ԭ��:" << StatusWord[Status] << endl;
		if (Status==1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//����Ѿ����߾���ʾ�黹ʱ��
			cout << endl;
		}
		return false;
	}

}

bool Book::borrow(Person borrower)
{
	chrono::system_clock::time_point* p_temp_time;
	//���ж��Ƿ���Խ�
	if (BorrowStatus)
	{
		BorrowStatus = false;//���ɽ�״̬תΪ���ɽ�
		Status = 1;
		//�ȵõ���ǰ�Ľ���ʱ��
		BorrowerID = borrower.ID;
		p_temp_time = get_Now();
		BorrowTime = *p_temp_time;
		delete(p_temp_time);//�ͷ�ʱ���ڴ�

		return true;
	}
	else
	{
		cout << "��ǰ���ɽ�," << setw(10) << "ԭ��:" << StatusWord[Status] << endl;
		if (Status == 1)
		{
			cout << BookWord[8] << ":"; time_display(ReturnTime);//����Ѿ����߾���ʾ�黹ʱ��
			cout << endl;
		}
		return false;
	}
}

/// <summary>
/// ���麯��
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
			cout << "��ǰ����ʱ���ѳ�������ɷ�" << endl;
		}
		else
		{
			cout << "����ɹ�" << endl;
		}
	}
}

Book::Book(const InitBookStruct& book_list)
{
	ID = book_list.ID;//��bookpackage����
	Title = book_list.Title;
	Author = book_list.Author;
	Press = book_list.Press;
	Price = book_list.Price;
	Status = book_list.Status;
	BorrowStatus = book_list.BorrowStatus;
	if (BorrowStatus==0)//����Ѿ����˽���
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
	if (temp_i == 1)//��ÿһ����ʾ����Ϣ���룬�Ա�֤��ʾ��������Ϣ����һ�¡�
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

	//��ʾ����״̬
		book_file << setw(8)<<BorrowStatus;
	//��ʾ����ʱ��,����ʱ��
	if (BorrowStatus == 0)
	{
		time_display_file(BorrowTime,book_file);
		book_file << setw(6) << " ";
		time_display_file(ReturnTime,book_file);
		book_file << setw(6) << " ";
		book_file << setw(8) << Borrower->Name;//�����˵�����
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
	//��ȡID�����
	book_file >> ID
		>> Title;
	//����һ��temp�����жϵ�ǰ���ַ�
	string temp_string,temp_string1;
	book_file >> temp_string;
	if (temp_string=="/")
	{
		while (1)//������ȡ���ߣ�ֱ��������/��
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
		>> BorrowStatus;//��ȡ�����磬�۸��Լ�״̬
	if (BorrowStatus==1)//û�˽裬�Ͳ���ȡ
	{
		//book_file.ignore();//ֱ�ӵ���һ��
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

		//book_file >> temp_string>>temp_string1;//�ֱ��ȡ����ʱ��
		//temp_string = temp_string +" "+ temp_string1;//��������ʱ�����
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
/// ���������������ж�ID�뵱ǰͼ���Ƿ�һ��
/// </summary>
/// <param name="ͼ���ID"></param>
/// <returns>
/// �����Ƿ�ɹ�
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
/// �ж��Ƿ���Խ�
/// </summary>
/// <returns>
/// ����:true
/// ������:false
/// </returns>
bool Book::borrowEnable()
{
	if (BorrowStatus)
	{
		return true;//���Խ�
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
/// ��һ��������vector���ҵ�ͬ��ID��ʵ�ֶ��ڽ����˵Ĺ���
/// </summary>
/// <param name="����������"></param>
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
			cout << "��ϵ�������ɹ�,δ�ҵ�ID:" << BorrowerID << "����:" << BorrowerName << endl;

		}
	}
}
