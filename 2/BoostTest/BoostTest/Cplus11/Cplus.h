#pragma once
#ifndef C_PLUS_11
#define C_PLUS_11

#include <iostream>
#include <string>

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



#endif