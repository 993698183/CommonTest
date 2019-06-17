#pragma once

#ifndef COMMONAPI_H
#define COMMONAPI_H

#include <string>

class CommonApi
{
public:
	static void test_unique_ptr_get_release_reset();
	static void test_computer_little_or_big_endian();
	static void test_size_type_vector();
	static void test_string_big_or_little();
	static void test_try_catch();
	static void test_string_wstring_to_upper_lowwer();
	static void test_findcommon();
	static void test_get_string_length();
	static void test_boost_filepath();
	static void test_boost_thread();
	static void test_boost_thread2();
	static void test_my_reverse_copy();
	static void test_format_time();
	static void test_ObserverPattern();
	static void test_log_dll();
	static void test_windows_event();
	static void test_string_to_i();
	static void test_string_to_float();
	static void test_string_c_str_data();
	static void test_my_log_file();
	static void test_unordered_map();
	static void test_vfprintf();
	static void test_copy_file();
	CommonApi();
	~CommonApi();
};

#endif


