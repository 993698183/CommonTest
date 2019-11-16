#pragma once
#ifndef C_PLUS_11
#define C_PLUS_11

#include <iostream>
#include <string>

//C++11ԭʼ�ַ�������
//ԭʼ�ַ����������Ķ���Ϊ��R"xxx(raw string)xxx"
//���У�ԭʼ�ַ����������ţ��������������ŵ�ǰ����Լ��������ַ��������ӵ��ַ����ᱻ���ԣ����Ҽӵ��ַ�����������������ͬʱ����

void test_Raw_string()
{
	std::string normal_str = "First line.\nSecond line.\nEnd of Message.\n";
	// һ��raw string��'\'���ᱻת�崦����ˣ�"\n"��ʾ�����ַ����ַ���б�� �� ��ĸn��
	std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
	std::cout << normal_str << std::endl;
	std::cout << raw_str << std::endl;
	std::cout << R"foo(hello, world)foo" << std::endl;
	//raw string ���Կ�Խ���У����еĿհ׺ͻ��з��������ַ�����һ����
	std::cout << R"(
                   Hello,
                   world!
                   )" << std::endl;
}



#endif