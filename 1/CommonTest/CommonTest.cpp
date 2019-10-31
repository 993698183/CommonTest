// CommonTest.cpp : Defines the entry point for the console application.
//

#pragma warning(disable:4996)

#include "stdafx.h"
#include "CommonApi.h"
//根据boost的asio连接，确定本地ip和远端ip
#include "BoostAsio.h"
//根据boost的asio连接，确定本地ip和远端ip

#include "BoostTest.h"

//boost::filesystem::is_directory异常捕获
//文件流操作
#include <iostream> 
#include <fstream> 
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

////unicode转gbk
//std::string UnicodeToGbk(const std::string& strGbk)// 传入的strGbk是GBK编码 
//{
//	return code_convert("UCS-2LE", "gb2312", strGbk);
//}
WCHAR * UTF_8ToUnicode(char *pText, WCHAR &unicode)
{
	/*
	UTF-8是一种多字节编码的字符集，表示一个Unicode字符时，它可以是1个至多个字节，在表示上有规律：
	1字节：0xxxxxxx
	2字节：110xxxxx 10xxxxxx
	3字节：1110xxxx 10xxxxxx 10xxxxxx
	4字节：11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	*/
	char *uchar = (char *)&unicode;
	uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
	uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);
	return &unicode;
}

char * UnicodeToGB2312(WCHAR uData, char buffer[2])
{
	WideCharToMultiByte(CP_ACP, NULL, &uData, 1, buffer, sizeof(WCHAR), NULL, NULL);
	return buffer;
}

char * TranslateUTF8ToGB(char *str, size_t len)
{
	char * newCharBuffer = new char[len];
	int index = 0;
	int nCBIndex = 0;
	WCHAR wTemp = 0;
	char cTemp[2] = " ";
	while (index < len)
	{
		if (str[index] == 0)
			break;
		else if (str[index] > 0)  // 如果是GB2312的字符  
		{
			newCharBuffer[nCBIndex] = str[index];    //直接复制  
			index += 1;    //源字符串偏移量1  
			nCBIndex += 1;   //目标字符串偏移量1  
		}
		else      //如果是UTF-8的字符  
		{
			UTF_8ToUnicode(str + index, wTemp);   //先把UTF-8转成Unicode  
			UnicodeToGB2312(wTemp, &newCharBuffer[nCBIndex]); //再把Unicode 转成 GB2312  
			index += 3;    //源字符串偏移量3  
			nCBIndex += 2;   //目标字符串偏移量2  因为一个中文UTF-8占3个字节，GB2312占两个字节  
		}
	}
	newCharBuffer[nCBIndex] = '\0'; //结束符  
	strcpy_s(str, strlen(newCharBuffer) + 1, newCharBuffer);
	delete newCharBuffer;  //避免内存泄漏，这是对源代码的稍许修改  
	newCharBuffer = NULL;
	return str;
}

HANDLE g_event;

UINT WINAPI TestThread(LPVOID lParam)
{
	while (1)
	{
		static int count = 0;
		if (5 == count)
		{
			SetEvent(g_event);
			std::cout << "TestThread is return" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "TestThread is running" << std::endl;
			count++;
			Sleep(1000);
		}
	}
}

#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>
using boost::uuids::detail::md5;
std::string toString(const md5::digest_type &digest)
{
	const auto charDigest = reinterpret_cast<const char *>(&digest);
	std::string result;
	boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(result));
	return result;
}
	

int main()
{	
	if (1)
	{
		char a[] = "1234";
		char b[] = "1234";
		std::string strA;
		std::string strB;
		//bool reta = GetMd5(strA, a, strlen(a));
		//bool retb = GetMd5(strB, b, strlen(b));

		std::string s;

		while (std::getline(std::cin, s)) 
		{
			md5 hash;
			md5::digest_type digest;

			hash.process_bytes(s.data(), s.size());
			hash.get_digest(digest);

			std::cout << "md5(" << s << ") = " << toString(digest) << '\n';
		}
	}
	if (0)
	{
		g_event = CreateEventA(NULL, FALSE, FALSE, NULL);

		UINT nid = 0;
		HANDLE hThread = (HANDLE)::_beginthreadex(NULL, 0, TestThread, NULL, 0, &nid);
		std::cout << "wait for TestThread return" << std::endl;
		WaitForSingleObject(g_event, INFINITE);
		return 0;
	}
	if (0)
	{
		std::ifstream ifs;
		//输出默认locale规则的名字
		//std::string strName = ifs.getloc().name;
		//更改locale规则以支持中文
		ifs.imbue(std::locale("chs"));
		//std::string strName2 = ifs.getloc().name;
		//打开中文路径文件
		ifs.open("C:\\Users\\waction\\Desktop\\test\\11.sql");
		if (ifs.good())
		{
			//读取中文字符
			std::string strLine;
			while (getline(ifs, strLine))
			{
				TranslateUTF8ToGB(const_cast<char *>(strLine.c_str()), strLine.length());
				std::cout << strLine << std::endl;
			}
		}
		ifs.close();

	}
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

