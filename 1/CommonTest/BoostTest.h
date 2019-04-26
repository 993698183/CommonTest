#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/minmax.hpp>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/filesystem.hpp>
class BoostTest
{
public:
	BoostTest();
	~BoostTest();

public:
	int get_sec();
	void test_timer();

	// boost::progress_timerҲ��һ����ʱ�������̳���timer��
	// ����������ʱ�Զ����ʱ�䣬ʡȥ��boost::timer�ֶ�����elapsed()�Ĺ�������һ�������Զ���ʱ�൱�����С����
	void test_progress_timer();
	void test_progress_display();
	void test_progress_display_restart();

	void show_file(const boost::filesystem::wpath &path);
};

