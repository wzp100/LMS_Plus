#include "libraryMaintenanceMenu.h"
using namespace std;
/// <summary>
/// 2.���ά�������˵�
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void libraryMaintenance_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nManageChoose = 0;
	while (1)
	{
		system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********���ά��ģ��********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.����ͼ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.ɾ��ͼ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.�޸�ͼ����Ϣ      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.�����ϼ��˵�      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------ \n");
		printf("\t\t   ��ѡ�������(0~3):");
		//�����û�ѡ��
		cin >> nManageChoose;

		switch (nManageChoose)
		{
		case 1:
			addBookInfo(Books);//ת������ͼ����Ϣ����
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//������û���һ��
			system("PAUSE");
			break;
		case 2:
			deleteBookInfo(Books);//ת��ɾ��ͼ����Ϣ����
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//������û���һ��
			system("PAUSE");
			break;
		case 3:
			modifyBook(Books);//ת���޸�ͼ����Ϣ����
			//outputBookInfo(stu, szCourseName, *npBookNum, 0, 0, *npBookNum);//������û���һ��
			system("PAUSE");
			break;
		case 0:
			//�û�������һ��
			return;
			break;
			//�û�ѡ������
		default:
			printf("\t\tѡ����������ѡ��\n");
		}
	}
}


/// <summary>
/// 2.1 ����ͼ����Ϣ
/// </summary>
/// <param name="Books"></param>
void addBookInfo(vector<Book>& Books)
{
	InitBookStruct bookList;
	int length;
	bool status = false;
	while (true)
	{
		cout << "������ID:";
		cin >> bookList.ID;
		if (bookList.ID == 0)
		{
			return;
		}
		for (Book temp_Book : Books)
		{
			//�жϵ�ǰID�Ƿ���ռ��
			if (temp_Book.searchBookID(bookList.ID))
			{
				status = true;
				break;
			}
		}

		if (status == true)
		{
			cout << "��ǰID��ռ��,����������ID,������0�˳���" << endl;
			status = false;
		}
		else
		{
			break;
		}
	}
	cout << "����������:";
	cin >> bookList.Title;
	cout << "�������м�λ����:";
	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		cout << "����������" << i + 1 << ":";
		string author;
		cin >> author;
		bookList.Author.push_back(author);
	}
	cout << "�����������:";
	cin >> bookList.Press;
	cout << "������ͼ��۸�:";
	cin >> bookList.Price;
	Book temp_book(bookList);

	cout << "������Ϣ�Ƿ���ȷ" << endl;
	display_book_title();
	temp_book.display();
	Books.push_back(temp_book);
	cout << "����ͼ��ɹ�" << endl;
}


/// <summary>
/// 2.2 ɾ��ͼ����Ϣ����
/// </summary>
/// <param name="Books"></param>
void deleteBookInfo(vector<Book>& Books)
{
	cout << "  ��ǰΪͼ����Ϣɾ��ģ��  " << endl;

	int temp_ID;
	cout << "������Ҫɾ��ͼ���ID(��ȷ����ǰͼ��û�б���):" << endl;
	cin >> temp_ID;
	for (vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++)
	{
		//��vector��ɾ��ָ����ĳһ��Ԫ��

		if ((*iter).searchBookID(temp_ID))
		{
			if ((*iter).borrowEnable())
			{
				Books.erase(iter);//�ѵ�ǰ��IDɾ��
				cout << "ɾ���ɹ�" << endl;
				return;
				break;
			}
			else
			{
				cout << "��ǰ���ѱ��裬�޷�ɾ��" << endl;
				return;
			}
		}
	}
	cout << "δ�ҵ�ID�����Ϣ������ID�Ƿ���ȷ" << endl;
}


/// <summary>
/// 2.3 �޸�ͼ����Ϣ����
/// </summary>
/// <param name="Books"></param>
void modifyBook(vector<Book>& Books)
{
	int temp_ID;
	cout << "������Ҫ�޸ĵ�ID:" << endl;
	cin >> temp_ID;
	for (vector<Book>::iterator i = Books.begin(); i != Books.end(); i++)
	{
		if ((*i).searchBookID(temp_ID))
		{
			if ((*i).borrowEnable())
			{
				(*i).modify();
				cout << "�����޸ĺ�Ľ��" << endl;
				display_book_title();
				(*i).display();
				return;
			}
			else
			{
				cout << "��ǰ���ѱ���,�޷��޸�" << endl;
				return;
			}
		}
	}
	cout << "û���ҵ�ID" << endl;
}

