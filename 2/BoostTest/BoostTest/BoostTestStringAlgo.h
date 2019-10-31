#pragma once
#ifndef BOOST_TEST_STRINGALGO
#define BOOST_TEST_STRINGALGO

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
/*
命名规则：
	前缀i：有这个前缀表明算法是大小写不敏感的，否则是大小写敏感的
	后缀copy：有这个后缀表明算法不变动输入，返回处理结果的拷贝，否则算法原地处理，输入即输出
	后缀if：有这个后缀表明算法需要一个作为判断式的谓词函数对象，否则使用默认的判断准则
*/

/*
算法分类：
	string_algo库提供的算法分五大类：
		1：大小写转换
		2：判断式与分类
		3：修剪
		4：查找与替换
		5：分割与合并
*/

void test_string_case()
{
	// 返回大写拷贝, 原字符串改变
	std::string str1("I Don't Know. ");
	boost::to_upper(str1);
	std::cout << "str1 = " << str1 << std::endl;

	// 返回大写拷贝, 原字符串不改变
	std::string str2("I Don't Know. ");
	std::string str3 = boost::to_upper_copy(str2);
	std::cout << "str2 = " << str2 << std::endl;
	std::cout << "str3 = " << str3 << std::endl;
}

void test_string_trim()
{
	std::string str1 = "  abc  ";
	std::string str2 = boost::trim_left_copy(str1);
	std::string str3 = boost::trim_right_copy(str1);
	std::string str4 = boost::trim_copy(str1);
	assert(str2 == "abc  ");
	assert(str3 == "  abc");
	assert(str4 == "abc");

	std::string str5 = "0005918580058";
	std::string str6 = boost::trim_left_copy_if(str5, boost::is_any_of("0"));
	std::cout << str6 << std::endl;
}

void test_string_precidate()
{
	// starts_with
	assert(boost::starts_with("boost_python-vc100-mt-1_49.dll", "boost"));
	assert(!boost::starts_with("boost_python-vc100-mt-1_49.dll", "BOOST"));
	assert(boost::istarts_with("boost_python-vc71-mt-1_33.dll", "BOOST"));

	// ends_with
	assert(boost::ends_with("boost_python-vc100-mt-1_49.dll", ".dll"));
	assert(!boost::ends_with("boost_python-vc100-mt-1_49.dll", ".DLL"));
	assert(boost::iends_with("boost_python-vc100-mt-1_49.dll", ".DLL"));

	// contains    
	assert(boost::contains("boost_python-vc100-mt-1_49.dll", "python"));
	assert(!boost::contains("boost_python-vc100-mt-1_49.dll", "PYTHON"));
	assert(boost::icontains("boost_python-vc100-mt-1_49.dll", "PYTHON"));

	// equals
	assert(boost::equals("boost", "boost"));
	assert(!boost::equals("boost", "BOOST"));
	assert(boost::iequals("boost", "BOOST"));

	// Empty string test
	assert(boost::starts_with("boost_python-vc100-mt-1_49.dll", ""));
	assert(boost::ends_with("boost_python-vc100-mt-1_49.dll", ""));
	assert(boost::contains("boost_python-vc100-mt-1_49.dll", ""));

	// lexicalgrephical_compare
	assert(boost::lexicographical_compare("boost_python-vc100-mt-1_49.dll", "boost_system-vc100-mt-1_49.dll"));

	// all: 如果它的所有元素满足一个给定的通过判断式描述的条件，则这个条件式成立。
	assert(boost::all("\x20\t\n\r", boost::is_space()));
	assert(boost::all("\x20\t\n\r", boost::is_classified(std::ctype_base::space)));
	assert(boost::all("\x20\t\n\r", boost::is_any_of("\x20\t\n\r")));
	assert(boost::all("abcde", boost::is_from_range('a', 'e')));
	assert(boost::all("abcde", boost::is_from_range('a', 'z')));
	assert(!boost::all("abcde", boost::is_from_range('b', 'c')));
	assert(boost::all("abc __ de", boost::is_from_range('a', 'z') || boost::is_space() || boost::is_any_of("_")));
}

void test_string_classify()
{
	// 	is_space: 字符是否为空格
	// 	is_alnum: 字符是否为字母和数字字符
	// 	is_alpha: 字符是否为字母
	// 	is_cntrl: 字符是否为控制字符
	// 	is_digit: 字符是否为十进制数字
	// 	is_graph: 字符是否为图形字符
	// 	is_lower: 字符是否为小写字符
	// 	is_print: 字符是否为可打印字符
	// 	is_punct: 字符是否为标点符号字符
	//  is_upper: 字符是否为大写字符
	//  is_xdigit: 字符是否为十六进制数字
	//  is_any_of: 字符是否是参数字符序列中的任意字符
	//  if_from_range 字符是否位于指定区间内，即from <= ch <= to

}

#endif