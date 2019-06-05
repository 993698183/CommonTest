#include "stdafx.h"
#include "BoostAsio.h"


CBoostAsio::CBoostAsio()
{
}


CBoostAsio::CBoostAsio(const std::string ip, const unsigned int port)
{
	this->m_ServerIP = ip;
	this->m_PortNum = port;
}

CBoostAsio::~CBoostAsio()
{
}

void CBoostAsio::SetIP()
{
	try
	{
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::socket socket(io_service);
		socket.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(m_ServerIP.c_str()), m_PortNum));

		m_strLocalClientIP = socket.local_endpoint().address().to_string();
		m_strRemoteServerIP = socket.remote_endpoint().address().to_string();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::string CBoostAsio::GetLocalClientIP()
{
	return m_strLocalClientIP;
}

std::string CBoostAsio::GetRemoteServerIP()
{
	return m_strRemoteServerIP;
}
