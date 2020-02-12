#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

namespace DelegatingConstructor {


/*
委派构造函数的使用，类似与构造基类
*/

class Info
{
public:
	Info() { init(); }
	//Info(int _age) : Info(), mName("qwe") //无法编译通过，不能同时 委派 和 初始化成员，如果需要初始化成员，必须放在构造函数体中
	Info(int _age) : Info()
	{ 
		mAge = _age; 
		printf("--- one param mAge:%d\n", mAge);
	}
	Info(int _age, std::string _name) : Info(_age)
	{
		mName = _name; 
		printf("--- two param mName:%s\n", mName.c_str());
	}

private:
	void init(){ mHeight = 1.23f; printf("--- init mheight:%f\n", mHeight); }
	int mAge;
	std::string mName;
	float mHeight;
};

void testDelegatingConstructor()
{
	Info info(77, "yang");
	/*
	--- init mheight:1.230000
	--- one param mAge:77
	--- two param mName:yang
	请按任意键继续. . .
	*/
}

void main()
{
	testDelegatingConstructor();
}

}
