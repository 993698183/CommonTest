#pragma once
#ifndef BOOST_TEST_STRING
#define BOOST_TEST_STRING

//http://zh.highscore.de/cpp/boost/stringhandling.html
//区域设置的问题：
	//区域设置在标准C++中封装了文化习俗的相关内容，包括货币符号、日期时间格式、分割整数部分和分数部分的符号，还有千位符
	//使用类std::string可以不考虑时间域的设置，因为它不依赖于特定语言
	//但是boost库中区域设置是必不可少的
	//全局区域设置可以使用类std::local中静态函数global()改变
#include <iostream>
#include <string>
#include <locale>
#include <boost/lexical_cast.hpp>

template<typename T> 
std::string to_string(const T& arg)
{
	try
	{
		return boost::lexical_cast<std::string>(agr);
	}
	catch (boost::bad_lexical_cast & e)
	{
		return "";
	}
}

void test_string()
{
	std::string s = to_string(412);
	std::cout << s << std::endl;
	s = to_string(2.123);
	std::cout << s << std::endl;
}

//打印local
void print_local()
{
	std::locale loc;
	//结果C：默认全局设置，包括了美式文化中使用的描述
	std::cout << loc.name() << std::endl;
}

//使用global函数改变全局区域设置
void change_local()
{
	std::cout << std::strcoll("ä", "z") << std::endl;
	std::locale::global(std::locale("German"));
	std::cout << std::strcoll("ä", "z") << std::endl;
}
#endif