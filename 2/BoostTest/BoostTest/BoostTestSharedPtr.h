#pragma once
#ifndef BOOST_TEST_SHARED_PTR
#define BOOST_TEST_SHARED_PTR
#include <iostream>
#include <string>

void test_1()
{
	std::cout << "test shared_ptr base usage:" << std::endl;
	std::shared_ptr<std::string> p1 = make_shared<std::string>("");
	if (p1 && p1->empty())
	{
		*p1 = "hello";
	}
	auto p2 = make_shared<std::string>("world");
	std::cout << *p1 << " " << *p2 << std::endl;

	std::cout << "test shared_ptr use_count:" << std::endl;
	std::cout << "p1 cnt:" << p1.use_count() << "\t p2 cnt:" << p2.use_count() << std::endl;

	auto p3 = p2;
	cout << "p1 cnt:" << p1.use_count() << "\t p2 cnt:" << p2.use_count() << "\t p3 cnt:" << p3.use_count() << std::endl;

	p2 = p1;
	std::cout << "p1 cnt:" << p1.use_count() << "\t p2 cnt:" << p2.use_count() << "\t p3 cnt:" << p3.use_count() << std::endl;
}

void test_sharedptr_new()
{
	std::cout << "test shared_ptr and new:" << std::endl;
	std::shared_ptr<int> p4(new int(1024));
	std::cout << *p4 << std::endl;
}

#endif