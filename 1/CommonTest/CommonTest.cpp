// CommonTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CommonApi.h"
//根据boost的asio连接，确定本地ip和远端ip
#include "BoostAsio.h"
//根据boost的asio连接，确定本地ip和远端ip

#include "BoostTest.h"



//验证对于空字符串使用 boost去掉前后空格是否报错问题
#include <boost/algorithm/string.hpp>
//验证对于空字符串使用 boost去掉前后空格是否报错问题



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

//C++常用宏定义
#include <stdio.h>
//C++常用宏定义

//boost::filesystem::is_directory异常捕获
#include <iostream>
#include <boost/filesystem.hpp>
//boost::filesystem::is_directory异常捕获

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

//string的c_str()函数和data()函数
#include <iostream>
#include <string>
//string的c_str()函数和data()函数

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
	const char *format,...
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





//测试类模板
#include "TemplateTest.h"
//测试类模板
int main()
{
	if (0)
	{
		CommonApi::test_unique_ptr_get_release_reset();
		system("pause");
	}
	//测试类模板
	if (0)
	{
		TemplateTest::test_template_class_function();
		system("pause");
	}
	//测试类模板

	//判断电脑指令集是小端字节序还是大端字节序
	if (0)
	{
		CommonApi::test_computer_little_or_big_endian();
		system("pause");
	}
	//判断电脑指令集是小端字节序还是大端字节序

	if (1)
	{
		CommonApi::test_size_type_vector();//适用stl的size_type变量
		CommonApi::test_string_big_or_little();//判断string类型的大小
		system("pause");
	}
	if (0)
	{
		CommonApi::test_try_catch();
		system("pause");
	}
	
	if (0)
	{
		BoostTest test;
		//test.get_sec();
		//test.test_timer();
		//test.test_progress_timer();
		//test.test_progress_display();
		//test.test_progress_display_restart();
		std::wstring wstrpath = L"E:\\1_ZXLCode\\1_QT\\1\\CH1\\CH101\\";
		test.show_file(wstrpath);
		system("pause");
	}

	//根据boost的asio连接，确定本地ip和远端ip
	if (0)
	{
		CBoostAsio  *pboostasio = new CBoostAsio("192.168.3.112", 57603);
		pboostasio->SetIP();
		std::cout << "LocalClientIP=" << pboostasio->GetLocalClientIP() << std::endl;
		std::cout << "RemoteServerIP=" << pboostasio->GetRemoteServerIP() << std::endl;

		delete pboostasio;
		pboostasio = nullptr;
		system("pause");
	}
	//根据boost的asio连接，确定本地ip和远端ip

	//c++调用cmd指令，启动Windows计算器
	if (0)
	{
		//方法一：
		system("calc");
		//方法二：
		//WinExec("calc", SW_NORMAL);
	}
	//c++调用cmd指令，启动Windows计算器
	//测试new失败的返回值
	if (0)
	{
		int *p = nullptr;
		p = new int[1000000];
		system("pause");
	}
	//测试new失败的返回值

	//string和wstring大小写转换功能
	if (0)
	{
		CommonApi::test_string_wstring_to_upper_lowwer();
		system("pause");
	}
	//string和wstring大小写转换功能

	//自己的log日志功能
	if (0)
	{
		DEBUG_LOG("%s, ranking NO.%d", "You are so smart", 1);
		system("pause");
	}
	//自己的log日志功能

	//string的c_str()函数和data()函数
	//1. c_str()：生成一个const char*指针，指向以空字符终止的数组。
	//2. data():与c_str()类似，但是返回的数组不以空字符终止。
	if (0)
	{
		std::string s = "12345";
		char test[10] = { 0 };
		strncpy_s(test, s.c_str(), 6);
		char test1[10] = { 0 };
		strncpy_s(test1, s.data(), 6);
		system("pause");
	}
	//string的c_str()函数和data()函数

	//mystringToi和mystringTofloat
	if (0)
	{
		char* p1 = "123";
		std::cout << string2i(p1) << std::endl;
		char* p2 = "123.333";
		std::cout << string2float(p2) << std::endl;
	}
	//mystringToi和mystringTofloat

	//面试题：输出两个字符数组中相同的字符
	if (0)
	{
		CommonApi::test_findcommon();
		system("pause");
	}
	//面试题：输出两个字符数组中相同的字符

	//Windows的Event编程
	if (0)
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

		system("pause");
	}
	//Windows的Event编程

	//调用log日志动态库
	if (0)
	{
		char c;
		HINSTANCE hInput;
		hInput = LoadLibrary(_T("LogDll.dll"));
		if (NULL == hInput)
		{
			std::cout << "load failed" << std::endl;
			c = getchar();
			return -1;
		}
		typedef bool(*FUNC)(const std::string &sFilePath);
		FUNC fun = (FUNC)GetProcAddress(hInput, "LogPath");
		if (NULL == fun)
		{
			std::cout << "load function failed" << std::endl;
			c = getchar();
			return -1;
		}
		bool iResult = fun("D://");
		std::cout << "result is" << iResult << std::endl;

		MYLOG = (LOGFUN)GetProcAddress(hInput, "WRITELOG");
		if (NULL == MYLOG)
		{
			std::cout << "load function failed" << std::endl;
			c = getchar();
			return -1;
		}
		while (true)
		{
			std::cout << "wrtite..." << std::endl;
			MYLOG(__FILE__, __FUNCTION__, __LINE__, "This is a test");
			FuncB();
			Sleep(5000);
		}
		c = getchar();
	}
	//调用log日志动态库
    return 0;
}

