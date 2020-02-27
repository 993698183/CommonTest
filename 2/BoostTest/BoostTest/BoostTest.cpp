// BoostTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BoostTestAny.h"
#include "BoostTestFunction.h"
#include "BoostTestBind.h"
#include "BoostTestString.h"
#include "BoostTestTokenizer.h"
#include "BoostTestStringAlgo.h"
#include "BoostTestStringAlgoFind.h"
#include "BoostTestDate.h"
#include "BoostTestThread.h"
#include "BoostTestXML.h"
#include "BoostTestException.h"
#include "BoostTestJson.h"
#include "BoostTestAsio.h"
#include "BoostTestSharedPtr.h"
#include "classorder/ClassOrderTest.h"
#include "semaphore/SemaphoreTest.h"
#include "guid/GuidTest.h"
#include "Cplus11/Cplus.h"
#include "checkjson/CCheckJson.h"
#include "stdfunctiontest/stdfunctiontest.h"
#include "jsoncpp/json_test.h"
#include "http/http.h"

//空类的size
class Car1
{};

//设定文件修改时间
int settime(LPCSTR filename)
{
	SYSTEMTIME  systime;
	FILETIME ft, ftUTC;
	HANDLE hFile;

	systime.wYear = 2000;
	systime.wMonth = 1;
	systime.wDay = 1;
	systime.wDayOfWeek = 1;
	systime.wSecond = 1;
	systime.wHour = 1;
	systime.wMinute = 1;
	systime.wMilliseconds = 1;

	SystemTimeToFileTime(&systime, &ft);
	LocalFileTimeToFileTime(&ft, &ftUTC);
	hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		SetFileTime(hFile, (LPFILETIME)NULL, (LPFILETIME)NULL, &ftUTC);
	}
	CloseHandle(hFile);

	return 0;
}

//typeid关键词的使用方法
void test_typeid()
{
	int i = 0;
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(i).hash_code() << std::endl;
}
//
int main()
{	

	getchar();
    return 0;
}

