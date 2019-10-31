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

	// ��ȡdate����һ���еĵڼ���
	date::day_of_year_type dy = dt.day_of_year();
	assert(dy == 58);	// һ��ĵ�58��

	// ��ȡdate����һ���еĵڼ���
	date::day_of_week_type dw = dt.day_of_week();
	assert(dw == 0);	// ������

	// ��ȡ��ǰ���ڵı������һ��
	date dend1 = dt.end_of_month();
	assert(dend1 == date(2011, 2, 28));
	date dend2 = dend1 + months(1);
	dend2 = dend2.end_of_month();
	assert(dend2 == date(2011, 3, 31));

	// ����ĵڼ���(ISO 8601 week number)
	// ע����������һ�ܽ�������������ϰ�ߵ�һ�ܵĿ�ʼ��
	int wn = dt.week_number();
	assert(wn == 8);	// �ڰ���

	// ������(Julian day), ��ָ�ɹ�Ԫǰ4713��1��1��
	long l = dt.julian_day();	// �������յ������ж�����?
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
	assert(t.tm_year == 111);	// ��1900���
	assert(t.tm_mon == 1);		// ���1����0��ʼ����ʾ2�·�
	assert(t.tm_mday == 27);
	assert(t.tm_wday == 0);		// ���0���������տ�ʼ��
	assert(t.tm_yday == 57);	// ���57����0��ʼ�ƣ�58��
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

//date���췽��
//������ø���������ϵͳ, ֧�ִ�1400-Jan-01��9999-Dec-31.

void test_dt_construct()
{
	using namespace boost::gregorian;

	// 1. ����Ĺ��캯�������¼���:
	date d0;
	date d1(2008, 8, 9);	// ��õĹ��췽��
	date d2(d1);			// ���ƹ���
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

	// 2. ͨ���ַ�������
	date dstr1(from_string("2011/08/09"));
	date dstr2(from_string("2011-08-09"));
	date dstr3(from_string("2011-Feb-28"));
	date dstr4(from_string("2011-February-28"));
	date dstr5(from_undelimited_string("20110809"));

	// �����õ��ַ���
	date dstr6(from_us_string("Feb-28-2011"));	// �������·ݵ���Ҳ����
	date dstr7(from_uk_string("28-Feb-2011"));	// �������·ݵ���Ҳ����

												// 3. ͨ��clock����
	date dc1(day_clock::local_day());
	date dc2(day_clock::universal_day());

	// 4. ����ʱ���쳣
	try
	{
		// ��, ��, �ճ�����Χʱ�����쳣.
		date d6(1300, 12, 25);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

//date_duration��date_period
void test_date_duration()
{
	using namespace boost::gregorian;

	// �����ļ��ֹ��췽��
	{
		date_duration dd(3);

		days dd1(neg_infin);
		days dd2(pos_infin);
		days dd3(not_a_date_time);
		days dd4(max_date_time);
		days dd5(min_date_time);
	}

	// ������
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

	// ע�������Ĺ��캯��������ҿ�
	date_period dp1(date(2010, 11, 29), date(2010, 12, 1));
	date_period dp2(date(2010, 11, 29), days(2));
	date_period dp3(dp2);

	// ʱ������ƽ��3��(dp2 = 12.2-->12.4)
	dp2.shift(days(3));
	assert(dp2 == date_period(date(2010, 12, 2), date(2010, 12, 4)));

	// ʱ�����ǰ�����չ1��(dp3 = 11.28-->12.2)
	dp3.expand(days(1));
	assert(dp3 == date_period(date(2010, 11, 28), date(2010, 12, 2)));

	// begin, end, last
	assert(dp1.begin() == date(2010, 11, 29));
	// ע��end, last������ last�����һ��, end��ʱ��ε��ұ߽磨��������
	assert(dp1.end() == date(2010, 12, 1));
	assert(dp1.last() == date(2010, 11, 30));

	// ʱ��εĳ���
	// assert(dp1.length() == 2);

	// һЩ�жϺ���(����ֵ��bool)
	assert(!dp1.is_null());	// ����ʼʱ����ڽ���ʱ��
	assert(!dp1.contains(date(2010, 12, 1)));	// Ҳ���԰���ʱ���	
	bool b1 = dp3.intersects(dp1);	// ���˰���ʱ���֮��, �����԰���ʱ��ν��������
	assert(b1 == true);
	bool b2 = dp3.intersects(dp2);
	assert(b2 == false);
	// intersection��intersects��ͬ����: ���ķ���ֵ��date_period
	date_period dp4(date(2010, 11, 30), date(2010, 12, 3));
	dp4 = dp4.intersection(dp1);
	assert(dp4.begin() == date(2010, 11, 30));
	assert(dp4.end() == date(2010, 12, 1));

	// is_adjacent�ж�ʱ����Ƿ�����. �����ص�.
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

	// ʱ��κϲ�(merge), ����û���غ�(��������)��ʱ���, ���Ϊ��.
	date_period dp6 = dp1.merge(dp3);
	assert(dp6 == date_period(date(2010, 11, 28), date(2010, 12, 2)));

	// ʱ��κϲ�(span)
	// begin = min(p1.begin, p2.begin)
	// end = max(p1.end , p2.end)
	date_period dp7(date(2010, 12, 1), date(2010, 12, 5));
	date_period dp8(date(2010, 12, 9), date(2010, 12, 31));
	date_period dp9 = dp7.span(dp8); // 2002-Jan-01/2002-Jan-31
	assert(dp9 == date_period(date(2010, 12, 1), date(2010, 12, 31)));
	// ���: [2010-Dec-01/2010-Dec-30]
	std::cout << dp9 << std::endl;
}

//ͨ��date����һЩ���ͼ���ڼ���
void test_date_holiday()
{
	using namespace boost::gregorian;

	// �����Ľ���
	// ���׽�(Father's Day), ÿ��6�·ݵĵ�3��������
	typedef nth_day_of_the_week_in_month type_ndwm;
	type_ndwm ndwm(type_ndwm::third, 0, 6);
	date d1 = ndwm.get_date(2012);		// 2012�길�׽�
	std::cout << "���׽�: " << d1 << std::endl;

	// ĸ�׽�(Mother's Day), ÿ��5�·ݵĵ�2��������
	// ��������븸�׽ڵ�

	// �͹���(Labor Day), ÿ��9�·ݵĵ�һ������һ
	first_day_of_the_week_in_month fdwn(1, 9);
	date d2 = fdwn.get_date(2012);		// 2012���͹���
	std::cout << "�͹���: " << d2 << std::endl;

	// �ж���(Thanksgiving Day), ÿ��11�����һ��������
	last_day_of_the_week_in_month ldwn(4, 11);
	date d3 = ldwn.get_date(2012);
	std::cout << "�ж���: " << d3 << std::endl;

	// ʥ����(Christmas Day), ÿ��12��25��
	partial_date pd(25, 12);
	date d4 = pd.get_date(2012);
	std::cout << "ʥ����: " << d4 << std::endl;
}

#endif // !BOOST_TEST_DATE
