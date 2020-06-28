#ifndef TestSingleton_h__
#define TestSingleton_h__

#include <iostream>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton instance;
		return instance;
	}
protected:
	Singleton() {}
	~Singleton() {}
	Singleton(const Singleton &);
	Singleton& operator=(const Singleton&);
private:

};

#endif // TestSingleton_h__
