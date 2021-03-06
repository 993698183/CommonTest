#pragma once
#ifndef GUID_TEST
#define GUID_TEST

#include <iostream>
#include <string>

#include <objbase.h>
#include <stdio.h>
#define GUID_LEN 64

void get_guid()
{
	char buffer[GUID_LEN] = { 0 };
	GUID guid;
	if (CoCreateGuid(&guid))
	{
		fprintf(stderr, "create guid error\n");
		return;
	}
	_snprintf(buffer,
		sizeof(buffer),
		"%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
		guid.Data1,
		guid.Data2,
		guid.Data3,
		guid.Data4[0],
		guid.Data4[1],
		guid.Data4[2],
		guid.Data4[3],
		guid.Data4[4],
		guid.Data4[5],
		guid.Data4[6],
		guid.Data4[7]
	);
	std::cout << "guid:" << buffer << std::endl;
}

#endif