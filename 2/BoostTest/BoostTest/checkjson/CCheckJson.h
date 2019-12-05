#ifndef _CHECKJSON_
#define _CHECKJSON_

#include <iostream>
#include <string>
#include <sstream>
#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

typedef struct RegPara
{
	int nRegType;
	std::string strPCID;
	std::string strCorpration;
}REGPARA, *PREGPARA;

void MakeRegJson()
{
	REGPARA reg;
	reg.nRegType = 2;
	reg.strCorpration = "waction";
	reg.strPCID = "111111";

	boost::property_tree::ptree ptRegister;
	boost::property_tree::ptree ptPara;
	ptRegister.put("type", "req");
	ptRegister.put("sid", "");
	ptRegister.put("req_id", "0");
	ptRegister.put("function", "register");
	//ptPara.put("")
}

#endif
