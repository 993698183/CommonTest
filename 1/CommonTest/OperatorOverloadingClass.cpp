#include "OperatorOverloadingClass.h"

OperatorOverloadingClass::OperatorOverloadingClass()
{
	m_number = 0;
	m_fnumber = 0.0;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
}

OperatorOverloadingClass::OperatorOverloadingClass(const int &number,
	const float &fnumber)
	: m_number(number)
	, m_fnumber(fnumber)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
}

void OperatorOverloadingClass::print()
{
	std::cout << "m_number =" << m_number;
}

OperatorOverloadingClass OperatorOverloadingClass::operator-(const OperatorOverloadingClass &obj)
{
	OperatorOverloadingClass out;
	out.m_number = this->m_number - obj.m_number;
	return out;
}

OperatorOverloadingClass OperatorOverloadingClass::operator+(const OperatorOverloadingClass &obj)
{
	OperatorOverloadingClass out;
	out.m_number = this->m_number + obj.m_number;
	return out;
}

