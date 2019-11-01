#pragma once
#ifndef BOOST_TEST_MUTEX_LOCK
#define BOOST_TEST_MUTEX_LOCK

#include <iostream>
#include <string>

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
//#include <boost/thread/shared_lock_guard.hpp>

/*
	mutex�����ࣺ
		mutex����ռʽ�Ļ��������������õ�һ�ֻ���������
		try_mutex������mutex��ͬ��ʣ�Ϊ�˼�����ǰ�İ汾���ṩ
		timed_mutex�����Ƕ�ռʽ�Ļ������������ṩ��ʱ��������
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
	//�����д��Ҳ�ǿ���
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

//������������
void test_thread_deadlock()
{
	thread2();
}

//���õݹ黥�����������Ҹ�����
void test_thread_recursivelock()
{
	thread4();
}

#endif
