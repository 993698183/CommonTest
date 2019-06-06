#pragma once

#ifndef TEMPLATETEST_H
#endif TEMPLATETEST_H

//https://www.cnblogs.com/sevenyuan/p/3154346.html
//---------类模板---------------
template<typename T1, typename T2>

class MyClass
{
public:
	MyClass(T1 a, T2 b);//构造函数
	void show();
protected:
private:
	T1 I;
	T2 J;
};

template<typename T1, typename T2>
MyClass<T1, T2>::MyClass(T1 a, T2 b)
{
	I = a;
	J = b;
}

template<typename T1, typename T2>
void MyClass<T1, T2>::show()
{
	std::cout << "I=" << I << "J=" << J << std::endl;
}
//---------类模板---------------


//---------函数模板-------------
template <typename T>
T min(T x, T y)
{
	return (x < y) ? x : y;
}
//---------函数模板-------------

class TemplateTest
{
public:
	static void test_template_class_function();
	TemplateTest();
	~TemplateTest();
};

