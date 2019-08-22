// CommonTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CommonApi.h"
//根据boost的asio连接，确定本地ip和远端ip
#include "BoostAsio.h"
//根据boost的asio连接，确定本地ip和远端ip

#include "BoostTest.h"

//boost::filesystem::is_directory异常捕获
#include <iostream>
#include <boost/filesystem.hpp>
//boost::filesystem::is_directory异常捕获

//测试类模板
#include "TemplateTest.h"
//测试类模板

enum EKeyRemarkFunSwitch
{
	eIsHideClientIcon = 0,
	eIsFileUpload,
	eIsFileMonitor,
	eIsOuterReport,

	eFuncMax,
};

int CharToNumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	if (c >= 'a' && c <= 'f')
	{
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'F')
	{
		return c - 'A' + 10;
	}

	return 0;
}
char szRemark[] = "000000000000000000000000000011";
bool IsBitSetInRemark(int bitPos)
{
	std::cout << "bitPos = " << bitPos << std::endl;
	int n1 = bitPos >> 2;
	std::cout << "（bitPos >> 2）n1 = " << n1 << std::endl;
	int arrayPos = 28 - n1;
	if (arrayPos < 0 || arrayPos > 28)
	{
		return false;
	}
	int bitVal = CharToNumber(szRemark[arrayPos]);
	std::cout << "bitVal = " << bitVal << std::endl;

	int n2 = bitPos & 0x3;
	std::cout << "（bitPos & 0x3）n2 = " << n2 << std::endl;
	int n3 = bitVal & n2;
	std::cout << "（bitVal & n2）n3 = " << n3 << std::endl;
	if (n3)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

#define A "123"
#define B "456"

int main()
{	
	if (0)
	{
		char *p = A B;
		std::cout << p << std::endl;
		system("pause");
	}
	if (0)
	{
		int nFuncSwitchVal = 0;
		for (int i = 0; i < eFuncMax; i++)
		{
			if (IsBitSetInRemark(i))
			{
				int a1 = 0x1 << i;
				std::cout << "（0x1 << i）= " << a1 << std::endl;
				nFuncSwitchVal |= a1;
				std::cout << "nFuncSwitchVal = " << nFuncSwitchVal << std::endl;
			}
		}
		system("pause");
	}
	if (0)
	{
		CommonApi::test_vfprintf();
		system("pause");
	}
	if (0)
	{
		CommonApi::test_unordered_map();
		system("pause");
	}
	if (0)
	{
		BoostTest test;
		//test.get_sec();
		//test.test_timer();
		//test.test_progress_timer();
		//test.test_progress_display();
		//test.test_progress_display_restart();
		std::wstring wstrpath = L"E:\\1_ZXLCode\\1_QT\\1\\CH1\\CH101\\";
		test.show_file(wstrpath);
		system("pause");
	}

	//根据boost的asio连接，确定本地ip和远端ip
	if (0)
	{
		CBoostAsio  *pboostasio = new CBoostAsio("192.168.3.112", 57603);
		pboostasio->SetIP();
		std::cout << "LocalClientIP=" << pboostasio->GetLocalClientIP() << std::endl;
		std::cout << "RemoteServerIP=" << pboostasio->GetRemoteServerIP() << std::endl;

		delete pboostasio;
		pboostasio = nullptr;
		system("pause");
	}
	//根据boost的asio连接，确定本地ip和远端ip

    return 0;
}

