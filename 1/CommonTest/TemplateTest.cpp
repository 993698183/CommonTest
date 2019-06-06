#include "stdafx.h"
#include "TemplateTest.h"
#include <iostream>

void TemplateTest::test_template_class_function()
{
	MyClass<int, int> class1(1, 3);
	class1.show();

	MyClass<int, char> class2(3, 'a');
	class2.show();

	MyClass<double, int> class3(3.9, 10);
	class3.show();

	int x = 2;
	int y = 4;
	double a = 1.0;
	double b = 2.0;

	std::cout << "x=2,y=4" << min(x, y) << std::endl;
	std::cout << "a=1.0,b=2.0" << min(a, b) << std::endl;
}

TemplateTest::TemplateTest()
{
}


TemplateTest::~TemplateTest()
{
}
