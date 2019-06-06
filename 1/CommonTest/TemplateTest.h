#pragma once

#ifndef TEMPLATETEST_H
#endif TEMPLATETEST_H

//https://www.cnblogs.com/sevenyuan/p/3154346.html
//---------��ģ��---------------
template<typename T1, typename T2>

class MyClass
{
public:
	MyClass(T1 a, T2 b);//���캯��
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
//---------��ģ��---------------


//---------����ģ��-------------
template <typename T>
T min(T x, T y)
{
	return (x < y) ? x : y;
}
//---------����ģ��-------------

class TemplateTest
{
public:
	static void test_template_class_function();
	TemplateTest();
	~TemplateTest();
};

