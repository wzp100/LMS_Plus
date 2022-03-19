
#include "saveMenu.h"
#include "FileProcess.h"
#include "Admin.h"


/// <summary>
/// 6.�ļ���������˵�
/// </summary>
/// <param name="books"></param>
/// <param name="Borrowers"></param>
/// <param name="nBookNum"></param>
void save_Menu(vector<Person>& Borrowers, vector<Book>& Books)
{
	int nSortChoose;

	while (1)
	{
		system("CLS");
		printf("\t\t----------------------------------\n");
		printf("\t\t|**********�ļ�����ģ��**********|\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        1.�ļ�����              |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        2.�ļ�����              |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|                                |\n");
		printf("\t\t|        0.�����ϼ��˵�          |\n");
		printf("\t\t|                                |\n");
		printf("\t\t----------------------------------\n");
		printf("\t\t   ��ѡ�������:");

		//�����û�ѡ��
		cin >> nSortChoose;

		switch (nSortChoose)
		{
		case 1:
			//����Ų�ѯ
			fileSave(Borrowers, Books);
			system("PAUSE");
			break;
		case 2:
			//����Ų�ѯ
			fileSort(Borrowers, Books);
			system("PAUSE");
			break;
		case 0:
			//����
			return;
			break;
		default:printf("\t\tѡ����������ѡ��\n");
		}//switch����
	}//while(1)����
}

/// <summary>
/// 6.1 �ļ����溯��
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void fileSave(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "  ��ǰ���ļ�����ģ��" << endl;
	person_file_save(Borrowers);
	cout << "������Ϣ�ѱ���,������Person.txt" << endl;
	book_file_save(Books);
	cout << "ͼ����Ϣ�ѱ���,������Book.txt" << endl;
	User::save_file();
	Admin::save_file();
	cout << "�˻���Ϣ�ѱ���" << endl;

}
/// <summary>
/// 6.2 �ļ�������
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void fileSort(vector<Person>& Borrowers, vector<Book>& Books)
{
	cout << "����Ϊ������Ϣ����" << endl;
	size_t length = Borrowers.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length - 1; j++)
		{
			Borrowers[j] << Borrowers[j + 1];//����
		}
	}
	cout << "����Ϊ�鼮��Ϣ����" << endl;
	length = Books.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length - 1; j++)
		{
			Books[j] << Books[j + 1];//����
		}
	}
	cout << "���������" << endl;
}
