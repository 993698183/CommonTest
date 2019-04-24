#include "stdafx.h"
#include "BoostTest.h"


BoostTest::BoostTest()
{
}


BoostTest::~BoostTest()
{
}

int BoostTest::get_sec()
{
	boost::timer t;
	double dTime = 0.0;
	while (true)
	{
		dTime = t.elapsed();
		std::cout << dTime << std::endl;
		Sleep(1000);
	}
}

void BoostTest::test_timer()
{
	// 声明一个计时器对象，并开始计时!
	boost::timer t;

	long long sum = 0;
	for (int i = 0; i < 1000000; i++)
	{
		sum = sum + i;
	}

	// 计算时间差, 测量自对象创建后所流逝的时间。
	double dl = t.elapsed();
	std::cout << "now time elapsed:" << dl << std::endl;

	//可度量的最大时间，以秒为单位	
	std::cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << std::endl;
	//可度量的最小时间，以秒为单位
	std::cout << "min timespan:" << t.elapsed_min() << "s" << std::endl;

	// 还有一个restart()开始重新计时
	t.restart();
}

void BoostTest::test_progress_timer()
{
	{
		boost::progress_timer pt;

		long long sum = 0;
		for (int i = 0; i < 10000000; i++)
			sum = sum + i;
	}

	//pt.elapsed();

	// 另外一种方法，不要用el
	{
		boost::progress_timer pt;
		// do_something();
		long long sum2 = 0;
		for (int i = 0; i < 10000000; i++)
			sum2 = sum2 + i;
	}   // pt析构时自动输出流逝时间
}

void BoostTest::test_progress_display()
{
	std::vector<std::string> v(1000000, "昝续路");
	std::ofstream fs("E:\\display.txt");

	// 声明一个progress_display 对象，基数是v的大小
	boost::progress_display pd(v.size());

	// 开始选代遍历向量，处理字符串
	std::vector<std::string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << std::endl;
		++pd; // 更新进度显示
	}
}

void BoostTest::test_progress_display_restart()
{
	std::vector<std::string> v(100, "abcd");
	v[10] = "";
	v[23] = "";
	std::ofstream fs("d:\\test.txt");
	boost::progress_display pd(v.size());
	std::vector<std::string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << std::endl;
		++pd;
		if (pos->empty())
		{
			std::cout << std::endl;
			std::cout << "Error: null string # " << (pos - v.begin()) << std::endl;
			pd.restart(v.size());
			pd += (pos - v.begin() + 1);
		}
	}
}
