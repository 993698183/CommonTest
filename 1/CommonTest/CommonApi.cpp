#include "stdafx.h"
#include "CommonApi.h"
#include <memory>
#include <iostream>
#include <cassert>

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

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
