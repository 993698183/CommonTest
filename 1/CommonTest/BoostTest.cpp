#include "stdafx.h"
#include "BoostTest.h"

//const的使用
class A
{
public:
	//构造函数
	A():a(0) {};
	A(int x):a(x) {};//初始化列表

	//const还可以用作对重载函数的区分
	int getValue();//普通成员函数
	int getValue() const;//常成员函数，不得修改任何类中的任何数据成员的值
protected:
private:
	const int a;//常对象成员，只能在初始化列表中使用
};

void function()
{
	//对象
	A b;//普通对象，可以调用全部成员函数
	const A a;//常对象，只能调用常成员函数，更新常成员变量
	const A *p = &a;//常指针
	const A &q = a;//常引用

	char greeting[] = "Hello";
	char *p1 = greeting;//指针变量，指向字符数组变量
	const char *p2 = greeting;//指针变量，指向字符数组常量
	char *const p3 = greeting;//常指针，指向字符数组常量
	const char * const p4 = greeting;//常指针，指向字符数组常量
}

//函数
void function1(const int Var);//传递过来的参数在函数内不可变
void function2(const char* Var);//参数指针所指内容为常量
void function3(char * const Var);//参数指针为常指针
void function4(const int &Var);//引用参数在函数内为常量

//函数返回值
const int function5();//返回一个常数
const int* function6();//返回一个指向常量的指针变量
int* const function7();//返回一个指向变量的常指针

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
		{
			sum = sum + i;
		}
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

void BoostTest::show_file(const boost::filesystem::wpath &path)
{
	std::wstring cmd = L"/select,";
	cmd += path.c_str();
	ShellExecuteW(NULL, NULL, L"explorer", cmd.c_str(), NULL, SW_NORMAL);
}
