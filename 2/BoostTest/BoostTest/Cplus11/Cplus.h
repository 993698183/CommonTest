#pragma once
#ifndef C_PLUS_11
#define C_PLUS_11

#include <iostream>
#include <string>

//C++11ԭʼ�ַ�������
//ԭʼ�ַ����������Ķ���Ϊ��R"xxx(raw string)xxx"
//���У�ԭʼ�ַ����������ţ��������������ŵ�ǰ����Լ��������ַ��������ӵ��ַ����ᱻ���ԣ����Ҽӵ��ַ�����������������ͬʱ����

void test_Raw_string()
{
	std::string normal_str = "First line.\nSecond line.\nEnd of Message.\n";
	// һ��raw string��'\'���ᱻת�崦����ˣ�"\n"��ʾ�����ַ����ַ���б�� �� ��ĸn��
	std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
	std::cout << normal_str << std::endl;
	std::cout << raw_str << std::endl;
	std::cout << R"foo(hello, world)foo" << std::endl;
	//raw string ���Կ�Խ���У����еĿհ׺ͻ��з��������ַ�����һ����
	std::cout << R"(
                   Hello,
                   world!
                   )" << std::endl;
}

//C++11��ԭ�Ӳ�����������
#include <boost/thread/thread.hpp>
#include <atomic> 
#include <iostream>
#include <time.h>

using namespace std;
// ȫ�ֵĽ������ 
//long total = 0;
//��ԭ������������Ϊ������Դ����������
atomic_long total(0);

// �Թ�����Դ���б����Ļ������
std::mutex m;

// �������
void click()
{
	for (int i = 0; i < 1000000; ++i)
	{
		// ��ȫ�����ݽ����������� 
		//m.lock();
		total += 1;
		//m.unlock();
	}
}

void test_atomic()
{
	// ��ʱ��ʼ
	clock_t start = clock();
	// ����100���߳�ģ����ͳ��
	boost::thread_group threads;
	for (int i = 0; i < 100; ++i)
	{
		threads.create_thread(click);
	}

	threads.join_all();
	// ��ʱ����
	clock_t finish = clock();
	// ������
	cout << "result:" << total << endl;
	cout << "duration:" << finish - start << "ms" << endl;
}
//------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <functional>
void test_lambda()
{
	std::vector<int> c{ 1,2,3,4,5,6,7 };
	int x = 5;
	c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

	std::cout << "c: ";
	for (auto i : c) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	// the type of a closure cannot be named, but can be inferred with auto
	auto func1 = [](int i) { return i + 4; };
	std::cout << "func1: " << func1(6) << '\n';

	// like all callable objects, closures can be captured in std::function
	// (this may incur unnecessary overhead)
	std::function<int(int)> func2 = [](int i) { return i + 4; };
	std::cout << "func2: " << func2(6) << '\n';
}

#include <iostream>
#include <memory>
#include <string>
#ifdef GCC
#include <sys/time.h>
#else
#include <ctime>
#endif // GCC

class TimeInterval
{
public:
	TimeInterval(const std::string& d) : detail(d)
	{
		init();
	}

	TimeInterval()
	{
		init();
	}

	~TimeInterval()
	{
#ifdef GCC
		gettimeofday(&end, NULL);
		std::cout << detail
			<< 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000
			<< " ms" << endl;
#else
		end = clock();
		std::cout << detail
			<< (double)(end - start) << " ms" << std::endl;
#endif // GCC
	}

protected:
	void init() {
#ifdef GCC
		gettimeofday(&start, NULL);
#else
		start = clock();
#endif // GCC
	}
private:
	std::string detail;
#ifdef GCC
	timeval start, end;
#else
	clock_t start, end;
#endif // GCC
};

#define TIME_INTERVAL_SCOPE(d)   std::shared_ptr<TimeInterval> time_interval_scope_begin = std::make_shared<TimeInterval>(d)

class Foo {
public:
	Foo(std::string str) : name(str) {
		std::cout << "constructor" << std::endl;
	}
	Foo(const Foo& f) : name(f.name) {
		std::cout << "copy constructor" << std::endl;
	}
	Foo(Foo&& f) : name(std::move(f.name)) {
		std::cout << "move constructor" << std::endl;
	}

private:
	std::string name;
};

void test_emplace_back()
{
	std::vector<Foo> v;
	int count = 10000000;
	v.reserve(count);       //Ԥ����ʮ���С���ų��������ڴ��ʱ��

	{
		TIME_INTERVAL_SCOPE("push_back T:");
		Foo temp("ceshi");
		v.push_back(temp);// push_back(const T&)����������ֵ����
						  //��ӡ�����
						  //constructor
						  //copy constructor
	}

	v.clear();
	{
		TIME_INTERVAL_SCOPE("push_back move(T):");
		Foo temp("ceshi");
		v.push_back(std::move(temp));// push_back(T &&), ��������ֵ����
									 //��ӡ�����
									 //constructor
									 //move constructor
	}

	v.clear();
	{
		TIME_INTERVAL_SCOPE("push_back(T&&):");
		v.push_back(Foo("ceshi"));// push_back(T &&), ��������ֵ����
								  //��ӡ�����
								  //constructor
								  //move constructor
	}

	v.clear();
	{
		std::string temp = "ceshi";
		TIME_INTERVAL_SCOPE("push_back(string):");
		v.push_back(temp);// push_back(T &&), ��������ֵ����
						  //��ӡ�����
						  //constructor
						  //move constructor
	}

	v.clear();
	{
		std::string temp = "ceshi";
		TIME_INTERVAL_SCOPE("emplace_back(string):");
		v.emplace_back(temp);// ֻ��һ�ι��캯���������ÿ������캯�����ٶ����
							 //��ӡ�����
							 //constructor
	}
}

//C++11���߳���
//std::thread
//ͷ�ļ���<thread>
void my_thread()
{
	puts("hello world");
}
void test_thread()
{
	std::thread t(my_thread);//ʵ����һ���̶߳���t������my_thread��һ������
	t.join();//join����,�ȴ����߳�ִ�����Ժ����̲߳ſ��Լ���ִ����ȥ����ʱ���̻߳��ͷŵ����߳���Դ
	//��Ȼ���������ȴ��ӽ��̣����������߳�����ִ��t.detch���������̴߳����̷߳���
	//���߳�ִ����ɺ���Զ��ͷ���Դ���������̣߳������̶���û�п���Ȩ��
	//�����beginthread�����������Ҫ����struct��ַ
	//�����boost::thread������Ҫbind
	//std::thread���������ĺܷ��㣬���ҿɶ��Էǳ���
}

void my_thread2(int num, const std::string &str)
{
	std::cout << "num:" << num << ",str:" << str << std::endl;
}
void test_my_thread2()
{
	int num = 1234;
	std::string str = "hello world";
	std::thread t(my_thread2, num, str);
	t.detach();
}


//https://www.cnblogs.com/lidabo/p/7266897.html
//���������߳��е�ʹ��
//����߳�ͬʱ���ʹ�����Դ��ʱ����Ҫ�õ�����������һ���߳���ס�˻������Ժ������̱߳���ȴ�����߳̽�������ܷ�����
//thread�ṩ�����ֲ�ͬ�Ļ�������
//��ռʽ������non-recursive��std::mutex��
//��ռʽ�������ӽ����ǳɶԵģ�ͬһ���߳��ڶ�ռʽ��������û�н���������£��ٴζ������м����ǲ��Եģ���õ�һ��δ������Ϊ
//ʹ��std::metex��Ա����lock������unlock�����������������ĺܺã��������ǲ���ȫ�ģ����ʼ�ռ�סlock�Ժ�һ��Ҫ��unlock
//��������м�������쳣�����߳�ֱ���˳��ˣ�unlockû��ִ�У���Ϊ����������Ƕ�ռʽ�ã�������thread1û�н���֮ǰ��
//����ʹ������������������̻߳�һֱ���ڵȴ�״̬�ò���ִ��
//lock_guardģ����ʹ��RAII�ַ���װ����������ʵ���������ʱ���������������ܱ�֤���뿪�������ʱ���Զ�������������lock_guard
#include <mutex>
int g_num = 0;
std::mutex g_mutex;
void thread_1()
{
	//g_mutex.lock();
	std::lock_guard<std::mutex> lg(g_mutex);
	g_num = 10;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "thread_1=" << g_num << std::endl;
	}
	//g_mutex.unlock();
}
void thread_2()
{
	//g_mutex.lock();
	std::lock_guard<std::mutex> lg(g_mutex);
	g_num = 20;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "thread2=" << g_num << std::endl;
	}
	//g_mutex.unlock();
}
void test_mutex()
{
	std::thread t1(thread_1);
	std::thread t2(thread_2);
	t1.join();
	t2.join();
}

//�ݹ�ʽ������recursive��std::recursive_mutex��
//����ʱ�Ķ�ռʽ������non-recursive that allows timeouts on the lock function��std::timed_mutex��
//����ʱ�ĵݹ�ʽ������recursive mutex that allows timeouts on the lock functions��std::recurive_timed_mutex��

//���Ⱥ�˳����̼߳�ͬ������������
//�̼߳乲�����ݣ������һ���̵߳ȴ���һ���̵߳����������֮������Ⱥ�˳��
//����뻥������ͬ����������ֻ֤��һ���̷߳��ʵ�ǰ�����˵Ĵ���飬����֮�䲻�����Ⱥ�˳��
#include <condition_variable>

//class Foo1
//{
//public:
//	Foo1()
//		:flag_(0),
//		thread1_(std::bind(&Foo1::threadFun1, this)),
//		thread2_(std::bind(&Foo1::threadFun2, this))
//		{
//
//		}
//	~Foo1()
//	{
//		thread1_.join();
//		thread2_.join();
//	}
//protected:
//private:
//	void threadFun1()
//	{
//		std::unique_lock<std::mutex> ul(mutex_);
//		while (0 == flag_)
//		{
//			cond_.wait(ul);
//		}
//		std::cout << flag_ << std::endl;
//	}
//	void threadFun2()
//	{
//		//Ϊ�˲��ԣ��ȴ�����
//		std::this_thread::sleep_for((std::chrono::milliseconds(3000)));
//		std::unique_lock<std::mutex> ul(mutex_);
//		flag_ = 100;
//		cond_.notify_one();
//	}
//	int flag_;
//	std::mutex mutex_;
//	std::condition_variable cond_;
//	std::thread thread1_;
//	std::thread thread2_;
//};
void test_Foo()
{
	//Foo1 f;
}
#endif