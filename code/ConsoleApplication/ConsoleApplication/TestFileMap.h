#pragma once
#ifndef TestFileMap_h__
#define TestFileMap_h__
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
using namespace std;
int test_file_map()
{
	HANDLE fh;
	HANDLE MapFileH;
	HANDLE OpenMap;
	HANDLE MapHandle;
	boost::filesystem::path p("C:\\1.txt");
	fh = CreateFile(p.wstring().c_str(), 
		GENERIC_READ|GENERIC_WRITE, 
		FILE_SHARE_READ, 
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);
	if (fh == INVALID_HANDLE_VALUE)
	{
		std::cout << "error in createfile" << std::endl;
		return false;
	}
	MapFileH = CreateFileMapping(fh,
		NULL,
		PAGE_READWRITE,
		0,
		0,
		L"Resource");
	if (MapFileH == NULL)
	{
		std::cout << "error in createFileMapping" << std::endl;
	}
	OpenMap = OpenFileMapping(FILE_MAP_ALL_ACCESS,
		true,
		L"Resource");
	if (OpenMap == NULL)
	{
		std::cout << "error in openfilemapping" << std::endl;
	}
	MapHandle = MapViewOfFile(OpenMap,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0);
	if (MapHandle == NULL)
	{
		std::cout << "error in mapviewoffile" << std::endl;
	}
	/*
	对数据进行处理
	*/
	UnmapViewOfFile(MapHandle);
	CloseHandle(OpenMap);
	CloseHandle(fh);
	return 0;
}

#endif // TestFileMap_h__
