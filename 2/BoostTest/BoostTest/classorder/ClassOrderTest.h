#pragma once
#ifndef CLASS_TEST_ORDER
#define CLASS_TEST_ORDER

#include <iostream>
#include <string>

class c
{
public:
	c() { std::cout << "c" << std::endl; }
	~c() { std::cout << "destory c" << std::endl; }
protected:
private:
};

class b
{
public:
	b() { std::cout << "b" << std::endl; }
	~b() { std::cout << "destory b" << std::endl; }
protected:
	c C;
private:
};

class a :public b
{
public:
	a() { std::cout << "a" << std::endl; }
	~a() { std::cout << "destory a" << std::endl; }
protected:
private:
};

void test_class_order()
{
	//C++遵循如下创建顺序
	//1：如果某个类有具体基类，执行默认构造函数
	//2：类的非静态数据成员，按照声明顺序创建
	//3：执行该类的构造函数
	//构造类时，会先构造其父类，然后创建类成员，最后调用本身构造函数
	a A;
}

#endif 