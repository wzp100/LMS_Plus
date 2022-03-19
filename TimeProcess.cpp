#include "TimeProcess.h"

//得到系统时间点
chrono::system_clock::time_point* get_Now()
{
	//struct tm t;//日历形式的结构体
	chrono::system_clock::time_point* p_now = new chrono::system_clock::time_point(chrono::system_clock::now());
	//得到时间点
	//time_t now_c = chrono::system_clock::to_time_t(*p_now);//时间点转换为纪元起始时间
	//localtime_s(&t, &now_c);//转换为当地时间
	//测试输出函数
	//cout << put_time(&t, "%F %T")<<endl;
	return p_now;
}

void time_display(const chrono::system_clock::time_point &p_now)
{
	struct tm t;//日历形式的结构体
	time_t now_c = chrono::system_clock::to_time_t(p_now);//时间点转换为纪元起始时间
	localtime_s(&t, &now_c);//转换为当地时间
	//测试输出函数
	cout << put_time(&t, "%F %T");
}

void time_display_file(const chrono::system_clock::time_point& p_now,ofstream& out_file)
{
	struct tm t;//日历形式的结构体
	time_t now_c = chrono::system_clock::to_time_t(p_now);//时间点转换为纪元起始时间
	localtime_s(&t, &now_c);//转换为当地时间
	//测试输出函数
	out_file << put_time(&t, "%F %T");
}


/*
struct tm* get_Now_tm()
{

	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间

	   //格式化输出本地时间
	printf("年：%d\n", t.tm_year + 1900);
	printf("月：%d\n", t.tm_mon + 1);
	printf("日：%d\n", t.tm_mday);
	printf("周：%d\n", t.tm_wday);
	printf("一年中：%d\n", t.tm_yday);
	printf("时：%d\n", t.tm_hour);
	printf("分：%d\n", t.tm_min);
	printf("秒：%d\n", t.tm_sec);
	printf("夏令时：%d\n", t.tm_isdst);
	system("pause");
}
*/