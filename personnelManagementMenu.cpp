
#include "personnelManagementMenu.h"


/// <summary>
/// 5.人员管理模块二级菜单
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
		printf("\t\t|********人员管理模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.增加人员信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.删除人员信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.修改人员信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        4.按编号搜索        |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        5.按姓名搜索        |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------  \n");
		printf("\t\t   请选择功能序号:");
		//读入用户选择
		//scanf("%d", &nPersonChoose);
		cin >> nPersonChoose;
		switch (nPersonChoose)
		{
		case 1:
			Person::add_a_Borrower();
;			system("PAUSE");
			break;
		case 2:
			deletePersonInfo(Borrowers);//(stu, szCourseName, npPersonNum);//转到删除人员信息函数
			//OutputPersonInfo(stu, szCourseName, *npPersonNum, 0, 0, *npPersonNum);//输出给用户看一下
			system("PAUSE");
			break;
		case 3:
			modifyPerson(Borrowers);//(stu, szCourseName, *npPersonNum);//转到修改人员信息函数
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
			printf("\t\t选择有误，请重选！\n");
		}
	}
}


/// <summary>
/// 5.1 增加人员信息
/// </summary>
/// <param name="Borrowers"></param>
void addPersonInfo(vector<Person>& Borrowers)
{
	InitPersonStruct personList;
	cout << "请输入ID:";
	cin >> personList.ID;
	cout << "请输入姓名:";
	cin >> personList.Name;
	cout << "请输入年龄:";
	cin >> personList.Age;
	cout << "请输入电话:";
	cin >> personList.PhoneNumber;
	cout << "请输入性别(0为女，1为男):" << endl;
	cin >> personList.Gender;
	cout << "请输入组别(0)为学生，(1)为教师:" << endl;
	cin >> personList.Type;
	Person temp_person(personList);

	cout << "请检查是否正确" << endl;
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
	cout << "请输入年龄:";
	cin >> personList.Age;
	cout << "请输入电话:";
	cin >> personList.PhoneNumber;
	cout << "请输入性别(0为女，1为男):" << endl;
	cin >> personList.Gender;
	cout << "请输入组别(0)为学生，(1)为教师:" << endl;
	cin >> personList.Type;
	Person temp_person(personList);

	cout << "请检查是否正确" << endl;
	display_person_title();

	temp_person.display();
	
	Borrowers.push_back(temp_person);
	system("pause");
}




/// <summary>
/// 5.2 删除人员信息
/// </summary>
/// <param name="Borrowers"></param>
void deletePersonInfo(vector<Person>& Borrowers)
{
	cout << "  当前为人员信息删除模块  " << endl;

	int temp_ID;
	cout << "请输入要删除人员的ID(请确保当前人员没有借书):" << endl;
	cin >> temp_ID;
	for (vector<Person>::iterator iter = Borrowers.begin(); iter != Borrowers.end(); iter++)
	{
		//从vector中删除指定的某一个元素

		if ((*iter).searchPersonID(temp_ID))
		{
			if ((*iter).BorrowedNumber == 0)
			{
				Borrowers.erase(iter);//把当前书ID删除
				cout << "删除成功" << endl;
				return;
				break;
			}
			else
			{
				cout << "当前人员已借书，无法删除" << endl;
				return;
			}
		}
	}
	cout << "未找到ID相关信息，请检查ID是否正确" << endl;
}


/// <summary>
/// 5.3 修改人员信息
/// </summary>
/// <param name="Borrowers"></param>
void modifyPerson(vector<Person>& Borrowers)
{
	int temp_ID;
	cout << "请输入要修改的ID:" << endl;
	cin >> temp_ID;
	for (vector<Person>::iterator i = Borrowers.begin(); i != Borrowers.end(); i++)
	{
		if ((*i).searchPersonID(temp_ID))
		{
			if ((*i).BorrowedNumber == 0)
			{
				(*i).modify();
				cout << "请检查修改后的结果" << endl;
				display_person_title();
				(*i).display();
				return;
			}
			else
			{
				cout << "当前人员已借书,无法修改" << endl;
				return;
			}
		}
	}
	cout << "没有找到ID" << endl;
}


/// <summary>
/// 5.4 按编号查询
/// </summary>
/// <param name="Borrowers"></param>
void idSearchPerson(vector<Person>& Borrowers)
{
	int temp_ID;
	cout << "当前为ID搜索人员模式" << endl;
	cout << "请输入要搜索的ID:";
	cin >> temp_ID;
	for (Person temp_person : Borrowers)
	{
		if (temp_person.searchPersonID(temp_ID))
		{
			cout << "搜索成功" << endl;
			display_person_title();
			temp_person.display();
			cout << endl;
			return;
		}
	}
	cout << "搜索失败，请检查ID是否正确" << endl;
}


/// <summary>
/// 5.5 按姓名查询
/// </summary>
/// <param name="Borrowers"></param>
void nameSearchPerson(vector<Person>& Borrowers)
{
	bool status = false;
	string name;
	cout << "当前为姓名搜索人员模式" << endl;
	cout << "请输入要搜索的人员:";
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
		cout << "搜索完毕" << endl;
		return;
	}
	else
	{
		cout << "未搜索到结果" << endl;
	}

}
