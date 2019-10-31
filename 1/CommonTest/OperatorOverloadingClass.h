#pragma once
#ifndef OPERATOROVERLOADINGCLASS_H
#define OPERATOROVERLOADINGCLASS_H
#include <iostream>
using namespace std;
const int SIZE = 10;

class OperatorOverloadingClass
{
public:
	OperatorOverloadingClass();
	OperatorOverloadingClass(const int &number, const float &fnumber);
	//��ֵ�����
	void operator = (const OperatorOverloadingClass &obj)
	{
		m_number = obj.m_number;
	}

	//���ã��������
	OperatorOverloadingClass operator()(int a, int b, int c)
	{
		OperatorOverloadingClass D;
		D.m_number = a + b + c;
		return D;
	}

	void print();

	//���������
	OperatorOverloadingClass operator + (const OperatorOverloadingClass &obj);
	OperatorOverloadingClass operator - (const OperatorOverloadingClass &obj);
	OperatorOverloadingClass operator * ()
protected:
private:
	int m_number;
	float m_fnumber;
	int arr[SIZE];
};

#endif //OPERATOROVERLOADINGCLASS_H