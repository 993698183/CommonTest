// BoostApplicationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include "my_list.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using namespace std;
//测试结构体
class HistroyInfo
{
public:
	HistroyInfo() {};
	~HistroyInfo() {};

	friend boost::filesystem::fstream& operator >> (boost::filesystem::fstream& f, HistroyInfo& h)
	{
		char c;
		f >> h.m_id;
		f >> c;
		f >> h.m_kk;
		f >> c;
		f >> h.m_sec;
		f >> c;
		f >> h.name;
		f >> c;
		return f;
	}

	friend boost::filesystem::fstream& operator << (boost::filesystem::fstream& f, const HistroyInfo& h)
	{
		f << h.m_id;
		f << ",";
		f << h.m_kk;
		f << ",";
		f << h.m_sec;
		f << ",";
		f << h.name;
		f << "\n";

		return f;
	}
	uint32_t m_id;
	uint32_t m_kk;
	uint32_t m_sec;
	std::string name;
protected:
private:
};
//格式话结构体到指定目录
void test_boostsystem()
{
	std::string path = "E:\\1_ZXLCode\\0_GitHub\\CommonTest\\2\\test.txt";
	HistroyInfo info;
	info.m_id = 20;
	info.m_kk = 20;
	info.m_sec = 20;
	info.name = "asdfasdfaf";

	//file path
	boost::filesystem::path fpath(path);
	boost::filesystem::fstream fstream(fpath, std::ios_base::out);
	//write data to file
	fstream << info;
	fstream.close();

	boost::filesystem::fstream fstream1(fpath, std::ios_base::in);
	HistroyInfo info2;
	//read data from file
	fstream1 >> info2;

	std::cout << info2.m_id << std::endl;
	std::cout << info2.name << std::endl;
	fstream1.close();
}

//2020年3月24日23点35分，给自定义对象定义std::cout<<操作符
class CPoint
{
public:
	CPoint(int x_, int y_) :x(x_), y(y_) {}

	friend ostream& operator <<(ostream& os, const CPoint& p) {
		return os << "x = " << p.x << " y = " << p.y << endl;
	}

	int x, y;
};
void test_ostream()
{
	CPoint p(1, 2);
	std::cout << p << std::endl;
}

//boost::md5计算
#include <boost/algorithm/hex.hpp>
#include <boost/uuid/detail/md5.hpp>
//获取buf的md5值
bool GetMd5(std::string& str_md5, const char* const buffer, size_t buffer_size)
{
	if (buffer == nullptr)
	{
		return false;
	}
	boost::uuids::detail::md5 boost_md5;
	boost_md5.process_bytes(buffer, buffer_size);
	boost::uuids::detail::md5::digest_type digest;
	boost_md5.get_digest(digest);
	const auto char_digest = reinterpret_cast<const char*>(&digest);
	str_md5.clear();
	boost::algorithm::hex(char_digest, char_digest + sizeof(boost::uuids::detail::md5::digest_type), std::back_inserter(str_md5));
	return true;
}

bool GetSHA1(std::string& str_sha1, const char* const buffer, size_t buffer_size)
{
	//char hash[20];
	//boost::uuids::detail::sha1 boost_sha1;
	//boost_sha1.process_bytes(buffer, buffer_size);
	//boost::uuids::detail::sha1::digest_type digest;
	//boost_sha1.get_digest(digest);
	//for (int i = 0; i < 5; ++i) {
	//	const char *tmp = reinterpret_cast<char*>(digest);
	//	hash[i * 4] = tmp[i * 4 + 3];
	//	hash[i * 4 + 1] = tmp[i * 4 + 2];
	//	hash[i * 4 + 2] = tmp[i * 4 + 1];
	//	hash[i * 4 + 3] = tmp[i * 4];
	//}

	//str_sha1.clear();
	//std::ostringstream buf;
	//for (int i = 0; i < 20; ++i) {
	//	buf << setiosflags(ios::uppercase) << std::hex << ((hash[i] & 0x0000000F0) >> 4);
	//	buf << setiosflags(ios::uppercase) << std::hex << (hash[i] & 0x00000000F);
	//}

	//str_sha1 = buf.str();
	return true;
}
void get_md5_sha()
{
	string str_md5;
	string str_sha1;
	string str = "1@948-3*9:-=!@#$%^&**()_+?><~`{}[]|;,.";

	if (GetMd5(str_md5, str.c_str(), str.length()) == true) {
		cout << "str_md5 : " << str_md5 << endl;
	}
	else {
		cout << "error .." << endl;
	}

	cout << "----------------------------------------------" << endl;

	if (GetSHA1(str_sha1, str.c_str(), str.length()) == true)
	{
		cout << "str_sha1 : " << str_sha1 << endl;
	}
	else
	{
		cout << "error .." << endl;
	}
}

int main()
{
	test_ostream();

	getchar();
	return 0;
}