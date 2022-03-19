#include "TimeProcess.h"

//�õ�ϵͳʱ���
chrono::system_clock::time_point* get_Now()
{
	//struct tm t;//������ʽ�Ľṹ��
	chrono::system_clock::time_point* p_now = new chrono::system_clock::time_point(chrono::system_clock::now());
	//�õ�ʱ���
	//time_t now_c = chrono::system_clock::to_time_t(*p_now);//ʱ���ת��Ϊ��Ԫ��ʼʱ��
	//localtime_s(&t, &now_c);//ת��Ϊ����ʱ��
	//�����������
	//cout << put_time(&t, "%F %T")<<endl;
	return p_now;
}

void time_display(const chrono::system_clock::time_point &p_now)
{
	struct tm t;//������ʽ�Ľṹ��
	time_t now_c = chrono::system_clock::to_time_t(p_now);//ʱ���ת��Ϊ��Ԫ��ʼʱ��
	localtime_s(&t, &now_c);//ת��Ϊ����ʱ��
	//�����������
	cout << put_time(&t, "%F %T");
}

void time_display_file(const chrono::system_clock::time_point& p_now,ofstream& out_file)
{
	struct tm t;//������ʽ�Ľṹ��
	time_t now_c = chrono::system_clock::to_time_t(p_now);//ʱ���ת��Ϊ��Ԫ��ʼʱ��
	localtime_s(&t, &now_c);//ת��Ϊ����ʱ��
	//�����������
	out_file << put_time(&t, "%F %T");
}


/*
struct tm* get_Now_tm()
{

	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	time(&now);      //��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��

	   //��ʽ���������ʱ��
	printf("�꣺%d\n", t.tm_year + 1900);
	printf("�£�%d\n", t.tm_mon + 1);
	printf("�գ�%d\n", t.tm_mday);
	printf("�ܣ�%d\n", t.tm_wday);
	printf("һ���У�%d\n", t.tm_yday);
	printf("ʱ��%d\n", t.tm_hour);
	printf("�֣�%d\n", t.tm_min);
	printf("�룺%d\n", t.tm_sec);
	printf("����ʱ��%d\n", t.tm_isdst);
	system("pause");
}
*/