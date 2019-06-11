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

//测试boost线程使用方式
#include "boost/thread.hpp"
#include <iostream>
void mythread()
{
	std::cout << "hello thread" << std::endl;
}
//测试boost线程使用方式
void CommonApi::test_boost_thread2()
{
	//测试boost线程使用方式
	boost::function<void()>f(mythread);
	boost::thread t(f);
	t.join();
	std::cout << "thread is over" << std::endl;
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

//测试观察者模式
#include "ObserverPattern.h"
//测试观察者模式
void CommonApi::test_ObserverPattern()
{
	testObserverPattern();
}

//调用log日志动态库
typedef  void(*LOGFUN)(const std::string &sFile, const std::string &sFunc, const long &lLine, const std::string &sMessage);
LOGFUN MYLOG;
//typedef void (*LOGFUN)(const string &sFunc,const string &sMessage);
//extern LOGFUN MYLOG;
void FuncB()
{
	MYLOG(__FILE__, __FUNCTION__, __LINE__, "It is in FuncB");
}
//调用log日志动态库
void CommonApi::test_log_dll()
{
	//调用log日志动态库
	char c;
	HINSTANCE hInput;
	hInput = LoadLibrary(_T("LogDll.dll"));
	if (NULL == hInput)
	{
		std::cout << "load failed" << std::endl;
	}
	typedef bool(*FUNC)(const std::string &sFilePath);
	FUNC fun = (FUNC)GetProcAddress(hInput, "LogPath");
	if (NULL == fun)
	{
		std::cout << "load function failed" << std::endl;
	}
	bool iResult = fun("D://");
	std::cout << "result is" << iResult << std::endl;

	MYLOG = (LOGFUN)GetProcAddress(hInput, "WRITELOG");
	if (NULL == MYLOG)
	{
		std::cout << "load function failed" << std::endl;
	}
	while (true)
	{
		std::cout << "wrtite..." << std::endl;
		MYLOG(__FILE__, __FUNCTION__, __LINE__, "This is a test");
		FuncB();
		Sleep(5000);
	}
	
}

//Windows的Event编程
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
//通过事件得知另一个线程的状态
//例如：线程中有三种状态：起床、吃饭、上班
HANDLE g_getupHandle;
HANDLE g_breakfastHandle;
HANDLE g_workHandle;

std::vector<std::string> stateTexts;
DWORD WINAPI Worker(LPVOID n)
{
	stateTexts.push_back("GetUp");
	SetEvent(g_getupHandle);
	stateTexts.push_back("Breakfast");
	SetEvent(g_breakfastHandle);
	stateTexts.push_back("Work");
	SetEvent(g_workHandle);

	return 0;
}
//Windows的Event编程
void CommonApi::test_windows_event()
{
	stateTexts.reserve(3);//容器预留空间
	g_getupHandle = CreateEventA(NULL, true, false, NULL);//手动，无信号
	g_breakfastHandle = CreateEventA(NULL, true, false, NULL);//手动，无信号
	g_workHandle = CreateEventA(NULL, true, false, NULL);//手动，无信号

	DWORD threadId;
	HANDLE theadHandle = CreateThread(NULL,
		0,
		Worker,
		0,
		0,
		&threadId
	);

	WaitForSingleObject(g_getupHandle, INFINITE);
	std::cout << stateTexts[0] << std::endl;

	WaitForSingleObject(g_breakfastHandle, 3000);
	std::cout << stateTexts[1] << std::endl;

	WaitForSingleObject(g_workHandle, INFINITE);
	std::cout << stateTexts[2] << std::endl;

	CloseHandle(theadHandle);
	CloseHandle(g_getupHandle);
	CloseHandle(g_breakfastHandle);
	CloseHandle(g_workHandle);
}


//mystringToi和mystringTofloat
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
int string2i(char *str)
{
	if (*str == NULL)
	{
		return 0;
	}

	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
		{
			return 0;
		}
		res = res * 10 + str[i] - '0';
	}

	return sign*res;
}

float string2float(const char* s)
{
	float rez = 0, fact = 1;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	for (int point_seen = 0; *s; s++)
	{
		if (*s == '.')
		{
			point_seen = 1;
			continue;
		}
		int d = *s - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen) fact /= 10.0f;
			rez = rez * 10.0f + (float)d;
		}
	}
	return rez * fact;
};
//mystringToi和mystringTofloat
void CommonApi::test_string_to_i()
{
	char* p1 = "123";
	std::cout << string2i(p1) << std::endl;
}

void CommonApi::test_string_to_float()
{
	char* p2 = "123.333";
	std::cout << string2float(p2) << std::endl;
}

void CommonApi::test_string_c_str_data()
{
	//string的c_str()函数和data()函数
	//1. c_str()：生成一个const char*指针，指向以空字符终止的数组。
	//2. data():与c_str()类似，但是返回的数组不以空字符终止。
	std::string s = "12345";
	char test[10] = { 0 };
	strncpy_s(test, s.c_str(), 6);
	char test1[10] = { 0 };
	strncpy_s(test1, s.data(), 6);
}


//自己的log日志功能
#include <iostream>
#include <string>
#include <vector>
#define DEBUG_LOG(...) debug_log("DEBUG", __TIME__, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
void debug_log(
	const char *loglevel,
	const char *time,
	const char *file,
	const char *func,
	const int iline,
	const char *format, ...
)
{
	static char output[10240] = { 0 };
	va_list arglist;
	va_start(arglist, format);
	vsnprintf(output, sizeof(output), format, arglist);
	printf("[%s][%s][%s][%s][%d]:%s\n", time, loglevel, file, func, iline, output);
	//此处会频繁打开文件
	FILE *fp = NULL;
	fopen_s(&fp, "d:\\logfile.txt", "a+");//
	fprintf_s(fp, "[%s][%s][%s][%s][%d]:%s\n", time, loglevel, file, func, iline, output);
	fclose(fp);
	va_end(arglist);
}
//自己的log日志功能
void CommonApi::test_my_log_file()
{
	DEBUG_LOG("%s, ranking NO.%d", "You are so smart", 1);
}

#include <unordered_map>
void CommonApi::test_unordered_map()
{
	std::unordered_map<std::string, std::string> u = {
		{"RED", "#FF0000"},
		{"GREEN", "#00FF00"},
		{"BLUE", "#0000FF"}
	};
	for (const auto &n : u)
	{
		std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
	}
	u["BLACK"] = "#000000";
	u["WHITE"] = "#FFFFFF";
	std::cout << "The Hex of color RED is:[" << u["RED"] << "]\n";
	std::cout << "The Hex of color BLACK is:[" << u["BLACK"] << "]\n";
}

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
