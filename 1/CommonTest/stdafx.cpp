// stdafx.cpp : source file that includes just the standard includes
// CommonTest.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <Windows.h>
#include <string>
//windows api进行字符集转换
//宽字符转多字节
std::string W2A(const std::wstring& utf8)
{
	int buffSize = WideCharToMultiByte(CP_ACP, NULL, utf8.c_str(), -1, NULL, NULL, NULL, FALSE);
	char *gbk = new char[buffSize + 1];
	memset(gbk, 0, buffSize + 1);
	WideCharToMultiByte(CP_ACP, NULL, utf8.c_str(), -1, gbk, buffSize, NULL, FALSE);
	std::string result(gbk);
	delete[] gbk;
	gbk = nullptr;
	return result;
}

//多字节转宽字符
std::wstring A2W(const std::string& gbk)
{
	int buffSize = MultiByteToWideChar(CP_ACP, NULL, gbk.c_str(), -1, NULL, NULL);
	wchar_t* utf8 = new wchar_t[buffSize + 2];
	memset(utf8, 0, buffSize + 2);
	MultiByteToWideChar(CP_ACP, NULL, gbk.c_str(), -1, utf8, buffSize);
	std::wstring result(utf8);
	delete[] utf8;
	utf8 = nullptr;
	return result;
}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
