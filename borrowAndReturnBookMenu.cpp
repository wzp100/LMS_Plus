#include "borrowAndReturnBookMenu.h"


/// <summary>
/// 1.����Ķ����˵�
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void borrowAndReturnBook_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nMainchoose;
	//���˵�����ѭ��
	while (1)
	{
		system("CLS"); //ϵͳ��Ļ���
		//����˵�������
		printf("\t\t------------------------------\n");
		printf("\t\t|********���黹��ģ��********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.����ͼ��          |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.�黹ͼ��          |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.�����ϼ��˵�      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------ \n");
		printf("\t\t   ��ѡ�������:");


		//�û����ݽ�����ʾ��������
		cin >> nMainchoose;
		system("CLS");
		//�����û���������ֿ�����ж�
		switch (nMainchoose)
		{
			//ת�����麯��
		case 1:
			borrowBook(Borrowers, Books);
			system("PAUSE");
			break;

			//ת�����麯��
		case 2:
			returnBook(Borrowers, Books);
			system("PAUSE");
			break;

			//ת�������˵������ά���˵�ѡ����ʾ
		case 3:
			break;

		case 0:
			return;
			break;
			//�û�ѡ������
		default:
			printf("ѡ����������ѡ��\n");
		}//switch����
	}//while(1)��������
}



int searchPerson(vector<Person>& Borrowers, int ID)
{
	int n = 0;
	for (Person& temp_Person : Borrowers)
	{
		if (ID == temp_Person.ID)
		{
			return n;//�ҵ����ر��
		}
		n++;
	}
	return -1;//û���ҵ�����-1
}

/// <summary>
/// 1.1���麯��
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void borrowBook(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  ��ǰΪ����ģ��  " << endl;

	int temp_ID;//�ݴ�ID
	int temp_BookID;
	int temp_Number;//���
	bool searchStatus = false;
	cout << "�������û�ID:";
	cin >> temp_ID;

	//�õ���ǰ�����
	temp_Number = searchPerson(Borrowers, temp_ID);
	if (temp_Number > 0)
	{
		display_person_title();//��ʾ��ͷ
		Borrowers[temp_Number].display();//��ʾ��Ϣ
		cout << "������Ϣ�Ƿ���ȷ" << endl;
		cout << "������Ҫ�����ID:";
		cin >> temp_BookID;
		//��鵱ǰ���ID�Ƿ�����ҵ�
		for (Book& temp_book : Books)
		{
			if (temp_book.searchBookID(temp_BookID))
			{
				searchStatus = true;
				Borrowers[temp_Number].borrow(temp_book);
				//��ʾ��ǰ����Ϣ
				cout << "����������Ϣ�Ƿ���ȷ" << endl;
				display_book_title();
				temp_book.display();
				display_person_title();
				Borrowers[temp_Number].display();
				Borrowers[temp_Number].display_all_books(Books);
				break;
			}

		}
		//�ҵ�����
		if (searchStatus == true)
		{

		}
		//û���ҵ�
		else
		{
			cout << "û���ҵ���Ӧ��ID��������" << endl;
		}

	}
	//û���ҵ�ID
	else
	{
		cout << "û���ҵ���ӦID��������" << endl;
	}

}


/// <summary>
/// 1.2���廹�麯��
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void returnBook(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  ��ǰΪ����ģ��  " << endl;

	int temp_ID;//�ݴ�ID
	int temp_BookID;
	int temp_Number;//���
	bool searchStatus = false;
	cout << "�������û�ID:";
	cin >> temp_ID;

	//�õ���ǰ�����
	temp_Number = searchPerson(Borrowers, temp_ID);
	//���û�н���ֱ�ӽ���
	if (Borrowers[temp_Number].BooksID.size() == 0)
	{
		cout << "��ǰû�н���" << endl;
		return;
	}
	if (temp_Number > 0)
	{
		display_person_title();//��ʾ��ͷ
		Borrowers[temp_Number].display();//��ʾ��Ϣ
		Borrowers[temp_Number].display_all_books(Books);
		cout << "������Ϣ�Ƿ���ȷ" << endl;
		cout << "������Ҫ�����ID:";
		cin >> temp_BookID;
		//��鵱ǰ���ID�Ƿ�����ҵ�
		for (Book& temp_book : Books)
		{
			if (temp_book.searchBookID(temp_BookID))
			{
				searchStatus = true;
				Borrowers[temp_Number].return_book(temp_book);
				//��ʾ��ǰ����Ϣ
				cout << "����������Ϣ�Ƿ���ȷ" << endl;
				display_book_title();
				temp_book.display();
				display_person_title();
				Borrowers[temp_Number].display();
				Borrowers[temp_Number].display_all_books(Books);
				break;
			}

		}
		//�ҵ�����
		if (searchStatus == true)
		{

		}
		//û���ҵ�
		else
		{
			cout << "û���ҵ���Ӧ��ID��������" << endl;
		}

	}
	//û���ҵ�ID
	else
	{
		cout << "û���ҵ���ӦID��������" << endl;
	}
}




