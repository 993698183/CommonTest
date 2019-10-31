#pragma once
#ifndef BOOST_TEST_ANY
#define BOOST_TEST_ANY

/* 
any是一种特殊的容器，它只能容纳一个元素，但这个元素可以是任意类型;
可以用any保存任何类型，在任何需要的时候取出它;
这种功能和shared_ptr<void>类似，但是any是类型安全的;
any不是一个模板类，但是其有模板构造函数，从而实现任意类型;
空的any构造函数创建一个空的any对象，不持有任何值;
成员函数empty()可判断any是否为空;
成员函数swap(...)可交换两个any的值;
如果any持有一个对象，函数type()返回对象的type_info类型信息;
当容器的元素是any时，容器就像是一个可持有多个不同类型对象的动态tuple;
如果希望一种数据结构具有tuple那样的容纳任意类型的能力，又可在运行时动态变化大小，可以用any作为元素类型搭配容器.
更多用法请参考boost程序完全开发指南...
*/

/*
class any {
public:
// construct/copy/destruct
any();
any(const any &);
template<typename ValueType> any(const ValueType &);
any & operator=(const any &);
template<typename ValueType> any & operator=(const ValueType &);
~any();

// modifiers
any & swap(any &);

// queries
bool empty() const;
const std::type_info & type() const;
};
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include <boost/any.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assert.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;

//辅助函数
template<typename T>
bool can_cast(any &a)
{
	return typeid(T) == a.type();
}

template<typename T>
T& get(any& an)
{
	BOOST_ASSERT(can_cast<T>(an));
	return *any_cast<T>(&an);
}

template<typename T>
T* get_ptr(any & aaa)
{
	BOOST_ASSERT(can_cast<T>(aaa));
	return any_cast<T>(&aaa);
}

int test()
{
	any a1(10);
	int nInt = any_cast<int>(a1);
	assert(nInt == 10);

	any_cast<int&>(a1) = 20;
	assert(any_cast<int>(a1) == 20);

	any a2 = 100;
	a1.swap(a2);

	any aaa("str");
	a1.swap(aaa);

	try
	{
		any aa;
		if (aa.empty())
		{
			cout << "empty" << endl;
		}
		int n = any_cast<int>(aa);
	}
	catch (boost::exception&)
	{
		cout << "exception" << endl;
	}

	get<int>(a1) = 10;
	*get_ptr<int>(a1) = 20;

	//应用于容器
	vector<any> v1;
	v1.push_back(23);
	v1.push_back(3.145);
	v1.push_back("Michael Joessy");

	vector<any> v2 = list_of<any>(10)(6.18)("string");
	return 0;
}
#endif
