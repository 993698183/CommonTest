#include "stdafx.h"
#include "CommonApi.h"
#include <memory>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

//根据boost的asio连接，确定本地ip和远端ip
#include "BoostAsio.h"
//根据boost的asio连接，确定本地ip和远端ip

struct Foo 
{
	Foo() { std::cout << "Foo\n"; }
	~Foo() { std::cout << "~Foo\n"; }
};

struct D
{
	void operator()(Foo *p)
	{
		std::cout << "calling delete for Foo object\n";
		delete p;
	}
};
void CommonApi::test_unique_ptr_get_release_reset()
{
	//unique_ptr的get方法和release方法

	//std::unique_ptr<T, Deleter>::get(C++11开始使用)
	//返回指向被管理对象的指针，如果无管理对象，则为nullptr
	std::unique_ptr<std::string> s_p(new std::string("hello world"));
	std::string *s = s_p.get();
	//std::cout << *s << std::endl;
	//std::cout << *s << std::endl;
	//release返回一个指向被管理对象的指针，并释放所有权(公开成员函数)（C++11开始使用）
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo> up(new Foo());
	std::cout << "about to release Foo\n";
	Foo *fp = up.release();
	assert(nullptr == up.get());
	std::cout << "Foo is nolonger own by unique_ptr\n";
	delete fp;
	//unique_ptr的get方法

	std::cout << "reset function\n";
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo, D> up1(new Foo(), D());//up1占有Foo指针和（删除器D）
	std::cout << "replace owned Foo with a new Foo\n";
	up1.reset(new Foo());//调用旧者的删除器

	std::cout << "release and delete the owned Foo\n";
	up1.reset(nullptr);
}

void CommonApi::test_computer_little_or_big_endian()
{
	int i = 0x12345678;
	if (0x12 == *((char *)&i))
	{
		std::cout << "Bid endian" << std::endl;
	}
	else
	{
		std::cout << "Little endian" << std::endl;
	}
}

void CommonApi::test_size_type_vector()
{
	std::vector<int> ivec1;
	ivec1.push_back(1);
	ivec1.push_back(2);

	std::vector<int>::size_type size1;
	size1 = ivec1.size();
}

void CommonApi::test_string_big_or_little()
{
	std::string str1 = "a";
	std::string str2 = "b";
	if (str1 < str2)
	{
		std::cout << "str1 is smaller than str2" << std::endl;
	}
}

//try...catch
double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (a / b);
}
//try...catch
void CommonApi::test_try_catch()
{
	int x = 50;
	int y = 0;
	double z = 0;

	try
	{
		z = division(x, y);
		std::cout << z << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
}

void CommonApi::test_boo_BOOL()
{
	BOOL bRet = TRUE;
	bool bRet2 = true;
	if (-1 == bRet)
	{
		int i = 0;
	}
	if (-1 == bRet2)
	{
		int i = 9;
	}
}

void CommonApi::test_boost_asio()
{
	CBoostAsio  *pboostasio = new CBoostAsio("192.168.3.112", 57603);
	pboostasio->SetIP();
	std::cout << "LocalClientIP=" << pboostasio->GetLocalClientIP() << std::endl;
	std::cout << "RemoteServerIP=" << pboostasio->GetRemoteServerIP() << std::endl;

	delete pboostasio;
	pboostasio = nullptr;
}

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
