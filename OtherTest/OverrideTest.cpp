#include <iostream>
#include <sstream>
#include <string>


namespace OverrideTest
{
	


class CBase
{
public:
	CBase() { printf("--- CBase 构造\n"); }
	virtual ~CBase(){ printf("--- CBase 析构\n"); }

	//覆盖是指派生类函数覆盖基类函数，函数名、参数都一致
	virtual void test1(int _a, std::string _b) { printf("--- CBase test1\n"); }

	//隐藏，函数名一致、参数不一致，根据指针的具体类型调用对应的方法，
	virtual void test2(int _a, std::string _b) { printf("--- CBase test2\n"); }

	//没有virtual关键字，函数名、参数都一致，依然是根据指针的具体类型调用对应的方法，
	void test3(int _a, std::string _b) { printf("--- CBase test3\n"); }

private:

};

class CDev : public CBase
{
public:
	CDev() { printf("--- CDev 构造\n"); }
	virtual ~CDev(){ printf("--- CDev 析构\n"); }

	virtual void test1(int _a, std::string _b) { printf("--- CDev test1\n"); }

	virtual void test2(int _a) { printf("--- CDev test2\n"); }

	void test3(int _a, std::string _b) { printf("--- CDev test3\n"); }

private:

};

void testOverride()
{
	CBase* d1 = new CDev;

	d1->test1(1, "asd");
	d1->test2(1, "asd");
	d1->test3(1, "asd");

	printf("\n");

	CDev* d2 = (CDev*)d1;
	d2->test2(2);
	d2->test3(2, "asd");
	delete d1;

}

void main()
{

	testOverride();
}

} // OverrideTest
