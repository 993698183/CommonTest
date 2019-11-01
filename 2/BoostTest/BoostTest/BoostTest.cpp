﻿// BoostTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BoostTestAny.h"
#include "BoostTestFunction.h"
#include "BoostTestBind.h"
#include "BoostTestString.h"
#include "BoostTestTokenizer.h"
#include "BoostTestStringAlgo.h"
#include "BoostTestStringAlgoFind.h"
#include "BoostTestDate.h"
#include "BoostTestThread.h"
#include "BoostTestMutexLock.h"

int main()
{
	//test_function();
	//test_string();
	//test_string_find_string();
	//test_string_find_token();
	//test_thread();
	//test_thread_mutex();
	//test_bind_fun1();
	//test_thread_deadlock();
	test_thread_recursivelock();
	getchar();
    return 0;
}

