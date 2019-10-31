#pragma once
#ifndef BOOST_TEST_STRING
#define BOOST_TEST_STRING
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

template<typename T> std::string to_string(const T& arg)
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
#endif