#pragma once
#ifndef _TEST_THREAD_H_
#define _TEST_THREAD_H_
#include <iostream>
#include <thread>
#include <chrono>
//using namespace std;
void fun1(int n)
{
    std::cout << "Thread" << n << std::endl;
    n += 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

//拷贝构造函数
void fun2(int& n)
{
    std::cout << "Thread" << n << "executing\n";
    n += 20;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int test_c11_thread()
{
    int n = 0;
    std::thread t1;//t1不是一个thread
    std::thread t2(fun1, n + 1);
    t2.join();
    std::cout << "n=" << n << std::endl;
    n = 10;
    std::thread t3(fun2, std::ref(n));//引用
    std::thread t4(move(t3));//t4执行t3，t3不是thread
    t4.join();
    std::cout << "n=" << n << std::endl;
    return 0;
}
#endif // !_TEST_THREAD_H_

