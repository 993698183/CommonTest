#pragma once
#ifndef _TEST_BOOST_H_
#define _TEST_BOOST_H_
#include <iostream>
#include <boost/lexical_cast.hpp>

void test_boost_lexical_cast()
{
	int i = boost::lexical_cast<int>("100");
	std::cout << i << std::endl;
}

#endif