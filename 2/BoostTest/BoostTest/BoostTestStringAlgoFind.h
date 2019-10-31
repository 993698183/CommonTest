#pragma once

#ifndef BOOST_TEST_STRING_ALGO_FIND
#define BOOST_TEST_STRING_ALGO_FIND

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>

// find_first:【1】查找字符串在输入中第一次出现的位置。
// find_last: 【2】查找字符串在输入中最后一次出现的位置。
// find_nth:  【3】查找字符串在输入中的第n次（从0开始计数）出现的位置。
// find_head: 【4】取一个字符串开头N个字符的字串，相当于substr(0,n);
// find_tail: 【5】取一个字符串末尾N个字符的字串。
void test_string_find_string()
{
	std::string str1("a1234_first_nth_first_nth_");
	boost::iterator_range<std::string::iterator> ir;

	// find_first与ifind_first（不区分大小写，其它同find_first）
	ir = boost::find_first(str1, "first");
	// 1. 通过iterator_range构建字符串
	assert(std::string(ir.begin(), ir.end()) == "first");
	// 2. 查看搜索到的字符串所在位置
	assert(ir.begin() - str1.begin() == 6 && ir.end() - str1.begin() == 6 + 5);
	// 3. 利用iterator_range处理搜索到的字符串
	boost::to_upper(ir);
	assert(str1 == "a1234_FIRST_nth_first_nth_");
	boost::to_lower(ir);
	assert(str1 == "a1234_first_nth_first_nth_");

	// find没有找到的情况
	ir = boost::find_first(str1, "no");
	assert(ir.empty()); // 不存在
	assert(std::string(ir.begin(), ir.end()).empty()); // 不存在，仍可构建一个string
	std::ostringstream osstr;
	osstr << boost::find_first(str1, "_first_");
	assert(osstr.str() == "_first_");
}

void test_string_find_token()
{
	using namespace boost;

	std::string str1("ab1234_first_nth_first_nth_");
	iterator_range<std::string::iterator> ir;

	ir = find_token(str1, is_any_of("irfst"));
	assert(std::string(ir.begin(), ir.end()) == "f");

	ir = find_token(str1, is_any_of("xfirts"), token_compress_off);
	assert(std::string(ir.begin(), ir.end()) == "f");

	ir = find_token(str1, is_any_of("irfst"), token_compress_on);
	assert(std::string(ir.begin(), ir.end()) == "first");

	ir = find_token(str1, is_any_of("fitr "), token_compress_on);
	assert(std::string(ir.begin(), ir.end()) == "fir");

	ir = find_token(str1, is_lower(), token_compress_on);
	assert(std::string(ir.begin(), ir.end()) == "ab");
}


// 注意加上头文件
// #include <boost/algorithm/string/regex.hpp>
// find_regex, find_all_regex
void test_string_find_regex()
{
	using namespace boost;

	std::string str1("ab1234_first_nth_first_nth_");
	iterator_range<std::string::iterator> ir;
	regex rx("b[0-9]+_");

	ir = find_regex(str1, rx);
	assert(std::string(ir.begin(), ir.end()) == "b1234_");

	std::string str2("b1_b22_b333_b4444");
	std::vector<std::string> tokens;
	find_all_regex(tokens, str2, rx);
	assert(tokens.size() == 3);
	assert(tokens[0] == "b1_");
	assert(tokens[1] == "b22_");
	assert(tokens[2] == "b333_");

	// 网络上找到的另一个例子
	std::string value = "123a1cxxxxa56c";
	regex pattern("a[0-9]+c");
	iterator_range<std::string::iterator> find_result;
	find_result = algorithm::find_regex(value, pattern);
	assert(!find_result.empty());

	std::vector<std::string> results;
	find_all_regex(results, value, pattern);
	assert("a1c" == results[0]);
	assert("a56c" == results[1]);
	assert(!results.empty());

	value = "10.10.10.10 1.1.1.1";
	boost::regex ip_pattern("(\\d{1, 3}.){3}\\d{1, 3}");
	find_all_regex(results, value, ip_pattern);
	assert("10.10.10.10" == results[0]);
	assert("1.1.1.1" == results[1]);
	assert(!results.empty());
}

void test_string_trim_if()
{
	std::string str = "abcd!@#$%^efghi1234xyz";

	std::string str1 = boost::trim_left_copy_if(str, boost::is_alnum());
	assert(str1 == "!@#$%^efghi1234xyz");
	std::string str2 = boost::trim_right_copy_if(str, boost::is_alnum());
	assert(str2 == "abcd!@#$%^");
	std::string str3 = boost::trim_copy_if(str, boost::is_alnum());
	assert(str3 == "!@#$%^");

	boost::trim_left_if(str, boost::is_alnum());
	assert(str == "!@#$%^efghi1234xyz");
	boost::trim_right_if(str, boost::is_alnum());
	assert(str == "!@#$%^");

	// 如果是二元函数，可以做如下处理
	std::string str2nd("###GoodBye ChongQing!######");
	boost::trim_if(str2nd, bind2nd(std::equal_to<char>(), '#'));
	assert(str2nd == "GoodBye ChongQing!");

	// 当然用下面的方法也可以实现如上的功能
	std::string strAny("###Hello Fuzhou!######");
	boost::trim_if(strAny, boost::is_any_of("#"));
	assert(strAny == "Hello Fuzhou!");
}

void test_string_erase()
{
	using namespace boost;
	std::string str = "Hello Dolly, Hello World!";

	std::cout << "#### erase_range ####" << std::endl;
	{
		std::string str1 = str;
		erase_range(str1, make_iterator_range(str1.begin() + 2, str1.end() - 2));
		std::cout << str1 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_first and erase_first_copy ####" << std::endl;
	{
		std::string str2 = str;
		erase_first(str2, "Hello");
		std::cout << str2 << std::endl;
	}
	{
		std::string str2 = str;
		std::string strc1 = erase_first_copy(str2, "Hello");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_first_copy(back_inserter(strc2), str, "Hello");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_last and erase_last_copy ####" << std::endl;
	{
		std::string str3 = str;
		erase_last(str3, "Hello");
		std::cout << str3 << std::endl;
	}
	{
		std::string str3 = str;
		std::string strc1 = erase_last_copy(str3, "Hello");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_last_copy(back_inserter(strc2), str, "Hello");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	// 注意nth的索引从0开始.
	std::cout << "#### erase_nth and erase_nth_copy ####" << std::endl;
	{
		std::string str4 = str;
		erase_nth(str4, "Hello", 1);
		std::cout << str4 << std::endl;
	}
	{
		std::string str4 = str;
		std::string strc1 = erase_nth_copy(str4, "Hello", 1);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_nth_copy(back_inserter(strc2), str, "Hello", 1);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_all and erase_all_copy ####" << std::endl;
	{
		std::string str5 = str;
		erase_all(str5, "Hello");
		std::cout << str5 << std::endl;
	}
	{
		std::string str5 = str;
		std::string strc1 = erase_all_copy(str5, "Hello");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_all_copy(back_inserter(strc2), str, "Hello");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_head and erase_head_copy ####" << std::endl;
	{
		std::string str6 = str;
		erase_head(str6, 3);
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		std::string strc1 = erase_head_copy(str6, 3);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_head_copy(back_inserter(strc2), str, 3);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_tail and erase_tail_copy ####" << std::endl;
	{
		std::string str6 = str;
		erase_tail(str6, 3);
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		std::string strc1 = erase_tail_copy(str6, 3);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_tail_copy(back_inserter(strc2), str, 3);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_regex, erase_regex_copy ####" << std::endl;
	{
		std::string str6 = str;
		regex reg("H.*?o");

		erase_regex(str6, reg);
		std::cout << str6 << std::endl;
	}

	{
		std::string str6 = str;
		regex reg("H.*?o");
		std::string strc1 = erase_regex_copy(str6, reg);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_regex_copy(back_inserter(strc2), str, reg);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### erase_all_regex, erase_all_regex_copy ####" << std::endl;
	{
		std::string str6 = str;
		regex reg("H.*?o");

		erase_all_regex(str6, reg);
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		regex reg("H.*?o");
		std::string strc1 = erase_all_regex_copy(str6, reg);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		erase_all_regex_copy(back_inserter(strc2), str, reg);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;
}

void test_string_replace()
{
	using namespace boost;
	std::string str = "Hello Dolly, Hello World!";

	std::cout << "#### replace_range ####" << std::endl;
	{
		std::string str1 = str;
		replace_range(str1, make_iterator_range(str1.begin() + 2, str1.end() - 2), "!!!");
		std::cout << str1 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_first and replace_first_copy ####" << std::endl;
	{
		std::string str2 = str;
		replace_first(str2, "Hello", "GoodBye");
		std::cout << str2 << std::endl;
	}
	{
		std::string str2 = str;
		std::string strc1 = replace_first_copy(str2, "Hello", "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_first_copy(back_inserter(strc2), str, "Hello", "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_last and replace_last_copy ####" << std::endl;
	{
		std::string str3 = str;
		replace_last(str3, "Hello", "GoodBye");
		std::cout << str3 << std::endl;
	}
	{
		std::string str3 = str;
		std::string strc1 = replace_last_copy(str3, "Hello", "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_last_copy(back_inserter(strc2), str, "Hello", "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	// 注意nth的索引从0开始.
	std::cout << "#### replace_nth and replace_nth_copy ####" << std::endl;
	{
		std::string str4 = str;
		replace_nth(str4, "Hello", 1, "GoodBye");
		std::cout << str4 << std::endl;
	}
	{
		std::string str4 = str;
		std::string strc1 = replace_nth_copy(str4, "Hello", 1, "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_nth_copy(back_inserter(strc2), str, "Hello", 1, "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_all and replace_all_copy ####" << std::endl;
	{
		std::string str5 = str;
		replace_all(str5, "Hello", "GoodBye");
		std::cout << str5 << std::endl;
	}
	{
		std::string str5 = str;
		std::string strc1 = replace_all_copy(str5, "Hello", "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_all_copy(back_inserter(strc2), str, "Hello", "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_head and replace_head_copy ####" << std::endl;
	{
		std::string str6 = str;
		replace_head(str6, 5, "GoodBye");
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		std::string strc1 = replace_head_copy(str6, 5, "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_head_copy(back_inserter(strc2), str, 5, "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_tail and replace_tail_copy ####" << std::endl;
	{
		std::string str6 = str;
		replace_tail(str6, 6, "GoodBye");
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		std::string strc1 = replace_tail_copy(str6, 6, "GoodBye");
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_tail_copy(back_inserter(strc2), str, 6, "GoodBye");
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_regex, replace_regex_copy ####" << std::endl;
	{
		std::string str6 = str;
		regex reg("H.*?o");

		//		replace_regex(str6, reg, "GoodBye");	// 直接这么写会报错. 要用如下的方法.
		std::string strReplace = "GoodBye";
		replace_regex(str6, reg, strReplace);

		std::cout << str6 << std::endl;
	}

	{
		std::string str6 = str;
		regex reg("H.*?o");
		std::string strReplace = "GoodBye";
		std::string strc1 = replace_regex_copy(str6, reg, strReplace);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_regex_copy(back_inserter(strc2), str, reg, strReplace);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#### replace_all_regex, replace_all_regex_copy ####" << std::endl;
	{
		std::string str6 = str;
		regex reg("H.*?o");
		std::string strReplace = "GoodBye";
		replace_all_regex(str6, reg, strReplace);
		std::cout << str6 << std::endl;
	}
	{
		std::string str6 = str;
		regex reg("H.*?o");
		std::string strReplace = "GoodBye";
		std::string strc1 = replace_all_regex_copy(str6, reg, strReplace);
		std::cout << strc1 << std::endl;

		std::string strc2 = "result = ";
		replace_all_regex_copy(back_inserter(strc2), str, reg, strReplace);
		std::cout << strc2 << std::endl;
	}
	std::cout << std::endl;
}

#endif
