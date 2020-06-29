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
#include "BoostTestSmartPtr.h"
#include "classorder/ClassOrderTest.h"
#include "semaphore/SemaphoreTest.h"
#include "guid/GuidTest.h"
#include "Cplus11/Cplus.h"
#include "checkjson/CCheckJson.h"
#include "stdfunctiontest/stdfunctiontest.h"
#include "jsoncpp/json_test.h"
#include "http/http.h"
#include "fileoperate/SetFileCreateTime.h"

int main()
{	
	test_stl_smart_ptr();
	getchar();
    return 0;
}

