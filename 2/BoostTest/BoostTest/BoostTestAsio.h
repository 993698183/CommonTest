#pragma once
#ifndef BOOST_TEST_ASIO
#define BOOST_TEST_ASIO

#include <iostream>
#include <boost/asio.hpp>

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