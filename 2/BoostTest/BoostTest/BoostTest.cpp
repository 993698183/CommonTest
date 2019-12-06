// BoostTest.cpp : Defines the entry point for the console application.
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
#include "BoostTestXML.h"
#include "BoostTestException.h"
#include "BoostTestJson.h"
#include "BoostTestAsio.h"
#include "BoostTestSharedPtr.h"
#include "classorder/ClassOrderTest.h"
#include "semaphore/SemaphoreTest.h"
#include "guid/GuidTest.h"
#include "Cplus11/Cplus.h"
#include "checkjson/CCheckJson.h"
#include "stdfunctiontest/stdfunctiontest.h"

int main()
{
	//test_function();
	//test_string();
	//test_string_find_string();
	//test_string_find_token();
	//test_thread();
	//test_thread_mutex();
	//test_bind_fun1();
	//test_xml();
	//test_xml2();
	//test_error();
	//test_error2();
	//test_error4();
	//test_json();
	//test_json2();
	//test_1();
	//test_sharedptr_new();
	//test_class_order();
	//get_guid();
	//test_Raw_string();
	//generate_user();
	//test_json3();
	//generate_user();
	test_std_function();
	getchar();
    return 0;
}

