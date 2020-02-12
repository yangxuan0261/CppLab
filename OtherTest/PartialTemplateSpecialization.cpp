#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>


namespace PartialTemplateSpecialization
{
    


/*
偏特化就是部分特化。
*/

template <typename T>
class A			//通用的模板生产
{
public:
	A(T _t)
	{
		std::cout << "--- common type:" << typeid(T).name() << ", value:" << _t << std::endl;
	}

	template<typename TP2>
	void output(TP2 _arg) {
		std::cout << "------ output type:" << typeid(TP2).name() << ", value:" << _arg << std::endl;
	}
};

template<>
class A<int>	//特例化int，使之使用这个模板生产
{
public:
	A(int _t)
	{
		std::cout << "--- special int value:" << _t << std::endl;
	}

	template<typename TP3>
	void myPrintf() {
		std::cout << "------ myPrintf type:" << typeid(TP3).name() << std::endl;
	}
};


//------------ 控制某些特化是不给编译通过，比如如下的int类型特化时不给编译通过
template <typename T>
class B
{
public:
	B(T _t)
	{
		std::cout << "--- value:" << _t << std::endl;
	}
};

template<>
class B<int>; //特例化int型不给实现，让编译时报错未定义

void testTemplate()
{
	A<int> a(111);
	a.myPrintf<double>(); //int特化的实例，有myPrintf方法
	//a.template myPrintf<double>(); //竟然也可以这样加个template调用，从cocos中的rapidjson中看到才知道
	std::cout << std::endl;

	A<double> b(123.23f);//不是int特化的实例，有output方法
	b.output(false);
	std::cout << std::endl;

	A<bool> c(true);
	c.output(123.456f);
	std::cout << std::endl;

	float x = 123.4f;
	B<decltype(x)> b1(x); //利用decltype推导出初始化参数的类型

	//int y = 111;
	//B<decltype(y)> b2(y); //error, 未定义int的B类

}



template <typename T>
inline T myClamp(T value, T low, T high)
{
	return value < low ? low : (value > high ? high : value);
}

void testTemplate3()
{
	int num = myClamp(2.f, 1.f, 3.f);
	printf("--- num:%d\n", num);
}

void main()
{
	testTemplate();
	//testTemplate3();

}

} // PartialTemplateSpecialization
