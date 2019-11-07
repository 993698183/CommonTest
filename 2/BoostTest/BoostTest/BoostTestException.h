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
	//boost::system::error_code���͵�һ�����������Ϊ�����Ĳ������ݸ�boost::asio::ip::host_name()�������ǰ�Ĳ���ϵͳ����ʧ�ܣ��������������صĴ������
	//Ҳ����ͨ������boost::asio::ip::host_name()���������κβ������Է�ֹ��������Ƿ���ص�
	std::string hostname = boost::asio::ip::host_name(ec);
	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
}

//ͨ������һ��������boost::system::error_category�����Լ�ʵ����Ϊ�·����������ĽӿڵĲ�ͬ�������Զ���һ���µĴ������
//����name������message��������boost::system::error_category�б�����Ϊ���麯���������������б���ʵ��
//���ڶ���ķ������ڱ�Ҫ�������£������������Ӧ��Ĭ����Ϊ
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
		throw allocation_failed(size);
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
