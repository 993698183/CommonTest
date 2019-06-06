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



//C++常用宏定义
#include <stdio.h>
//C++常用宏定义

//boost::filesystem::is_directory异常捕获
#include <iostream>
#include <boost/filesystem.hpp>
//boost::filesystem::is_directory异常捕获



//string的c_str()函数和data()函数
#include <iostream>
#include <string>
//string的c_str()函数和data()函数


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

		system("pause");
	}
	//自己的log日志功能

	//面试题：输出两个字符数组中相同的字符
	if (0)
	{
		CommonApi::test_findcommon();
		system("pause");
	}
	//面试题：输出两个字符数组中相同的字符

    return 0;
}

