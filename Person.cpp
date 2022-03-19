#include "Person.h"
#include "User.h"
#include"Menu.h"
vector <string> PersonWord{ "���","����","����","�Ա�","�绰","��������" ,"�ѽ�����Ŀ","�ѽ��������ID","���"};

//��ʾ����
extern User* present_user;
extern Person* present_borrower;
extern Admin* present_admin;
extern vector<Admin> Admins;
extern vector<User> Users;
extern vector<Person>Borrowers;
extern vector<Book> Books;

/// <summary>
/// ��ʾ����
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
//����һ��������
void add_a_person() {
	//TODO:����һ��person������
}

Person::Person(const InitPersonStruct& person_list)
{
	ID=person_list.ID;//0���
	Name =person_list.Name;//1����
	Age = person_list.Age;//2����
	Gender = person_list.Gender;//3�Ա���Ϊ1��ŮΪ0
	PhoneNumber = person_list.PhoneNumber;//4�绰
	BorrowedNumber = person_list.BorrowedNumber;//6�ѽ���Ŀ
	BooksID=person_list.BooksID;//7�ӵ������ID����
	Type=person_list.Type;//8��𣬱�ʾ�˵����ͣ���ͬ���в�ͬ�Ľ�����Ŀ���Լ������ʱ��
	switch (Type)
	{
	case 0 ://ѧ��
		BookNumberLimit = 10;
		BorrowDuration = 30 * chrono::hours(24);//30��
		break;
	case 1://��ʦ
		BookNumberLimit = 20;
		BorrowDuration = 50 * chrono::hours(24);//50��
		break;

	default:
		BookNumberLimit = 5;
		BorrowDuration = 15 * chrono::hours(24);//15��
		break;
	}


}
//"���","����","����","�Ա�","�绰","ͼ�������������" ,"�ѽ�����Ŀ","�ѽ��������ID","���"
void Person::display()
{
	string sex;
	(Gender) ? (sex = "��") : (sex = "Ů");
	cout << setw(10) << ID
		<< setw(10) << Name
		<< setw(8) << Age
		<< setw(8) << sex
		<< setw(15) << PhoneNumber
		<< setw(10) << BookNumberLimit
		<< setw(12) << BorrowedNumber;
	switch (Type)
	{
	case 0://ѧ��
		cout <<setw(10) << "ѧ��";
		break;
	case 1://��ʦ
		cout <<setw(10) << "��ʦ";
		break;

	default:
		cout <<setw(10)<< "����";
		break;
	}

	cout<< endl;
}

//Person�޸ĺ����Ľӿ�
void person_modify(Person & person)
{

}


//"���","����","����","�Ա�","�绰","��������" ,"�ѽ�����Ŀ","�ѽ��������ID","���"
void Person::modify()
{
	size_t i = 0;
	int SNumber = 0;

	cout << "ѡ���޸���Ӧ�����" << endl;

	for (string temp : PersonWord)
	{
		if (i == 8)
		{
			continue;
		}
		cout << "[" << i++ << "]" << ":" << temp << endl;

	}
	cin >> SNumber;
	string temp_name;
	int temp_id;
	User* temp_user;
	switch (SNumber)
	{
	case 0:

		cout << PersonWord[SNumber]<<":"; cin >> temp_id;
		temp_user = User::Search_ID(temp_id);
		(*temp_user).ID = temp_id;
		ID = temp_id;
		break;
	case 1:

		cout << PersonWord[SNumber]<<":"; cin >> temp_name;
		temp_user = User::Search_ID(ID);
		(*temp_user).Name = temp_name;
		Name = temp_name;
		
		break;

	case 2:
		cout << PersonWord[SNumber] << ":"; cin >> Age;
		break;
	case 3:
		cout << PersonWord[SNumber] <<"(�С�1����Ů��0��)" << ":"; cin >> Gender;
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
		cout << PersonWord[SNumber] <<"(ѧ����0������ʦ��1��)" << ":"; cin >> Type;
		break;
	default:
		cout << "�������ִ���������ѡ��" << endl;
		break;

	}

}

void Person::personal_modify()
{
	size_t i = 0;
	int SNumber = 0;
	size_t n = 0;
	cout << "ѡ���޸���Ӧ�����" << endl;

	for (string temp : PersonWord)
	{
		i++;
		if (i==1)
		{
			
			continue;
		}
		if (i == 8)
		{
			continue;
		}
		n++;
		cout << "[" << n << "]" << ":" << temp << endl;

	}
	cin >> SNumber;
	string temp_name;
	User* temp_user;
	switch (SNumber)
	{
	case 1:

		cout << PersonWord[SNumber] << ":"; cin >> temp_name;
		temp_user = User::Search_ID(ID);
		(*temp_user).Name = temp_name;
		Name = temp_name;

		break;

	case 2:
		cout << PersonWord[SNumber] << ":"; cin >> Age;
		break;
	case 3:
		cout << PersonWord[SNumber] << "(�С�1����Ů��0��)" << ":"; cin >> Gender;
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
		cout << PersonWord[SNumber] << "(ѧ����0������ʦ��1��)" << ":"; cin >> Type;
		break;
	default:
		cout << "�������ִ���������ѡ��" << endl;
		break;

	}
}


/// <summary>
/// ���麯��
/// </summary>
/// <param name="borrowing_book"></param>
void Person::borrow( Book& borrowing_book)
{
	//TODO:��������ж��Ƿ�������ڣ����й��ھͲ��������


	//�жϵ�ǰ�Ƿ���Խ���
	if (BorrowedNumber<BookNumberLimit)
	{
		//��ͨ��book��Ľ��麯���жϵ�ǰ���Ƿ���Խ�
		if (borrowing_book.borrow())
		{
			borrowing_book.ReturnTime = borrowing_book.BorrowTime + BorrowDuration;
			borrowing_book.BorrowerID = ID;//�ѽ����˵�ID����book��
			borrowing_book.Borrower = this;
			BooksID.push_back(borrowing_book.ID);
			BorrowedNumber++;
			cout << "����ɹ�" << endl;
		}
	}
	else
	{
		cout << "��ǰ��������������Χ���������ʧ��" << endl;
	}
}


//���麯����ͨ��ָ�����ID��ʵ�ֶ���Ļ�
void Person::return_book(Book& returning_book)
{
	//�����ж����Ƿ����Լ����
	bool return_status;
	if (BorrowedNumber==0)//��ǰû�н���
	{
		return_status = false;
		cout << "��ǰû�н���" << endl;
	}
	else
	{
		//�жϵ�ǰ���Ƿ��ѽ�
		for (vector<int>::iterator iter = BooksID.begin(); iter != BooksID.end(); iter++)
		{        //��vector��ɾ��ָ����ĳһ��Ԫ��
			if (*iter == returning_book.ID)
			{

				BooksID.erase(iter);//�ѵ�ǰ��IDɾ��
				BorrowedNumber--;
				return_status = true;

				//����book��
				returning_book.return_book();
				return;
				break;

			}
		}
		return_status = false;
		cout << "��ǰ���鲢û�н�" << endl;
	}



}


/// <summary>
/// ��ʾ�����Ѿ��������
/// </summary>
/// <param name="books"></param>
void Person::display_all_books( vector<Book> &books)
{
	cout << "��ǰ�ѽ����:";
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

void Person::display_all_books()
{
	extern vector <Book>Books;
	cout << setw(10) << "ID" << setw(10) << "����" << setw(25) << "����ʱ��" << setw(25) << "����ʱ��" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	for (auto temp_bookID : BooksID)
	{
		for (Book &temp_book : Books)
		{
			if (temp_book.ID == temp_bookID)
			{
				cout <<setw(10)<< temp_book.ID << setw(10)
					<< temp_book.Title << setw(10);
				time_display(temp_book.BorrowTime);
				cout << "  ";
				time_display(temp_book.ReturnTime);
				cout << endl;
				
			}
		}
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

}

/// <summary>
/// ������ԱID����
/// </summary>
/// <param name="personID"></param>
/// <returns>
/// ��ȷ����true
/// ʧ�ܷ���false
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


//"���","����","����","�Ա�","�绰","��������" ,"�ѽ�����Ŀ","�ѽ��������ID","���"
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
	case 0://ѧ��
		BookNumberLimit = 10;
		BorrowDuration = 30 * chrono::hours(24);//30��
		break;
	case 1://��ʦ
		BookNumberLimit = 20;
		BorrowDuration = 50 * chrono::hours(24);//50��
		break;

	default:
		BookNumberLimit = 5;
		BorrowDuration = 15 * chrono::hours(24);//15��
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

void Person::display_header()
{
	cout << "--------------------------------------------------------------------------------" << endl;
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

void Person::delete_a_Borrower()
{
	cout << "  ��ǰΪ��Ա��Ϣɾ��ģ��  " << endl;

	int temp_ID;
	cout << "������Ҫɾ����Ա��ID(��ȷ����ǰ��Աû�н���):" << endl;
	cin >> temp_ID;
	for (vector<Person>::iterator iter = Borrowers.begin(); iter != Borrowers.end(); iter++)
	{
		//��vector��ɾ��ָ����ĳһ��Ԫ��

		if ((*iter).searchPersonID(temp_ID))
		{
			if ((*iter).BorrowedNumber == 0)
			{
				Borrowers.erase(iter);//�ѵ�ǰ��IDɾ��
				cout << "ɾ����Ϣ�ɹ�" << endl;
				


				for (vector<User>::iterator ite = Users.begin(); ite != Users.end(); ite++)
				{
					if ((*ite).search_ID(temp_ID))
					{
						Users.erase(ite);
						cout << "ɾ���˺ųɹ�" << endl;
						return;
						
					}
				}
				cout << "ɾ���˺�ʧ��" << endl;
				break;

			}
			else
			{
				cout << "��ǰ��Ա�ѽ��飬�޷�ɾ��" << endl;
				return;
			}
		}
	}


	cout << "δ�ҵ�ID�����Ϣ������ID�Ƿ���ȷ" << endl;
}

void Person::display_all_books_header()
{
	cout << "��ǰ�ѽ����:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

}

void Person::add_a_Borrower()
{
	User_Register();
}