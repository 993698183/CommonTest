#pragma once
#ifndef BOOT_TEST_BIND
#define BOOT_TEST_BIND
#include <iostream>
#include <boost/bind.hpp>

int f(int a, int b)
{
	return a + b;
}

int g(int a, int b, int c)
{
	return a + b + c;
}

// 函数指针定义
typedef int(*f_type) (int, int);
typedef int(*g_type) (int, int, int);

// 使用struct仅仅是为了方便, 不必写出public
struct demo
{
	int f(int a, int b)
	{
		return a + b;
	}
};

// 函数对象
struct sf
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test_bind_common()
{
	std::cout << boost::bind(f, 1, 2)() << std::endl;
	std::cout << boost::bind(g, 1, 2, 3)() << std::endl;
}

// 1. 普通函数应用boost::bind
void test_bind_fun1()
{
	// 	bind(f, _1, 9)(x);	           // f(x, 9), 相当于bind2nd(f, 9)
	// 	bind(f, _1, _2)(x, y);	       // f(x, y)
	// 	bind(f, _2, _1)(x, y);         // f(y, x)
	// 	bind(f, _1, _1)(x, y);         // f(x, x), y参数被忽略
	// 	bind(g, _1, 8, _2)(x, y);      // g(x, 8, y)
	// 	bind(g, _3, _2, _2)(x, y, z);  // g(z, y, y), x参数被忽略

	int x = 1, y = 2, z = 3;
	std::cout << boost::bind(f, _1, 9)(x) << std::endl;
	std::cout << boost::bind(f, _1, _2)(x, y) << std::endl;
	std::cout << boost::bind(f, _2, _1)(x, y) << std::endl;
	std::cout << boost::bind(f, _1, _1)(x, y) << std::endl;
	std::cout << boost::bind(g, _1, 8, _2)(x, y) << std::endl;
	std::cout << boost::bind(g, _3, _2, _2)(x, y, z) << std::endl;
}

// 2. 成员函数应用boost::bind
void test_bind_fun2()
{
	demo a, &ra = a;
	demo *p = &a;

	// 必须在成员函数前加上取地址操作符&, 表明这是一个成员函数指针
	// 第二个参数用struct demo, struct demo * 两个类型都可以
	std::cout << boost::bind(&demo::f, a, _1, 20)(10) << std::endl;
	std::cout << boost::bind(&demo::f, ra, _2, _1)(10, 20) << std::endl;
	std::cout << boost::bind(&demo::f, p, _1, _2)(10, 20) << std::endl;
}

// 3. 成员变量
void test_bind_val()
{
	typedef std::pair<int, std::string> pair_t;
	pair_t p(123, "string");
	std::cout << boost::bind(&pair_t::first, p)() << std::endl;
	std::cout << boost::bind(&pair_t::second, p)() << std::endl;
}

// 4. 函数对象
void test_bind_functor()
{
	std::cout << boost::bind(std::plus<int>(), _1, _2)(10, 20) << std::endl;
	std::cout << boost::bind(std::modulus<int>(), _1, 3)(11) << std::endl;
	std::cout << std::boolalpha << boost::bind(std::greater<int>(), _1, 10)(20) << std::endl;

	std::cout << boost::bind<int>(sf(), _1, _2)(11, 22) << std::endl;
}

// 可以使用ref库包装了对象的引用，可以让bind 存储对象引用的拷贝，从而降低了拷贝的代价。
void test_bind_ref()
{
	// 变量
	int x = 10;
	// 11 + 10 + 10
	std::cout << boost::bind(g, _1, boost::cref(x), boost::ref(x))(11) << std::endl;

	// 一个函数对象
	sf af;
	std::cout << boost::bind<int>(boost::ref(af), _1, _2)(11, 22) << std::endl;
}

#endif