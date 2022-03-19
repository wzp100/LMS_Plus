#include"Menu.h"
#include<iostream>
#include "FileProcess.h"
using namespace std;
//����ͼ��ṹ�����飬����ṹ�����飬����ֵʹ��ָ��




void Login_Menu()
{
	extern vector<User> Users;
	int nMainChoose;
	bool status;
	system("cls");
	while (1)
	{
		cout << "\t\t --------------------------------------" << endl;
		cout<<  "\t\t         ��ӭʹ��ͼ�����ϵͳ          " <<endl<<endl;

		cout << "\t\t            1.����Ա��¼" << endl<<endl;

		cout << "\t\t            2.�û���¼" << endl<<endl;

		cout << "\t\t            3.�û�ע��" <<endl<<endl;

		cout << "\t\t            0.��    ��" << endl<<endl;
		cout << "\t\t --------------------------------------" << endl;
		cout << "\t\t            ��ѡ��";
		cin >> nMainChoose;
		switch (nMainChoose)
		{
		case 1:
			status = Admin_Login();
			if (status)
			{
				Main_Menu();
			}
			break;
		case 2:
			status = User_Login();
			if (status)
			{
				User_Main_Menu();
			}
			break;
		case 3:
			status = User_Register();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "����������������룡" << endl;
		}
	}
	


}


bool Admin_Login()
{
	extern vector<Admin> Admins;
	int ID;
	string Password;
	system("CLS");
	cout<<"�������û�ID��";
	cin>>ID;
	for(auto& temp_user:Admins)
	{
		if(temp_user.login(ID)) 
		{
			cout<<"��¼�ɹ���"<<endl;
			return true;
		}
	}
	cout<<"��¼ʧ��,δ�ҵ��û���"<<endl;
	return false;
}

bool User_Login()
{
	extern vector<User> Users;
	int ID;
	string Password;
	system("CLS");
	cout << "�������û�ID��";
	cin >> ID;
	for (auto& temp_user : Users)
	{
		if (temp_user.login(ID))
		{
			cout << "��¼�ɹ���" << endl;
			return true;
		}
	}
	cout << "��¼ʧ��,δ�ҵ��û���" << endl;
	return false;
}


/// <summary>
/// �û����˵�����
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void User_Main_Menu()
{

	extern vector<Person> Borrowers;
	extern vector<Book> Books;
	extern vector<User> Users;
	int nMainchoose;
	//���˵�����ѭ��
	while (1)
	{
		system("CLS"); //ϵͳ��Ļ���
		//����˵�������
		printf("\t\t --------------------------------------\n");
		printf("\t\t|             ͼ�����ϵͳ            |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   1.ͼ����Ĺ黹     2.ͼ����Ϣ��ѯ |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   3.������Ϣ��ѯ     4.�ļ�����     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   0.�˳�ϵͳ                        |\n");
		printf("\t\t --------------------------------------\n");
		//���ݺ궨����ļ������鼮��Ŀ��ʾ
		extern size_t the_Number_of_Books;
		extern size_t the_Number_of_Persons;
		extern string file_name_books;
		extern string file_name_persons;
		cout << "\n\tͼ�������Ѵ�" << file_name_books << "����,ͼ�����Ŀǰ����" << the_Number_of_Books << "���� \n\n";
		cout << "\n\t���������Ѵ�" << file_name_persons << "����,ͼ�����Ŀǰ����" << the_Number_of_Persons << "λ���� \n\n";

		//���û�����ѡ�������
		printf("\t\t   ��ѡ�������(0~5):");
		//�û����ݽ�����ʾ��������
		cin >> nMainchoose;
		//�����û���������ֿ�����ж�
		switch (nMainchoose)
		{
			//ת�������˵������Ĺ黹ͼ��˵�ѡ����ʾ
		case 1:
			borrowAndReturnBook_Menu(Borrowers, Books);
			break;

			//ת�������˵���ͼ����Ϣ��ѯ�˵�ѡ����ʾ
		case 2:

			bookInformationQquery_Menu(Borrowers, Books);
			break;

			//ת�������˵���������Ϣ�˵�
		case 3:
			personInfo_Menu();
			break;

		case 4:
			//6.����˵�
			save_Menu(Borrowers, Books);
			break;
		case 0:
			//�û��˳�
			cout << "\n\n\t\t��лʹ�����ǵ��������ӭ�´�������" << endl;
			exit(0);
			break;
			//�û�ѡ������
		default:
			printf("ѡ����������ѡ��\n");
		}//switch����
	}//while(1)��������
}
void personInfo_Menu()
{
	User::save_file();
	system("pause");
}
//���˵���������






bool User_Register()
{
	extern vector<User> Users;
	return false;
}




/// <summary>
/// ���˵�����
/// </summary>
/// <param name="Borrowers"></param>
/// <param name="Books"></param>
void Main_Menu( )
{
	
	extern vector<Person> Borrowers;
	extern vector<Book> Books;
	extern vector<User> Users;
	int nMainchoose;
	//���˵�����ѭ��
	while (1)
	{
		system("CLS"); //ϵͳ��Ļ���
		//����˵�������
		printf("\t\t --------------------------------------\n");
		printf("\t\t|             ͼ�����ϵͳ            |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   1.ͼ����Ĺ黹   2.���ά��       |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   3.������Ϣ��ѯ   4.ͼ����Ϣ��ѯ   |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   5.��Ա����       6.�ļ�����       |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|   0.�˳�ϵͳ                        |\n");
		printf("\t\t --------------------------------------\n");
		//���ݺ궨����ļ������鼮��Ŀ��ʾ
		//printf("\n\tͼ�����%s��Ŀǰ����%d���� \n\n");//, //FILENAME, *npStudentNum);
		extern size_t the_Number_of_Books;
		extern size_t the_Number_of_Persons;
		extern string file_name_books;
		extern string file_name_persons;
		cout << "\n\tͼ�������Ѵ�" << file_name_books << "����,ͼ�����Ŀǰ����" << the_Number_of_Books << "���� \n\n";
		cout << "\n\t���������Ѵ�" << file_name_persons << "����,ͼ�����Ŀǰ����" << the_Number_of_Persons << "λ���� \n\n";

		//���û�����ѡ�������
		printf("\t\t   ��ѡ�������(0~5):");
		//�û����ݽ�����ʾ��������
		//scanf("%d", &nMainchoose);
		cin >> nMainchoose;
		//�����û���������ֿ�����ж�
		switch (nMainchoose)
		{
			//ת�������˵������Ĺ黹ͼ��˵�ѡ����ʾ
		case 1:
			borrowAndReturnBook_Menu(Borrowers,Books);
			break;

			//ת�������˵������ά���˵�ѡ����ʾ
		case 2:
			libraryMaintenance_Menu(Borrowers, Books);//���庯��
			break;

			//ת�������˵���������Ϣ��ѯ�˵�ѡ����ʾ
		case 3:
			borrowingInformationQquery_Menu(Borrowers, Books);
			break;

			//ת�������˵���ͼ����Ϣ��ѯ�˵�ѡ����ʾ
		case 4:

			bookInformationQquery_Menu(Borrowers,Books);
			break;

			//ת�������˵�����Ա����˵�ѡ����ʾ
		case 5:
			personnelManagement_Menu(Borrowers, Books);
			break;

		case 6:
			//6.����˵�
			save_Menu(Borrowers, Books);
			break;
		case 0:
			//�û��˳�
			cout << "\n\n\t\t��лʹ�����ǵ��������ӭ�´�������" << endl;
			exit(0);
			break;
			//�û�ѡ������
		default:
			printf("ѡ����������ѡ��\n");
		}//switch����
	}//while(1)��������
}
//���˵���������



























/// <summary>
/// .������Ϣ��ѯ�����˵�
/// </summary>
/// <param name="Books"></param>
void allInformationQquery_Menu(vector<Book>& Books)
{
	int nMainchoose;
	//���˵�����ѭ��
	while (1)
	{
		system("CLS"); //ϵͳ��Ļ���
		//����˵�������
		cout << "\t\t-----------------------------------" << endl;
		cout << "\t\t   1.�������ͼ����Ϣ" << endl;
		cout << "\t\t   0.������һ��" << endl;
		cout << "\t\t-----------------------------------" << endl;
		//���û�����ѡ�������
		cout << "\t\t   ��ѡ�������:";
		//�û����ݽ�����ʾ��������
		cin >> nMainchoose;
		system("CLS");
		//�����û���������ֿ�����ж�
		switch (nMainchoose)
		{
			//ת�������˵�������ͼ��˵�ѡ����ʾ
		case 1: //BorrowBook//(stu, szCourseName, *npStudentNum, 0, 0, *npStudentNum);//���庯��

			cout << "��ǰ�鼮����Ϣ" << endl;
			//����չʾ����
			display_book_title();
			for (Book temp_book : Books)
			{
				temp_book.display();
			}
			system("pause");
			break;
			//ת�������˵����黹ͼ��˵�ѡ����ʾ
		case 2: //ReturnBook //(stu, szCourseName, npStudentNum);//���庯��
			break;
			//ת�������˵������ά���˵�ѡ����ʾ
		case 3: //LibraryMaintenance//(stu, szCourseName, *npStudentNum);//���庯��
			break;
			//ת�������˵���������Ϣ��ѯ�˵�ѡ����ʾ
		case 4://Borrowing_InformationQquery//(stu, szCourseName, *npStudentNum);//���庯��
			break;
			//ת�������˵���ͼ����Ϣ��ѯ�˵�ѡ����ʾ
		case 5://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//���庯��
			break;
			//ת�������˵�����Ա����˵�ѡ����ʾ
		case 6://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//���庯��
			break;
			//ת�������˵����޸�����˵�ѡ����ʾ
		case 7://Book_InformationQquery//(stu, szCourseName, *npStudentNum);//���庯��
			break;
		case 0:
			//�û�������һ��
			return;
			break;
			//�û�ѡ������
		default:
			cout << "ѡ����������ѡ��\n";
		}//switch����
	}//while(1)��������
}