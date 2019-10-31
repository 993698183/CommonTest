#pragma once
#ifndef BOOST_TEST_THREAD
#define BOOST_TEST_THREAD

#include <iostream>
#include <string>
#include <boost/thread.hpp>

void wait(int seconds)
{
	boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}
#endif