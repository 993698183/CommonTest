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
		node<T> *ptr;//ָ��������ĳ��Ԫ�ص�ָ��

	public:
		list_iterator(node<T> *p = nullptr) :ptr(p) {}

		//����++��������*��->�Ȼ�������
		//�������ã�����ͨ��*it���޸Ķ���
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
			//this��ָ��list_iterator�ĳ���ָ�룬���*this����list_iterator����ǰ��++�Ѿ������ع�
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
	typedef list_iterator iterator;//���ͱ���
	my_list() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	//������β������Ԫ��
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
	//��ӡ����Ԫ��
	void print(std::ostream &os = std::cout)const 
	{
		for (node<T> *ptr = head; ptr != tail->next; ptr = ptr->next)
		{
			os << ptr->value << std::endl;
		}
	}
public:
	//�����������ķ���
	//��������ͷ��ָ��
	iterator begin() const 
	{
		return list_iterator(head);
	}
	//��������β��ָ��
	iterator end()const
	{
		return list_iterator(tail->next);
	}
	//������Ա����insert/erase/emplace
};

struct Student
{
	std::string name;
	int age;
	Student(std::string n, int a) :name(n), age(a) {}
	//�������������
	friend ostream & operator <<(ostream & os, const Student & stu)
	{
		//os << stu.name;// << " " << stu.age;
		return os;
	}
};

#endif


