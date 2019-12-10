#pragma once
#ifndef BOOST_TEST_JSON
#define BOOST_TEST_JSON

#include <iostream>
#include <string>
//boost��json�����ⲻ���̰߳�ȫ�ģ��ڶ��߳���Ҫ����ʹ��
//�����Ҫ֧���̰߳�ȫ���ͱ������һ����#define BOOST_SPIRIT_THREADSAFE
//����������������boostͷ�ļ��ʼ����
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>

void test_json()
{
	std::string s = "{ \"a\": 100, \"b\": [1, 2, 3, 4] }";
	std::stringstream ss(s);
	boost::property_tree::ptree pt;
	//��ȡjson����
	boost::property_tree::read_json(ss, pt);
	std::cout << pt.get_child("b").data() << std::endl;
	//д��json����
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
		//������������  
		int a = it->second.get_value<int>();
		std::cout << a << std::endl;
	}
}

const std::string file_path = "d:\\test.txt";
void generate_user()
{
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;

	boost::property_tree::ptree item1;
	boost::property_tree::ptree tmp;
	boost::property_tree::ptree item1_1;
	//item1.add_child("", 1);
	item1_1.put("", 1);
	tmp.push_back(std::make_pair("", item1_1));
	item1_1.put("", 2);
	tmp.push_back(std::make_pair("", item1_1));
	item1_1.put("", 3);
	tmp.push_back(std::make_pair("", item1_1));
	
	item1.add_child("ID", tmp);
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
	//std::stringstream ss;
	//boost::property_tree::write_json(ss, root);
	//std::string strContent = ss.str();
	//std::cout << strContent << std::endl;
}


void read_user()
{
	boost::property_tree::ptree root;
	boost::property_tree::ptree items;
	boost::property_tree::read_json<boost::property_tree::ptree>(file_path, root);

	items = root.get_child("user");
	for (boost::property_tree::ptree::iterator it = items.begin(); it != items.end(); ++it)
	{
		//������������  
		string key = it->first;//key ID  
		string ID = it->second.get<string>("ID");
		string Name = it->second.get<string>("Name");
		std::cout << key << " " << ID << " " << Name << std::endl;
	}
}

//ʹ�ø�����������������
using boost::property_tree::ptree;

template <typename T>
std::vector<T> as_vector(ptree const& pt, ptree::key_type const& key)
{
	std::vector<T> r;
	for (auto& item : pt.get_child(key))
		r.push_back(item.second.get_value<T>());
	return r;
}
void test_shuzu()
{
	std::stringstream ss("{\"a\": [8, 6, 2], \"b\": [2, 2, 1]}");
	ptree pt;
	read_json(ss, pt);
	for (auto i : as_vector<int>(pt, "a")) std::cout << i << ' ';
	std::cout << '\n';
	for (auto i : as_vector<int>(pt, "b")) std::cout << i << ' ';
}

//"100012": [
//{"����":"õ��"},
//{ "��������":"��ͨ" },
//{ "����ֵ":20 },
//{ "������û���":20 },
//{ "��һ�û���":20 },
//{ "��������":0 },
//{ "�۸�":2 },
//{ "��������":"Ԫ��" },
//{ "˵��":"����һ��õ�廨��" },
//{ "��Ч˵��":"һ��������10��������Ч��1�ε�Ļ" },
//{ "��Ļ����":[{"1":0},{ "10":1 },{ "99":2 },{ "520":3 },{ "1314":4 }] },
//{ "��������":[{"1":0},{ "10":1 },{ "99":1 },{ "520":1 },{ "1314":1 }] }
//],
//"100013": [
//{"����":"��"},
//{ "��������":"����" },
//{ "����ֵ":50 },
//{ "������û���":50 },
//{ "��һ�û���":50 },
//{ "��������":2500 },
//{ "�۸�":5 },
//{ "��������":"Ԫ��" },
//{ "˵��":"���˵�ף����" },
//{ "��Ч˵��":"һ��������10��������Ч��2�ε�Ļ" },
//{ "��Ļ����":[{"1":1},{ "10":2 },{ "99":3 },{ "520":4 },{ "1314":5 }] },
//{ "��������":[{"1":0},{ "10":1 },{ "99":1 },{ "520":1 },{ "1314":1 }] }
//]
//}
#include "boost/shared_ptr.hpp"                  //����ָ��
#include "boost/lexical_cast.hpp"                //�ַ���������ת��
#include "boost/property_tree/ptree.hpp"         //JSon����
#include "boost/property_tree/json_parser.hpp"   //JSon����
#include "boost/foreach.hpp"
typedef struct _CHARMPROP
{
	long    lPropID;
	string  strPropName;
	string  strText;                //˵��
	string  strType;                //����
	float   fPrice;                 //�۸�
	string  strMoneyType;           //��������
	long    lDesGetCharm;           //���������ӵ�����ֵ
	long    recver_score;           //�����߻�õĻ���
	long    sender_score;           //�����߻�õĻ���
	int     return_sliver;          //������������
	string  texiao_str;             //��Ч˵��
	map<long, int>   donghua_num;   //��������
	map<long, int>   danmu_num;     //��Ļ����
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
		//�˴���ȥ���У����Ǹ�data_str��json�ַ���
		if (NULL == data_str)
		{
			//��ȡ�ļ�ʧ��
			return FALSE;
		}
		//��ʽ�����ַ�������
		stringstream str_stream;
		str_stream << data_str;
		boost::property_tree::ptree     ptree_root, pt_tmp, pt_tmp2;
		//δ�����ļ����Խ�str_stream�滻Ϊ����ļ���
		//����json��ʽ���������нڵ���Ϣ���浽ptree_root�ṹ��
		boost::property_tree::json_parser::read_json<boost::property_tree::ptree>(str_stream, ptree_root);

		long charm_id(0); //����Ψһ��ʶID
						  //��ptree_rootö�����еı����б���"100012","100013"
		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, ptree_root)
		{
			//��ȡkey��ת����long��
			charm_id = boost::lexical_cast<long>(v.first);
			//�½�һ���ڴ�ѣ���ź����ȡ��������
			boost::shared_ptr<CHARMPROP> pCharm(new CHARMPROP);
			pCharm->lPropID = charm_id;
			//��ʼö��ÿһ�����ڵ����ж��󣬻��ж��ֲ�ͬ�Ľڵ㣬�����������Լ���������
			pt_tmp = ptree_root.get_child(v.first);
			BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, pt_tmp)
			{
				//��ȡö�ٵ��Ķ���ͨ���ַ����Աȣ��ж���Ӧ���ֶ�
				string key_str, vul_str;
				boost::property_tree::ptree p = vul.second;
				key_str = p.front().first;
				vul_str = p.front().second.data();
				if (key_str.compare("����") == 0)
				{
					pCharm->strPropName = vul_str;
				}
				else if (key_str.compare("��������") == 0)
				{
					pCharm->strType = vul_str;
				}
				else if (key_str.compare("˵��") == 0)
				{
					pCharm->strText = vul_str;
				}
				else if (key_str.compare("�۸�") == 0)
				{
					pCharm->fPrice = boost::lexical_cast<float>(vul_str);
				}
				else if (key_str.compare("����ֵ") == 0)
				{
					pCharm->lDesGetCharm = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("������û���") == 0)
				{
					pCharm->recver_score = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("��һ�û���") == 0)
				{
					pCharm->sender_score = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("��������") == 0)
				{
					pCharm->return_sliver = boost::lexical_cast<long>(vul_str);
				}
				else if (key_str.compare("��������") == 0)
				{
					pCharm->strMoneyType = vul_str;
				}
				else if (key_str.compare("��Ч˵��") == 0)
				{
					pCharm->texiao_str = vul_str;
				}
				else if (key_str.compare("��Ļ����") == 0)
				{
					//�˽ڵ����滹��n���Ӷ�����Ҫ�ֱ��ȡ�����浽�ṹ���map�У��������ö�ٵ�ǰptree��ʱ�������Ի�ȡ������
					BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, p) //ö�ٵ�Ļ����
					{
						boost::property_tree::ptree pt_tmp2 = vul.second;
						//ö�ٻ�ȡ�����Ӷ���
						BOOST_FOREACH(boost::property_tree::ptree::value_type& vul2, pt_tmp2)
						{
							boost::property_tree::ptree p2 = vul2.second;
							key_str = p2.front().first;
							vul_str = p2.front().second.data();
							pCharm->danmu_num[boost::lexical_cast<long>(key_str)] = boost::lexical_cast<int>(vul_str);
						}
					}
				}
				else if (key_str.compare("��������") == 0)
				{
					//�˽ڵ����滹��n���Ӷ�����Ҫ�ֱ��ȡ�����浽�ṹ���map�У��������ö�ٵ�ǰptree��ʱ�������Ի�ȡ������
					BOOST_FOREACH(boost::property_tree::ptree::value_type& vul, p)
					{
						boost::property_tree::ptree pt_tmp2 = vul.second;
						//ö�ٻ�ȡ�����Ӷ���
						BOOST_FOREACH(boost::property_tree::ptree::value_type& vul2, pt_tmp2)
						{
							boost::property_tree::ptree p2 = vul2.second;
							key_str = p2.front().first;
							vul_str = p2.front().second.data();
							pCharm->donghua_num[boost::lexical_cast<long>(key_str)] = boost::lexical_cast<int>(vul_str);
						}
					}
				}
				_charm_map[charm_id] = pCharm; //������ָ�뱣�浽map������
			}
		}

	}
	catch (boost::property_tree::json_parser::json_parser_error& e) //json�����쳣
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::property_tree::ptree_bad_path& e) //json��ȡ��������ʱ�쳣
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::bad_lexical_cast& e) //lexical_castת��ʱ�쳣
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	catch (const boost::property_tree::ptree_bad_data& e) //json��ȡ��������ʱ�쳣
	{
		const char* err_buf = e.what();
		_charm_map.clear();
		return FALSE;
	}
	return TRUE;
}
#endif
