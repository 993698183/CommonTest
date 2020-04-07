#pragma once
#ifndef Cplusplus11_h__
#define Cplusplus11_h__
/*!
 * \file Cplusplus11.h
 * \date 2020/04/02 11:50
 *
 * \author waction
 * Contact: user@company.com
 *
 * \brief
 *
 * TODO: long description
 *
 * \note
*/

#include <iostream>
#include <codecvt>
#include <string>
#include <vector>
#include <functional>

//C++11原始字符串操作
//原始字符串字面量的定义为：R"xxx(raw string)xxx"
//其中，原始字符必须用括号（）括起来，括号的前后可以加其他的字符串，所加的字符串会被忽略，并且加的字符串必须在括号两边同时出现

void test_Raw_string()
{
	std::string normal_str = "First line.\nSecond line.\nEnd of Message.\n";
	// 一个raw string，'\'不会被转义处理。因此，"\n"表示两个字符：字符反斜杠 和 字母n。
	std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
	std::cout << normal_str << std::endl;
	std::cout << raw_str << std::endl;
	std::cout << R"foo(hello, world)foo" << std::endl;
	//raw string 可以跨越多行，其中的空白和换行符都属于字符串的一部分
	std::cout << R"(
                   Hello,
                   world!
                   )" << std::endl;
}

void test_lambda()
{
    std::vector<int> c{1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());
    std::cout << "c:";
    for (auto i : c)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n";

    auto func1 = [](int i) {return i + 4; };
    std::cout << "func1:" << func1(6) << std::endl;
    std::function<int(int)> func2 = [](int i) {return i + 4; };
    std::cout << "func2:" << func2(6) << std::endl;

	int m = [](int x) { return [](int y) { return y * 2; }(x) + 6; }(5);
	std::cout << "m:" << m << std::endl;//输出m:16
}

std::string UnicodeToUTF8(const std::wstring& wstr)
{
	std::string ret;
	try
	{
		std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.to_bytes(wstr);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::wstring UTF8ToUnicode(const std::string& str)
{
	std::wstring ret;
	try
	{
		std::wstring_convert< std::codecvt_utf8<wchar_t> > wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

//Unicode <=> ANSI
std::string UnicodeToANSI(const std::wstring& wstr)
{
	std::string ret;
	std::mbstate_t state = {};
	const wchar_t* src = wstr.data();
	size_t len = std::wcsrtombs(nullptr, &src, 0, &state);
	if (static_cast<size_t>(-1) != len)
	{
		std::unique_ptr< char[] > buff(new char[len + 1]);
		len = std::wcsrtombs(buff.get(), &src, len, &state);
		if (static_cast<size_t>(-1) != len)
		{
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}

std::wstring ANSIToUnicode(const std::string& str)
{
	std::wstring ret;
	std::mbstate_t state = {};
	const char* src = str.data();
	size_t len = std::mbsrtowcs(nullptr, &src, 0, &state);
	if (static_cast<size_t>(-1) != len)
	{
		std::unique_ptr< wchar_t[] > buff(new wchar_t[len + 1]);
		len = std::mbsrtowcs(buff.get(), &src, len, &state);
		if (static_cast<size_t>(-1) != len)
		{
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}

std::string UTF8ToANSI(const std::string& str)
{
	return UnicodeToANSI(UTF8ToUnicode(str));
}

std::string ANSIToUTF8(const std::string& str)
{
	return UnicodeToUTF8(ANSIToUnicode(str));
}

#endif // Cplusplus11_h__
