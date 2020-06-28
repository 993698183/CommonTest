#pragma once
#ifndef _TEST_BOOST_H_
#define _TEST_BOOST_H_
#include <iostream>
#include <boost/lexical_cast.hpp>


void test_boost_lexical_cast()
{
	int i = boost::lexical_cast<int>("0010");
	std::cout << i << std::endl;
}

bool isTimeScale(int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin)
{
	//将时间都转化为分钟数，利于判断
	uint16_t startMin = startTimeHour * 60 + startTimeMin;
	uint16_t endMin = endTimeHour * 60 + endTimeMin;
	//uint16_t curMin = 当前时间;
	uint16_t curMin = 0;
	//不跨天的情况
	if (startMin < endMin)
	{
		if (startMin <= curMin && curMin <= endMin)
		{
			return true;
		}
	}
	//跨天的情况
	else if (startMin > endMin)
	{
		if (startMin <= curMin || curMin <= endMin)
		{
			return true;
		}
	}
	return false;
}

#endif