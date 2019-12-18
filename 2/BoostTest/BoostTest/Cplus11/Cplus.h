#pragma once
#ifndef C_PLUS_11
#define C_PLUS_11

#include <iostream>
#include <string>

//C++11原始字符串操作
//原始字符串字面量的定义为：R"xxx(raw string)xxx"
//其中，原始字符必须用括号（）括起来，括号的前后可以加其他的字符串，所加的字符串会被忽略，并且加的字符串必须在括号两边同时出现

void test_Raw_string()
{
	std::string normal_str = "First line.\nSecond line.\nEnd of Message.\n";
	// 一个raw string，'\'不会被转义处理。因此，"\n"表示两个字符：字符反斜杠 和 字母n。
	std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
	std::cout << normal_str << std::endl;
	std::cout << raw_str << std::endl;
	std::cout << R"foo(hello, world)foo" << std::endl;
	//raw string 可以跨越多行，其中的空白和换行符都属于字符串的一部分
	std::cout << R"(
                   Hello,
                   world!
                   )" << std::endl;
}

//C++11的原子操作类型数据
#include <boost/thread/thread.hpp>
#include <atomic> 
#include <iostream>
#include <time.h>

using namespace std;
// 全局的结果数据 
//long total = 0;
//用原子数据类型作为共享资源的数据类型
atomic_long total(0);

// 对共享资源进行保护的互斥对象
std::mutex m;

// 点击函数
void click()
{
	for (int i = 0; i < 1000000; ++i)
	{
		// 对全局数据进行无锁访问 
		//m.lock();
		total += 1;
		//m.unlock();
	}
}

void test_atomic()
{
	// 计时开始
	clock_t start = clock();
	// 创建100个线程模拟点击统计
	boost::thread_group threads;
	for (int i = 0; i < 100; ++i)
	{
		threads.create_thread(click);
	}

	threads.join_all();
	// 计时结束
	clock_t finish = clock();
	// 输出结果
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
	v.reserve(count);       //预分配十万大小，排除掉分配内存的时间

	{
		TIME_INTERVAL_SCOPE("push_back T:");
		Foo temp("ceshi");
		v.push_back(temp);// push_back(const T&)，参数是左值引用
						  //打印结果：
						  //constructor
						  //copy constructor
	}

	v.clear();
	{
		TIME_INTERVAL_SCOPE("push_back move(T):");
		Foo temp("ceshi");
		v.push_back(std::move(temp));// push_back(T &&), 参数是右值引用
									 //打印结果：
									 //constructor
									 //move constructor
	}

	v.clear();
	{
		TIME_INTERVAL_SCOPE("push_back(T&&):");
		v.push_back(Foo("ceshi"));// push_back(T &&), 参数是右值引用
								  //打印结果：
								  //constructor
								  //move constructor
	}

	v.clear();
	{
		std::string temp = "ceshi";
		TIME_INTERVAL_SCOPE("push_back(string):");
		v.push_back(temp);// push_back(T &&), 参数是右值引用
						  //打印结果：
						  //constructor
						  //move constructor
	}

	v.clear();
	{
		std::string temp = "ceshi";
		TIME_INTERVAL_SCOPE("emplace_back(string):");
		v.emplace_back(temp);// 只有一次构造函数，不调用拷贝构造函数，速度最快
							 //打印结果：
							 //constructor
	}
}

//C++11的线程类
//std::thread
//头文件：<thread>
void my_thread()
{
	puts("hello world");
}
void test_thread()
{
	std::thread t(my_thread);//实例化一个线程对象t，参数my_thread是一个函数
	t.join();//join（）,等待子线程执行完以后，主线程才可以继续执行下去，此时主线程会释放的子线程资源
	//当然，如果不想等待子进程，可以在主线程里面执行t.detch（）将子线程从主线程分离
	//子线程执行完成后会自动释放资源，分离后的线程，主进程对它没有控制权了
	//相比于beginthread传多个参数需要传入struct地址
	//相比于boost::thread传参需要bind
	//std::thread传入参数真的很方便，而且可读性非常好
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
//互斥量在线程中的使用
//多个线程同时访问贡献资源的时候需要用到互斥量，当一个线程锁住了互斥量以后，其他线程必须等待这个线程解锁后才能访问它
//thread提供了四种不同的互斥量：
//独占式互斥量non-recursive（std::mutex）
//独占式互斥量加解锁是成对的，同一个线程内独占式互斥量在没有解锁的情况下，再次对它进行加锁是不对的，会得到一个未定义行为
//使用std::metex成员函数lock加锁和unlock解锁，看起来工作的很好，但这样是不安全的，你得始终记住lock以后一定要有unlock
//但是如果中间出现了异常或者线程直接退出了，unlock没有执行，因为这个互斥量是独占式得，所以在thread1没有解锁之前，
//其他使用这个互斥量加锁得线程会一直处于等待状态得不到执行
//lock_guard模板类使用RAII手法封装互斥量，在实例化对象的时候帮你加锁，并且能保证在离开作用域的时候自动解锁，所以用lock_guard
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

//递归式互斥量recursive（std::recursive_mutex）
//允许超时的独占式互斥量non-recursive that allows timeouts on the lock function（std::timed_mutex）
//允许超时的递归式互斥量recursive mutex that allows timeouts on the lock functions（std::recurive_timed_mutex）
#endif