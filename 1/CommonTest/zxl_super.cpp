#include "stdafx.h"
#include "zxl_super.h"

// deriv_super.cpp
// compile with: /c
struct B1 {
	void mf(int) {}
};

struct B2 {
	void mf(short) {}

	void mf(char) {}
};

struct D : B1, B2 {
	void mf(short) {
		__super::mf(1);   // Calls B1::mf(int)
		__super::mf('s');   // Calls B2::mf(char)
	}
};

zxl_super::zxl_super()
{
}


zxl_super::~zxl_super()
{
}
