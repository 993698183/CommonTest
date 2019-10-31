#pragma once
#ifndef BOOST_TEST_ANY
#define BOOST_TEST_ANY

/* 
any��һ���������������ֻ������һ��Ԫ�أ������Ԫ�ؿ�������������;
������any�����κ����ͣ����κ���Ҫ��ʱ��ȡ����;
���ֹ��ܺ�shared_ptr<void>���ƣ�����any�����Ͱ�ȫ��;
any����һ��ģ���࣬��������ģ�幹�캯�����Ӷ�ʵ����������;
�յ�any���캯������һ���յ�any���󣬲������κ�ֵ;
��Ա����empty()���ж�any�Ƿ�Ϊ��;
��Ա����swap(...)�ɽ�������any��ֵ;
���any����һ�����󣬺���type()���ض����type_info������Ϣ;
��������Ԫ����anyʱ������������һ���ɳ��ж����ͬ���Ͷ���Ķ�̬tuple;
���ϣ��һ�����ݽṹ����tuple�����������������͵��������ֿ�������ʱ��̬�仯��С��������any��ΪԪ�����ʹ�������.
�����÷���ο�boost������ȫ����ָ��...
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

//��������
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

	//Ӧ��������
	vector<any> v1;
	v1.push_back(23);
	v1.push_back(3.145);
	v1.push_back("Michael Joessy");

	vector<any> v2 = list_of<any>(10)(6.18)("string");
	return 0;
}
#endif
