#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "AAA.h"
using namespace std;

namespace DeepCopy {


class BBB
{
public:
	BBB() :a(nullptr), b(nullptr)
	{
		a = new int;
		*a = 10;
		b = new string;
		*b = "helloworld";
	}
	//浅拷贝
	//如果在类中没有显式地声明一个拷贝构造函数，
	//那么，编译器将会自动生成一个默认的拷贝构造函数，
	//该构造函数完成对象之间的位拷贝。位拷贝又称浅拷贝

	//深拷贝
	BBB(const BBB& _b)
	{
		a = new int;
		*a = *_b.a;

		b = new string;
		*b = *_b.b;
	}

	virtual ~BBB()
	{
		if (a)
		{
			delete a;
			a = nullptr;
		}

		if (b)
		{
			delete b;
			b = nullptr;
		}
	}

	void Show()
	{
		printf("--- a=%d, b=%s\n", *a, b->c_str());
	}

public:
	int* a;
	std::string* b;

};

void testCopyConstruct()
{
	BBB b1;
	b1.Show();
	BBB b2 = b1;//调用赋值构造函数
	b2.Show();
	system("pause");

	//这个方法调用完之后，会释放栈中b1,b2的内存
	//如果是浅拷贝，则 b1和b2 中的 a和b分别指向相同的地址，
	//b1析构释放完后ab的内存后，b2中ab就成了野指针，析构中的if判断还是会跑进去，delete野指针就会造成崩溃

	//如果是深拷贝，则b2 中的ab指向新的地址，和b1中的ab完全无关
	//所以b1 b2都正常析构，方法正常跑完

	//什么时候用到拷贝函数？
	//	a.一个对象以值传递的方式传入函数体；
	//	b.一个对象以值传递的方式从函数返回；
	//	c.一个对象需要通过另外一个对象进行初始化。

}

void main()
{
	testCopyConstruct();
}

}
