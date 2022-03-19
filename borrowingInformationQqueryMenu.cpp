#include "borrowingInformationQqueryMenu.h"


/// <summary>
/// 3.������Ϣ��ѯ�˵�
/// </summary>
/// <param name="Books"></param>
/// <param name="Borrowers"></param>
void borrowingInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|********������Ϣ��ѯģ��********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.����ͼ��������      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.������Ա�������      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        3.���������Ϣ��ѯ      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        4.���˽�����Ϣ��ѯ      |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.�����ϼ��˵�          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   ��ѡ�������(0~4):");
		//�����û�ѡ��
		//scanf("%d", &nSortChoose);
		cin >> nSortChoose;
		system("CLS");
		switch (nSortChoose)
		{
		case 1:
			//3.1 ����ͼ��������
			allBooksInformation(Books);
			system("PAUSE");
			break;
		case 2:
			//3.2 ������Ա�������
			allPersonsInformation(Borrowers, Books);
			system("PAUSE");
			break;
		case 3:
			//3.3 ���������Ϣ��ѯ
			singleBookInformation(Books);
			system("PAUSE");
			break;
		case 4:
			//3.4 ���˽�����Ϣ��ѯ
			singlePersonInformation(Borrowers, Books);
			system("PAUSE");
			break;
		case 0:
			return;
			break;
		default:printf("\t\tѡ����������ѡ��\n");
		}//switch����
	}//while(1)����
}

/// <summary>
/// 3.1 ����ͼ��������
/// </summary>
/// <param name="Books"></param>
void allBooksInformation(vector<Book>& Books)
{
	cout << "��ǰ�鼮����Ϣ" << endl;
	//����չʾ����
	display_book_title();
	for (Book temp_book : Books)
	{
		temp_book.display();
	}
}

/// <summary>
/// 3.2 ������Ա�������
/// </summary>
/// <param name="Borrowers"></param>
void allPersonsInformation(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "��ǰ�鼮����Ϣ" << endl;
	//����չʾ����
	display_person_title();
	for (Person temp_person : Borrowers)
	{
		temp_person.display();
		temp_person.display_all_books(Books);
	}
}

/// <summary>
/// 3.3 ���˽�����Ϣ��ѯ
/// </summary>
/// <param name="Books"></param>
void singleBookInformation(vector<Book>& Books)
{
	int temp_ID;
	cout << "�������鼮ID:";
	cin >> temp_ID;
	for (Book temp_Book : Books)
	{
		if (temp_Book.searchBookID(temp_ID))
		{
			display_book_title();
			temp_Book.display();
			return;
			break;
		}
	}
	cout << "û���ҵ�����" << endl;
}

/// <summary>
/// 3.4 ���˽�����Ϣ��ѯ
/// </summary>
/// <param name="Borrowers"></param>
void singlePersonInformation(vector<Person>& Borrowers, vector<Book>& Books)
{
	int temp_ID;
	cout << "��������ԱID:";
	cin >> temp_ID;
	for (Person temp_Borrower : Borrowers)
	{
		if (temp_Borrower.searchPersonID(temp_ID))
		{
			display_person_title();
			temp_Borrower.display();
			temp_Borrower.display_all_books(Books);
			return;
			break;
		}
	}
	cout << "û���ҵ�����" << endl;
}

