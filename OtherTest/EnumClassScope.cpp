#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

void GFuncTest() { printf("--- GFuncTest\n"); }
namespace EnumClassScope {

enum EM_A
{
	aaa = 0,
	bbb,
	ccc,
};

enum class EM_B
{
	qqq = 0,
	www,
	eee,
};

class Yun
{
public:
	enum class EM_C
	{
		xxx = 0,
		yyy,
		zzz,
	};

public:
	Yun(){}
	virtual ~Yun(){}

	void test1()
	{
		::GFuncTest(); //::xxx ，xxx是个全局函数，不是对象函。::可以明显是全局函数
	}

	void test2(){ printf("--- Yun test2"); }
};

void testEnum()
{
	int a = bbb;
	//int b = EM_B::eee; //error, c++11枚举类，必须使用作用域EM_B, 且转换必须使用显示强转，不然编译报错
	int b = (int)EM_B::eee; //正确

	Yun y;
	int c = (int)Yun::EM_C::xxx;

	printf("--- a:%d, b:%d, c:%d\n", a, b, c);
}

enum BitSet
{
	V0 = 1 << 0,
	V1 = 1 << 1,
	V2 = 1 << 2,
	VMAX = 1 << 3,
};

void testScope()
{
	auto p = new Yun();
	p->test1();
}

void main()
{
	//testEnum();
	testScope();
}
}
