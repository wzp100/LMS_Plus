#pragma once
#include <ctime>
#include <iomanip>
#include<iostream>
#include<chrono>
#include<fstream>

using namespace std;

chrono::system_clock::time_point* get_Now();

void time_display(const chrono::system_clock::time_point &);
void time_display_file(const chrono::system_clock::time_point &, ofstream&);
//����ʱ��Ļ�ȡ��ʱ��Ĵ���

//TODO:��ʱ���ַ������д���
//struct tm * get_Now_tm();


