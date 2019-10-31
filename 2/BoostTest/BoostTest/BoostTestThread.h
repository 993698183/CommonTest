#pragma once
#ifndef BOOST_TEST_THREAD
#define BOOST_TEST_THREAD

#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>

void wait(int seconds)
{
	boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void hello()
{
	while (1)
	{
		wait(1);
		std::cout << "hello multi-thread" << std::endl;
	}
}

void test_thread()
{
	boost::thread thrd(&hello);
	thrd.join();
}

boost::mutex g_io_mutex;
void count(int id)
{
	for (int i = 0; i < 10; i++)
	{
		boost::mutex::scoped_lock lock(g_io_mutex);
		std::cout << id << ":" << i << std::endl;
	}
}

void test_thread_mutex()
{
	boost::thread thrd1(boost::bind(&count, 1));
	boost::thread thrd2(boost::bind(&count, 1));
	thrd1.join();
	thrd2.join();
}

#endif