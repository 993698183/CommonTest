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

void test_jsoncpp2()
{
	//const char* str = "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\",""\"born\":-100,\"died\":-44}";
	std::string  str = R"({
	"praenomen":"Gaius",
	"nomen":"Julius",
	"cognomen":"Caezar",
	"born":-100,
	"died":-44
}")";
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str, root))
	{
		std::string praenomen = root["praenomen"].asString();
		std::string nomen = root["nomen"].asString();
		std::string cognomen = root["cognomen"].asString();
		int born = root["born"].asInt();
		int died = root["died"].asInt();
		std::cout << praenomen + " " + nomen + " " + cognomen << " was born in year " << born << ", died in year " << died << std::endl;

	}
}

void test_jsoncpp3()
{
	//通过字符串创建json对象
	std::string strValue = R"({ "key":"value1","array":[{"arraykey":1},{"arraykey":2}]})";
	//std::string strValue = "{ \"key\":\"value1\",\
	//	\"array\":[{\"arraykey\":1},{\"arraykey\":2}]}"; 

	Json::Reader reader;
	Json::Value root;
	// reader将Json字符串解析到root，root将包含Json里所有子元素
	if (reader.parse(strValue, root))
	{
		if (!root["key"].isNull())//判断key是否为null
		{
			std::string strValue = root["key"].asString();
			std::cout << strValue << std::endl;

			if (root.isMember("key"))//判断key是否存在
			{
				std::cout << "key is a member" << std::endl;
			}
			else
			{
				std::cout << "key is not a member" << std::endl;
			}
		}
		Json::Value arrayObj = root["array"];
		for (int i = 0; i < arrayObj.size(); i++)
		{
			int iarrayValue = arrayObj[i]["arraykey"].asInt();
			std::cout << iarrayValue << std::endl;
		}
	}
}

void test_jsoncpp4()
{
	//构建Json对象序列化为字符串
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	root["key"] = "value1";
	for (int i = 0; i < 10; i++)
	{
		item["arraykey"] = i;
		arrayObj.append(item);  //添加新的数组成员
	}
	root["array"] = arrayObj;
	std::string out = root.toStyledString();  //将Json对象序列化为字符串
	std::cout << out << std::endl;
}


#endif
