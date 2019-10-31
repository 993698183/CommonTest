#pragma once
#ifndef BOOST_TEST_STRINGALGO
#define BOOST_TEST_STRINGALGO

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
/*
��������
	ǰ׺i�������ǰ׺�����㷨�Ǵ�Сд�����еģ������Ǵ�Сд���е�
	��׺copy���������׺�����㷨���䶯���룬���ش������Ŀ����������㷨ԭ�ش������뼴���
	��׺if���������׺�����㷨��Ҫһ����Ϊ�ж�ʽ��ν�ʺ������󣬷���ʹ��Ĭ�ϵ��ж�׼��
*/

/*
�㷨���ࣺ
	string_algo���ṩ���㷨������ࣺ
		1����Сдת��
		2���ж�ʽ�����
		3���޼�
		4���������滻
		5���ָ���ϲ�
*/

void test_string_case()
{
	// ���ش�д����, ԭ�ַ����ı�
	std::string str1("I Don't Know. ");
	boost::to_upper(str1);
	std::cout << "str1 = " << str1 << std::endl;

	// ���ش�д����, ԭ�ַ������ı�
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

	// all: �����������Ԫ������һ��������ͨ���ж�ʽ���������������������ʽ������
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
	// 	is_space: �ַ��Ƿ�Ϊ�ո�
	// 	is_alnum: �ַ��Ƿ�Ϊ��ĸ�������ַ�
	// 	is_alpha: �ַ��Ƿ�Ϊ��ĸ
	// 	is_cntrl: �ַ��Ƿ�Ϊ�����ַ�
	// 	is_digit: �ַ��Ƿ�Ϊʮ��������
	// 	is_graph: �ַ��Ƿ�Ϊͼ���ַ�
	// 	is_lower: �ַ��Ƿ�ΪСд�ַ�
	// 	is_print: �ַ��Ƿ�Ϊ�ɴ�ӡ�ַ�
	// 	is_punct: �ַ��Ƿ�Ϊ�������ַ�
	//  is_upper: �ַ��Ƿ�Ϊ��д�ַ�
	//  is_xdigit: �ַ��Ƿ�Ϊʮ����������
	//  is_any_of: �ַ��Ƿ��ǲ����ַ������е������ַ�
	//  if_from_range �ַ��Ƿ�λ��ָ�������ڣ���from <= ch <= to

}

#endif