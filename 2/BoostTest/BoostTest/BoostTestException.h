#pragma once
#ifndef BOOST_TEST_EXCEPTION
#define BOOST_TEST_EXCEPTION

#include <iostream>
#include <string>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>

void test_error()
{
	boost::system::error_code ec;
	//boost::system::error_code类型的一个对象可以作为单独的参数传递给boost::asio::ip::host_name()。如果当前的操作系统函数失败，这个参数包含相关的错误代码
	//也可以通过调用boost::asio::ip::host_name()而不适用任何参数，以防止错误代码是非相关的
	std::string hostname = boost::asio::ip::host_name(ec);
	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
}

//通过创建一个派生于boost::system::error_category的类以及实现作为新分类的所必须的接口的不同方法可以定义一个新的错误分类
//由于name（）和message（）在类boost::system::error_category中被定义为纯虚函数，所以在子类中必须实现
//至于额外的方法，在必要的条件下，可以重载相对应的默认行为
class application_category:
	public boost::system::error_category
{
public:
	const char *name() const BOOST_SYSTEM_NOEXCEPT
	{
		return "application";
	}
	std::string message(int ev) const
	{
		return "error message";
	}
protected:
private:
};

application_category cat;
void test_error2()
{
	boost::system::error_code ec(14, cat);
	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
}

void test_error3()
{
	try
	{
		std::cout << boost::asio::ip::host_name() << std::endl;
	}
	catch (boost::system::system_error &e)
	{
		boost::system::error_code ec = e.code();
		std::cerr << ec.value() << std::endl;
		std::cerr << ec.category().name() << std::endl;
	}
}

#include <boost/exception/all.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_array.hpp>
#include <exception>

typedef boost::error_info<struct tag_errmsg, std::string> errmsg_info;

class allocation_failed:
	public boost::exception,
	public std::exception
{
public:
	allocation_failed(std::size_t size)
		:what_("allocation of " + boost::lexical_cast<std::string>(size) + " bytes failed")
	{

	}
	virtual const char *what() const throw()
	{
		return what_.c_str();
	}
protected:
private:
	std::string what_;
};

boost::shared_array<char> allocate(std::size_t size)
{
	if (size > 1000)
	{
		//throw allocation_failed(size);
		//通过使用BOOST_THROW_EXCEPTION替代throw，如函数名、文件名、行数之类附加信息将自动被添加到异常中。
		//但这仅仅在编译器支持宏的情况下有效
		BOOST_THROW_EXCEPTION(allocation_failed(size));
	}
	return boost::shared_array<char>(new char[size]);
}

void save_configuration_data()
{
	try
	{
		boost::shared_array<char> a = allocate(2000);
	}
	catch (boost::exception &e)
	{
		e << errmsg_info("saving configuration data failed");
		throw;
	}
}

void test_error4()
{
	try
	{
		save_configuration_data();
	}
	catch (boost::exception &e)
	{
		std::cerr << boost::diagnostic_information(e);
	}
}

#endif
