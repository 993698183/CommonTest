#include "stdafx.h"
#include "BoostTest.h"

//const��ʹ��
class A
{
public:
	//���캯��
	A():a(0) {};
	A(int x):a(x) {};//��ʼ���б�

	//const���������������غ���������
	int getValue();//��ͨ��Ա����
	int getValue() const;//����Ա�����������޸��κ����е��κ����ݳ�Ա��ֵ
protected:
private:
	const int a;//�������Ա��ֻ���ڳ�ʼ���б���ʹ��
};

void function()
{
	//����
	A b;//��ͨ���󣬿��Ե���ȫ����Ա����
	const A a;//������ֻ�ܵ��ó���Ա���������³���Ա����
	const A *p = &a;//��ָ��
	const A &q = a;//������

	char greeting[] = "Hello";
	char *p1 = greeting;//ָ�������ָ���ַ��������
	const char *p2 = greeting;//ָ�������ָ���ַ����鳣��
	char *const p3 = greeting;//��ָ�룬ָ���ַ����鳣��
	const char * const p4 = greeting;//��ָ�룬ָ���ַ����鳣��
}

//����
void function1(const int Var);//���ݹ����Ĳ����ں����ڲ��ɱ�
void function2(const char* Var);//����ָ����ָ����Ϊ����
void function3(char * const Var);//����ָ��Ϊ��ָ��
void function4(const int &Var);//���ò����ں�����Ϊ����

//��������ֵ
const int function5();//����һ������
const int* function6();//����һ��ָ������ָ�����
int* const function7();//����һ��ָ������ĳ�ָ��

BoostTest::BoostTest()
{
}


BoostTest::~BoostTest()
{
}

int BoostTest::get_sec()
{
	boost::timer t;
	double dTime = 0.0;
	while (true)
	{
		dTime = t.elapsed();
		std::cout << dTime << std::endl;
		Sleep(1000);
	}
}

void BoostTest::test_timer()
{
	// ����һ����ʱ�����󣬲���ʼ��ʱ!
	boost::timer t;

	long long sum = 0;
	for (int i = 0; i < 1000000; i++)
	{
		sum = sum + i;
	}

	// ����ʱ���, �����Զ��󴴽��������ŵ�ʱ�䡣
	double dl = t.elapsed();
	std::cout << "now time elapsed:" << dl << std::endl;

	//�ɶ��������ʱ�䣬����Ϊ��λ	
	std::cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << std::endl;
	//�ɶ�������Сʱ�䣬����Ϊ��λ
	std::cout << "min timespan:" << t.elapsed_min() << "s" << std::endl;

	// ����һ��restart()��ʼ���¼�ʱ
	t.restart();
}

void BoostTest::test_progress_timer()
{
	{
		boost::progress_timer pt;

		long long sum = 0;
		for (int i = 0; i < 10000000; i++)
		{
			sum = sum + i;
		}
	}

	//pt.elapsed();

	// ����һ�ַ�������Ҫ��el
	{
		boost::progress_timer pt;
		// do_something();
		long long sum2 = 0;
		for (int i = 0; i < 10000000; i++)
			sum2 = sum2 + i;
	}   // pt����ʱ�Զ��������ʱ��
}

void BoostTest::test_progress_display()
{
	std::vector<std::string> v(1000000, "����·");
	std::ofstream fs("E:\\display.txt");

	// ����һ��progress_display ���󣬻�����v�Ĵ�С
	boost::progress_display pd(v.size());

	// ��ʼѡ�����������������ַ���
	std::vector<std::string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << std::endl;
		++pd; // ���½�����ʾ
	}
}

void BoostTest::test_progress_display_restart()
{
	std::vector<std::string> v(100, "abcd");
	v[10] = "";
	v[23] = "";
	std::ofstream fs("d:\\test.txt");
	boost::progress_display pd(v.size());
	std::vector<std::string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << std::endl;
		++pd;
		if (pos->empty())
		{
			std::cout << std::endl;
			std::cout << "Error: null string # " << (pos - v.begin()) << std::endl;
			pd.restart(v.size());
			pd += (pos - v.begin() + 1);
		}
	}
}

void BoostTest::show_file(const boost::filesystem::wpath &path)
{
	std::wstring cmd = L"/select,";
	cmd += path.c_str();
	ShellExecuteW(NULL, NULL, L"explorer", cmd.c_str(), NULL, SW_NORMAL);
}
