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
//用于时间的获取与时间的处理

//TODO:对时间字符串进行处理
//struct tm * get_Now_tm();


