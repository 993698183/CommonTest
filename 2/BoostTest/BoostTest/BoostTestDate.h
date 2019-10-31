#pragma once
#ifndef BOOST_TEST_DATE
#define BOOST_TEST_DATE
#include <iostream>
#include <string>
#include <boost/date_time.hpp>

void test_date_accessor()
{
	using namespace boost::gregorian;
	date dt(2011, 2, 27);

	greg_year y = dt.year();
	assert(y == 2011);
	greg_month m = dt.month();
	assert(m == 2);
	greg_day d = dt.day();
	assert(d == 27);

	date::ymd_type ymd = dt.year_month_day();
	assert(ymd.year == 2011);
	assert(ymd.month == 2);
	assert(ymd.day == 27);

	// 获取date是在一年中的第几天
	date::day_of_year_type dy = dt.day_of_year();
	assert(dy == 58);	// 一年的第58天

	// 获取date是在一周中的第几天
	date::day_of_week_type dw = dt.day_of_week();
	assert(dw == 0);	// 星期天

	// 获取当前日期的本月最后一天
	date dend1 = dt.end_of_month();
	assert(dend1 == date(2011, 2, 28));
	date dend2 = dend1 + months(1);
	dend2 = dend2.end_of_month();
	assert(dend2 == date(2011, 3, 31));

	// 本年的第几周(ISO 8601 week number)
	// 注意星期天变成一周结束，不是老外习惯的一周的开始。
	int wn = dt.week_number();
	assert(wn == 8);	// 第八周

	// 儒略日(Julian day), 是指由公元前4713年1月1日
	long l = dt.julian_day();	// 从儒略日到当天有多少天?
}

void test_date2string()
{
	using namespace boost::gregorian;
	date dt(2011, 2, 27);

	std::string dstr1 = to_iso_string(dt);
	std::string dstr2 = to_iso_extended_string(dt);
	std::string dstr3 = to_simple_string(dt);

	assert(dstr1 == "20110227");
	assert(dstr2 == "2011-02-27");
	assert(dstr3 == "2011-Feb-27");
}

#endif // !BOOST_TEST_DATE
