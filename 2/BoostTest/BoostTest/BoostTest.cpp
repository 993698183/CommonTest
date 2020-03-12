// BoostTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BoostTestAny.h"
#include "BoostTestFunction.h"
#include "BoostTestBind.h"
#include "BoostTestString.h"
#include "BoostTestTokenizer.h"
#include "BoostTestStringAlgo.h"
#include "BoostTestStringAlgoFind.h"
#include "BoostTestDate.h"
#include "BoostTestThread.h"
#include "BoostTestXML.h"
#include "BoostTestException.h"
#include "BoostTestJson.h"
#include "BoostTestAsio.h"
#include "BoostTestSharedPtr.h"
#include "classorder/ClassOrderTest.h"
#include "semaphore/SemaphoreTest.h"
#include "guid/GuidTest.h"
#include "Cplus11/Cplus.h"
#include "checkjson/CCheckJson.h"
#include "stdfunctiontest/stdfunctiontest.h"
#include "jsoncpp/json_test.h"
#include "http/http.h"

//空类的size
class Car1
{};

//设定文件修改时间
int settime(LPCSTR filename)
{
	SYSTEMTIME  systime;
	FILETIME ft, ftUTC;
	HANDLE hFile;

	systime.wYear = 2000;
	systime.wMonth = 1;
	systime.wDay = 1;
	systime.wDayOfWeek = 1;
	systime.wSecond = 1;
	systime.wHour = 1;
	systime.wMinute = 1;
	systime.wMilliseconds = 1;

	SystemTimeToFileTime(&systime, &ft);
	LocalFileTimeToFileTime(&ft, &ftUTC);
	hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		SetFileTime(hFile, (LPFILETIME)NULL, (LPFILETIME)NULL, &ftUTC);
	}
	CloseHandle(hFile);

	return 0;
}

//typeid关键词的使用方法
void test_typeid()
{
	int i = 0;
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(i).hash_code() << std::endl;
}
//

//测试value_type函数
class C {
public:
	C(int x) 
	{
		cout << x << endl;
	}
	C()
	{
		cout << 10 << endl;
	}

};
void test_value_type()
{
	std::vector<C> vec;
	C c1, c2(11);
	vec.push_back(c1);
	vec.push_back(c2);
	std::vector<C>::value_type n1;
	std::vector<C>::value_type n2(13);
	vec.push_back(n1);
	vec.push_back(n2);
	std::cout << vec.size() << std::endl;
}

int BinarySearch(vector<int> v, int value, int low, int high) {
	if (v.size() <= 0) {
		return -1;
	}
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (v[mid] == value) {
			return mid;
		}
		else if (v[mid] > value) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}
void test_binarysearch()
{
	std:vector<int> vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}
	int ret = BinarySearch(vec, 30, 0, 100);
}
void Full_Kline(const time_t &new_t, const time_t &old_t)
{
	int nSpanSecond = 60;
	int n1 = new_t - old_t;
	int nNum = n1 / nSpanSecond;
	std::cout << old_t << std::endl;
	for (int i = 1; i < nNum; i++)
	{
		time_t tmp_t = old_t + (60 * i);
		std::cout << tmp_t << std::endl;
	}
	std::cout << new_t << std::endl;
}

void test_kline()
{
	time_t new_t = 1583800620;//2020/3/10 8:37:00
	time_t old_t = 1583800580;//2020/3/10 8:27:00
	Full_Kline(new_t, old_t);
}
int main()
{	

	getchar();
    return 0;
}

