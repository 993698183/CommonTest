#pragma once
#include <iostream>
//根据boost的asio连接，确定本地ip和远端ip
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>  
using boost::asio::ip::tcp;
//根据boost的asio连接，确定本地ip和远端ip
class CBoostAsio
{
public:
	CBoostAsio();
	CBoostAsio(const std::string ip, const unsigned int port);
	~CBoostAsio();
	void SetIP();
	std::string GetLocalClientIP();
	std::string GetRemoteServerIP();
private:
	std::string m_ServerIP;
	unsigned int m_PortNum;
	std::string m_strLocalClientIP;
	std::string m_strRemoteServerIP;
};

