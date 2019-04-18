#pragma once
#include <iostream>
//����boost��asio���ӣ�ȷ������ip��Զ��ip
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>  
using boost::asio::ip::tcp;
//����boost��asio���ӣ�ȷ������ip��Զ��ip
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

