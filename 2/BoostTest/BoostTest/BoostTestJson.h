#pragma once
#ifndef BOOST_TEST_JSON
#define BOOST_TEST_JSON

#include <iostream>
#include <string>
//boost中json解析库不是线程安全的，在多线程中要谨慎使用
//如果需要支持线程安全，就必须加入一个宏#define BOOST_SPIRIT_THREADSAFE
//把这个宏放置在引用boost头文件最开始就行
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
void test_json()
{
	std::string s = "{ \"a\": 100, \"b\": [1, 2, 3, 4] }";
	std::stringstream ss(s);
	boost::property_tree::ptree pt;
	//读取json数据
	boost::property_tree::read_json(ss, pt);
	std::cout << pt.get_child("b").data() << std::endl;
	//写回json数据
	boost::property_tree::write_json("./tmp.json", pt);
}

void test_json2()
{
	std::string s = "{ \"a\": { \"b\":1, \"c\":2 }, \"d\":3 }";
	std::stringstream ss(s);
	boost::property_tree::ptree ptree;
	boost::property_tree::read_json(ss, ptree);
	std::cout << "input text:" << std::endl;
	boost::property_tree::write_json(std::cout, ptree);
	std::cout << "parse result: " << std::endl;
	std::cout << "a->b" << ptree.get_child("a").get_child("b").get_value<int>() << std::endl;
	std::cout << "a->b" << ptree.get_child("a.b").get_value<int>() << std::endl;
	std::cout << "a->c" << ptree.get_child("a.c").get_value<int>() << std::endl;
	std::cout << "d:" << ptree.get_child("d").get_value<int>() << std::endl;
}

void test_json3()
{
	std::string s = "{ \"a\": { \"b\":1, \"c\":2 }, \"d\":[1, 2, 3, 4] }";
	std::stringstream ss(s);
	boost::property_tree::ptree ptree;
	boost::property_tree::read_json(ss, ptree);
	std::cout << "input text" << std::endl;
	boost::property_tree::write_json(std::cout, ptree);
	std::cout << "-----------------------" << std::endl;
	std::cout << "a->b" << ptree.get<int>("a.b") << std::endl;
	std::cout << "a->c: " << ptree.get<int>("a.c") << std::endl;
	//std::cout << "d: " << ptree.get<int>("d") << std::endl;
	//boost::property_tree::ptree root;
	boost::property_tree::ptree items;
	items = ptree.get_child("d");
	for (boost::property_tree::ptree::iterator it = items.begin(); it != items.end(); ++it)
	{
		//遍历读出数据  
		int a = it->second.get_value<int>();
		std::cout << a << std::endl;
	}
}

const std::string file_path = "./test.txt";
void generate_user()
{
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;

	boost::property_tree::ptree item1;
	item1.put("ID", "1");
	item1.put("Name", "wang");
	items.push_back(std::make_pair("1", item1));

	boost::property_tree::ptree item2;
	item2.put("ID", "2");
	item2.put("Name", "zhang");
	items.push_back(std::make_pair("2", item2));

	boost::property_tree::ptree item3;
	item3.put("ID", "3");
	item3.put("Name", "li");
	items.push_back(std::make_pair("3", item3));

	root.put_child("user", items);
	boost::property_tree::write_json(file_path, root);
}
void read_user()
{
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;
	boost::property_tree::read_json<boost::property_tree::ptree>(file_path, root);

	items = root.get_child("user");
	for (boost::property_tree::ptree::iterator it = items.begin(); it != items.end(); ++it)
	{
		//遍历读出数据  
		string key = it->first;//key ID  
		string ID = it->second.get<string>("ID");
		string Name = it->second.get<string>("Name");
		std::cout << key << " " << ID << " " << Name << std::endl;
	}
}

//"100012": [
//{"名字":"玫瑰"},
//{ "道具类型":"普通" },
//{ "经验值":20 },
//{ "主播获得积分":20 },
//{ "玩家获得积分":20 },
//{ "返现银子":0 },
//{ "价格":2 },
//{ "货币类型":"元宝" },
//{ "说明":"送你一朵玫瑰花！" },
//{ "特效说明":"一次性赠送10个触发特效和1次弹幕" },
//{ "弹幕次数":[{"1":0},{ "10":1 },{ "99":2 },{ "520":3 },{ "1314":4 }] },
//{ "动画次数":[{"1":0},{ "10":1 },{ "99":1 },{ "520":1 },{ "1314":1 }] }
//],
//"100013": [
//{"名字":"吻"},
//{ "道具类型":"浪漫" },
//{ "经验值":50 },
//{ "主播获得积分":50 },
//{ "玩家获得积分":50 },
//{ "返现银子":2500 },
//{ "价格":5 },
//{ "货币类型":"元宝" },
//{ "说明":"幸运的祝福！" },
//{ "特效说明":"一次性赠送10个触发特效和2次弹幕" },
//{ "弹幕次数":[{"1":1},{ "10":2 },{ "99":3 },{ "520":4 },{ "1314":5 }] },
//{ "动画次数":[{"1":0},{ "10":1 },{ "99":1 },{ "520":1 },{ "1314":1 }] }
//]
//}
#include "boost/shared_ptr.hpp"                  //智能指针
#include "boost/lexical_cast.hpp"                //字符串、数据转换
#include "boost/property_tree/ptree.hpp"         //JSon解析
#include "boost/property_tree/json_parser.hpp"   //JSon解析
#include "boost/foreach.hpp"
typedef struct _CHARMPROP
{
	long    lPropID;
	string  strPropName;
	string  strText;                //说明
	string  strType;                //类型
	float   fPrice;                 //价格
	string  strMoneyType;           //货币类型
	long    lDesGetCharm;           //接受者增加的魅力值
	long    recver_score;           //接受者获得的积分
	long    sender_score;           //发送者获得的积分
	int     return_sliver;          //返还银子数量
	string  texiao_str;             //特效说明
	map<long, int>   donghua_num;   //动画次数
	map<long, int>   danmu_num;     //弹幕次数
	~_CHARMPROP()
	{
		donghua_num.clear();
		danmu_num.clear();
	}
}CHARMPROP, *PCharmProp;

BOOL LoadCharmConfigUct()
{
	std::map<long, boost::shared_ptr<CHARMPROP> >_charm_map;
	_charm_map.clear();
	try
	{
		LPCSTR data_str = NULL;
		//... 
		//此处略去几行，就是给data_str赋json字符串
		if (NULL == data_str)
		{
			//读取文件失败
			return FALSE;
		}
		//格式化到字符串流中
		stringstream str_stream;
		str_stream << data_str;
		boost::property_tree::ptree     ptree_root, pt_tmp, pt_tmp2;
		//未加密文件可以将str_stream替换为你的文件名
		//解析json格式，并将所有节点信息保存到ptree_root结构中
		boost::property_tree::json_parser::read_json<boost::property_tree::ptree>(str_stream, ptree_root);

		long charm_id(0); //道具唯一标识ID
						  //从ptree_root枚举所有的变量列表，如"100012","100013"
		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, ptree_root)
		{
			//获取key并转换成long型
			charm_id = boost::lexical_cast<long>(v.first);
			//新建一个内存堆，存放后面读取到的数据
			boost::shared_ptr<CHARMPROP> pCharm(new CHARMPROP);
			pCharm->lPropID = charm_id;
			//开始枚举每一变量内的所有对象，会有多种不同的节点，甚至还会有自己的子数组
			pt_tmp = ptree_root.get_child(v.first);
			BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, pt_tmp)
			{
				//获取枚举到的对象，通过字符串对比，判断相应的字段
				string key_str, vul_str;
				boost::property_tree::ptree p = vul.second;
				key_str = p.front().first;
				vul_str = p.front().second.data();
				if (key_str.compare("名字") == 0)
				{
					pCharm->strPropName = vul_str;
				}
				else if (key_str.compare("道具类型") == 0)
				{
					pCharm->strType = vul_str;
				}
				else if (key_str.compare("说明") == 0)
				{
					pCharm->strText = vul_str;
				}
				else if (key_str.compare("价格") == 0)
				{
					pCharm->fPrice = boost::lexical_cast<float>(vul_str);
				}
				else if (key_str.compare("经验值") == 0)
				{
					pCharm->lDesGetCharm = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("主播获得积分") == 0)
				{
					pCharm->recver_score = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("玩家获得积分") == 0)
				{
					pCharm->sender_score = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("返现银子") == 0)
				{
					pCharm->return_sliver = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("货币类型") == 0)
				{
					pCharm->strMoneyType = vul_str;
				}
				else if (key_str.compare("特效说明") == 0)
				{
					pCharm->texiao_str = vul_str;
				}
				else if (key_str.compare("弹幕次数") == 0)
				{
					//此节点下面还有n个子对象，需要分别读取并保存到结构体的map中，这里继续枚举当前ptree临时变量，以获取其数组
					BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, p) //枚举弹幕数组
					{
						boost::property_tree::ptree pt_tmp2 = vul.second;
						//枚举获取所有子对象
						BOOST_FOREACH(boost::property_tree::ptree::value_type& vul2, pt_tmp2)
						{
							boost::property_tree::ptree p2 = vul2.second;
							key_str = p2.front().first;
							vul_str = p2.front().second.data();
							pCharm->danmu_num[boost::lexical_cast<long>(key_str)] = boost::lexical_cast<int>(vul_str);
						}
					}
				}
				else if (key_str.compare("动画次数") == 0)
				{
					//此节点下面还有n个子对象，需要分别读取并保存到结构体的map中，这里继续枚举当前ptree临时变量，以获取其数组
					BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, p)
					{
						boost::property_tree::ptree pt_tmp2 = vul.second;
						//枚举获取所有子对象
						BOOST_FOREACH(boost::property_tree::ptree::value_type& vul2, pt_tmp2)
						{
							boost::property_tree::ptree p2 = vul2.second;
							key_str = p2.front().first;
							vul_str = p2.front().second.data();
							pCharm->donghua_num[boost::lexical_cast<long>(key_str)] = boost::lexical_cast<int>(vul_str);
						}
					}
				}
				_charm_map[charm_id] = pCharm; //将智能指针保存到map容器中
			}
		}

	}
	catch (boost::property_tree::json_parser::json_parser_error& e) //json解析异常
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::property_tree::ptree_bad_path& e) //json读取数组或对象时异常
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::bad_lexical_cast& e) //lexical_cast转换时异常
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::property_tree::ptree_bad_data& e) //json读取数组或对象时异常
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	return TRUE;
}
#endif
