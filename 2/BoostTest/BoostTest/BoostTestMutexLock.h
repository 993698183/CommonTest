#pragma once
#ifndef BOOST_TEST_MUTEX_LOCK
#define BOOST_TEST_MUTEX_LOCK

#include <iostream>
#include <string>

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
//#include <boost/thread/shared_lock_guard.hpp>

/*
	mutex对象类：
		mutex：独占式的互斥量，是最简单最常用的一种互斥量类型
		try_mutex：它是mutex的同义词，为了兼容以前的版本而提供
		timed_mutex：它是独占式的互斥量，但是提供超时锁定功能
*/

boost::mutex g_mutex;
boost::recursive_mutex g_recursive_mutex;
void thread1()
{
	std::cout << "enter thread1" << std::endl;
	boost::lock_guard<boost::mutex> lock(g_mutex);
	std::cout << "excute thread1" << std::endl;
}

void thread2()
{
	std::cout << "enter thread2" << std::endl;
	boost::lock_guard<boost::mutex> lock(g_mutex);
	thread1();
	std::cout << "excute thread2" << std::endl;
}

void thread3()
{
	std::cout << "enter thread3" << std::endl;
	boost::recursive_mutex::scoped_lock lock(g_recursive_mutex);
	//下面的写法也是可以
	//boost::lock_guard<boost::recursive_mutex> lock(g_recursive_mutex);
	std::cout << "excute thread3" << std::endl;
}

void thread4()
{
	std::cout << "enter thread4" << std::endl;
	boost::recursive_mutex::scoped_lock lock(g_recursive_mutex);
	thread3();
	std::cout << "excuter thread4" << std::endl;
}

//测试死锁例子
void test_thread_deadlock()
{
	thread2();
}

//利用递归互斥量来避免找个问题
void test_thread_recursivelock()
{
	thread4();
}

#endif
