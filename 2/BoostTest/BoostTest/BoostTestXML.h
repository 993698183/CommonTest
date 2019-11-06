#pragma once
#ifndef BOOST_TEST_XML
#define BOOST_TEST_XML

#include <iostream>
#include <string>
#include <set>
#include <exception>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

struct debug_settting 
{
	std::string m_file;//log file name
	int m_level;//debug level
	std::set<std::string> m_modules;//modules where logging is enabled
	void load(const std::string &filename);
	void save(const std::string &filename);
};

void debug_settting::load(const std::string &filename)
{
	boost::property_tree::ptree pt;
	read_xml(filename, pt);
	m_file = pt.get<std::string>("debug.filename");
	m_level = pt.get("debug.level", 0);
}

void debug_settting::save(const std::string &filename)
{
	boost::property_tree::ptree pt;
	pt.put("debug.filename", m_file);
	pt.put("debug.level", m_level);
	BOOST_FOREACH(const std::string &filename, m_modules);
	pt.add("debug.modules.module", filename);
	write_xml(filename, pt);
}

void test_xml()
{
	try
	{
		debug_settting ds;
		ds.load("d:\\debug_settings.xml");
		ds.save("d:\\debug_settings_out.xml");
		std::cout << "success" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error" << e.what() << std::endl;
	}
}

#endif