
#include "bookInformationQqueryMenu.h"

/// <summary>
/// 4.ͼ����Ϣ��ѯ�����˵�
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void bookInformationQquery_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|********ͼ����Ϣ��ѯģ��********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.����Ų�ѯ            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.�������ѯ            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        3.�����߲�ѯ            |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        4.���������ѯ          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.�����ϼ��˵�          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   ��ѡ�������(0~4):");
		//�����û�ѡ��
		//scanf("%d", &nSortChoose);
		cin >> nSortChoose;
		switch (nSortChoose)
		{
		case 1:
			//4.1 ����Ų�ѯ
			idSearchBook(Books);
			system("PAUSE");
			break;
		case 2:
			//4.2 �������ѯ
			titleSearchBook(Books);
			system("PAUSE");
			break;
		case 3:
			//4.3 �����߲�ѯ
			authorSearchBook(Books);
			system("PAUSE");
			break;
		case 4:
			//4.4 ���������ѯ
			pressSearchBook(Books);
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
/// 4.1 ����Ų�ѯ
/// </summary>
/// <param name="Books"></param>
void idSearchBook(vector<Book>& Books)
{
	int temp_ID;
	cout << "��ǰΪID����ͼ��ģʽ" << endl;
	cout << "������Ҫ������ID:";
	cin >> temp_ID;
	for (Book temp_book : Books)
	{
		if (temp_book.searchBookID(temp_ID))
		{
			cout << "�����ɹ�" << endl;
			display_book_title();
			temp_book.display();
			return;
		}
	}
	cout << "����ʧ�ܣ�����ID�Ƿ���ȷ" << endl;
}

/// <summary>
/// 4.2 �������ѯ
/// </summary>
/// <param name="Books"></param>
void titleSearchBook(vector<Book>& Books)
{
	bool status = false;
	string title;
	cout << "��ǰΪ��������ͼ��ģʽ" << endl;
	cout << "������Ҫ����������:";
	cin >> title;

	display_book_title();
	for (Book temp_book : Books)
	{
		if (temp_book.Title == title)
		{
			temp_book.display();
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


/// <summary>
/// 4.3 �����߲�ѯ
/// </summary>
/// <param name="Books"></param>
void authorSearchBook(vector<Book>& Books)
{
	bool status = false;
	string author;
	cout << "��ǰΪ��������ͼ��ģʽ" << endl;
	cout << "������Ҫ����������:";
	cin >> author;

	display_book_title();
	for (Book temp_book : Books)
	{
		for (string temp_author : temp_book.Author)
		{
			if (temp_author == author)
			{
				temp_book.display();
				status = true;
				continue;
			}
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


/// <summary>
/// 4.4 ���������ѯ
/// </summary>
/// <param name="Books"></param>
void pressSearchBook(vector<Book>& Books)
{
	bool status = false;
	string press;
	cout << "��ǰΪ����������ͼ��ģʽ" << endl;
	cout << "������Ҫ�����ĳ�����:";
	cin >> press;

	display_book_title();
	for (Book temp_book : Books)
	{
		if (temp_book.Press == press)
		{
			temp_book.display();
			status = true;
		}
	}
	if (status)
	{
		cout << "  �������" << endl;
		return;
	}
	else
	{
		cout << "  δ���������" << endl;
	}
}
