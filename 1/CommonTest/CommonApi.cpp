#include "stdafx.h"
#include "CommonApi.h"
#include <memory>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
//string和wstring大小写转换功能
#include <string>
#include <algorithm>
//string和wstring大小写转换功能
struct Foo 
{
	Foo() { std::cout << "Foo\n"; }
	~Foo() { std::cout << "~Foo\n"; }
};

struct D
{
	void operator()(Foo *p)
	{
		std::cout << "calling delete for Foo object\n";
		delete p;
	}
};
void CommonApi::test_unique_ptr_get_release_reset()
{
	//unique_ptr的get方法和release方法

	//std::unique_ptr<T, Deleter>::get(C++11开始使用)
	//返回指向被管理对象的指针，如果无管理对象，则为nullptr
	std::unique_ptr<std::string> s_p(new std::string("hello world"));
	std::string *s = s_p.get();
	//std::cout << *s << std::endl;
	//std::cout << *s << std::endl;
	//release返回一个指向被管理对象的指针，并释放所有权(公开成员函数)（C++11开始使用）
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo> up(new Foo());
	std::cout << "about to release Foo\n";
	Foo *fp = up.release();
	assert(nullptr == up.get());
	std::cout << "Foo is nolonger own by unique_ptr\n";
	delete fp;
	//unique_ptr的get方法

	std::cout << "reset function\n";
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo, D> up1(new Foo(), D());//up1占有Foo指针和（删除器D）
	std::cout << "replace owned Foo with a new Foo\n";
	up1.reset(new Foo());//调用旧者的删除器

	std::cout << "release and delete the owned Foo\n";
	up1.reset(nullptr);
}

void CommonApi::test_computer_little_or_big_endian()
{
	int i = 0x12345678;
	if (0x12 == *((char *)&i))
	{
		std::cout << "Bid endian" << std::endl;
	}
	else
	{
		std::cout << "Little endian" << std::endl;
	}
}

void CommonApi::test_size_type_vector()
{
	std::vector<int> ivec1;
	ivec1.push_back(1);
	ivec1.push_back(2);

	std::vector<int>::size_type size1;
	size1 = ivec1.size();
}

void CommonApi::test_string_big_or_little()
{
	std::string str1 = "a";
	std::string str2 = "b";
	if (str1 < str2)
	{
		std::cout << "str1 is smaller than str2" << std::endl;
	}
}

//try...catch
double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (a / b);
}
//try...catch
void CommonApi::test_try_catch()
{
	int x = 50;
	int y = 0;
	double z = 0;

	try
	{
		z = division(x, y);
		std::cout << z << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
}

void CommonApi::test_string_wstring_to_upper_lowwer()
{
	std::wstring wstr(L"abs中文-Da");
	transform(wstr.begin(), wstr.end(), wstr.begin(), ::toupper);

	std::string strA = "你好yasaken@126.com";
	transform(strA.begin(), strA.end(), strA.begin(), ::toupper);
}

//面试题：输出两个字符数组中相同的字符
void FindCommonChar(char a[], int lena, char b[], int lenb)
{
	int hasha[256] = { 0 };
	int hashb[256] = { 0 };
	for (int i = 0; i < lena; i++)
	{
		hasha[(int)a[i]] = 1;
	}

	for (int j = 0; j < lena; j++)
	{
		hashb[(int)b[j]] = 1;
	}

	for (int i = 0; i < 256; i++)
	{
		if (hasha[i] == 1 && hashb[i] == 1)
		{
			std::cout << (char)i << std::endl;
		}
	}
}
//面试题：输出两个字符数组中相同的字符
void CommonApi::test_findcommon()
{
	char a[5] = { '1', 'b', 'C', 'f', 'f' };
	char b[6] = { '1', 'b', 'd', 'e', 'C','d' };
	FindCommonChar(a, _countof(a), b, _countof(b));
}

//VC获取字符长度的方法
#include "string"
#include "comutil.h"
#pragma comment(lib, "comsuppw.lib")
//VC获取字符长度的方法
void CommonApi::test_get_string_length()
{
	//VC获取字符长度的方法
	char s1[] = "中文ABC";
	wchar_t s2[] = L"中文ABC";

	//使用sizeof获取字符串长度
	printf("sizeof s1: %d\r\n", sizeof(s1));
	printf("sizeof s2: %d\r\n", sizeof(s2));

	//使用strlen获取字符串长度
	printf("strlen(s1): %d\r\n", strlen(s1));
	printf("wcslen(s2): %d\r\n", wcslen(s2));

	//使用CString::GetLength()获取字符串长度
	//CStringA sa = s1;
	//CStringW sw = s2;
	//printf("sa.GetLength(): %d\r\n", sa.GetLength());
	//printf("sw.GetLength(): %d\r\n", sw.GetLength());
	//使用string::size()获取字符串长度
	std::string ss1 = s1;
	std::wstring ss2 = s2;
	printf("ss1.size(): %d\r\n", ss1.size());
	printf("ss2.size(): %d\r\n", ss2.size());
	//使用_bstr_t::length()获取字符串长度
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);
	printf("bs1.length(): %d\r\n", bs1.length());
	printf("bs2.length(): %d\r\n", bs2.length());
}

//boost文件目录操作
#include <boost/filesystem.hpp>
//boost文件目录操作
void CommonApi::test_boost_filepath()
{
	TCHAR szCurPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurPath, MAX_PATH);
	std::wstring wstrpath(szCurPath);
	boost::filesystem::path path_send(wstrpath);
	boost::filesystem::path path_send_monitor(path_send.parent_path().wstring() + _T("\\send"));
	path_send = path_send.filename();
	path_send_monitor /= path_send;
}

//boost线程
#include <boost/thread.hpp>
void hello()
{
	while (true)
	{
		std::cout << "hello world, i am a thread" << std::endl;
		//Sleep(1000);
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}
}
//boost线程
void CommonApi::test_boost_thread()
{
	//boost线程
	boost::thread thrd(&hello);
	thrd.join();
}

void CommonApi::test_my_reverse_copy()
{
	int myints[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> myvector;
	myvector.resize(9);//申请空间
	std::reverse_copy(myints, myints + 9, myvector.begin());

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	{
		std::cout << ' ' << *it;
	}

	std::cout << '\n';
}

//时间格式输出
void SplitSpring(const std::string &src, const char &csplit, std::vector<std::string> &vResult)
{
	std::string sTemp = "";
	for (unsigned int iIndex = 0; iIndex < src.length(); iIndex++)
	{
		if (src[iIndex] == csplit)
		{
			vResult.push_back(sTemp);
			sTemp = "";
			continue;
		}
		sTemp += src[iIndex];
	}

	if ("" != sTemp)
	{
		vResult.push_back(sTemp);
	}
}

std::string IntToTheString(int &iValue)
{
	char cTemp[100] = { 0 };
	sprintf_s(cTemp, "%02d", iValue);
	std::string sTemp(cTemp);
	return sTemp;
}
std::string GetAbsolulyTime(const std::string &sLastTime, const int &iAddSeconds)
{
	std::vector<std::string> vResult;
	SplitSpring(sLastTime, ':', vResult);
	if (vResult.size() < 3)
	{
		return sLastTime;
	}
	int iHour = atoi(vResult[0].c_str());
	int iMinite = atoi(vResult[1].c_str());
	int iSecond = atoi(vResult[2].c_str());
	int iAddTime = 0;
	iSecond += iAddSeconds;

	if (iSecond >= 60)
	{
		iAddTime = iSecond / 60;
		iSecond = iSecond % 60;
		iMinite += iAddTime;
		if (iMinite >= 60)
		{
			iAddTime = iMinite / 60;
			iMinite = iMinite % 60;
			iHour += iAddTime;
		}
	}

	std::string sHour = IntToTheString(iHour);
	std::string sMinite = IntToTheString(iMinite);
	std::string sSecond = IntToTheString(iSecond);
	return sHour + ":" + sMinite + ":" + sSecond;
}
//时间格式输出
void CommonApi::test_format_time()
{
	//格式化输出时间，并计算80秒后的时间
	std::string sTest = "00:00:00";
	std::string sResult;
	while (true)
	{
		sTest = GetAbsolulyTime(sTest, 80);
		Sleep(1000);
		std::cout << "Time is" << sTest << std::endl;
	}
}

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
