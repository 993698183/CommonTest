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

void test_date2tm()
{
	using namespace boost::gregorian;
	date dt(2011, 2, 27);

	tm t = to_tm(dt);
	assert(t.tm_year == 111);	// 从1900年计
	assert(t.tm_mon == 1);		// 结果1，从0开始，表示2月份
	assert(t.tm_mday == 27);
	assert(t.tm_wday == 0);		// 结果0，从星期日开始计
	assert(t.tm_yday == 57);	// 结果57，从0开始计，58天
	assert(t.tm_hour == 0);
	assert(t.tm_min == 0);
	assert(t.tm_sec == 0);
	assert(t.tm_isdst == -1);
}

void test_tm2date()
{
	using namespace boost::gregorian;
	tm t;
	t.tm_year = 111;
	t.tm_mon = 1;
	t.tm_mday = 27;
	date d = date_from_tm(t);
	assert(to_iso_extended_string(d) == "2011-02-27");
}

//date构造方法
//本库采用格里历日期系统, 支持从1400-Jan-01到9999-Dec-31.

void test_dt_construct()
{
	using namespace boost::gregorian;

	// 1. 常规的构造函数有如下几种:
	date d0;
	date d1(2008, 8, 9);	// 最常用的构造方法
	date d2(d1);			// 复制构造
	date ds1(neg_infin);
	date ds2(pos_infin);
	date ds3(not_a_date_time);
	date ds4(max_date_time);	// 9999-Dec-31
	date ds5(min_date_time);	// 1400-Jan-01

	assert(d0.is_not_a_date());
	assert(d0.is_special());
	assert(ds1.is_special());
	assert(ds2.is_special());
	assert(ds3.is_special());
	assert(!ds4.is_special());
	assert(!ds5.is_special());

	// 2. 通过字符串构造
	date dstr1(from_string("2011/08/09"));
	date dstr2(from_string("2011-08-09"));
	date dstr3(from_string("2011-Feb-28"));
	date dstr4(from_string("2011-February-28"));
	date dstr5(from_undelimited_string("20110809"));

	// 不常用的字符串
	date dstr6(from_us_string("Feb-28-2011"));	// 完整的月份单词也可以
	date dstr7(from_uk_string("28-Feb-2011"));	// 完整的月份单词也可以

												// 3. 通过clock构造
	date dc1(day_clock::local_day());
	date dc2(day_clock::universal_day());

	// 4. 构造时的异常
	try
	{
		// 年, 月, 日超过范围时会抛异常.
		date d6(1300, 12, 25);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

//date_duration与date_period
void test_date_duration()
{
	using namespace boost::gregorian;

	// 常见的几种构造方法
	{
		date_duration dd(3);

		days dd1(neg_infin);
		days dd2(pos_infin);
		days dd3(not_a_date_time);
		days dd4(max_date_time);
		days dd5(min_date_time);
	}

	// 简单运算
	{
		date_duration dd1(3);
		date_duration dd2(5);
		date_duration dd3 = dd1 + dd2;
		date_duration dd4 = dd1 - dd2;
		assert(dd3.days() == 8);
		assert(dd4.days() == -2);
	}

	// years, months, days
	{
		years ysingle(1);
		date dy1 = date(2003, 2, 28) + ysingle;
		assert(dy1 == date(2004, 2, 29));
		date dy2 = date(2004, 2, 29) + ysingle;
		assert(dy2 == date(2005, 2, 28));

		months msingle(1);
		date dm1 = date(2004, 1, 31) + msingle; // => 2004-Feb-29
		date dm2 = date(2005, 1, 31) + msingle; // => 2005-Feb-28
		assert(dm1 == date(2004, 2, 29));
		assert(dm2 == date(2005, 2, 28));

		weeks wsingle(1);
		date dw1 = date(2005, 1, 1) + wsingle; // => 2005-Jan-08
		assert(dw1 == date(2005, 1, 8));

		date_duration dd(3);
		assert(dd.days() == 3);
	}
}

void test_date_period()
{
	using namespace boost::gregorian;

	// 注意这样的构造函数是左闭右开
	date_period dp1(date(2010, 11, 29), date(2010, 12, 1));
	date_period dp2(date(2010, 11, 29), days(2));
	date_period dp3(dp2);

	// 时间段向后平移3天(dp2 = 12.2-->12.4)
	dp2.shift(days(3));
	assert(dp2 == date_period(date(2010, 12, 2), date(2010, 12, 4)));

	// 时间段向前后各扩展1天(dp3 = 11.28-->12.2)
	dp3.expand(days(1));
	assert(dp3 == date_period(date(2010, 11, 28), date(2010, 12, 2)));

	// begin, end, last
	assert(dp1.begin() == date(2010, 11, 29));
	// 注意end, last的区别。 last是最后一天, end是时间段的右边界（不包含）
	assert(dp1.end() == date(2010, 12, 1));
	assert(dp1.last() == date(2010, 11, 30));

	// 时间段的长度
	// assert(dp1.length() == 2);

	// 一些判断函数(返回值是bool)
	assert(!dp1.is_null());	// 当起始时间大于结束时间
	assert(!dp1.contains(date(2010, 12, 1)));	// 也可以包含时间段	
	bool b1 = dp3.intersects(dp1);	// 除了包含时间点之外, 还可以包含时间段交叉的运算
	assert(b1 == true);
	bool b2 = dp3.intersects(dp2);
	assert(b2 == false);
	// intersection与intersects不同在于: 它的返回值上date_period
	date_period dp4(date(2010, 11, 30), date(2010, 12, 3));
	dp4 = dp4.intersection(dp1);
	assert(dp4.begin() == date(2010, 11, 30));
	assert(dp4.end() == date(2010, 12, 1));

	// is_adjacent判断时间段是否相邻. 不能重叠.
	date_period dp5(date(2010, 12, 1), date(2010, 12, 5));
	bool b3 = dp1.is_adjacent(dp5);
	assert(b3);

	// is_before, is_after
	date d1(2010, 12, 1);
	bool b4 = dp1.is_before(d1);
	assert(b4);
	d1 = d1 - days(1);
	bool b5 = dp1.is_before(d1);
	assert(!b5);

	// 时间段合并(merge), 两个没有重合(包括相邻)的时间段, 结果为空.
	date_period dp6 = dp1.merge(dp3);
	assert(dp6 == date_period(date(2010, 11, 28), date(2010, 12, 2)));

	// 时间段合并(span)
	// begin = min(p1.begin, p2.begin)
	// end = max(p1.end , p2.end)
	date_period dp7(date(2010, 12, 1), date(2010, 12, 5));
	date_period dp8(date(2010, 12, 9), date(2010, 12, 31));
	date_period dp9 = dp7.span(dp8); // 2002-Jan-01/2002-Jan-31
	assert(dp9 == date_period(date(2010, 12, 1), date(2010, 12, 31)));
	// 输出: [2010-Dec-01/2010-Dec-30]
	std::cout << dp9 << std::endl;
}

#endif // !BOOST_TEST_DATE
