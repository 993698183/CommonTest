#ifndef SetFileCreateTime_h__
#define SetFileCreateTime_h__

#include <iostream>

//设定文件修改时间
int settime(LPCSTR filename)
{
	SYSTEMTIME  systime;
	FILETIME ft, ftUTC;
	HANDLE hFile;

	systime.wYear = 2000;
	systime.wMonth = 1;
	systime.wDay = 1;
	systime.wDayOfWeek = 1;
	systime.wSecond = 1;
	systime.wHour = 1;
	systime.wMinute = 1;
	systime.wMilliseconds = 1;

	SystemTimeToFileTime(&systime, &ft);
	LocalFileTimeToFileTime(&ft, &ftUTC);
	hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		SetFileTime(hFile, (LPFILETIME)NULL, (LPFILETIME)NULL, &ftUTC);
	}
	CloseHandle(hFile);

	return 0;
}

#endif // SetFileCreateTime_h__
