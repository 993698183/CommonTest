#pragma once
#ifndef CLASS_TEST_ORDER
#define CLASS_TEST_ORDER

#include <iostream>
#include <string>

class c
{
public:
	c() { std::cout << "c" << std::endl; }
	~c() { std::cout << "destory c" << std::endl; }
protected:
private:
};

class b
{
public:
	b() { std::cout << "b" << std::endl; }
	~b() { std::cout << "destory b" << std::endl; }
protected:
	c C;
private:
};

class a :public b
{
public:
	a() { std::cout << "a" << std::endl; }
	~a() { std::cout << "destory a" << std::endl; }
protected:
private:
};

void test_class_order()
{
	//C++��ѭ���´���˳��
	//1�����ĳ�����о�����ִ࣬��Ĭ�Ϲ��캯��
	//2����ķǾ�̬���ݳ�Ա����������˳�򴴽�
	//3��ִ�и���Ĺ��캯��
	//������ʱ�����ȹ����丸�࣬Ȼ�󴴽����Ա�������ñ����캯��

	//����˳��
		//���๹�캯���������Ա���캯���������౾���캯��
	//����˳��
		//�����౾�����������������Ա�������������������������빹��˳�������෴��

	//������
	//�ֲ��������˳�������ʱ����
	//��̬�����ڶ��������ļ�����ʱ����
	//ȫ�ֶ����ڳ������ʱ����
	//�̳ж��������������࣬����������
	//�����Ա������������������������Ա
	a A;
}

#endif 