#pragma once

#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>
#include <ostream>
using namespace std;
template<typename T>
class node
{
public:
	T value;
	node *next;
	node() :next(nullptr) {}
	node(T val, node *p = nullptr) :value(val), next(p) {}
protected:
private:
};

template<typename T>
class my_list
{
public:
private:
	node<T> *head;
	node<T> *tail;
	int size;

private:
	class list_iterator
	{
	private:
		node<T> *ptr;//指向容器中某个元素的指针

	public:
		list_iterator(node<T> *p = nullptr) :ptr(p) {}

		//重载++，——，*，->等基本操作
		//返回引用，方便通过*it来修改对象
		T &operator*() const {
			return ptr->value;
		}
		node<T> *operator->()const {
			return ptr;
		}
		list_iterator &operator++() {
			ptr = ptr->next;
			return *this;
		}
		list_iterator operator++(int) {
			node<T> *tmp = ptr;
			//this是指向list_iterator的常量指针，因此*this就是list_iterator对象，前置++已经被重载过
			++(*this);
			return list_iterator(tmp);
		}

		bool operator==(const list_iterator &t) const {
			return t.ptr == this->ptr;
		}
		
		bool operator!=(const list_iterator &t) const {
			return t->ptr != this->ptr;
		}
	};

public:
	typedef list_iterator iterator;//类型别名
	my_list() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	//从链表尾部插入元素
	void push_back(const T &value)
	{
		if (head == nullptr)
		{
			head = new node<T>(value);
			tail = head;
		}
		else
		{
			tail->next = new node<T>(value);
			tail = tail->next;
		}
		size++;
	}
	//打印链表元素
	void print(std::ostream &os = std::cout)const 
	{
		for (node<T> *ptr = head; ptr != tail->next; ptr = ptr->next)
		{
			os << ptr->value << std::endl;
		}
	}
public:
	//操作迭代器的方法
	//返回链表头部指针
	iterator begin() const 
	{
		return list_iterator(head);
	}
	//返回链表尾部指针
	iterator end()const
	{
		return list_iterator(tail->next);
	}
	//其他成员函数insert/erase/emplace
};

struct Student
{
	std::string name;
	int age;
	Student(std::string n, int a) :name(n), age(a) {}
	//重载输出操作符
	friend ostream & operator <<(ostream & os, const Student & stu)
	{
		//os << stu.name;// << " " << stu.age;
		return os;
	}
};

#endif


