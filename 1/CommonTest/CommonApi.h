#pragma once

#ifndef COMMONAPI_H
#define COMMONAPI_H

class CommonApi
{
public:
	static void test_unique_ptr_get_release_reset();
	static void test_computer_little_or_big_endian();
	static void test_size_type_vector();
	static void test_string_big_or_little();
	static void test_try_catch();
	CommonApi();
	~CommonApi();
};

#endif

