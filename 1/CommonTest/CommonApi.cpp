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
	//unique_ptr��get������release����

	//std::unique_ptr<T, Deleter>::get(C++11��ʼʹ��)
	//����ָ�򱻹�������ָ�룬����޹��������Ϊnullptr
	std::unique_ptr<std::string> s_p(new std::string("hello world"));
	std::string *s = s_p.get();
	//std::cout << *s << std::endl;
	//std::cout << *s << std::endl;
	//release����һ��ָ�򱻹�������ָ�룬���ͷ�����Ȩ(������Ա����)��C++11��ʼʹ�ã�
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo> up(new Foo());
	std::cout << "about to release Foo\n";
	Foo *fp = up.release();
	assert(nullptr == up.get());
	std::cout << "Foo is nolonger own by unique_ptr\n";
	delete fp;
	//unique_ptr��get����

	std::cout << "reset function\n";
	std::cout << "creat new Foo\n";
	std::unique_ptr<Foo, D> up1(new Foo(), D());//up1ռ��Fooָ��ͣ�ɾ����D��
	std::cout << "replace owned Foo with a new Foo\n";
	up1.reset(new Foo());//���þ��ߵ�ɾ����

	std::cout << "release and delete the owned Foo\n";
	up1.reset(nullptr);
}

CommonApi::CommonApi()
{
}


CommonApi::~CommonApi()
{
}
