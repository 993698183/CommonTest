#include "stdafx.h"
#include "CommonApi.h"
#include <memory>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
//string��wstring��Сдת������
#include <string>
#include <algorithm>
//string��wstring��Сдת������
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
	//unique_ptr��get������release����

	//std::unique_ptr<T, Deleter>::get(C++11��ʼʹ��)
	//����ָ�򱻹�������ָ�룬����޹��������Ϊnullptr
	std::unique_ptr<std::string> s_p(new std::string("hello world"));
	std::string *s = s_p.get();
	//std::cout << *s << std::endl;
	//std::cout << *s << std::endl;
	//release����һ��ָ�򱻹�������ָ�룬���ͷ�����Ȩ(������Ա����)��C++11��ʼʹ�ã�
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo> up(new Foo());
	std::cout << "about to release Foo\n";
	Foo *fp = up.release();
	assert(nullptr == up.get());
	std::cout << "Foo is nolonger own by unique_ptr\n";
	delete fp;
	//unique_ptr��get����

	std::cout << "reset function\n";
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo, D> up1(new Foo(), D());//up1ռ��Fooָ��ͣ�ɾ����D��
	std::cout << "replace owned Foo with a new Foo\n";
	up1.reset(new Foo());//���þ��ߵ�ɾ����

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
	std::wstring wstr(L"abs����-Da");
	transform(wstr.begin(), wstr.end(), wstr.begin(), ::toupper);

	std::string strA = "���yasaken@126.com";
	transform(strA.begin(), strA.end(), strA.begin(), ::toupper);
}

//�����⣺��������ַ���������ͬ���ַ�
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
//�����⣺��������ַ���������ͬ���ַ�
void CommonApi::test_findcommon()
{
	char a[5] = { '1', 'b', 'C', 'f', 'f' };
	char b[6] = { '1', 'b', 'd', 'e', 'C','d' };
	FindCommonChar(a, _countof(a), b, _countof(b));
}

//VC��ȡ�ַ����ȵķ���
#include "string"
#include "comutil.h"
#pragma comment(lib, "comsuppw.lib")
//VC��ȡ�ַ����ȵķ���
void CommonApi::test_get_string_length()
{
	//VC��ȡ�ַ����ȵķ���
	char s1[] = "����ABC";
	wchar_t s2[] = L"����ABC";

	//ʹ��sizeof��ȡ�ַ�������
	printf("sizeof s1: %d\r\n", sizeof(s1));
	printf("sizeof s2: %d\r\n", sizeof(s2));

	//ʹ��strlen��ȡ�ַ�������
	printf("strlen(s1): %d\r\n", strlen(s1));
	printf("wcslen(s2): %d\r\n", wcslen(s2));

	//ʹ��CString::GetLength()��ȡ�ַ�������
	//CStringA sa = s1;
	//CStringW sw = s2;
	//printf("sa.GetLength(): %d\r\n", sa.GetLength());
	//printf("sw.GetLength(): %d\r\n", sw.GetLength());
	//ʹ��string::size()��ȡ�ַ�������
	std::string ss1 = s1;
	std::wstring ss2 = s2;
	printf("ss1.size(): %d\r\n", ss1.size());
	printf("ss2.size(): %d\r\n", ss2.size());
	//ʹ��_bstr_t::length()��ȡ�ַ�������
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);
	printf("bs1.length(): %d\r\n", bs1.length());
	printf("bs2.length(): %d\r\n", bs2.length());
}

//boost�ļ�Ŀ¼����
#include <boost/filesystem.hpp>
//boost�ļ�Ŀ¼����
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

//boost�߳�
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
//boost�߳�
void CommonApi::test_boost_thread()
{
	//boost�߳�
	boost::thread thrd(&hello);
	thrd.join();
}

//����boost�߳�ʹ�÷�ʽ
#include "boost/thread.hpp"
#include <iostream>
void mythread()
{
	std::cout << "hello thread" << std::endl;
}
//����boost�߳�ʹ�÷�ʽ
void CommonApi::test_boost_thread2()
{
	//����boost�߳�ʹ�÷�ʽ
	boost::function<void()>f(mythread);
	boost::thread t(f);
	t.join();
	std::cout << "thread is over" << std::endl;
}

void CommonApi::test_my_reverse_copy()
{
	int myints[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> myvector;
	myvector.resize(9);//����ռ�
	std::reverse_copy(myints, myints + 9, myvector.begin());

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	{
		std::cout << ' ' << *it;
	}

	std::cout << '\n';
}

//ʱ���ʽ���
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
//ʱ���ʽ���
void CommonApi::test_format_time()
{
	//��ʽ�����ʱ�䣬������80����ʱ��
	std::string sTest = "00:00:00";
	std::string sResult;
	while (true)
	{
		sTest = GetAbsolulyTime(sTest, 80);
		Sleep(1000);
		std::cout << "Time is" << sTest << std::endl;
	}
}

//���Թ۲���ģʽ
#include "ObserverPattern.h"
//���Թ۲���ģʽ
void CommonApi::test_ObserverPattern()
{
	testObserverPattern();
}

//����log��־��̬��
typedef  void(*LOGFUN)(const std::string &sFile, const std::string &sFunc, const long &lLine, const std::string &sMessage);
LOGFUN MYLOG;
//typedef void (*LOGFUN)(const string &sFunc,const string &sMessage);
//extern LOGFUN MYLOG;
void FuncB()
{
	MYLOG(__FILE__, __FUNCTION__, __LINE__, "It is in FuncB");
}
//����log��־��̬��
void CommonApi::test_log_dll()
{
	//����log��־��̬��
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

//Windows��Event���
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
//ͨ���¼���֪��һ���̵߳�״̬
//���磺�߳���������״̬���𴲡��Է����ϰ�
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
//Windows��Event���
void CommonApi::test_windows_event()
{
	stateTexts.reserve(3);//����Ԥ���ռ�
	g_getupHandle = CreateEventA(NULL, true, false, NULL);//�ֶ������ź�
	g_breakfastHandle = CreateEventA(NULL, true, false, NULL);//�ֶ������ź�
	g_workHandle = CreateEventA(NULL, true, false, NULL);//�ֶ������ź�

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


//mystringToi��mystringTofloat
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
//mystringToi��mystringTofloat
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
	//string��c_str()������data()����
	//1. c_str()������һ��const char*ָ�룬ָ���Կ��ַ���ֹ�����顣
	//2. data():��c_str()���ƣ����Ƿ��ص����鲻�Կ��ַ���ֹ��
	std::string s = "12345";
	char test[10] = { 0 };
	strncpy_s(test, s.c_str(), 6);
	char test1[10] = { 0 };
	strncpy_s(test1, s.data(), 6);
}

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
