
#include "personnelManagementMenu.h"


/// <summary>
/// 5.��Ա����ģ������˵�
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void personnelManagement_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nPersonChoose;
	while (1)
	{
		system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********��Ա����ģ��********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.������Ա��Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.ɾ����Ա��Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.�޸���Ա��Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        4.���������        |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        5.����������        |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.�����ϼ��˵�      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------  \n");
		printf("\t\t   ��ѡ�������:");
		//�����û�ѡ��
		//scanf("%d", &nPersonChoose);
		cin >> nPersonChoose;
		switch (nPersonChoose)
		{
		case 1:
			Person::add_a_Borrower();
;			system("PAUSE");
			break;
		case 2:
			deletePersonInfo(Borrowers);//(stu, szCourseName, npPersonNum);//ת��ɾ����Ա��Ϣ����
			//OutputPersonInfo(stu, szCourseName, *npPersonNum, 0, 0, *npPersonNum);//������û���һ��
			system("PAUSE");
			break;
		case 3:
			modifyPerson(Borrowers);//(stu, szCourseName, *npPersonNum);//ת���޸���Ա��Ϣ����
			system("PAUSE");
			break;
		case 4:
			idSearchPerson(Borrowers);
			system("PAUSE");
			break;
		case 5:
			nameSearchPerson(Borrowers);
			system("PAUSE");
			break;
		case 0:
			return;
			break;

		default:
			printf("\t\tѡ����������ѡ��\n");
		}
	}
}


/// <summary>
/// 5.1 ������Ա��Ϣ
/// </summary>
/// <param name="Borrowers"></param>
void addPersonInfo(vector<Person>& Borrowers)
{
	InitPersonStruct personList;
	cout << "������ID:";
	cin >> personList.ID;
	cout << "����������:";
	cin >> personList.Name;
	cout << "����������:";
	cin >> personList.Age;
	cout << "������绰:";
	cin >> personList.PhoneNumber;
	cout << "�������Ա�(0ΪŮ��1Ϊ��):" << endl;
	cin >> personList.Gender;
	cout << "���������(0)Ϊѧ����(1)Ϊ��ʦ:" << endl;
	cin >> personList.Type;
	Person temp_person(personList);

	cout << "�����Ƿ���ȷ" << endl;
	display_person_title();

	temp_person.display();

	Borrowers.push_back(temp_person);

}

void addPersonInfo(int id, string name)
{
	extern vector<Person> Borrowers;
	InitPersonStruct personList;
	personList.ID=id;
	personList.Name=name;
	cout << "����������:";
	cin >> personList.Age;
	cout << "������绰:";
	cin >> personList.PhoneNumber;
	cout << "�������Ա�(0ΪŮ��1Ϊ��):" << endl;
	cin >> personList.Gender;
	cout << "���������(0)Ϊѧ����(1)Ϊ��ʦ:" << endl;
	cin >> personList.Type;
	Person temp_person(personList);

	cout << "�����Ƿ���ȷ" << endl;
	display_person_title();

	temp_person.display();
	
	Borrowers.push_back(temp_person);
	system("pause");
}




/// <summary>
/// 5.2 ɾ����Ա��Ϣ
/// </summary>
/// <param name="Borrowers"></param>
void deletePersonInfo(vector<Person>& Borrowers)
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
				cout << "ɾ���ɹ�" << endl;
				return;
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


/// <summary>
/// 5.3 �޸���Ա��Ϣ
/// </summary>
/// <param name="Borrowers"></param>
void modifyPerson(vector<Person>& Borrowers)
{
	int temp_ID;
	cout << "������Ҫ�޸ĵ�ID:" << endl;
	cin >> temp_ID;
	for (vector<Person>::iterator i = Borrowers.begin(); i != Borrowers.end(); i++)
	{
		if ((*i).searchPersonID(temp_ID))
		{
			if ((*i).BorrowedNumber == 0)
			{
				(*i).modify();
				cout << "�����޸ĺ�Ľ��" << endl;
				display_person_title();
				(*i).display();
				return;
			}
			else
			{
				cout << "��ǰ��Ա�ѽ���,�޷��޸�" << endl;
				return;
			}
		}
	}
	cout << "û���ҵ�ID" << endl;
}


/// <summary>
/// 5.4 ����Ų�ѯ
/// </summary>
/// <param name="Borrowers"></param>
void idSearchPerson(vector<Person>& Borrowers)
{
	int temp_ID;
	cout << "��ǰΪID������Աģʽ" << endl;
	cout << "������Ҫ������ID:";
	cin >> temp_ID;
	for (Person temp_person : Borrowers)
	{
		if (temp_person.searchPersonID(temp_ID))
		{
			cout << "�����ɹ�" << endl;
			display_person_title();
			temp_person.display();
			cout << endl;
			return;
		}
	}
	cout << "����ʧ�ܣ�����ID�Ƿ���ȷ" << endl;
}


/// <summary>
/// 5.5 ��������ѯ
/// </summary>
/// <param name="Borrowers"></param>
void nameSearchPerson(vector<Person>& Borrowers)
{
	bool status = false;
	string name;
	cout << "��ǰΪ����������Աģʽ" << endl;
	cout << "������Ҫ��������Ա:";
	cin >> name;

	display_person_title();
	for (Person temp_person : Borrowers)
	{
		if (temp_person.searchPersonName(name))
		{
			temp_person.display();
			status = true;
		}
	}
	if (status)
	{
		cout << "�������" << endl;
		return;
	}
	else
	{
		cout << "δ���������" << endl;
	}

}
