#pragma once
#ifndef BOOST_TEST_JSON
#define BOOST_TEST_JSON

#include <iostream>
#include <string>
//boost��json�����ⲻ���̰߳�ȫ�ģ��ڶ��߳���Ҫ����ʹ��
//�����Ҫ֧���̰߳�ȫ���ͱ������һ����#define BOOST_SPIRIT_THREADSAFE
//����������������boostͷ�ļ��ʼ����
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
void test_json()
{
	std::string s = "{ \"a\": 100, \"b\": [1, 2, 3, 4] }";
	std::stringstream ss(s);
	boost::property_tree::ptree pt;
	//��ȡjson����
	boost::property_tree::read_json(ss, pt);
	std::cout << pt.get_child("a").data() << std::endl;
	//д��json����
	boost::property_tree::write_json("./tmp.json", pt);
}

void test_json2()
{
	std::string s = "{ \"a\": { \"b\":1, \"c\":2 }, \"d\":3 }";
	std::stringstream ss(s);
	boost::property_tree::ptree ptree;
	boost::property_tree::read_json(ss, ptree);
	std::cout << "input text:" << std::endl;
	boost::property_tree::write_json(std::cout, ptree);
	std::cout << "parse result: " << std::endl;
	std::cout << "a->b" << ptree.get_child("a").get_child("b").get_value<int>() << std::endl;
	std::cout << "a->b" << ptree.get_child("a.b").get_value<int>() << std::endl;
	std::cout << "a->c" << ptree.get_child("a.c").get_value<int>() << std::endl;
	std::cout << "d:" << ptree.get_child("d").get_value<int>() << std::endl;
}

void test_json3()
{
	std::string s = "{ \"a\": { \"b\":1, \"c\":2 }, \"d\":3 }";
	std::stringstream ss(s);
	boost::property_tree::ptree ptree;
	boost::property_tree::read_json(ss, ptree);
	std::cout << "input text" << std::endl;
	boost::property_tree::write_json(std::cout, ptree);
	std::cout << "-----------------------" << std::endl;
	std::cout << "a->b" << ptree.get<int>("a.b") << std::endl;
	std::cout << "a->c: " << ptree.get<int>("a.c") << std::endl;
	std::cout << "d: " << ptree.get<int>("d") << std::endl;
}
#endif
