#ifndef _JSON_TEST_
#define _JSON_TEST_
#include "include/json.h"
//lib�ļ��к�.vcxproj�ļ�ͬһ��Ŀ¼
#pragma comment(lib, "lib/jsond.lib")
#include <string>
#include <iostream>
//�ܽ����Ҫ�ж��Ƿ���key��ʹ��isMember��Ա������
//value�Ƿ�Ϊnullʹ��isNull��Ա������
//value�Ƿ�Ϊ�տ�����empty() �� size()��Ա������

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
	//ͨ���ַ�������json����
	std::string strValue = R"({ "key":"value1","array":[{"arraykey":1},{"arraykey":2}]})";
	//std::string strValue = "{ \"key\":\"value1\",\
	//	\"array\":[{\"arraykey\":1},{\"arraykey\":2}]}"; 

	Json::Reader reader;
	Json::Value root;
	// reader��Json�ַ���������root��root������Json��������Ԫ��
	if (reader.parse(strValue, root))
	{
		if (!root["key"].isNull())//�ж�key�Ƿ�Ϊnull
		{
			std::string strValue = root["key"].asString();
			std::cout << strValue << std::endl;

			if (root.isMember("key"))//�ж�key�Ƿ����
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
	//����Json�������л�Ϊ�ַ���
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	root["key"] = "value1";
	for (int i = 0; i < 10; i++)
	{
		item["arraykey"] = i;
		arrayObj.append(item);  //����µ������Ա
	}
	root["array"] = arrayObj;
	std::string out = root.toStyledString();  //��Json�������л�Ϊ�ַ���
	std::cout << out << std::endl;
}

//����json�ַ���
void test_json5()
{
	Json::Value root;
	Json::FastWriter writer;
	string name = "abcd";
	root["name"] = name;
	root["number"] = "2010014357";
	root["address"] = "xxxx";
	root["age"] = 100;
	string data = writer.write(root);  //need #include <fstream>
	cout << "data:\n" << data << endl;
}

//����json����
void test_json6()
{
	//root�ڵ�ֱ��apped��û�нڵ����ƣ�����������ɵĶ���json����
	Json::Value root;
	Json::FastWriter writer;
	Json::Value person;
	person["name"] = "hello world1";
	person["age"] = 100;
	root.append(person);
	person["name"] = "hello world2";
	person["age"] = 200;
	root.append(person);
	string data = writer.write(root);
	cout << data << endl;
	cout << root.toStyledString() << endl;
}
#endif
