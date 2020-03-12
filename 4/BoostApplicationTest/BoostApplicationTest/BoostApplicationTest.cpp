// BoostApplicationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

int main()
{
	int i = 100;
	std::string strInt = boost::lexical_cast<std::string>(i);
	std::cout << strInt << std::endl;
	getchar();
    return 0;
}

