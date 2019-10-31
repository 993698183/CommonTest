#pragma once
#ifndef BOOST_TEST_FUNCTION
#define BOOST_TEST_FUNCTION

#include <iostream>
#include <string>
#include <boost/function.hpp>

int fsum(int i, int j)
{
	return i + j;
}

class Person
{
public:
	void operator()(std::string name, int age)
	{
		std::cout << name << ":" << age << std::endl;
	}
protected:
private:
};

class Car
{
public:
	Car() {};
	virtual ~Car(){};
	void info(int i)
	{
		std::cout << "info=" << i << std::endl;
	}
protected:
private:
};

void test_function()
{
	//��ͨ����
	boost::function<int(int, int)> func1;
	func1 = fsum;
	std::cout << "4+5=" << func1(4, 5) << std::endl;

	//��������
	boost::function<void(std::string, int)> func2;
	Person person;
	func2 = person;
	func2("myname", 30);

	//��Ա����
	boost::function<void(Car*, int)> func3;
	func3 = &Car::info;
	Car car;
	func3(&car, 25);

	//�պ���
	boost::function<int(int, int)> func4;
	assert(func4.empty());
	assert(!func1.empty());
	func1.clear();
	assert(func1.empty());
	try
	{
		func1(4, 5);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

#endif
