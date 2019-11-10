#pragma once
#ifndef BOOST_TEST_ASIO
#define BOOST_TEST_ASIO

#include <iostream>
#include <boost/asio.hpp>

//ASIO,基于操作系统的异步机制，可有效避免多线程编程的诸多副作用
//定时器的实现
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/bind.hpp>

void async_timer_callback(asio::deadline_timer* async_timer, int async_count, const system::error_code& err)
{
	if (err)
	{
		std::cout << "async_timer.async_wait err = " << err.message() << std::endl;
	} 
	else
	{
		std::cout << "async_timer async_count =" << async_count << "now expires_from_now=" << async_timer->expires_from_now() << std::endl;
		if (--async_count > 0)
		{
			async_timer->expires_at(async_timer->expires_at() + posix_time::milliseconds(500));
			async_timer->async_wait(boost::bind(async_timer_callback, async_timer, async_count, asio::placeholders::error));
		}
	}
}

void handler(const boost::system::error_code &ec)
{
	std::cout << "5s" << std::endl;
}

void test_asio_handler()
{
	boost::asio::io_service io_service;
	boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
	timer.async_wait(handler);
	io_service.run();
}

#endif