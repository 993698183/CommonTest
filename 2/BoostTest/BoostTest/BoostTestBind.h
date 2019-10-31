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

// ����ָ�붨��
typedef int(*f_type) (int, int);
typedef int(*g_type) (int, int, int);

// ʹ��struct������Ϊ�˷���, ����д��public
struct demo
{
	int f(int a, int b)
	{
		return a + b;
	}
};

// ��������
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

// 1. ��ͨ����Ӧ��boost::bind
void test_bind_fun1()
{
	// 	bind(f, _1, 9)(x);	           // f(x, 9), �൱��bind2nd(f, 9)
	// 	bind(f, _1, _2)(x, y);	       // f(x, y)
	// 	bind(f, _2, _1)(x, y);         // f(y, x)
	// 	bind(f, _1, _1)(x, y);         // f(x, x), y����������
	// 	bind(g, _1, 8, _2)(x, y);      // g(x, 8, y)
	// 	bind(g, _3, _2, _2)(x, y, z);  // g(z, y, y), x����������

	int x = 1, y = 2, z = 3;
	std::cout << boost::bind(f, _1, 9)(x) << std::endl;
	std::cout << boost::bind(f, _1, _2)(x, y) << std::endl;
	std::cout << boost::bind(f, _2, _1)(x, y) << std::endl;
	std::cout << boost::bind(f, _1, _1)(x, y) << std::endl;
	std::cout << boost::bind(g, _1, 8, _2)(x, y) << std::endl;
	std::cout << boost::bind(g, _3, _2, _2)(x, y, z) << std::endl;
}

// 2. ��Ա����Ӧ��boost::bind
void test_bind_fun2()
{
	demo a, &ra = a;
	demo *p = &a;

	// �����ڳ�Ա����ǰ����ȡ��ַ������&, ��������һ����Ա����ָ��
	// �ڶ���������struct demo, struct demo * �������Ͷ�����
	std::cout << boost::bind(&demo::f, a, _1, 20)(10) << std::endl;
	std::cout << boost::bind(&demo::f, ra, _2, _1)(10, 20) << std::endl;
	std::cout << boost::bind(&demo::f, p, _1, _2)(10, 20) << std::endl;
}

// 3. ��Ա����
void test_bind_val()
{
	typedef std::pair<int, std::string> pair_t;
	pair_t p(123, "string");
	std::cout << boost::bind(&pair_t::first, p)() << std::endl;
	std::cout << boost::bind(&pair_t::second, p)() << std::endl;
}

// 4. ��������
void test_bind_functor()
{
	std::cout << boost::bind(std::plus<int>(), _1, _2)(10, 20) << std::endl;
	std::cout << boost::bind(std::modulus<int>(), _1, 3)(11) << std::endl;
	std::cout << std::boolalpha << boost::bind(std::greater<int>(), _1, 10)(20) << std::endl;

	std::cout << boost::bind<int>(sf(), _1, _2)(11, 22) << std::endl;
}

// ����ʹ��ref���װ�˶�������ã�������bind �洢�������õĿ������Ӷ������˿����Ĵ��ۡ�
void test_bind_ref()
{
	// ����
	int x = 10;
	// 11 + 10 + 10
	std::cout << boost::bind(g, _1, boost::cref(x), boost::ref(x))(11) << std::endl;

	// һ����������
	sf af;
	std::cout << boost::bind<int>(boost::ref(af), _1, _2)(11, 22) << std::endl;
}

#endif