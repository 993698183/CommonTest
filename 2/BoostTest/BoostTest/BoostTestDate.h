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

#endif // !BOOST_TEST_DATE
