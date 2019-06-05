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

	// boost::progress_timer也是一个计时器，它继承自timer，
	// 它会在析构时自动输出时间，省去了boost::timer手动调用elapsed()的工作，是一个用于自动计时相当方便的小工具
	void test_progress_timer();
	void test_progress_display();
	void test_progress_display_restart();

	void show_file(const boost::filesystem::wpath &path);
};

