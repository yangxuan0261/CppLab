#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

namespace DeconstructTest {


class Base
{
public:
	Base() { printf("--- Base construce\n"); }

	//如果不用虚函数析构，则父类指针指向之类对象时，delete父类指针，无法调用到子类的析构函数（多态性）
	//~Base() { printf("--- Base deconstruce\n"); } 
	virtual ~Base() { printf("--- Base virtual deconstruce\n"); }
};

class Dev : public Base
{
public:
	Dev() { printf("--- Dev construce\n"); }
	//~Dev() { printf("--- Dev deconstruce\n"); }
	virtual ~Dev() { printf("--- Dev virtual deconstruce\n"); }
};




void testDeconstruce()
{
	Dev* d = new Dev;
	delete d;
	printf("\n");

	Base* d2 = new Dev;
	delete d2;
	printf("\n");
}

void main()
{
	testDeconstruce();
}

}
