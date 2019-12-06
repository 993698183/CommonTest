#ifndef _JSON_TEST_
#define _JSON_TEST_
#include "include/json.h"
//lib�ļ��к�.vcxproj�ļ�ͬһ��Ŀ¼
#pragma comment(lib, "lib/jsond.lib")
#include <string>
#include <iostream>
void test_jsoncpp()
{
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";

	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		std::string upload_id = root["uploadid"].asString();  // ���ʽڵ㣬upload_id = "UP000000" 
		std::cout << upload_id << std::endl;
		int code = root["code"].asInt();    // ���ʽڵ㣬code = 100 
		std::cout << code << std::endl;
	}
}
#endif
