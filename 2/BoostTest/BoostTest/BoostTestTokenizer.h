#pragma once
#ifndef BOOST_TEST_TOKENIZER
#define BOOST_TEST_TOKENIZER

#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

void test_string_tokenizer()
{
	using namespace boost;

	// 1. ʹ��ȱʡģ����������ִʶ���, Ĭ�ϰ����еĿո�ͱ����Ϊ�ָ���. 
	{
		std::string str("Link raise the master-sword.");

		tokenizer<> tok(str);
		for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
		// [Link][raise][the][master][sword]
	}

	// 2. char_separator()
	{
		std::string str("Link raise the master-sword.");

		// һ��char_separator����, Ĭ�Ϲ��캯��(������㵫���������ָ���)
		char_separator<char> sep;
		tokenizer<char_separator<char> > tok(str, sep);
		for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
		// [Link][raise][the][master][-][sword][.]
	}

	// 3. char_separator(const Char* dropped_delims,
	//                   const Char* kept_delims = 0, 
	//                   empty_token_policy empty_tokens = drop_empty_tokens)
	{
		std::string str = ";!!;Hello|world||-foo--bar;yow;baz|";

		char_separator<char> sep1("-;|");
		tokenizer<char_separator<char> > tok1(str, sep1);
		for (BOOST_AUTO(pos, tok1.begin()); pos != tok1.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
		// [!!][Hello][world][foo][bar][yow][baz]

		char_separator<char> sep2("-;", "|", keep_empty_tokens);
		tokenizer<char_separator<char> > tok2(str, sep2);
		for (BOOST_AUTO(pos, tok2.begin()); pos != tok2.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
		// [][!!][Hello][|][world][|][][|][][foo][][bar][yow][baz][|][]
	}

	// 4. escaped_list_separator
	{
		std::string str = "Field 1,\"putting quotes around fields, allows commas\",Field 3";

		tokenizer<escaped_list_separator<char> > tok(str);
		for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
		// [Field 1][putting quotes around fields, allows commas][Field 3]
		// �����ڵĶ��Ų�����Ϊ�ָ���.
	}

	// 5. offset_separator
	{
		std::string str = "12252001400";

		int offsets[] = { 2, 2, 4 };
		offset_separator f(offsets, offsets + 3);
		tokenizer<offset_separator> tok(str, f);

		for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
			std::cout << "[" << *pos << "]";
		std::cout << std::endl;
	}
}

#endif
