
#ifndef TestEvent_h__
#define TestEvent_h__

#include <iostream>

#include <windows.h>
#include <process.h>
#include <stdio.h>

struct ThreadInfo
{
	ThreadInfo();
	~ThreadInfo();

	HANDLE	fire;
	HANDLE	stop;
private:
	ThreadInfo(const ThreadInfo&);
	ThreadInfo& operator=(const ThreadInfo&);
};

ThreadInfo::ThreadInfo()
{
	fire = CreateEvent(0, FALSE, FALSE, NULL);
	stop = CreateEvent(0, TRUE, FALSE, NULL);
}

ThreadInfo::~ThreadInfo()
{
	CloseHandle(stop);
	CloseHandle(fire);
}

unsigned __stdcall threadfunc(void* param)
{
	if (ThreadInfo* info = reinterpret_cast<ThreadInfo*>(param))
	{
		char buf[32];

		for (;;)
		{
			HANDLE h[2] = { info->fire, info->stop };
			DWORD ret = WaitForMultipleObjects(2, h, FALSE, INFINITE);
			if (ret == WAIT_OBJECT_0)
			{
				_snprintf(buf, sizeof(buf), "Thread %ld fired\n", GetCurrentThreadId());
				printf(buf);
			}
			else if (ret == WAIT_OBJECT_0 + 1)
			{
				_snprintf(buf, sizeof(buf), "Thread %ld clean shutdown\n", GetCurrentThreadId());
				printf(buf);
				break;
			}
			else
			{
				_snprintf(buf, sizeof(buf), "Thread %ld abnormal shutdown\n", GetCurrentThreadId());
				printf(buf);
				break;
			}
			_snprintf(buf, sizeof(buf), "Thread %ld running\n", GetCurrentThreadId());
			printf(buf);
		}
	}
	return 0;
}

void test_event()
{
	const size_t N = 1;
	ThreadInfo info[N];
	HANDLE h[N];

	for (size_t i = 0; i != N; ++i)
	{
		unsigned threadid;
		h[i] = (HANDLE)_beginthreadex(0, 0, threadfunc, &info[i], 0, &threadid);
	}
	Sleep(5 * 1000);

	for (size_t i = 0; i != N; ++i)
	{
		std::cout << "setevent fire" << std::endl;
		SetEvent(info[i].fire);
	}
	Sleep(5 * 1000);

	for (size_t i = 0; i != N; ++i)
	{
		std::cout << "setevent stop" << std::endl;
		SetEvent(info[i].stop);
	}
	Sleep(5 * 1000);
}
#endif // TestEvent_h__