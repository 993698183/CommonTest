#ifndef _JSON_TEST_
#define _JSON_TEST_
#include "include/json.h"
//lib文件夹和.vcxproj文件同一级目录
#pragma comment(lib, "lib/jsond.lib")
#include <string>
#include <iostream>
void test_jsoncpp()
{
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";

	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000" 
		std::cout << upload_id << std::endl;
		int code = root["code"].asInt();    // 访问节点，code = 100 
		std::cout << code << std::endl;
	}
}
#endif
